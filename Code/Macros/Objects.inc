; ==================================================================================================
; Title:      Objects.inc
; Author:     G. Friedrich
; Version:    C.1.5
; Purpose:    ObjAsm object support using MASM compatible assembers (UASM, ASMC, JWASM, ML)
; Notes:      Version C.1.0, October 2017
;               - First release.
;             Version C.1.1, September 2019
;               - Method "uses": skip 64 bit registers in 32 bit mode.
;               - Undefined symbol warning added in $PushMethodArgs.
;             Version C.1.2, December 2020
;               - $MethodAddr can handle addresses of embedded objects.
;             Version C.1.3, May 2021
;               - vararg stack correction bug corrected.
;               - dup spacing issue coorected.
;             Version C.1.4, August 2022
;               - Mitigation measures against multiple inclusion of object definition files.
;             Version C.1.5, September 2022
;               - $PushMethodArgs renamend to $PushMethodArgs32 => intended for 32 bits.
;               - Stack correction bug for vararg methods in 32 bit fixed.  
; ==================================================================================================


; Object metadata (OMD) chain and layout:
; ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
;
;                    Object Metadata (OMD) #1                #2    ...    #n
;
;   p1stOMD    ——>   POINTER to next OMD sibling      ——>    ...  ——> NULL = last OMD
;                    sizeof(Object Template) (XWORD)         ...          ...
;                    Object Template (TPL_...)               ...          ...
;                    Object Dual Method Table (DMT)          ...          ...
;                    Object type ID (DWORD)                  ...          ...
;                    Ancestor type ID (DWORD)                ...          ...
;   ——> ETT start:   # of following ??EVENT_ENTRY (QWORD)    ...          ...
;  |    Event        ??EVENT_ENTRY #1                        ...          ...
;  |    Translation  ??EVENT_ENTRY #2                        ...          ...
;  |    Table        ??EVENT_ENTRY #3                        ...          ...
;  |                 ...                                     ...          ...
;  |
;  |  Object structures:
;  |  ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
;  |  Object Template (TPL)
;  |    (+00h) POINTER to the Dual Method Table (DMT) —————————
;  |    (+08h) Variables and dynamic methods                   |
;  |          ...                                              |
;  |  Dual Method Table (DMT)                                  |  Offset
;  |    (-20h) Virtual method 3     (...)                      |    -
;  |    (-18h) Virtual method 2     (...)                      |    |
;  |    (-10h) Virtual method 1     (Done destructor)          |    |  Virtual Method Table (VMT)
;  '——— (-08h) POINTER to Event Translation Table (ETT)        |    |
; ENTRY (+00h) Interface method 1   (QueryInterface method) <——'    0 Dual Method Table (DMT)
;       (+08h) Interface method 2   (AddRef method)                 |
;       (+10h) Interface method 3   (Release method)                |  Interface Method Table (IMT)
;              ...                                                  |      (= Vtbl - Microsoft)
;                                                                   +
;
; Object Instance: (copy of Object Template = TPL)
; ¯¯¯¯¯¯¯¯¯¯¯¯¯¯¯
;     (+00h) POINTER to object Dual Method Table (-> DMT)
;     (+08h) Variables and dynamic methods (DYN)
;            ...


??EVENT_ENTRY struc 1
  dID       DWORD   ?                                   ;Event ID, like WM_COMMAND
  wFlags    WORD    ?                                   ;DISPATCH_METHOD, DISPATCH_PROPERTYGET, etc.
  wType     WORD    ?                                   ;??MTDTYPE_STATIC, ??MTDTYPE_VIRTUAL, etc.
  pHandler  POINTER ?                                   ;-> handler method, -> DMT, -> DYN
??EVENT_ENTRY ends
P??EventEntry typedef ptr ??EVENT_ENTRY

OBJECT_LOCK struc 1
  dOwnerTheadID DWORD   ?
  dLockCount    DWORD   ?
OBJECT_LOCK ends
POBJECT_LOCK typedef ptr OBJECT_LOCK

;Global object namespace
OBJASM_NAMESPACE        textequ <OA>                    ;Default namespace
??ObjPfxSep             textequ <_>                     ;Cosmetic separator
??ObjPfx                CatStr OBJASM_NAMESPACE, ??ObjPfxSep ;Object prefix to avoid name conflicts
??MtdPfx                textequ <_>                     ;Method prefix to avoid name conflicts
??ObjPfxOfs             = @SizeStr(%??ObjPfx) + 1
??MtdPfxOfs             = @SizeStr(%??MtdPfx) + 1

;Global definitions
??1stOMD                = NULL                          ;-> 1st structure in the obj. metadata chain
??ObjectCount           = 0
??StartupMtdCount       = 0
??ShutdownMtdCount      = 0
??ObjRedefIndex         = 2                             ;Modify method names when there is a duplication 

if TARGET_BITNESS eq 32
  ??ABSTRACT_ERROR_PROC equ <0FFFFFFFFh>                ;May be redefined to an error procedure
  ??OBSOLETE_ERROR_PROC equ <0DEADBEEFh>                ;May be redefined to an error procedure
else
  ??ABSTRACT_ERROR_PROC equ <0FFFFFFFFFFFFFFFFh>        ;May be redefined to an error procedure
  ??OBSOLETE_ERROR_PROC equ <0BADC0FFEE0DDF00Dh>        ;May be redefined to an error procedure
endif
??RegisterCasted        textequ <>

??OBJERR_UNDEFINED      equ -1
??OBJERR_NONE           equ 0                           ;Flags != ??OBJERR_NONE stops compilation
??OBJERR_SYNTAX         equ 1                           ;  of object related macros like
??OBJERR_UNK_ANCESTOR   equ 2                           ;  New, OCall, Override, etc.
??OBJERR_VAR_OVERRIDE   equ 3
??OBJERR_MTD_OVERRIDE   equ 4
??OBJERR_TYPE_ID        equ 5
??OBJERR_TEMPLATE       equ 6
??OBJERR_REDEFINITION   equ 7

??MTDTYPE_UNKNOWN       equ 0
??MTDTYPE_STATIC        equ 1
??MTDTYPE_VIRTUAL       equ 2
??MTDTYPE_INTERFACE     equ 3
??MTDTYPE_DYNAMIC       equ 4
??MTDTYPE_INLINE        equ 5

??MTDACCESS_UNKNOWN     equ 0
??MTDACCESS_PUBLIC      equ 1
??MTDACCESS_PRIVATE     equ 2


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ObjNamespace
; Purpose:    Set the current object namespace.
; Arguments:  Arg1: Space name.

ObjNamespace macro SpcName:req
  ??ObjPfx CatStr <SpcName>, ??ObjPfxSep
  ??ObjPfxOfs = @SizeStr(%??ObjPfx) + 1
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ObjInst
; Purpose:    Return the mangled object name instance.
; Arguments:  Arg1: Object Expression     [Namespace:]ObjectName.
; Example:    .data
;               MyObject $ObjInst(Primer)

$ObjInst macro Expression:req
  PreParseExpr Expression
  if $ParseObjExpr(Expression) eq FALSE
    @Err <$ObjInst Error: syntax error in Expression>
    exitm <>
  else
    exitm @CatStr(<??>, %??ObjExpr, <_Init {}>)        ;;Referenced structure
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ObjMthd
; Purpose:    Return the mangled object method name.
; Arguments:  Arg1: Object name.
; Example:    .data
;               MyObject $ObjMtd(pop)

$ObjMthd macro MtdName:req
  exitm @CatStr(%??MtdPfx, MtdName)
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $Obj
; Purpose:    Return the mangled object name.
; Arguments:  Arg1: Object Expression    [Namespace:]ObjectName.

$Obj macro ObjExpr:req
  PreParseExpr ObjExpr
  if $ParseObjExpr(ObjExpr) eq FALSE
    @Err <$Obj Error: syntax error in ObjExpr>
    exitm <>
  else
    %exitm <??ObjExpr>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ObjPtr
; Purpose:    Return the mangled object pointer name.
; Arguments:  Arg1: Object Expression: [Namespace:]ObjectName.

$ObjPtr macro ObjExpr:req
  PreParseExpr ObjExpr
  if $ParseObjExpr(ObjExpr) eq FALSE
    @Err <$ObjPtr Error: syntax error in ObjExpr>
    exitm <>
  else
    exitm @CatStr(<POB_>, %??ObjExpr)
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ObjTmpl
; Purpose:    Return the mangled object template name.
; Arguments:  Arg1: Object Expression: [Namespace:]ObjectName.

$ObjTmpl macro ObjExpr:req
  PreParseExpr ObjExpr
  if $ParseObjExpr(ObjExpr) eq FALSE
    @Err <$ObjTmpl Error: syntax error in ObjExpr>
    exitm <>
  else
    exitm @CatStr(<TPL_>, %??ObjExpr)
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ExterndefMethod
; Purpose:    Declares an external defined method.
; Arguments:  Arg1: Method Expression: ObjectName.MethodName.

ExterndefMethod macro MtdExpr:req
  PreParseExpr MtdExpr
  if $ParseMtdExpr(MtdExpr) eq FALSE
    @Err <ExterndefMethod Error: syntax error in MtdExpr>
  else
    externdef @CatStr(%??ObjExpr, %??MtdExpr, <:proc>)
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      BuildObjInherPath
; Purpose:    Helper macro to put in 1 symbol the whole interitance path starting from Primer to
;             the final object and viceversa.
; Arguments:  Arg1: Mangled object name.
;             Arg2: Mangled ancestor name.
; Return:     TRUE = OK, FALSE = failure.

BuildObjInherPath macro MglObjName:req, MglAncName:=<>
  ifnb <MglAncName>
    ifdef MglAncName
      @CatStr(MglObjName, <_InherFrwPath>) textequ \
        @CatStr(MglAncName, <,>, %@CatStr(MglObjName, <_InherFrwPath>))
      @CatStr(MglObjName, <_InherRevPath>) textequ \
        @CatStr(%@CatStr(MglObjName, <_InherRevPath>), <,>, MglAncName)
      $$Inher CatStr <MglAncName>, <_Inherit>
      %exitm <BuildObjInherPath(MglObjName, %$$Inher)>  ;;Use recursion
    else
      @Err <BuildObjInherPath Error: undefined ancestor MglAncName>
      exitm <FALSE>                                     ;;Error
    endif
  else
    exitm <TRUE>                                        ;;OK
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      Object
; Purpose:    Start object definition. Here starts the magic!
; Arguments:  Arg1: Object Expression: Namespace:ObjectName.
;             Arg2: Unique number to identificate the object type at run-time.
;             Arg3: Ancestor Expression: [Namespace:]AncestorName. (single inheritance).

Object macro ObjExpr:req, ObjTypeID:=<0>, AncExpr:=<>
  PreParseExpr ObjExpr
  if $ParseObjExpr(ObjExpr) eq FALSE
    %??ObjName&_Error = ??OBJERR_SYNTAX
    @Err <Object Error: invalid syntax in ObjExpr>
    exitm
  endif

  ??ObjName textequ ??ObjExpr                           ;;Global symbol used in all comming defs

  %ifdef ??ObjExpr
    %??ObjName&_Error = ??OBJERR_REDEFINITION
    ??ObjRedefIndex = ??ObjRedefIndex + 1
    @Err <Object Error: redefinition of ??ObjExpr>       ;;Alert about a second declaration
    exitm
  endif

  ifb <AncExpr>
    ??AncName textequ <>
  else
    PreParseExpr AncExpr
    if $ParseObjExpr(AncExpr) eq FALSE
      %??ObjName&_Error = ??OBJERR_SYNTAX
      @Err <Object Error: invalid syntax in AncExpr>
      exitm
    endif
    ??AncName textequ ??ObjExpr
  endif

  $$sz1 CatStr ??ObjName, <_Error>
  $$sz1 = ??OBJERR_NONE                                 ;;Reset error flag

  $$Count = 0
  repeat ??ObjectCount
    if @CatStr(<OBJECTID_>, %$$Count) eq ObjTypeID
      %??ObjName&_Error = ??OBJERR_TYPE_ID
      @Err <Object Error: type ID duplication ObjTypeID>    ;;Don't stop compilation here
      exitm
    endif
    $$Count = $$Count + 1
  endm
  if ObjTypeID ne 0
    @CatStr(<OBJECTID_>, %??ObjectCount) = ObjTypeID
    ??ObjectCount = ??ObjectCount + 1
  endif

  ??MethodAccess = ??MTDACCESS_PUBLIC                   ;;Set default method access

  ifb <AncExpr>                                         ;;Ancestor
    %&??ObjName&_Inherit equ <>
  else
    %&??ObjName&_Inherit textequ <??AncName>
  endif
  %&??ObjName&_TypeID      equ ObjTypeID                ;;Type ID
  %&??ObjName&_IfcMtdCount = 0                          ;;Count of new added interface methods
  %&??ObjName&_VtlMtdCount = 0                          ;;Count of new added virtual methods
  %&??ObjName&_DynMtdCount = 0                          ;;Count of new added dynamic methods
  %&??ObjName&_StcMtdCount = 0                          ;;Count of new added static methods
  %&??ObjName&_ExtMtdCount = 0                          ;;Count of new added external bound methods
  %&??ObjName&_IlnMtdCount = 0                          ;;Count of new added inline methods
  %&??ObjName&_VCount      = 0                          ;;Count of new added variables
  %&??ObjName&_OMCount     = 0                          ;;Count of methods to override
  %&??ObjName&_OVCount     = 0                          ;;Count of variables to override
  %&??ObjName&_EvCount     = 0                          ;;Count of new added Events

  @CatStr(%??ObjName, <_InherFrwPath>) CatStr ??ObjName ;;Start forward path
  @CatStr(%??ObjName, <_InherRevPath>) CatStr ??ObjName ;;Start forward path

  if $$sz1 eq ??OBJERR_NONE
    if BuildObjInherPath(%??ObjName, %??AncName) eq FALSE
      %$$sz1 = ??OBJERR_UNK_ANCESTOR                    ;;Error flag that prevents further compilation
    endif

    ;Build a Object-ID to Object-Name lookup table for debugging purposes
    if DEBUGGING
      if ObjTypeID ne 0
        S_OBJID segment
          DWORD    ObjTypeID
          POINTER  $OfsTStrA(@CatStr(<!">, %??ObjName, <!">))
        S_OBJID ends
        ??ObjIDTableCount = ??ObjIDTableCount + 1
      endif
    endif
  endif

  if CREATETYPEDEFS ne FALSE
    %POB_&??ObjName typedef ptr &??ObjName
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ObjectEnd
; Purpose:    Terminate the declaration of an object and defines the following structures:
;               ObjectName:           Uninitialized object Template.
;               ??ObjectName_VMT:     Uninitialized Virtual Method Table (VMT).
;               ??ObjectName_IMT:     Uninitialized Interface Method Table (IMT).
;               ??ObjectName_DMT:     Uninitialized VMT + IMT.
;               ??ObjectName_Events:  Initialized ??EVENT_ENTRY structures list.
;               TPL_ObjectName:       Initialized ObjectName template.
; Arguments:  None.

ObjectEnd macro
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    ;;Create unreferenced template structure.
    ??OMCount = CreateOMList(%??ObjName)
    ??RMCount = 0

    ??OVCount = CreateOVList(%??ObjName)
    ??RVCount = 0

    ??IMCount = CountInterfaceMethods(%??ObjName)

    %??&??ObjName&_VMT struc 1
      CreateVirtualMethodTable %??ObjName, <FALSE>      ;;Create uninitialized VMT.
    %??&??ObjName&_VMT ends

    %??ObjName struc 1                                  ;;Template: struc holding vars & dyn. meths.
      POINTER ?                                         ;;Placeholder (-> Dual Method Table)
      CreateDynamicTemplate %??ObjName, <FALSE>         ;;Create uninitialized dynamic struc (DYN).
    %??ObjName ends

    %if ??IMCount gt 0
      %??&??ObjName&_IMT struc 1
        CreateInterfaceMethodTable %??ObjName, <FALSE>  ;;Create uninitialized IMT.
      %??&??ObjName&_IMT ends

      %??&??ObjName&_DMT struc 1                        ;;Start uninitialized DMT.
        %??&??ObjName&_VMT    {}
        POINTER ?                                       ;;Placeholder (-> ETT)
        %??&??ObjName&_IMT    {}
      %??&??ObjName&_DMT ends
    else
      %??&??ObjName&_DMT struc 1                        ;;Start uninitialized DMT.
        %??&??ObjName&_VMT    {}
        POINTER ?                                       ;;Placeholder (-> ETT)
      %??&??ObjName&_DMT ends
    endif

    if MAKETEMPL ne FALSE                               ;;If MAKETEMPL is TRUE
      %??&??ObjName&_Events struc 1                     ;;Event structure definition.
        CreateEventList %??ObjName                      ;;Create Event list.
      %??&??ObjName&_Events ends

      %CreateTemplate ??ObjName                         ;;Create initialized object template.
      public @CatStr(<TPL_>, %??ObjName)
      public @CatStr(<TPL_>, %??ObjName, <_DMT>)
    else
      externdef @CatStr(<TPL_>, %??ObjName, <:>, %??ObjName)
      externdef @CatStr(<TPL_>, %??ObjName, <_DMT:??>, %??ObjName, <_DMT>)
    endif

    if SHOWINHERITANCE ne FALSE
      %echo Inheritance path: @CatStr(%??ObjName, <_InherFrwPath>)
    endif
  endif

  .code                                                 ;;Switch to code

  if IMPLEMENT ne FALSE and MAKETEMPL ne FALSE          ;;Now include external methods only
                                                        ;;  if we use MakeObjects!
    ??ExternFilePath SubStr @FileCur, 1, @SizeStr(%@FileCur) - 3

    $$Count = 0
    %repeat @CatStr(%??ObjName, <_ExtMtdCount>)
      $$ExtMtdName CatStr ??ObjName, <_ExtMethod_Name_>, %$$Count
      %include @CatStr(%??ExternFilePath, %$$ExtMtdName, <.inc>)
      $$Count = $$Count + 1
    endm

  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      Private
; Purpose:    Methods that follows this directive are defined with private scope.
; Arguments:  None.

Private macro
  ??MethodAccess = ??MTDACCESS_PRIVATE
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     PrivateEnd
; Purpose:   Methods that follows this directive are defined with public scope.
; Arguments: None.

PrivateEnd macro
  ??MethodAccess = ??MTDACCESS_PUBLIC
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      InterfaceAbstract
; Purpose:    Define a placeholder for an interface method that can be overridden.
;             Calling an abstract method without overriding it, causes an GPF-Error.
; Arguments:  Arg1: Method name.
;             Arg2: List of argument types.

InterfaceAbstract macro MtdName:req, Args:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    PrototypeMethod %??ObjName, MtdName, Args
    %$$Index = &??ObjName&_IfcMtdCount + 1
    %&??ObjName&_IfcMtdCount = $$Index
    @CatStr(%??ObjName, <_IfcMethodName_>, %$$Index) textequ <MtdName>
  
    ;;Set a mark. If you prefer, you can set it equal to an offset of an error handler procedure.
    %@CatStr(%??ObjName, <_IfcMethodProc_>, %$$Index) textequ <??ABSTRACT_ERROR_PROC>
    %&??ObjName&_&MtdName&_Access = ??MethodAccess
    @CatStr(%??ObjName, %??MtdPfx, MtdName, <_MtdType>) = ??MTDTYPE_INTERFACE
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      InterfaceMethod
; Purpose:    Define a method that is common to each instance of the object.
;             The implementation of the method must be placed in the code segment like:
;               Method <ObjectName>.<MethodName>, uses..., Argument1:...
;             pSelf is the instance POINTER passed to the method to access instance data.
; Arguments:  Arg1: Method name.
;             Arg2: List of argument types.

InterfaceMethod macro MtdName:req, Args:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    PrototypeMethod %??ObjName, MtdName, Args
    %$$Index = &??ObjName&_IfcMtdCount + 1
    %&??ObjName&_IfcMtdCount = $$Index
    @CatStr(%??ObjName, <_IfcMethodName_>, %$$Index) textequ @CatStr(%??MtdPfx, MtdName)
    @CatStr(%??ObjName, <_IfcMethodProc_>, %$$Index) textequ \
           @CatStr(<offset(>, %??ObjName, %??MtdPfx, MtdName, <)>)
    %&??ObjName&_&MtdName&_Access = ??MethodAccess
    @CatStr(%??ObjName, %??MtdPfx, MtdName, <_MtdType>) = ??MTDTYPE_INTERFACE
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      VirtualAbstract
; Purpose:    Define a placeholder for a virtual method that can be overridden.
;             Calling an abstract method without overriding it, causes a GPF-Error.
; Arguments:  Arg1: Method name.
;             Arg2: List of argument types.

VirtualAbstract macro MtdName:req, Args:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    PrototypeMethod %??ObjName, MtdName, Args
    %$$Index = &??ObjName&_VtlMtdCount + 1
    %&??ObjName&_VtlMtdCount = $$Index
    @CatStr(%??ObjName, <_VtlMethodName_>, %$$Index) textequ @CatStr(%??MtdPfx, MtdName)
  
    ;;Set a mark. If you prefer, you can set it to an error handler procedure address.
    %@CatStr(%??ObjName, <_VtlMethodProc_>, %$$Index) textequ <??ABSTRACT_ERROR_PROC>
    %&??ObjName&_&MtdName&_Access = ??MethodAccess
    @CatStr(%??ObjName, %??MtdPfx, MtdName, <_MtdType>) = ??MTDTYPE_VIRTUAL
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      VirtualMethod
; Purpose:    Define a method that is common to each instance of the object.
;             The implementation of the method must be placed in the code segment like:
;               Method <ObjectName>.<MethodName>, uses..., Argument1:...
;             pSelf is the instance POINTER passed to the method to access instance data.
; Arguments:  Arg1: Method name.
;             Arg2: List of argument types.

VirtualMethod macro MtdName:req, Args:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    PrototypeMethod %??ObjName, MtdName, Args
    %$$Index = &??ObjName&_VtlMtdCount + 1
    %&??ObjName&_VtlMtdCount = $$Index
    @CatStr(%??ObjName, <_VtlMethodName_>, %$$Index) textequ @CatStr(%??MtdPfx, MtdName)
    @CatStr(%??ObjName, <_VtlMethodProc_>, %$$Index) textequ \
           @CatStr(<offset(>, %??ObjName, %??MtdPfx, MtdName, <)>)
    %&??ObjName&_&MtdName&_Access = ??MethodAccess
    @CatStr(%??ObjName, %??MtdPfx, MtdName, <_MtdType>) = ??MTDTYPE_VIRTUAL
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DynamicAbstract
; Purpose:    Define a placeholder for a dynamic method that can be overridden.
;             Calling an abstract method without overriding it, causes an GPF-Error.
; Arguments:  Arg1: Method name.
;             Arg2: List of argument types.

DynamicAbstract macro MtdName:req, Args:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    PrototypeMethod %??ObjName, MtdName, Args
    %$$Index = &??ObjName&_DynMtdCount + 1
    %&??ObjName&_DynMtdCount = $$Index
    @CatStr(%??ObjName, <_DynMtdName_>, %$$Index) textequ @CatStr(%??MtdPfx, MtdName)
  
    ;;Set a marker. If you prefer, you can set it equal to an offset of an error handler procedure.
    %@CatStr(%??ObjName, <_DynMtdProc_>, %$$Index) textequ <??ABSTRACT_ERROR_PROC>
    %&??ObjName&_&MtdName&_Access = ??MethodAccess
    @CatStr(%??ObjName, %??MtdPfx, MtdName, <_MtdType>) = ??MTDTYPE_DYNAMIC
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DynamicMethod
; Purpose:    Define a method that is unique for each instance of the object.
;             The implementation of the method must be placed in the code Segment like:
;               Method <ObjectName>.<MethodName>, uses..., Argument1:...
;             pSelf is the instance POINTER passed to the method to access instance data.
; Arguments:  Arg1: Method name.
;             Arg2: List of argument types.

DynamicMethod macro MtdName:req, Args:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    PrototypeMethod %??ObjName, MtdName, Args
    %$$Index = &??ObjName&_DynMtdCount + 1
    %&??ObjName&_DynMtdCount = $$Index
    @CatStr(%??ObjName, <_DynMtdName_>, %$$Index) textequ @CatStr(%??MtdPfx, MtdName)
    @CatStr(%??ObjName, <_DynMtdProc_>, %$$Index) textequ \
           @CatStr(<offset(>, %??ObjName, %??MtdPfx, MtdName, <)>)
    %&??ObjName&_&MtdName&_Access = ??MethodAccess
    @CatStr(%??ObjName, %??MtdPfx, MtdName, <_MtdType>) = ??MTDTYPE_DYNAMIC
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      StaticMethod
; Purpose:    Define a method that is common to each instance of the object and it is called
;             directly, avoiding the indirection over the DMT. This implements early binding.
;             The implementation of the method must be placed in the code segment like:
;               Method <ObjectName>.<MethodName>, uses..., Argument1:...
;             pSelf is the instance POINTER passed to the method to access instance data.
; Arguments:  Arg1: Method name.
;             Arg2: List of argument types.

StaticMethod macro MtdName:req, Args:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    ;;Check if this StaticMethod already exists
    $$OName textequ <??ObjName>
    while TRUE
      %ifdef @CatStr(%$$OName, %??MtdPfx, MtdName)
        %??ObjName&_Error = ??OBJERR_MTD_OVERRIDE
        %@Err <@CatStr(<StaticMethod Error: >, ??ObjName, <.>, MtdName, < already defined in >, $$OName)>
        exitm
      else
        $$Ancestor textequ <@CatStr(%$$OName, <_Inherit>)>
        %ifb <$$Ancestor>
          exitm
        else
          $$OName textequ $$Ancestor
        endif
      endif
    endm
  
    PrototypeMethod %??ObjName, MtdName, Args
    %$$Index = &??ObjName&_StcMtdCount + 1
    %&??ObjName&_StcMtdCount = $$Index
    @CatStr(%??ObjName, <_StcMethod_Name_>, %$$Index) textequ @CatStr(%??MtdPfx, MtdName)
    %&??ObjName&_&MtdName&_Access = ??MethodAccess
    @CatStr(%??ObjName, %??MtdPfx, MtdName, <_MtdType>) = ??MTDTYPE_STATIC
  
    if MAKETEMPL ne FALSE
      ifidn <MtdName>, <Startup>
        %@CatStr(<StartupObjName_>, %??StartupMtdCount) textequ <??ObjName>
        ??StartupMtdCount = ??StartupMtdCount + 1
      elseifidn <MtdName>, <Shutdown>
        %@CatStr(<ShutdownObjName_>, %??ShutdownMtdCount) textequ <??ObjName>
        ??ShutdownMtdCount = ??ShutdownMtdCount + 1
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      InlineMethod
; Purpose:    Define a method that is common to each instance of the object.
;             The implementation of the method must be placed in the code segment like:
;               Method <ObjectName>.<MethodName>, uses..., Argument1:...
;             pSelf is the instance POINTER passed to the method to access instance data.
; Arguments:  Arg1: Method name.
;             Arg2: List of argument types.

InlineMethod macro MtdName:req, Args:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    ;;Check if this InlineMethod exists
    $$OName textequ <??ObjName>
    while TRUE
      %ifdef @CatStr(%$$OName, $$MtdPfx, MtdName)
        %@CatStr(??ObjName, <_Error>) = ??OBJERR_MTD_OVERRIDE
        %@Err <@CatStr(<InlineMethod Error: >, ??ObjName, <.>, MtdName, < already defined in >, $$OName)>
        exitm
      else
        $$Ancestor textequ <@CatStr(%$$OName, <_Inherit>)>
        %ifb <$$Ancestor>
          exitm
        else
          $$OName textequ $$Ancestor
        endif
      endif
    endm
  
    %$$Index = &??ObjName&_IlnMtdCount + 1
    %&??ObjName&_IlnMtdCount = $$Index
    @CatStr(%??ObjName, <_IlnMethodName_>, %$$Index) textequ @CatStr(%??MtdPfx, MtdName)
    %&??ObjName&_&MtdName&_Access = ??MethodAccess
    @CatStr(%??ObjName, %??MtdPfx, MtdName, <_MtdType>) = ??MTDTYPE_INLINE
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      RedefineMethod
; Purpose:    Redefine a method (static, virtual, dynamic or interface) at compile-time.
; Arguments:  Arg1: Method Name to be redefined.
;             Arg2: List of new argument types.

RedefineMethod macro MtdName:req, Args:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    GetMtdType %??ObjName, @CatStr(%??MtdPfx, MtdName)
    @CatStr(%??ObjName, %??MtdPfx, MtdName, <_MtdType>) = ??MtdType

    if ??MtdType eq ??MTDTYPE_INLINE
      %$$Index = &??ObjName&_IlnMtdCount + 1
      %&??ObjName&_IlnMtdCount = $$Index
      @CatStr(%??ObjName, <_IlnMethodName_>, %$$Index) textequ @CatStr(%??MtdPfx, MtdName)

    else
      %PrototypeMethod ??ObjName, MtdName, Args
      if ??MtdType eq ??MTDTYPE_STATIC
        %$$Index = &??ObjName&_StcMtdCount + 1
        %&??ObjName&_StcMtdCount = $$Index
        @CatStr(%??ObjName, <_StcMethod_Name_>, %$$Index) textequ @CatStr(%??MtdPfx, MtdName)
        if MAKETEMPL ne FALSE
          ifidn <MtdName>, <Startup>
            %@CatStr(<StartupObjName_>, %??StartupMtdCount) textequ <??ObjName>
            ??StartupMtdCount = ??StartupMtdCount + 1
          elseifidn <MtdName>, <Shutdown>
            %@CatStr(<ShutdownObjName_>, %??ShutdownMtdCount) textequ <??ObjName>
            ??ShutdownMtdCount = ??ShutdownMtdCount + 1
          endif
        endif

      else
        %$$Index = &??ObjName&_OMCount + 1
        %&??ObjName&_OMCount = $$Index
        @CatStr(%??ObjName, <_OvrMtdName_>, %$$Index) textequ @CatStr(%??MtdPfx, MtdName)
        @CatStr(%??ObjName, <_OvrMtdProc_>, %$$Index) textequ \
               @CatStr(<offset(>, %??ObjName, %??MtdPfx, MtdName, <)>)
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ObsoleteMethod
; Purpose:    Invalidate a method definition (virtual or dynamic) at compile-time.
; Arguments:  Arg1: Method name to be erased.

ObsoleteMethod macro MtdName:req
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    PrototypeMethod %??ObjName, MtdName, <>
    %$$Index = &??ObjName&_OMCount + 1
    %&??ObjName&_OMCount = $$Index
    @CatStr(%??ObjName, <_OvrMtdName_>, %$$Index) textequ <%??MtdPfx&MtdName>
    @CatStr(%??ObjName, <_OvrMtdProc_>, %$$Index) textequ <??OBSOLETE_ERROR_PROC>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DefineEvent
; Purpose:    Helper macro to define an event. Don't called directly.
; Arguments:  Arg1: Mangled method name.
;             Arg2: EventID list, like WM_CLOSE.

DefineEvent macro MglMtdName:req, EventIDs:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    ifb <EventIDs>
      @Err <DefineEvent Error: missing IDs in event definition>
    else
      %$$Index = &??ObjName&_EvCount + 1
      %&??ObjName&_EvCount = $$Index
      @CatStr(%??ObjName, <_EvProc_>,  %$$Index) textequ <MglMtdName>
      @CatStr(%??ObjName, <_EvIDs_>,   %$$Index) textequ <EventIDs>
      @CatStr(%??ObjName, <_EvFlags_>, %$$Index) textequ <0>
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      Event
; Purpose:    Define a method that responds to an event, like a Windows message.
; Arguments:  Arg1: Method name.
;             Arg2: EventID list, like WM_CLOSE.
; Note:       Inline Methods are not allowed.

Event macro MtdName:req, EventIDs:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    GetMtdType %??ObjName, @CatStr(%??MtdPfx, MtdName)
    if ??MtdType eq ??MTDTYPE_INLINE
      @Err <Event Error: inline methods are not allowed as event handlers>
      exitm
    endif
    DefineEvent @CatStr(%??MtdPfx, <MtdName>), EventIDs
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      IDispEvent
; Purpose:    Define a method that responds to the COM IDispatch.Invoke call.
; Arguments:  Arg1: Method name.
;             Arg2: DispID.
;             Arg3: Flags (DISPATCH_METHOD, DISPATCH_PROPERTYGET, DISPATCH_PROPERTYPUT,
;                          DISPATCH_PROPERTYPUTREF).

IDispEvent macro MtdName:req, DispID:req, Flags:=<DISPATCH_METHOD>
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    %$$Index = &??ObjName&_EvCount + 1
    %&??ObjName&_EvCount = $$Index
    @CatStr(%??ObjName, <_EvProc_>,  %$$Index) textequ @CatStr(%??MtdPfx, MtdName)
    @CatStr(%??ObjName, <_EvIDs_>,   %$$Index) textequ <DispID>
    @CatStr(%??ObjName, <_EvFlags_>, %$$Index) textequ <Flags>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      StaticEvent
; Purpose:    This is a shortcut for StaticMethod and Event macros.
; Arguments:  Arg1: Method name.
;             Arg2: EventID list, like WM_CLOSE.

StaticEvent macro MtdName:req, Events:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    StaticMethod MtdName, WPARAM, LPARAM
    DefineEvent @CatStr(%??MtdPfx, <MtdName>), Events
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      VirtualEvent
; Purpose:    This is a shortcut for VirtualMethod and Event macros.
; Arguments:  Arg1: Method name.
;             Arg2: EventID list, like WM_CLOSE.

VirtualEvent macro MtdName:req, Events:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    VirtualMethod MtdName, WPARAM, LPARAM
    DefineEvent @CatStr(%??MtdPfx, <MtdName>), Events
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      InterfaceEvent
; Purpose:    This is a shortcut for InterfaceMethod and Event macros.
; Arguments:  Arg1: Method name.
;             Arg2: EventID list, like WM_CLOSE.

InterfaceEvent macro MtdName:req, Events:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    InterfaceMethod MtdName, WPARAM, LPARAM
    DefineEvent @CatStr(%??MtdPfx, <MtdName>), Events
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DynamicEvent
; Purpose:    This is a shortcut for DynamicMethod and Event macros.
; Arguments:  Arg1: Method name.
;             Arg2: EventID list, like WM_CLOSE.

DynamicEvent macro MtdName:req, Events:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    DynamicMethod MtdName, WPARAM, LPARAM
    DefineEvent @CatStr(%??MtdPfx, <MtdName>), Events
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DefineVariable
; Purpose:    Define a variable (Unique to each instance of the object).
; Arguments:  Arg1: Variable name.
;             Arg2: Variable type.
;             Arg3/4: Optional initial value/structure initial value(s).

DefineVariable macro VarName:req, VarType:=<DWORD>, VarInit:=<?>, VarInitMore:vararg
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    %$$Index = &??ObjName&_VCount + 1
    %&??ObjName&_VCount = $$Index
    @CatStr(%??ObjName, <_VarName_>, %$$Index) textequ <VarName>
    @CatStr(%??ObjName, <_VarType_>, %$$Index) textequ <VarType>
  
    ??VarInitValue textequ <VarInit>
    for ??VarPart:= <?>, <VarInitMore>
      ??VarInitValue CatStr ??VarInitValue, <, >, <??VarPart>
    endm
  
    %@CatStr(%??ObjName, <_VarInit_>, %$$Index) textequ <??VarInitValue>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      RedefineVariable
; Purpose:    Redefine a variables initial value.
; Arguments:  Arg1: Variable name.
;             Arg2: New initial value.

RedefineVariable macro VarName:req, VarInit:=<?>
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    %$$Index = &??ObjName&_OVCount + 1
    %&??ObjName&_OVCount = $$Index
    @CatStr(%??ObjName, <_OvrVarName_>, %$$Index) textequ <VarName>
    @CatStr(%??ObjName, <_OvrVarInit_>, %$$Index) textequ <VarInit>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      LoadObjects
; Purpose:    Load all object structures from a precompiled file (ObjectName.lib).
; Arguments:  Arg1: File name list (without extention) that contain the object data to load.

LoadObjects macro FileNameList:vararg
  IMPLEMENT = FALSE
  for $$FileName:req, <FileNameList>
    if @InStr(1, $$FileName, <\>) eq 0
      $$IncObjPath textequ <&ObjPath&>
      if TARGET_STR_TYPE eq STR_TYPE_ANSI
        $$LibObjPath catstr <&ObjPath&>, <Lib\>, %TARGET_BITNESS, <A\>
      else
        $$LibObjPath catstr <&ObjPath&>, <Lib\>, %TARGET_BITNESS, <W\>
      endif
    else
      $$IncObjPath textequ <>
      $$LibObjPath textequ <>
    endif
    if TARGET_BIN_FORMAT eq BIN_FORMAT_LIB
      MAKETEMPL = FALSE
    else
      %includelib &$$LibObjPath&&$$FileName&.lib
    endif
    %include &$$IncObjPath&&$$FileName&.inc
  endm
  IMPLEMENT = TRUE                                      ;;Restore defaults
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      MakeObjects
; Purpose:    Load all object data from a file.
; Arguments:  Arg1: File name list (without extention) that contain the object data to compile.

MakeObjects macro FileNameList:vararg
  for $$FileName:req, <FileNameList>
    IMPLEMENT = TRUE                                    ;;In case it was reseted
    if @InStr(1, $$FileName, <\>) eq 0
      $$IncObjPath textequ <&ObjPath&>
    else
      $$IncObjPath textequ <>
    endif
    %include &$$IncObjPath&&$$FileName&.inc
  endm
  IMPLEMENT = TRUE                                      ;;In case it was reseted
endm
;
; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      VirtualObjects
; Purpose:    Create the object data structures to reference an external object instance.
; Arguments:  Arg1: File name list (without extention) that contain the object data definitions.

VirtualObjects macro FileNameList:req
  for $$FileName:req, <FileNameList>
    $$FName textequ <$$FileName>
    IMPLEMENT = FALSE
    MAKETEMPL = FALSE
    if @InStr(1, $$FileName, <\>) eq 0
      $$FName CatStr <&ObjPath&>, <$$FileName>
    endif
    %include $$FName.inc
  endm
  IMPLEMENT = TRUE                                      ;;Set defaults
  MAKETEMPL = TRUE
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      PrototypeMethod
; Purpose:    Helper macro to perform the necessary method definitions for the compiler.
; Arguments:  Arg1: Mangled object name
;             Arg2: Method name.
;             Arg3: List of argument types.

PrototypeMethod macro MglObjName:req, MtdName:req, Args:vararg
  $$sz1 textequ <:ptr &MglObjName&>                     ;;First argument is always pSelf
  $$ArgCount = 0
  $$Flag = TRUE
  ifnb <Args>
    for $$Arg:req, <&Args>
      if $$Flag ne FALSE                                ;;Ignore the rest if $$Flag = FALSE
        ifidn <$$Arg>, <?>                              ;;Unknown number of arguments
          $$ArgCount = -1 - $$ArgCount                  ;;Set a negative value!
          $$Flag = FALSE
          $$sz1 CatStr $$sz1, <,:VARARG>
        else
          $$ArgCount = $$ArgCount + 1                   ;;Pointer size
          $$sz1 CatStr $$sz1, <,:>, <&$$Arg>
        endif
      endif
    endm
  endif

  if TARGET_BITNESS eq 32
    if $$Flag eq FALSE                                  ;;In 32 bit, vararg requires c calling conv.
      %@CatStr(MglObjName, %??MtdPfx, MtdName) proto c, $$sz1
      %@CatStr(<TYPE_>, MglObjName, %??MtdPfx, MtdName) typedef proto c, $$sz1
    else
      %@CatStr(MglObjName, %??MtdPfx, MtdName) proto stdcall, $$sz1
      %@CatStr(<TYPE_>, MglObjName, %??MtdPfx, MtdName) typedef proto stdcall, $$sz1
    endif
  else
    %@CatStr(MglObjName, %??MtdPfx, MtdName) proto fastcall, $$sz1
    %@CatStr(<TYPE_>, MglObjName, %??MtdPfx, MtdName) typedef proto fastcall, $$sz1
  endif
  @CatStr(MglObjName, %??MtdPfx, MtdName, <_ArgCnt>) = $$ArgCount
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      CountInterfaceMethods
; Purpose:    Helper macro that counts all interface methods belonging to an object.
; Arguments:  Arg1: Mangled object name.
; Return:     Count of Interface methods.

CountInterfaceMethods macro MglObjName:req
  $$Sum = 0
  %for $$TestObject, <&MglObjName&_InherFrwPath>
    $$Sum = $$Sum + @CatStr($$TestObject, <_IfcMtdCount>)
  endm
  %exitm <$$Sum>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      CreateOMList
; Purpose:    Helper macro to create a list of methods to override.
; Arguments:  Arg1: Mangled object name.
; Return:     Count of methods to override.

CreateOMList macro MglObjName:req
  $$Sum = 0
  %for $$TestObject, <&MglObjName&_InherFrwPath>
    $$Count = 0
    repeat @CatStr($$TestObject, <_OMCount>)
      $$Sum = $$Sum + 1
      $$Count = $$Count + 1
      @CatStr(<OvrMtd_Name_>, %$$Sum) CatStr <$$TestObject>, <_OvrMtdName_>, %$$Count
      @CatStr(<OvrMtd_Proc_>, %$$Sum) CatStr <$$TestObject>, <_OvrMtdProc_>, %$$Count
    endm
  endm
  %exitm <$$Sum>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      CreateOVList
; Purpose:    Helper macro to create a list of variables to override.
; Arguments:  Arg1: Mangled object name.
; Return:     Count of variables to override.

CreateOVList macro MglObjName:req
  $$Sum = 0
  %for $$TestObject, <&MglObjName&_InherFrwPath>
    $$Count = 0
    repeat @CatStr($$TestObject, <_OVCount>)
      $$Sum = $$Sum + 1
      $$Count = $$Count + 1
      @CatStr(<OvrVarName_>, %$$Sum) CatStr <$$TestObject>, <_OvrVarName_>, %$$Count
      @CatStr(<OvrVarInit_>, %$$Sum) CatStr <$$TestObject>, <_OvrVarInit_>, %$$Count
    endm
  endm
  %exitm <$$Sum>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      CreateInterfaceMethodTable
; Purpose:    Helper macro to create the structure of the interface method table of an object.
; Arguments:  Arg1: Mangled object name.
;             Arg2: with (TRUE) or without (FALSE) member initialization.

CreateInterfaceMethodTable macro MglObjName:req, Init:=<TRUE>
  %for $$TestObject, <@CatStr(MglObjName, <_InherFrwPath>)>  ;;Use forward list
    $$ACount = 0
    repeat @CatStr($$TestObject, <_IfcMtdCount>)
      $$ACount = $$ACount + 1
      $$sz1 CatStr <$$TestObject>, <_IfcMethodName_>, %$$ACount
      $$sz3 CatStr <$$TestObject>, <_IfcMethodProc_>, %$$ACount
      $$TCount = 0
      repeat ??OMCount
        $$TCount = $$TCount + 1
        $$sz4 CatStr <OvrMtd_Name_>, %$$TCount
        ifidn $$sz1, $$sz4
          $$sz3 CatStr <OvrMtd_Proc_>, %$$TCount
          ifidn <$$sz3>, <ObsoleteErrorProc>            ;;Erase it but don't remove the placeholder!
            $$sz1 textequ <>                            ;;Erase the name of the IMT
          endif
          ??RMCount = ??RMCount + 1
        endif
      endm
      ifidn <Init>, <TRUE>
        $$sz1 POINTER $$sz3                             ;;Remove method prefix
      else
        $$sz1 POINTER ?                                 ;;Remove method prefix
      endif
    endm
  endm
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      CreateVirtualMethodTable
; Purpose:    Helper macro to create the structure of the virtual method table of an object.
; Arguments:  Arg1: Mangled object name.
;             Arg2: with (TRUE) or without (FALSE) references.
; Note:       This VMT is in reverse order to make place for the IMT!

CreateVirtualMethodTable macro MglObjName:req, Init:=<TRUE>
  %for $$TestObject, <@CatStr(MglObjName, <_InherRevPath>)>;;Use reverse list
    $$ACount = @CatStr($$TestObject, <_VtlMtdCount>)
    repeat @CatStr($$TestObject, <_VtlMtdCount>)
      $$sz1 CatStr <$$TestObject>, <_VtlMethodName_>, %$$ACount
      $$sz3 CatStr <$$TestObject>, <_VtlMethodProc_>, %$$ACount
      $$TCount = 0
      repeat ??OMCount
        $$TCount = $$TCount + 1
        $$sz4 CatStr <OvrMtd_Name_>, %$$TCount
        ifidn $$sz1, $$sz4
          $$sz3 CatStr <OvrMtd_Proc_>, %$$TCount
          ifidn <$$sz3>, <ObsoleteErrorProc>            ;;Erase it but don't remove the placeholder!
            $$sz1 textequ <>                            ;;Erase the name of the VMT
          endif
          ??RMCount = ??RMCount + 1
        endif
      endm
      ifidn <Init>, <TRUE>
        $$sz1 POINTER $$sz3
      else
        $$sz1 POINTER ?
      endif
      $$ACount = $$ACount - 1
    endm
  endm
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      CreateTemplate
; Purpose:    Helper macro that defines the following structures:
;               ??ObjectName_Init:     Initialized template.
;               ??ObjectName_DMT_Init: Initialized VMT + IMT.
;             Additionally it creates the object data list in the .data segment.
; Arguments:  Arg1: Mangled Object name.

CreateTemplate macro MglObjName:req
  ??OMCount = CreateOMList(MglObjName)
  ??RMCount = 0                                         ;;Initialize to zero

  ??OVCount = CreateOVList(MglObjName)
  ??RVCount = 0                                         ;;Initialize to zero

  ??IMCount = CountInterfaceMethods(MglObjName)

  %??&MglObjName&_Init struc 1                          ;;Structure holding vars & dynamic methods
    %POINTER offset(@CatStr(<TPL_>, MglObjName, <_DMT>)) + \ ;;-> Dual Method Table
             sizeof(??&MglObjName&_VMT) + sizeof(POINTER)
    CreateDynamicTemplate MglObjName, <TRUE>            ;;Create initialized dynamic (DYN) struc
  %??&MglObjName&_Init ends

  %??&MglObjName&_DMT_Init struc 1
    CreateVirtualMethodTable MglObjName, <TRUE>         ;;Create VMT initialized structure
    %POINTER offset(@CatStr(<TPL_>, MglObjName, <_DMT>)) + \ ;;-> end of structure
             sizeof(??&MglObjName&_DMT) + 2*sizeof(DWORD)   ;;2 IDs
    %if ??IMCount gt 0
      CreateInterfaceMethodTable MglObjName, <TRUE>     ;;Create initialized IMT structure
    endif
  %??&MglObjName&_DMT_Init ends

  ifdif %??OMCount, %??RMCount                          ;;Check if all was overridden
    %echo @CatStr(MglObjName, < has a method definition problem>)
    %echo @CatStr(<Number of overwritten methods: >, %??OMCount)
    %echo @CatStr(<Number of redefined methods:   >, %??RMCount)
    %@CatStr(MglObjName, <_Error>) = ??OBJERR_MTD_OVERRIDE
    @Err <CreateTemplate Error: one or more methods were not overridden, check method defintitions>
    .code
    exitm
  endif
  ifdif %??OVCount, %??RVCount                          ;;Check if all was overridden
    %echo @CatStr(MglObjName, < has a variable definition problem>)
    %echo @CatStr(<Number of overwritten variables: >, %??OVCount)
    %echo @CatStr(<Number of redefined variables:   >, %??RVCount)
    %@CatStr(MglObjName, <_Error>) = ??OBJERR_VAR_OVERRIDE
    @Err <CreateTemplate Error: one or more variables were not overridden, check Object variable defintitions>
    .code
    exitm
  endif

  .data
  align ALIGN_DATA
  ;;Stores a POINTER to the next object metadata
  POINTER ??1stOMD
  ??1stOMD = $ - sizeof(POINTER)                        ;;Store this address in the ??1stOMD symbol

  ;;Store sizeof(object TPL)
  %XWORD sizeof(MglObjName)

  ;;Creates the template for the object methods and variables
  @CatStr(<TPL_>, MglObjName, < ??>, MglObjName, <_Init>) {}

  align ALIGN_DATA
  ;;Creates the Dual Method Table
  @CatStr(<TPL_>, MglObjName, <_DMT ??>, MglObjName, <_DMT_Init>) {}

  ;;Stores IDs
  DWORD @CatStr(MglObjName, <_TypeID>)                  ;;Store object type ID
  $$sz1 CatStr <MglObjName>, <_Inherit>
  %ifb <$$sz1>                                          ;;Check if ancestor exists
    DWORD 0                                             ;;NO => store 0
  else
    DWORD @CatStr(%$$sz1, <_TypeID>)                    ;;YES => store ancestor type ID
  endif

  ;;Set the number of events handled by the object
  %QWORD sizeof(??&MglObjName&_Events) / sizeof(??EVENT_ENTRY)

  ;;Create the events list (unnamed)
  %if sizeof(??&MglObjName&_Events) gt 0
    @CatStr(<??>, MglObjName, <_Events>) {}
  endif

  ;;Checks if the logical structure has the same size as the template structure
  if sizeof(@CatStr(MglObjName)) ne sizeof(@CatStr(<TPL_>, MglObjName))
    @Err <CreateTemplate Error: object structure error in MglObjName>
    ??&MglObjName&_Error = ??OBJERR_TEMPLATE
  endif

  .code
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      CreateDynamicTemplate
; Purpose:    Helper macro to create the dynamic section of the object template.
; Arguments:  Arg1: Mangled object name.
;             Arg2: with (TRUE) or without (FALSE) references.

CreateDynamicTemplate macro MglObjName:req, Init:=<TRUE>
  %for $$TestObject, <@CatStr(MglObjName, <_InherFrwPath>)>
    ;;--- Dynamic Methods ------------------------------------------------------------------
    $$ACount = 0
    repeat @CatStr($$TestObject, <_DynMtdCount>)
      $$ACount = $$ACount + 1
      $$sz1 CatStr <$$TestObject>, <_DynMtdName_>, %$$ACount
      $$sz3 CatStr <$$TestObject>, <_DynMtdProc_>, %$$ACount
      $$TCount = 0
      repeat ??OMCount
        $$TCount = $$TCount + 1
        %ifidn <$$sz1>, <@CatStr(<OvrMtd_Name_>, %$$TCount)>
          $$sz3 CatStr <OvrMtd_Proc_>, %$$TCount
          ifidn <$$sz3>, <??OBSOLETE_ERROR_PROC>        ;;Erase it but don't remove the placeholder!
            $$sz1 textequ <>                            ;;Erase the name of the template
          endif
          ??RMCount = ??RMCount + 1
        endif
      endm
      ifidn <Init>, <TRUE>
        $$sz1 POINTER $$sz3
      else
        $$sz1 POINTER ?
      endif
    endm

    ;;--- Vars -----------------------------------------------------------------------------
    $$ACount = 0
    repeat @CatStr($$TestObject, <_VCount>)
      $$ACount = $$ACount + 1
      $$sz1 CatStr <$$TestObject>, <_VarName_>, %$$ACount
      $$sz2 CatStr <$$TestObject>, <_VarType_>, %$$ACount
      $$sz3 CatStr <$$TestObject>, <_VarInit_>, %$$ACount
      $$TCount = 0
      repeat ??OVCount
        $$TCount = $$TCount + 1
          %ifidn <$$sz1>, <@CatStr(<OvrVarName_>, %$$TCount)>
          $$sz3 CatStr <OvrVarInit_>, %$$TCount
          ??RVCount = ??RVCount + 1
        endif
      endm

      ifidn <Init>, <TRUE>
        $$sz1 $$sz2 $$sz3
      else
        if @InStr(1, %$$sz3, <{>) eq 1
%         $$sz1 $$sz2 {}
        else
          $$sz4 textequ <$Lower($$sz3)>                 ;;Convert to lowercase
          ??Pos1 = @InStr(1, %$$sz4, < dup>)
          if ??Pos1 gt 0
            if @InStr(1, %$$sz4, <{>) gt 0
              $$sz1 $$sz2 @CatStr(@SubStr(%$$sz3, 1, ??Pos1), < dup({})>)
            else
              $$sz1 $$sz2 @CatStr(@SubStr(%$$sz3, 1, ??Pos1), < dup(?)>)
            endif
          else
            $$sz1 $$sz2 ?
          endif
        endif
      endif
    endm
  endm
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      CreateEventList
; Purpose:    Helper macro to create the event list of an object.
; Arguments:  Arg1: Mangled object name.

CreateEventList macro MglObjName:req
  %for $$TestObject, <@CatStr(MglObjName, <_InherFrwPath>)>
    $$Index = 0
    repeat @CatStr($$TestObject, <_EvCount>)
      $$Index = $$Index + 1
      $$sz1 CatStr <$$TestObject>, <_EvProc_>, %$$Index
      if $IsObsoleteMethod(MglObjName, $$sz1)
      else
        %for ??EventID:req, <@CatStr($$TestObject, <_EvIDs_>, %$$Index)>
          ;;Message & relative method offset
          GetMtdType MglObjName, %$$sz1
          DWORD ??EventID
          WORD  @CatStr($$TestObject, <_EvFlags_>, %$$Index)
          WORD  ??MtdType
          if ??MtdType eq ??MTDTYPE_STATIC
            POINTER offset(@CatStr(MglObjName, %$$sz1)) ;;Method address
          elseif ??MtdType eq ??MTDTYPE_VIRTUAL
            POINTER offset(@CatStr(<TPL_>, MglObjName, <_DMT.>, %$$sz1)) ;;Address into the DMT
          elseif ??MtdType eq ??MTDTYPE_INTERFACE
            POINTER offset(@CatStr(<TPL_>, MglObjName, <_DMT.>, %$$sz1))
          elseif ??MtdType eq ??MTDTYPE_DYNAMIC
            POINTER offset(@CatStr(<TPL_>, MglObjName, <.>, %$$sz1)) - \
                    offset(@CatStr(<TPL_>, MglObjName))
          else
            %@Err <CreateEventList Error: unknown method $$sz1>
          endif
        endm
      endif
    endm
  endm
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      GetMtdType
; Purpose:    Return method type.
; Arguments:  Arg1: Mangled object name.
;             Arg2: Mangled method name.
; Retrun:     ??MtdType: ??MTDTYPE_UNKNOWN, ..., ??MTDTYPE_DYNAMIC
;             ??ImpObj: Mangled object name that implements the method.

GetMtdType macro MglObjName:req, MglMtdName:req
  ??ImpObj textequ <>
  ??MtdType = ??MTDTYPE_UNKNOWN
  ifdef MglObjName&_InherFrwPath
    %for $$TestObject, <&MglObjName&_InherRevPath>
      $$sz2 CatStr <$$TestObject>, <MglMtdName>, <_MtdType>
      %ifdef $$sz2
        ??MtdType = $$sz2
        ??ImpObj textequ <$$TestObject>
        exitm                                           ;;Exit the for loop
      endif
    endm
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $IsObsoleteMethod
; Purpose:    Check if a method of an object is obsolete or not.
; Arguments:  Arg1: Mangled object name.
;             Arg2: Mangled method name.
; Retrun:     FALSE: is NOT an obsolete method, TRUE: it is an obsolete method.

$IsObsoleteMethod macro MglObjName:req, MglMtdName:req
  $$Found = FALSE
  ifdef &MglObjName&_InherFrwPath
    %for $$TestObject, <&MglObjName&_InherRevPath>
      if $$Found eq FALSE
        $$ACount = 0
        repeat @CatStr($$TestObject, <_OMCount>)
          $$ACount = $$ACount + 1
          %ifidn <MglMtdName>, <@CatStr($$TestObject, <_OvrMtdName_>, %$$ACount)>
            %ifidn <@CatStr($$TestObject, <_OvrMtdProc_>, %$$ACount)>, <??OBSOLETE_ERROR_PROC>
              $$Found = TRUE
              exitm                                     ;;Exit the for loop
            endif
          endif
        endm
      else
        exitm                                           ;;Exit the for loop
      endif
    endm
  endif
  %exitm <$$Found>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $IsPrivateMethod
; Purpose:    Scan recursively in the inheritance path of a specified method to find out
;             if it is a private method.
; Arguments:  Arg1: Mangled object name.
;             Arg2: Mangled method name.
; Retrun:     TRUE: it is a virtual method, FALSE: is NOT a virtual method.

$IsPrivateMethod macro MglObjName:req, MglMtdName:req
  $$Found = FALSE
  ifdef &MglObjName&_InherFrwPath
    %for $$TestObject, <&MglObjName&_InherRevPath>
      if $$Found eq FALSE
        $$sz CatStr <$$TestObject>, <MglMtdName>, <_Access>
        %ifdef $$sz
          %if $$sz eq ??MTDACCESS_PRIVATE
            $$Found = TRUE
            exitm                                       ;;Exit the for loop
          endif
        endif
      else
        exitm                                           ;;Exit the for loop
      endif
    endm
  endif
  %exitm <$$Found>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $MethodAddr
; Purpose:    Return a method address.
; Arguments:  Arg1: Expression of the form: "InsName::NameSpace:ObjName.MtdName"
; Notes:      - this macro uses the eax/rax register, except for static methods.
;             - if the expression contains an instance POINTER, then the returned address is
;               relative to this particular instance, otherwise to the object template.
;             - can be used inside nested into OCall/ACall/etc. macros.
;             - Possible syntax combinations:
;               - Ins::Nsp:Obj.Mtd
;               - Ins::Obj.Mtd
;               - Nsp:Obj.Mtd
;               - Obj.Mtd
;               - Mtd

$MethodAddr macro Expression:req
  PreParseExpr Expression
  if $ParseMtdExpr(Expression) eq FALSE
    @Err <$MethodAddr Error: invalid syntax in Expression>
    exitm <NULL>
  else
    %ifdef ??ObjExpr
      %GetMtdType ??ObjExpr, ??MtdExpr                  ;;Updates ??MtdType & ??ImpObj
      if ??MtdType eq ??MTDTYPE_STATIC
        exitm @CatStr(<offset(>, %??ImpObj, %??MtdExpr, <)>)

      elseif ??MtdType eq ??MTDTYPE_VIRTUAL
        %ifb <??InsExpr>
          mov xax, @CatStr(<offset(TPL_>, %??ImpObj, <)>)
          mov xax, POINTER ptr [xax]
        else
          if (opattr ??InsExpr) and OAT_REGISTER        ;;Is ??InsExpr a register?
            mov xax, POINTER ptr [??InsExpr]            ;;Get address of VMT
          else
            if type(??InsExpr) eq @WordSize
              mov xax, ??InsExpr                          ;;??InsExpr is not a register => load it
            else
              $$Attributes = opattr(??InsExpr)
              if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE)) or \
                 ($$Attributes eq (OAT_SS_RELATIVE or OAT_NO_ERROR or OAT_RELOCATABLE))
                lea xax, ??InsExpr
              else
                mov xax, ??InsExpr
              endif
            endif
            mov xax, POINTER ptr [xax]                  ;;Get address of VMT
          endif
        endif
        %exitm <@CatStr(<(??>, %??ObjExpr, <_VMT ptr [xax - ??>, %??ObjExpr, \
                        <_VMT - sizeof(POINTER)]).>, %??MtdExpr)>

      elseif ??MtdType eq ??MTDTYPE_INTERFACE
        %ifb <??InsExpr>
          mov xax, @CatStr(<offset(TPL_>, %??ImpObj, <_DMT) + sizeof(??>, %??ImpObj, <_VMT)>)) + \
                   sizeof(POINTER)                      ;;xax -> IMT of the implementing object
        else
          if (opattr ??InsExpr) and OAT_REGISTER        ;;Is ??InsExpr a register?
            mov xax, POINTER ptr [??InsExpr]            ;;Get address of IMT
          else
            $$Attributes = opattr(??InsExpr)
            if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE)) or \
               ($$Attributes eq (OAT_SS_RELATIVE or OAT_NO_ERROR or OAT_RELOCATABLE))
              lea xax, ??InsExpr
            else
              mov xax, ??InsExpr
            endif
            mov xax, POINTER ptr [xax]                  ;;Get address of IMT from this instance
          endif
        endif
        exitm @CatStr(<(??>, %??ObjExpr, <_IMT ptr [xax]).>, %??MtdExpr) ;;Ret mtd addr in IMT

      elseif ??MtdType eq ??MTDTYPE_DYNAMIC
        %ifb <??InsExpr>
          mov xax, @CatStr(<offset(TPL_>, %??ImpObj, <.>, %??MtdExpr, <)>) ;;Get member addr in DYN.
          exitm <POINTER ptr [xax]>                     ;;Return method address
        else
          if (opattr ??InsExpr) and OAT_REGISTER        ;;Is ??InsExpr a register?
            %exitm <(??ObjExpr ptr [??InsExpr]).??MtdExpr>;;Return method address in instance data
          else
            $$Attributes = opattr(??InsExpr)
            if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE)) or \
               ($$Attributes eq (OAT_SS_RELATIVE or OAT_NO_ERROR or OAT_RELOCATABLE))
              lea xax, ??InsExpr
            else
              mov xax, ??InsExpr
            endif
            %exitm <(??ObjExpr ptr [xax]).??MtdExpr>    ;;Return method address in instance data
          endif
        endif

      elseif ??MtdType eq ??MTDTYPE_INLINE
        @Err <$MethodAddr Error: inline method has no address Expression>
        exitm <NULL>
      else
        @Err <$MethodAddr Error: undefined method Expression>
        exitm <NULL>
      endif
    else
      @Err <$MethodAddr Error: undefined object Expression>
      exitm <NULL>
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      New / $New
; Purpose:    Create a new instance of an object copying the object template.
;             It is also suitable for object instances located on the stack using the LOCAL keyword.
; Arguments:  Arg1: Expression of the form "Instance::Namespace:Object"
;                   "Instance" is an optional expression used for preallocated instances like when
;                   stack is used to hold the object.
;                   "Object" is a required expression, that identifies the object type to
;                   instantiate.
; Return:     rax -> created object instance.
;             Possible syntax combinations:
;               - Preallocated memory
;                 - Ins::Nsp:Obj
;                 - Ins::Obj
;               - With memory allocation
;                 - Nsp:Obj
;                 - Obj

New macro Expression:req, MemSize:=<$$DynamicTemplateSize>
  PreParseExpr Expression

  ;;Get ??MtdExpr
  if ??Pos3 ne 0
    @Err <New Error: method Expression not allowed>
    exitm
  endif

  ;;Get ??ObjExpr
  if ??Pos1 ne 0
    if ??Pos2 ne 0
      ??ObjExpr CatStr @SubStr(<Expression>, ??Pos1 + 2, ??Pos2 - ??Pos1 - 2), \
                       ??ObjPfxSep, \
                       @SubStr(<Expression>, ??Pos2 + 1)
    else
      ??ObjExpr CatStr ??ObjPfx, @SubStr(<Expression>, ??Pos1 + 2)
    endif
  else
    if ??Pos2 ne 0
      ??ObjExpr CatStr @SubStr(<Expression>, 1, ??Pos2 - 1), \
                       ??ObjPfxSep, \
                       @SubStr(<Expression>, ??Pos2 + 1)
    else
      ??ObjExpr CatStr ??ObjPfx, <Expression>
    endif
  endif

  ;;Get ??InsExpr
  if ??Pos1 ne 0
    ??InsExpr SubStr <Expression>, 1, ??Pos1 - 1
  endif

  %ifdef ??ObjExpr
    if @CatStr(%??ObjExpr, <_Error>) eq ??OBJERR_NONE
      $$DynamicTemplateSize = sizeof(??ObjExpr)
      %ifb <??InsExpr>
        if TARGET_BITNESS eq 64
          sub rsp, 20h
        endif
        MemAlloc MemSize
        if TARGET_BITNESS eq 64
          add rsp, 20h
        endif
      else
        %if type(??InsExpr) eq @WordSize
          %ifdifi <??InsExpr>, <xax>
            %mov xax, ??InsExpr
          endif
        else
          %$$Attributes = opattr(??InsExpr)
          if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE)) or \
             ($$Attributes eq (OAT_SS_RELATIVE or OAT_NO_ERROR or OAT_RELOCATABLE))
            %lea xax, ??InsExpr
          else
            %mov xax, offset(??InsExpr)
          endif
        endif
      endif
      ;Use all volatile registers except xax, which is used as return register
      s2s ??ObjExpr ptr [xax], @CatStr(<TPL_>, %??ObjExpr), xmm7, xmm6, xmm5, xmm4, xmm3, xmm2, xmm1, xmm0, xcx, xdx
    endif
  else
    @Err <New Error: undefined object Expression>
  endif
endm                                                    ;;xax -> allocated object instance

$New macro Args:vararg
  New Args
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      Destroy
; Purpose:    Safely free the memory allocated for a particular object instance but calling first
;             its destructor method. If not specified, "Done" is assumed.
; Arguments:  Arg1: Expression of the form: "InsName::NameSpace:ObjName.MtdName"
;             Possible syntax combinations:
;               - Ins::Nsp:Obj.Mtd
;               - Ins::Obj.Mtd
;               - Ins.Mtd
;               - Ins

Destroy macro Expression:req, Args:vararg
  PreParseExpr Expression

  if ??Pos1 ne 0
    $$IName SubStr <Expression>, 1, ??Pos1 - 1
  else
    if ??Pos3 ne 0
      $$IName SubStr <Expression>, 1, ??Pos3 - 1
    else
      $$IName textequ <Expression>
    endif
  endif

  .if POINTER ptr $$IName != NULL
    Kill Expression, Args
  .endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      Kill
; Purpose:    Free the memory allocated for a particular object instance but calling first its
;             destructor method. If not specified, "Done" is assumed.
; Arguments:  Arg1: Expression of the form: "InsName::NameSpace:ObjName.MtdName"
;             Possible syntax combinations:
;               - Ins::Nsp:Obj.Mtd
;               - Ins::Obj.Mtd
;               - Ins.Mtd
;               - Ins

Kill macro Expression:req, Args:vararg
  PreParseExpr Expression

  ;;Get ??MtdExpr
  if ??Pos3 ne 0
    ??MtdExpr CatStr ??MtdPfx, @SubStr(<Expression>, ??Pos3 + 1)
  else
    if ??Pos1 eq 0 and ??Pos2 eq 0
      ??MtdExpr CatStr ??MtdPfx, <Done>
    endif
  endif

  ;;Get ??ObjExpr
  if ??Pos1 ne 0
    if ??Pos2 ne 0
      if ??Pos3 ne 0
        ??ObjExpr CatStr @SubStr(<Expression>, ??Pos1 + 2, ??Pos2 - ??Pos1 - 2), \
                         ??ObjPfxSep, \
                         @SubStr(<Expression>, ??Pos2 + 1, ??Pos3 - ??Pos2 - 1)
      else
        ??ObjExpr CatStr @SubStr(<Expression>, ??Pos1 + 2, ??Pos2 - ??Pos1 - 2), \
                         ??ObjPfxSep, \
                         @SubStr(<Expression>, ??Pos2 + 1)
      endif
    else
      if ??Pos3 ne 0
        ??ObjExpr CatStr ??ObjPfx, @SubStr(<Expression>, ??Pos1 + 2, ??Pos3 - ??Pos1 - 2)
      else
        ifnb ??ObjectContext
          ??ObjExpr textequ ??ObjectContext
        else
          ??ObjExpr CatStr OBJASM_NAMESPACE, ??ObjPfxSep, <Primer>
          exitm
        endif
      endif
    endif
  else
    if ??Pos2 ne 0
      @Err <Kill Error: undefined instance Expression>
      exitm
    else
      ifnb ??ObjectContext
        ??ObjExpr textequ ??ObjectContext
      else
        ??ObjExpr CatStr OBJASM_NAMESPACE, ??ObjPfxSep, <Primer>
      endif
    endif
  endif

  ;;Get ??InsExpr
  if ??Pos1 ne 0
    ??InsExpr SubStr <Expression>, 1, ??Pos1 - 1
  else
    if ??Pos2 ne 0
      @Err <Kill Error: undefined instance Expression>
      exitm
    else
      if ??Pos3 ne 0
        ??InsExpr SubStr <Expression>, 1, ??Pos3 - 1
      else
        ??InsExpr textequ <Expression>
      endif
    endif
  endif

  if TARGET_BITNESS eq 32
    %push ??InsExpr                                     ;;Save pInstance onto stack
    %MethodInvoke FALSE, ??InsExpr, ??ObjExpr, ??MtdExpr, Args  ;;Call destructor method
    pop eax                                             ;;Little overhead: pop eax; push eax
    MemFree eax                                         ;;Dispose object instance from memory
  else
    ifdifi ??InsExpr, <rcx>
      mov rcx, ??InsExpr
    endif
    push rcx
    sub rsp, 28h                                        ;;Align again + new homing area
    %MethodInvoke FALSE, rcx, ??ObjExpr, ??MtdExpr, Args  ;;Call destructor method
    add rsp, 28h
    pop r8
    MemFree r8                                          ;;Dispose object instance from memory
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      SetObject
; Purpose:    Assume a register to an object type.
; Arguments:  Arg1: Register, i.e.: rax, rbx, ...
;             Arg2: (optional) Object name.
;             Arg3: (optional) Instance POINTER. Default is pSelf.

SetObject macro Register:req, ObjName:=<>, pInstance
  if (opattr Register) and OAT_REGISTER                 ;;Is pInstance a register?
    ifb <ObjName>
      $$OName textequ <??ObjectContext>
    else
      $$OName CatStr ??ObjPfx, <ObjName>
    endif

    %ifb <??RegisterCasted>
      ??RegisterCasted textequ <Register>             ;;Set first member in global list
      ??ObjectAssumed textequ $$OName                 ;;Set first member in global list
    else
      ??RegisterCasted CatStr <Register>, <!,>, ??RegisterCasted  ;;Add more members
      ??ObjectAssumed CatStr $$OName, <!,>, ??ObjectAssumed       ;;Add more members
    endif

    ifb <pInstance>
      $$InstPtr equ <pSelf>
    else
      $$InstPtr equ pInstance
    endif

    if type($$InstPtr) eq @WordSize
      ifdifi <Register>, <$$InstPtr>
        mov Register, $$InstPtr
      endif
    else
      $$Attributes = opattr($$InstPtr)
      if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE)) or \
         ($$Attributes eq (OAT_SS_RELATIVE or OAT_NO_ERROR or OAT_RELOCATABLE))
        lea Register, $$InstPtr
      else
        mov Register, offset($$InstPtr)
      endif
    endif

    assume Register:ptr $$OName

  else
    @Err <SetObject Error: first argument must be a register>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      SetOwner
; Purpose:    Link a register to an object owner object type and instance at compile-time.
; Arguments:  Arg1: Register, i.e.: rax, rbx, ...
;             Arg2: Object name.
;             Arg3: (optional) Instance POINTER. Default is pSelf.

SetOwner macro RegName:req, ObjName:req, pInstance:=<pSelf>
  if (opattr RegName) and OAT_REGISTER                  ;;Is RegName a register?
    %ifb <??RegisterCasted>
      ??RegisterCasted textequ <RegName>                ;;Set first member in list
      ??ObjectAssumed textequ <ObjName>
    else
      ??RegisterCasted CatStr <RegName>, <!,>, ??RegisterCasted  ;;Add more members.
      ??ObjectAssumed CatStr <ObjName>, <!,>, ??ObjectAssumed
    endif

    if (opattr pInstance) and OAT_REGISTER              ;;Is pInstance a register?
      mov RegName, ($Obj(Primer) ptr [pInstance]).pOwner
    else
      ifdifi <RegName>, <pInstance>
        mov RegName, pInstance
      endif
      mov RegName, [RegName].$Obj(Primer).pOwner
    endif

    assume RegName:ptr $Obj(ObjName)

  else
    @Err <SetOwner Error: argument must be a register>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ReleaseObject
; Purpose:    Free the link between a register and an object at compile-time.
; Arguments:  Arg1: (Optional) Register, i.e.: rax, rbx, ...

ReleaseObject macro RegName
  ifnb <RegName>
    assume RegName:NOTHING                              ;;Use indicated register
    ??RegisterCasted textequ <>                         ;;Reset the list
  else
    %ifnb <??RegisterCasted>
      $$Pos1 Instr ??RegisterCasted, <!,>
      if $$Pos1 eq 0
        assume ??RegisterCasted:NOTHING                 ;;Last member in list
        ??RegisterCasted textequ <>                     ;;Reset list
      else
        assume @SubStr(%??RegisterCasted, 1, $$Pos1 - 1):NOTHING  ;;Use first memeber in list
        ??RegisterCasted SubStr ??RegisterCasted, $$Pos1 + 1      ;;Delete first member in list
        $$Pos1 Instr ??ObjectAssumed, <!,>
        ??ObjectAssumed SubStr ??ObjectAssumed, $$Pos1 + 1        ;;Delete first member in list
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      Override
; Purpose:    Set a new method address in the dynamic-, virtual-, interfacetable.
; Arguments:  Arg1: Instance::Object.Method
;             Arg2: Object.Method or procedure address.
; Note:       Don't use r11 to pass a procedure address! It is used internally.
; Example:    Override [xsi].GdiObjects::XWCollection.DestroyItem, GdiObjects.DestroyItem

Override macro DstExpression:req, SrcExpression:req
  PreParseExpr SrcExpression
  if $ParseMtdExpr(SrcExpression) eq FALSE
    @Err <Override Error: invalid syntax in SrcExpression>
  else
    if ??Pos3 ne 0
      $$OffsetText textequ @CatStr(<offset(>, %??ObjExpr, %??MtdExpr, <)>)
    else
      $$OffsetText textequ @CatStr(%??MtdExpr)
    endif

    PreParseExpr DstExpression
    if $ParseCallExpr(DstExpression) eq FALSE
      @Err <Override Error: invalid syntax in DstExpression>
    else
      %ifdef ??ObjExpr
        if @CatStr(%??ObjExpr, <_Error>) eq ??OBJERR_NONE
          GetMtdType %??ObjExpr, %??MtdExpr
          if ??MtdType eq ??MTDTYPE_INTERFACE
            $$Txo textequ @CatStr(<??>, %??ObjExpr, <_IMT>)
            if type(??InsExpr) eq @WordSize
              if (opattr ??InsExpr) and OAT_REGISTER    ;;Is ??InsExpr a register?
                mov xdx, POINTER ptr [??InsExpr]        ;;Make DMT indirection
              else
                mov xcx, ??InsExpr
                mov xdx, POINTER ptr [xcx]              ;;Make DMT indirection
              endif
            else
              $$Attributes = opattr(??InsExpr)
              if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE)) or \
                 ($$Attributes eq (OAT_SS_RELATIVE or OAT_NO_ERROR or OAT_RELOCATABLE))
                lea xcx, ??InsExpr
              else
                mov xcx, offset(??InsExpr)
              endif
              mov xdx, POINTER ptr [xcx]                ;;Make DMT indirection
            endif
            mrm ($$Txo ptr [xdx]).??MtdExpr, %$$OffsetText, xcx
          elseif ??MtdType eq ??MTDTYPE_VIRTUAL
            $$Txo textequ @CatStr(<??>, %??ObjExpr, <_VMT>)
            if type(??InsExpr) eq @WordSize
              if (opattr ??InsExpr) and OAT_REGISTER    ;;Is ??InsExpr a register?
                mov xdx, POINTER ptr [??InsExpr]        ;;Make DMT indirection
              else
                mov xcx, ??InsExpr
                mov xdx, POINTER ptr [xcx]              ;;Make DMT indirection
              endif
            else
              $$Attributes = opattr(??InsExpr)
              if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE)) or \
                 ($$Attributes eq (OAT_SS_RELATIVE or OAT_NO_ERROR or OAT_RELOCATABLE))
                lea xcx, ??InsExpr
              else
                mov xcx, offset(??InsExpr)
              endif
              mov xdx, POINTER ptr [xcx]                ;;Make DMT indirection
            endif
            mrm ($$Txo ptr [xdx - sizeof($$Txo - @WordSize]).??MtdExpr), %$$OffsetText, xcx
          elseif ??MtdType eq ??MTDTYPE_DYNAMIC
            if type(??InsExpr) eq @WordSize
              if (opattr ??InsExpr) and OAT_REGISTER    ;;Is ??InsExpr a register?
                mrm (??ObjExpr ptr [??InsExpr]).??MtdExpr, %$$OffsetText, xdx
              else
                mov xdx, ??InsExpr
                mrm (??ObjExpr ptr [xdx]).??MtdExpr, %$$OffsetText, xcx
              endif
            else
              $$Attributes = opattr(??InsExpr)
              if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE)) or \
                 ($$Attributes eq (OAT_SS_RELATIVE or OAT_NO_ERROR or OAT_RELOCATABLE))
                lea xdx, ??InsExpr
              else
                mov xdx, offset(??InsExpr)
              endif
              mrm (??ObjExpr ptr [xdx]).??MtdExpr, %$$OffsetText, xcx
            endif
          elseif ??MtdType eq ??MTDTYPE_STATIC or ??MtdType eq ??MTDTYPE_INLINE
            @Err <Override Error: invalid method type DstExpression>
            exitm
          else
            @Err <Override Error: unkown method DstExpression>
            exitm
          endif
        endif
      else
       @Err <Override Error: unkown object DstExpression>
       exitm
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ObjectsInit
; Purpose:    Helper macro to initialize all object templates calling their Startup procedure.
;             No instance creation takes place.
; Arguments:  None.

ObjectsInit macro
  $$Count = 0
  while $$Count lt ??StartupMtdCount
    $$OName CatStr <StartupObjName_>, %$$Count
    invoke @CatStr(%$$OName, %??MtdPfx, <Startup>), offset(@CatStr(<TPL_>, %$$OName))
    $$Count = $$Count + 1
  endm
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ObjectsDone
; Purpose:    Helper macro to finalize all object templates calling their Shutdown procedure.
; Arguments:  None.

ObjectsDone macro
  $$Count = 0
  while $$Count lt ??ShutdownMtdCount
    $$OName CatStr <ShutdownObjName_>, %$$Count
    invoke @CatStr(%$$OName, %??MtdPfx, <Shutdown>), offset(@CatStr(<TPL_>, %$$OName))
    $$Count = $$Count + 1
  endm
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $MethodPrologue32
; Purpose:    Method prolog macro.
; Arguments:  Arg1: Procedure name
;             Arg2: Flags.
;             Arg3: Number of parameter bytes.
;             Arg4: Number of local bytes.
;             Arg5: Uses register list.
;             Arg6: Additional macro arguments.
; Return:     Total local space (byte count).

$MethodPrologue32 macro ProcName, Flags, ParamBytes, LocalBytes, RegList, UserParams
  ??ExtraBytes = 0

  if TRACING ne FALSE
    ??DbgTraceMtdCount CatStr <MtdCnt_>, <ProcName>
    ??DbgTraceMtdTicks CatStr <MtdTck_>, <ProcName>

    ;;Create trace variables in the S_PROF
    %ifndef ??DbgTraceMtdCount
      S_PROF segment
        ??DbgTraceMtdCount  DWORD  0
        ??DbgTraceMtdTicks  QWORD  0
      S_PROF ends
    endif

    ;;Do the tracing job
    ifidn @SubStr(<ProcName>, @InStr(1, <ProcName>, <_Startup>)), <_Startup>
      inc ??DbgTraceMtdCount                          ;;Increment access counter
      push eax
      push edx
      rdtsc                                           ;;Get current tick count
      sub ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax
      sbb ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
      pop edx
      pop eax
    else
      ifidn @SubStr(<ProcName>, @InStr(1, <ProcName>, <_Shutdown>)), <_Shutdown>
        inc ??DbgTraceMtdCount                        ;;Increment access counter
        push eax
        push edx
        rdtsc                                         ;;Get current tick count
        sub ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax
        sbb ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
        pop edx
        pop eax
      else
        push eax
        mov eax, POINTER ptr [esp + 08]               ;;Get instance pointer from stack
        .if eax == ??pDbgTraceInstance                ;;Check if it is the correct instance
          inc ??DbgTraceMtdCount                      ;;Increment access counter
          push edx
          rdtsc                                       ;;Get current tick count
          sub ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax
          sbb ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
          pop edx
        .endif
        pop eax
      endif
    endif
  endif

  if ??CurrFrame eq 1
    ;;Create stack frame
    if (ParamBytes + LocalBytes) gt 0                 ;;If both are zero, we can omit the
      push ebp                                        ;;  stack frame
      mov ebp, esp
      if STKGUARDING ne FALSE
        push xStkGrdCookie                            ;;Push the Cookie on the stack
        ??ExtraBytes = ??ExtraBytes + 4
      endif

      ;;Unrolled stack probing
      if LocalBytes + ??ExtraBytes ge PAGESIZE
      ;;Calc the furthest memory to probe and round up to next memory page
        ??MaxProbe = (LocalBytes + ??ExtraBytes + PAGESIZE - 1) and (- PAGESIZE)
        ??CurrProbe = PAGESIZE
        while ??CurrProbe le ??MaxProbe
          mov [ebp - ??CurrProbe], eax                ;;Probe stack now
          ??CurrProbe = ??CurrProbe + PAGESIZE
        endm
      endif

      if LocalBytes gt 0                              ;;Reserve room for the local vars
        add esp, not LocalBytes - 1                   ;;Same as 'sub esp, LocalBytes'
      endif
    endif

    ;;Save registers declared with 'uses'
    ifnb RegList
      for ??Register, RegList                         ;;Push declared registers
        push ??Register
      endm
    endif
  endif

  exitm %LocalBytes + ??ExtraBytes
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      MethodEpilogue32
; Purpose:    Helper macro that defines the method epilog.
; Arguments:  Arg1: Procedure name
;             Arg2: Flags.
;             Arg3: Number of parameter bytes.
;             Arg4: Number of local bytes.
;             Arg5: Uses register list.
;             Arg6: Additional macro arguments.

MethodEpilogue32 macro ProcName, Flags, ParamBytes, LocalBytes, RegList, UserParams
  if ??CurrFrame eq 1
    ;;Restore registers declared with 'uses'; The list is just reversed
    ifnb RegList
      for ??Register, RegList                           ;;Pop off declared registers
        pop ??Register                                  ;;They are in inverse order from
      endm                                              ;;  the prologue call
    endif

    if (ParamBytes + LocalBytes) gt 0                   ;;Stack frame removement
      if STKGUARDING ne FALSE
        lea esp, [ebp - 4]
        pop ebp                                         ;;ebp = Cookie
        pushfd                                          ;;Save Flags in the place taken by the Cookie
        cmp ebp, xStkGrdCookie                          ;;Is Cookie unchanged?
        jz @F
        sub esp, LocalBytes + 20                        ;;Preserve Stack values for diagnosis
        ; call StkGrdCallback
        lea esp, [esp + LocalBytes + 20]
        .if ZERO?
          @CatStr(<int >, <3>)                          ;;Breakpoint to start debugging here
        .endif
      @@:
        popfd                                           ;;Restore Flags
        pop ebp
      else
        leave
      endif
    endif
  endif

  if TRACING ne FALSE
    ??DbgTraceMtdTicks CatStr <MtdTck_>, <ProcName>
    ;;Do the tracing job
    pushfd
    ifidn @SubStr(<ProcName>, @InStr(1, <ProcName>, <_Startup>)), <_Startup>
      push eax
      push edx
      rdtsc                                             ;;Get current tick count
      add ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax      ;;Compute tick difference
      adc ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
      pop edx
      pop eax
    else
      ifidn @SubStr(<ProcName>, @InStr(1, <ProcName>, <_Shutdown>)), <_Shutdown>
        push eax
        push edx
        rdtsc                                           ;;Get current tick count
        add ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax    ;;Compute tick difference
        adc ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
        pop edx
        pop eax
      else
        push eax
        mov eax, POINTER ptr [esp + 12]                 ;;Get instance pointer from stack
        .if eax == ??pDbgTraceInstance                  ;;Check if it is the correct instance
          push edx
          rdtsc                                         ;;Get current tick count
          add ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax  ;;Compute tick difference
          adc ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
          pop edx
        .endif
        pop eax
      endif
    endif
    popfd
  endif

  ;;Correct stack or leave it to caller?
  if (Flags and 010000y) or (ParamBytes eq 0)
    ret
  else
    ret ParamBytes
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $NoFramePrologue32
; Purpose:    Method prolog macro.
; Arguments:  Arg1: Procedure name
;             Arg2: Flags.
;             Arg3: Number of parameter bytes.
;             Arg4: Number of local bytes.
;             Arg5: Uses register list.
;             Arg6: Additional macro arguments.

$NoFramePrologue32 macro ProcName, Flags, ParamBytes, LocalBytes, RegList, UserParams
  if TRACING ne FALSE
    ??DbgTraceMtdCount CatStr <MtdCnt_>, <ProcName>
    ??DbgTraceMtdTicks CatStr <MtdTck_>, <ProcName>

    ;;Create trace variables in the S_PROF
    %ifndef ??DbgTraceMtdCount
      S_PROF segment
        ??DbgTraceMtdCount  DWORD  0
        ??DbgTraceMtdTicks  QWORD  0
      S_PROF ends
    endif

    ;;Do the tracing job
    ifidn @SubStr(<ProcName>, @InStr(1, <ProcName>, <_Startup>)), <_Startup>
      inc ??DbgTraceMtdCount                            ;;Increment access counter
      push eax
      push edx
      rdtsc                                             ;;Get current tick count
      sub ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax
      sbb ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
      pop edx
      pop eax
    else
      ifidn @SubStr(<ProcName>, @InStr(1, <ProcName>, <_Shutdown>)), <_Shutdown>
        inc ??DbgTraceMtdCount                          ;;Increment access counter
        push eax
        push edx
        rdtsc                                           ;;Get current tick count
        sub ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax
        sbb ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
        pop edx
        pop eax
      else
        push eax
        mov eax, POINTER ptr [esp + 08]                 ;;Get instance pointer from stack
        .if eax == ??pDbgTraceInstance                  ;;Check if it is the correct instance
          inc ??DbgTraceMtdCount                      ;;Increment access counter
          push edx
          rdtsc                                       ;;Get current tick count
          sub ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax
          sbb ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
          pop edx
        .endif
        pop eax
      endif
    endif
  endif

  exitm <0>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      NoFrameEpilogue32
; Purpose:    Helper macro that defines the NOFRAME method epilog.
; Arguments:  Arg1: Procedure name
;             Arg2: Flags.
;             Arg3: Number of parameter bytes.
;             Arg4: Number of local bytes.
;             Arg5: Uses register list.
;             Arg6: Additional macro arguments.

NoFrameEpilogue32 macro ProcName, Flags, ParamBytes, LocalBytes, RegList, UserParams
  if TRACING ne FALSE
    ??DbgTraceMtdTicks CatStr <MtdTck_>, <ProcName>
  endif

  if TRACING ne FALSE
    ;;Do the tracing job
    pushfd
    ifidn @SubStr(<ProcName>, @InStr(1, <ProcName>, <_Startup>)), <_Startup>
      push eax
      push edx
      rdtsc                                             ;;Get current tick count
      add ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax      ;;Compute tick difference
      adc ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
      pop edx
      pop eax
    else
      ifidn @SubStr(<ProcName>, @InStr(1, <ProcName>, <_Shutdown>)), <_Shutdown>
        push eax
        push edx
        rdtsc                                           ;;Get current tick count
        add ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax    ;;Compute tick difference
        adc ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
        pop edx
        pop eax
      else
        push eax
        mov eax, POINTER ptr [esp + 12]                 ;;Get instance pointer from stack
        .if eax == ??pDbgTraceInstance                  ;;Check if it is the correct instance
          push edx
          rdtsc                                       ;;Get current tick count
          add ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax  ;;Compute tick difference
          adc ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
          pop edx
        .endif
        pop eax
      endif
    endif
    popfd
  endif

  ;;Correct stack or leave it to caller?
  if (Flags and 010000y) or (ParamBytes eq 0)
    ret
  else
    ret ParamBytes
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      Method
; Purpose:    Define an object method.
; Arguments:  Arg1: Object method name (ObjectName.MethodName).
;             Arg2: Method options like "uses".
;             Arg3: Method arguments.

Method macro Expression:req, MtdOpts:=<>, Args:vararg
  $$Pos1 InStr <Expression>, <.>
  if $$Pos1 ne 0
    $$OName CatStr ??ObjPfx, @SubStr(<Expression>, 1, $$Pos1 - 1)
    $$PName CatStr ??MtdPfx, @SubStr(<Expression>, $$Pos1 + 1)
    ??ObjectContext textequ $$OName                     ;;Define global symbol
    ??MethodContext textequ $$PName                     ;;Define global symbol
  else
    @Err <Method Error: method missing>
    exitm
  endif

  GetMtdType %$$OName, %$$PName
  if ??MtdType eq ??MTDTYPE_INLINE
    @Err <Method Error: Inline methods must be declared as a macro using $Method() ...>
    exitm
  endif

  ??CurrFrame = 1                                       ;;Set default

  if TARGET_BITNESS eq 32
    OPTION PROLOGUE:$MethodPrologue32
    OPTION EPILOGUE:MethodEpilogue32

    ifnb <MtdOpts>
      ifidni <MtdOpts>, <NOFRAME>
        $$UseRegs equ <>
        OPTION PROLOGUE:$NoFramePrologue32
        OPTION EPILOGUE:NoFrameEpilogue32
        ??CurrFrame = 0
      else
        if @InStr(1, <MtdOpts>, <:>) ne 0
          @Err <Method Error: incrorrect method options>
          exitm
        else
          $$UseRegs textequ <MtdOpts>
        endif
      endif
    else
      $$UseRegs textequ <>
    endif

    ;Note: The following lines MUST be the last.
    ;      An "endif" after the proc definition is not tolerated!
    .code

    ;Check the calling convention: c if ArgCnt < 0
    $$CallConv textequ <StdCall>
    %ifdef @CatStr(%$$OName, %$$PName, <_ArgCnt>)
      %if @CatStr(%$$OName, %$$PName, <_ArgCnt>) lt 0
        $$CallConv textequ <c>
      endif
    endif

    ;Skip 64 bit registers (those starting with "r") in 32 bit mode
    $$UseRegs32 textequ <>
    $$Flag = 0
    %forc $$Char, <$$UseRegs>
      ifidn <$$Char>, < >
        $$Flag = 1
      else
        if $$Flag eq 1
          ifidni <$$Char>, <r>
            $$Flag = 2
          else
            $$Flag = 0
          endif
        endif
      endif
      if $$Flag ne 2
        $$UseRegs32 CatStr $$UseRegs32, <$$Char>
      endif
    endm

    align ALIGN_CODE
    if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
      ifb <Args>
        @CatStr(%$$OName, %$$PName, < proc >, $$CallConv, < >, %$$UseRegs32, <, pSelf:ptr >, %$$OName)
      else
        @CatStr(%$$OName, %$$PName, < proc >, $$CallConv, < >, %$$UseRegs32, <, pSelf:ptr >, %$$OName, <!,>, <Args>)
      endif
    else
      ifb <Args>
        @CatStr(%$$OName, %??ObjRedefIndex, %$$PName, < proc >, $$CallConv, < >, %$$UseRegs32, <, pSelf:ptr >, %$$OName)
      else
        @CatStr(%$$OName, %??ObjRedefIndex, %$$PName, < proc >, $$CallConv, < >, %$$UseRegs32, <, pSelf:ptr >, %$$OName, <!,>, <Args>)
      endif
    endif

  else
    .code
    align ALIGN_CODE
    if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
      ifb <Args>
        @CatStr(%$$OName, %$$PName, < proc >, <MtdOpts>, <!, pSelf:ptr >, $$OName)
      else
        @CatStr(%$$OName, %$$PName, < proc >, <MtdOpts>, <!, pSelf:ptr >, $$OName, <!,>, <Args>)
      endif
    else
      ifb <Args>
        @CatStr(%$$OName, %??ObjRedefIndex, %$$PName, < proc >, <MtdOpts>, <!, pSelf:ptr >, $$OName)
      else
        @CatStr(%$$OName, %??ObjRedefIndex, %$$PName, < proc >, <MtdOpts>, <!, pSelf:ptr >, $$OName, <!,>, <Args>)
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      MethodEnd
; Purpose:    Terminate an object method.
; Arguments:  None.

MethodEnd macro
  %for $$Register, <??RegisterCasted>
    assume $$Register:NOTHING
  endm
  ??RegisterCasted textequ <>                         ;;Reset global symbol
  ??ObjectAssumed textequ <>                          ;;Reset global symbol

  @@EOM:                                              ;;"End Of Method" label
  ret                                                 ;;This triggers the epilogue generation
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    @CatStr(%??ObjectContext, %??MethodContext, < endp>)
  else
    @CatStr(%??ObjectContext, %??ObjRedefIndex, %??MethodContext, < endp>)
  endif
  ??ObjectContext textequ <>                          ;;Reset global symbol
  ??MethodContext textequ <>                          ;;Reset global symbol

  if TARGET_BITNESS eq 32
    OPTION PROLOGUE:PrologueDef                       ;;Set default prologue and
    OPTION EPILOGUE:EpilogueDef                       ;; epilogue generation
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $Method
; Purpose:    Returns the mangled object template name.
; Arguments:  Arg1: ObjectName.MethodName
; Example:    $Method(Object.Method) macro pSelf, Arg1, Arg2
;             ...
;             endm

$Method macro Expression:req
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    $$Pos1 InStr <Expression>, <.>
    if $$Pos1 ne 0
      $$OName CatStr ??ObjPfx, @SubStr(<Expression>, 1, $$Pos1 - 1)
      $$PName CatStr ??MtdPfx, @SubStr(<Expression>, $$Pos1 + 1)
      $$ObjectContext textequ $$OName
      $$MethodContext textequ $$PName
    else
      @Err <$Method Error: method missing>
      exitm <>
    endif
    exitm @CatStr(%$$OName, %$$PName)
  else
    exitm <>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ExitMethod
; Purpose:    Terminate an object method.
; Arguments:  Arg1: Expression.
; Note:       - More efficient is the use of i.e. "je @@EOM".
;             - Attention with the != comparison, !!= should be used.

ExitMethod macro Expression
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    %ifb <Expression>
      jmp @@EOM
    else
      if @SizeStr(Expression) ge 3
        ifidni @SubStr(Expression, 1),  <.if>
          Expression
            jmp @@EOM
          @CatStr(<.endif>)                               ;;Hide this line
        endif
      else
        ifidn <Expression>, <0>
          xor eax, eax
          echo 1111111111111
        elseifidni <Expression>, <xax>                  ;;Skip all these possibilities
        elseifidni <Expression>, <rax>
        elseifidni <Expression>, <eax>
        elseifidni <Expression>, <ax>
        elseifidni <Expression>, <al>
        else
          mov xax, Expression
        endif
        jmp @@EOM
        echo ******************
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      Embed
; Purpose:    Embed a named object instance into the template of another object.
; Arguments:  Arg1: Instance name.
;             Arg2: Object expression (Namespace:ObjectName).
; Note:       - Never call Destroy to free an embedded object. Only call "Done".

Embed macro InsName:req, ObjExpr:req
  if @CatStr(%??ObjName, <_Error>) eq ??OBJERR_NONE
    PreParseExpr ObjExpr
    if $ParseObjExpr(ObjExpr) eq FALSE
      @Err <Embed Error: invaid syntax in ObjExpr>
    else
      %$$Index = &??ObjName&_VCount + 1
      %&??ObjName&_VCount = $$Index
      @CatStr(%??ObjName, <_VarName_>, %$$Index) textequ <InsName>
      if MAKETEMPL ne FALSE
        @CatStr(%??ObjName, <_VarType_>, %$$Index) CatStr <??>, ??ObjExpr, <_Init>
      else
        @CatStr(%??ObjName, <_VarType_>, %$$Index) textequ ??ObjExpr
      endif
      @CatStr(%??ObjName, <_VarInit_>, %$$Index) textequ <{}>
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $PushMethodArgs32
; Purpose:    Helper macro that pushes all method arguments.
; Arguments:  Arg1: Argument count.
;             Arg2: Method argument list.

$PushMethodArgs32 macro ArgCount:req, Args:vararg
  $$EaxUsed = FALSE
  $$ArgPushed = FALSE
  $$ErrFlag = FALSE

  ;Reverse arguments and store them in ??Params
  ??Params textequ <>
  ifnb <Args>
    for $$Arg, <Args>
      ifb ??Params
        ??Params catstr <$$Arg>
      else
        ??Params catstr <$$Arg>, <!,>, ??Params
      endif
    endm
  endif

  ??ParamCount = 0
  $$StackCorrection = sizeof(POINTER)                   ;pSelf
  %for $$Arg, <??Params>
    ifnb <$$Arg>
      ??UArg textequ $Upper($$Arg)
      if $$EaxUsed ne FALSE
        $$ErrFlag = FALSE
        $$ErrFlag InStr 1, ??UArg, <EAX>
        if $$ErrFlag ne 0
          $$ErrFlag = TRUE
          if  $$ErrFlag gt 1
            if @InStr(1, %??WordChars, @SubStr(%??UArg, $$ErrFlag - 1, 1)) gt 0
              $$ErrFlag = FALSE
            endif
          endif
          if ( $$ErrFlag ne 0 and  $$ErrFlag le @SizeStr(%??UArg) - 3)
            if @InStr(1, %??WordChars, @SubStr(%??UArg, $$ErrFlag + 3, 1)) gt 0
              $$ErrFlag = FALSE
            endif
          endif
        endif
        if $$ErrFlag ne FALSE
          %echo @CatStr (<$PushMethodArgs32 - Error on line >, %@Line, < of >, @FileCur)
          @Err <$PushMethodArgs32 Error: EAX register already in use.>
          exitm
        else
          $$ErrFlag InStr 1, ??UArg, <AX>
          if  $$ErrFlag ne 0
            $$ErrFlag = TRUE
            if  $$ErrFlag gt 1
              if @InStr(1, %??WordChars, @SubStr(%??UArg, $$ErrFlag - 1, 1)) gt 0
                $$ErrFlag = FALSE
              endif
            endif
            if ( $$ErrFlag ne 0 and  $$ErrFlag le @SizeStr(%??UArg) - 2)
              if @InStr(1, %??WordChars, @SubStr(%??UArg, $$ErrFlag + 2, 1)) gt 0
                $$ErrFlag = FALSE
              endif
            endif
          endif
        endif
        if  $$ErrFlag ne FALSE
          @Err <$PushMethodArgs32 Error: AX register already in use.>
          exitm
        else
          $$ErrFlag InStr 1, ??UArg, <AL>
          if  $$ErrFlag ne 0
            $$ErrFlag = TRUE
            if  $$ErrFlag gt 1
              if @InStr(1, %??WordChars, @SubStr(%??UArg, $$ErrFlag - 1, 1)) gt 0
                $$ErrFlag = FALSE
              endif
            endif
            if ( $$ErrFlag ne 0 and  $$ErrFlag le @SizeStr(%??UArg) - 2)
              if @InStr(1, %??WordChars, @SubStr(%??UArg, $$ErrFlag + 2, 1)) gt 0
                $$ErrFlag = FALSE
              endif
            endif
          endif
        endif
        if  $$ErrFlag ne FALSE
          @Err <$PushMethodArgs32 Error: AL register already in use.>
          exitm
        endif
      endif

      ??Pos1 InStr 1, ??UArg, <ADDR >
      if ??Pos1 eq 1
        ??Attributes = opattr(@SubStr($$Arg, ??Pos1 + 5))
        if ??Attributes eq 00100010y or ??Attributes eq 01100010y
          $$EaxUsed = TRUE
          lea eax, @SubStr($$Arg, ??Pos1 + 5)
          push eax
        else
          if @InStr(6, $$Arg, <[>)
            $$EaxUsed = TRUE
            lea eax, @SubStr($$Arg, ??Pos1 + 5)
            push eax
          else
            push offset(@SubStr($$Arg, ??Pos1 + 5))
          endif
        endif
        ??ParamCount = ??ParamCount + 1
        $$StackCorrection = $$StackCorrection + @WordSize
      else
        ifidn @SubStr($$Arg, 1, 1), </>                 ;;Don't push this argument
          if $$ArgPushed                                ;;Check if we have yet pushed something
            @Err <$PushMethodArgs32 Error: can't use "/" escape before a pushed argument.>
            $$ErrFlag = TRUE
            exitm <0>
          endif
          ??Arg1 textequ @SubStr($$Arg, 2)
          $$ArgSize = type(??Arg1)
          ??Count = (($$ArgSize + @WordSize - 1) / @WordSize) * @WordSize
          repeat ($$ArgSize + @WordSize - 1) / @WordSize
            ??Count = ??Count - 4
            ??ParamCount = ??ParamCount + 1
            $$StackCorrection = $$StackCorrection + @WordSize
          endm

        else
          ??FloatFirstChar textequ @SubStr($$Arg, 1, 1)
          if (@InStr(1, <-0123456789>, %??FloatFirstChar) ne 0) and (@InStr(1, $$Arg, <.>) ne 0)
            db 68h                                      ;;push opcode
            REAL4 $$Arg                                 ;;push argument = REAL4
            ??ParamCount = ??ParamCount + 1
            $$StackCorrection = $$StackCorrection + @WordSize
          else
            if (opattr $$Arg) and 00010000b             ;;$$Arg is register
              ??RegSize SizeStr <$$Arg>
              if ??RegSize eq 3                         ;;eax, ebx, ecx, edx, esi, esi, esp, esp
                push $$Arg
                ??ParamCount = ??ParamCount + 1
                $$StackCorrection = $$StackCorrection + @WordSize
              elseif ??RegSize eq 2
                ??Char SubStr <$$Arg>, 2, 1
                %ifidni <??Char>, <l>                   ;;al, bl, cl, dl
                  $$EaxUsed = TRUE
                  push WORD ptr 0
                  movzx ax, $$Arg
                  push ax
                  ??ParamCount = ??ParamCount + 1
                  $$StackCorrection = $$StackCorrection + @WordSize
                else
                  %ifidni <??Char>, <h>                 ;;ah, bh, ch, dh
                    $$EaxUsed = TRUE
                    push WORD ptr 0
                    movzx ax, $$Arg
                    push ax
                    ??ParamCount = ??ParamCount + 1
                    $$StackCorrection = $$StackCorrection + @WordSize
                  else
                    push WORD ptr 0
                    push $$Arg                          ;;ax, bx, cx, dx, si, di, sp, bp
                    ??ParamCount = ??ParamCount + 1
                    $$StackCorrection = $$StackCorrection + @WordSize
                  endif
                endif
              else
                @Err <$PushMethodArgs32 Error: register &$$Arg not recognized.>
               $$ErrFlag = TRUE
                exitm
              endif
            else
              if (opattr $$Arg) and OAT_IMMEDIATE       ;;Immediate expression
                $$ArgSize = type($$Arg)
                if $$ArgSize eq 8                       ;;In case that the argument is a QWORD
                  push DWORD ptr ($$Arg and 0FFFFFFFFh)
                  push DWORD ptr ($$Arg shr 32)
                  $$StackCorrection = $$StackCorrection + 2*@WordSize
                else
                  push DWORD ptr $$Arg
                  $$StackCorrection = $$StackCorrection + @WordSize
                endif
                ??ParamCount = ??ParamCount + 1
              else
                $$ArgSize = type($$Arg)
                ??Count = (($$ArgSize + 3)/4)*4
                if ??Count eq 0
                  %echo @CatStr(<$PushMethodArgs32 - Error on line >, %@Line, < of >, @FileCur)
                  @Err <$PushMethodArgs32 Error: undefined symbol ($$Arg).>
                else
                  repeat ($$ArgSize + 3)/4
                    ??Count = ??Count - 4
                    push DWORD ptr [$$Arg + ??Count]
                    $$StackCorrection = $$StackCorrection + @WordSize
                  endm
                endif
                ??ParamCount = ??ParamCount + 1
              endif
            endif
          endif
          $$ArgPushed = TRUE
        endif
      endif
    endif
  endm

  if $$ErrFlag
    exitm <0>
  else
    if ArgCount ge 0
;      echo ==============================
;      %echo Argument Count  = $ToStr(%ArgCount)
;      %echo Parameter Count = $ToStr(%??ParamCount)
;      echo ==============================

      if ??ParamCount gt ArgCount
        %echo @CatStr(<$PushMethodArgs32 - Error on line >, %@Line, < of >, @FileCur)
        @Err <$PushMethodArgs32 Error: too many arguments or argument type mismatch.>
      elseif ??ParamCount lt ArgCount
        %echo @CatStr(<$PushMethodArgs32 - Error on line >, %@Line, < of >, @FileCur)
        @Err <$PushMethodArgs32 Error: too few arguments or argument type mismatch.>
      endif
      exitm <0>                                         ;;Regular call => stack balance by callee
    else
      if ??ParamCount lt (-1-ArgCount)                  ;;vararg
        @Err <$PushMethodArgs32 Error: too few arguments or argument type mismatch.>
        %echo @CatStr(<$PushMethodArgs32 - Error on line >, %@Line, < of >, @FileCur)
        exitm <0>
      else
        %exitm <$$StackCorrection>                      ;;Return number of bytes to remove
      endif                                             ;; from stack by the caller
    endif                                               
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $GetDeclaredParamCount
; Purpose:    Helper macro that returns the parameter count of a method definition inside "Object".
; Arguments:  Arg1: Mangled object name.
;             Arg2: Mangled method name.

$GetDeclaredParamCount macro MglObjName, MglMtdName
  $$Result = 0
  %for $$TestObject, <@CatStr(MglObjName, <_InherRevPath>)>
    %ifdef @CatStr(<$$TestObject>, <&MglMtdName>, <_ArgCnt>)
      $$Result = @CatStr(<$$TestObject>, <&MglMtdName>, <_ArgCnt>)
      exitm
    endif
  endm
  %exitm <$$Result>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $GetInstance32
; Purpose:    Helper macro for 32 bit that returns the instance pointer in a register.
; Arguments:  Arg1: Instance name.
;             Arg2: Used register.

$GetInstance32 macro InsName:req, Reg:req
  if type(InsName) eq @WordSize                         ;;If type = @WordSize, then it isn't an
    if (opattr InsName) and OAT_REGISTER                ;;  Object instance
      exitm <InsName>
    else
      mov Reg, InsName
      exitm <Reg>
    endif
  else
    $$Attributes = opattr(InsName)
    if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE)) or \
       ($$Attributes eq (OAT_SS_RELATIVE or OAT_NO_ERROR or OAT_RELOCATABLE))
      lea Reg, InsName
    else
      mov Reg, offset(InsName)
    endif
    exitm <Reg>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      GetInstance64
; Purpose:    Helper macro for 64 bit that returns the instance pointer in the rcx register.
; Arguments:  Arg1: Instance name.

GetInstance64 macro InsName:req
  if type(InsName) eq @WordSize                         ;;If type = @WordSize, then it isn't an
    if (opattr InsName) and OAT_REGISTER                ;;  Object instance
      ifdifi <InsName>, <rcx>
        mov rcx, InsName
      endif
    else
      mov rcx, InsName
    endif
  else
    $$Attributes = opattr(InsName)
    if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE)) or \
       ($$Attributes eq (OAT_SS_RELATIVE or OAT_NO_ERROR or OAT_RELOCATABLE))
      lea rcx, InsName
    else
      mov rcx, offset(InsName)
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      SetVarargPassedParams
; Purpose:    Helper macro that sets the total parameter count (excluded pSelf) in the eax register.
; Arguments:  Arg1: Method arguments.

SetVarargPassedParams macro Args
  ;;Only if VARARG, we load eax with the total number of passed arguments
  if $$DeclaredParamCount lt 0                          ;;If negative => VARARG
    $$PassedParamCount = $GetParamCount(Args)
    if $$PassedParamCount eq 0
      xor eax, eax
    else
      mov eax, $$PassedParamCount                       ;;eax = Total number of passed arguments,
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      MethodInvoke
; Purpose:    Helper macro that calls a method.
; Arguments:  Arg1: Invocation flag: TRUE = use the template, FALSE = use object instance.
;             Arg2: Instance name.
;             Arg3: Mangled object name.
;             Arg4: Mangled method name.
;             Arg5: Arguments.
; Notes:      If a method has VARARGs, the number of arguments is passed in eax.

MethodInvoke macro UseTPL, InsName:req, MglObjName:req, MglMtdName:req, Args:vararg
  $$IName textequ <InsName>

  ifdef MglObjName
    if @CatStr(MglObjName, <_Error>) eq ??OBJERR_NONE
      $$Result = $IsPrivateMethod(MglObjName, MglMtdName)
      if $$Result eq 1
        %ifdifi <??ObjectContext>, <MglObjName>         ;;Check scope
          @Err <MethodInvoke Error: private method can't be called from within current context>
          exitm
        endif
      elseif $$Result eq 2
        @Err <@CatStr(<MethodInvoke Error: undefined method >, %MglObjName, <.>, %MglMtdName)>
        exitm
      endif

      if $IsObsoleteMethod(MglObjName, MglMtdName)      ;;Obsolete method
        %@Err <@CatStr(<MethodInvoke Error: obsolete method >, MglObjName, <.>, MglMtdName)>
        exitm

      else
        GetMtdType MglObjName, MglMtdName               ;;Updates ??MtdType & ??ImpObj
        if ??MtdType eq ??MTDTYPE_UNKNOWN
          %@Err <@CatStr(<MethodInvoke Error: unknown method >, MglObjName, <.>, MglMtdName)>
          exitm

        else
          ;********************************************************************************
          if ??MtdType eq ??MTDTYPE_INLINE
            pushcontext assumes                         ;;Save context assume values
            ;Use default proc assume values
            assume xax:NOTHING, xbx:NOTHING, xcx:NOTHING, xdx:NOTHING, xdi:NOTHING, xsi:NOTHING
            assume fs:ERROR, gs:ERROR, es:ERROR

            %ifb <Args>
              @CatStr(%??ImpObj, MglMtdName, < >, InsName)
            else
              @CatStr(%??ImpObj, MglMtdName, < >, InsName, <,>, <Args>)
            endif

            popcontext assumes                          ;;Restore context assume values
          else
            $$DeclaredParamCount = $GetDeclaredParamCount(MglObjName, MglMtdName)
            $$ProcType CatStr <TYPE_>, ??ImpObj, <MglMtdName>

            ;********************************************************************************
            if ??MtdType eq ??MTDTYPE_STATIC
              if TARGET_BITNESS eq 32
                $$StackCorr = $PushMethodArgs32($$DeclaredParamCount, Args)
                if type(InsName) eq @WordSize
                  push InsName
                else
                  $$Attributes = opattr(InsName)
                  if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE)) or \
                     ($$Attributes eq (OAT_SS_RELATIVE or OAT_NO_ERROR or OAT_RELOCATABLE))
                    lea edx, InsName
                    push edx
                  else
                    push offset(InsName)
                  endif
                endif
                SetVarargPassedParams <Args>
                call @CatStr(%??ImpObj, MglMtdName)
                if $$StackCorr gt 0
                  add esp, $$StackCorr                  ;;Correct the stack in case of vararg
                endif
              else
                if type(InsName) ne @WordSize
                  $$Attributes = opattr(InsName)
                  if ($$Attributes eq (OAT_NO_ERROR or OAT_RELOCATABLE)) or \
                     ($$Attributes eq (OAT_SS_RELATIVE or OAT_NO_ERROR or OAT_RELOCATABLE))
                    lea rcx, InsName
                  else
                    mov rcx, offset(InsName)
                  endif
                  $$IName textequ <rcx>
                endif

                ifb <Args>
                  %invoke $$ProcType ptr [0], $$IName
                else
                  %invoke $$ProcType ptr [0], $$IName, Args
                endif
                org $ - 7                               ;;Discard call instruction [FF142500000000]
                SetVarargPassedParams <Args>
                call @CatStr(%??ImpObj, MglMtdName)
              endif

            ;********************************************************************************
            else
              if ??MtdType eq ??MTDTYPE_VIRTUAL or ??MtdType eq ??MTDTYPE_INTERFACE
                $$Txo CatStr <??>, <MglObjName>, <_DMT>
                if TARGET_BITNESS eq 32
                  $$StackCorr = $PushMethodArgs32($$DeclaredParamCount, Args)
                  $$IName textequ $GetInstance32(InsName, edx)
                  push $$IName
                  SetVarargPassedParams <Args>
                  if UseTPL eq FALSE
                    mov edx, POINTER ptr [$$IName]      ;;Make DMT indirection
                    call ($$Txo ptr [edx - sizeof(@CatStr(<??>, MglObjName, <_VMT>)) - sizeof(POINTER)]).&MglMtdName
                  else
                    $$SName textequ <TPL_&MglObjName&_DMT>
                    call ($$Txo ptr [$$SName]).&MglMtdName
                  endif
                  if $$StackCorr gt 0
                  add esp, $$StackCorr                  ;;Correct the stack in case of vararg
                  endif
                else
                  GetInstance64 InsName
                  ifb <Args>
                    %invoke $$ProcType ptr [0], rcx
                  else
                    %invoke $$ProcType ptr [0], rcx, Args
                  endif

                  org $ - 7                             ;;Discard call instruction [FF142500000000]
                  if UseTPL eq FALSE
                    mov r11, [rcx]                      ;;Make DMT indirection
                    $$SName textequ <r11 - sizeof(@CatStr(<??>, MglObjName, <_VMT>)) - sizeof(POINTER)>
                  else
                    $$SName textequ <TPL_&MglObjName&_DMT>
                  endif
                  SetVarargPassedParams <Args>
                  call ($$Txo ptr [$$SName]).&MglMtdName  ;;Call method
                endif

              ;******************************************************************************
              elseif ??MtdType eq ??MTDTYPE_DYNAMIC
                $$Txo textequ <MglObjName>
                if TARGET_BITNESS eq 32
                  $$StackCorr = $PushMethodArgs32($$DeclaredParamCount, Args)
                  $$IName textequ $GetInstance32(InsName, edx)
                  push $$IName
                  SetVarargPassedParams <Args>
                  if UseTPL eq FALSE
                    call ($$Txo ptr [$$IName]).&MglMtdName
                  else
                    $$SName textequ <TPL_&MglObjName&_DMT>
                    call ($$Txo ptr [$$SName]).&MglMtdName
                  endif
                  if $$StackCorr gt 0
                    add esp, $$StackCorr                ;;Correct the stack in case of vararg
                  endif
                else
                  GetInstance64 InsName
                  ifb <Args>
                    %invoke $$ProcType ptr [0], rcx
                  else
                    %invoke $$ProcType ptr [0], rcx, Args
                  endif

                  org $ - 7                             ;;Discard call instruction [FF142500000000]
                  if UseTPL eq FALSE
                    $$SName textequ <rcx>
                  else
                    $$SName textequ <TPL_&MglObjName>
                  endif
                  SetVarargPassedParams <Args>
                  call ($$Txo ptr [$$SName]).&MglMtdName  ;;Call method
                endif
              else
                @Err <MethodInvoke Error: logic error>
              endif
            endif
          endif
        endif
      endif
    endif
  else
    @Err <MethodInvoke Error: unknown object: MglObjName>
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      PreParseExpr
; Purpose:    Get the positions of the separators of an expression like:
;                 "InsName::Namespace:ObjName.MtdName"
;                         |          |       |
;                      ??Pos1     ??Pos2  ??Pos3
; Arguments:  Arg1: Expression of the form: "InsName::NameSpace:ObjName.MtdName"
; Return:     ??Pos1, ??Pos2 & ??Pos3.

PreParseExpr macro Expression:req
  ??InsExpr textequ <>
  ??ObjExpr textequ <>
  ??MtdExpr textequ <>

  ;;Get separator positions
  ??Pos1 InStr <Expression>, <::>
  if ??Pos1 ne 0
    if ??Pos1 + 1 lt @SizeStr(<Expression>)
      ??Pos2 InStr ??Pos1 + 2, <Expression>, <:>
    else
      ??Pos2 = 0
    endif
  else
    ??Pos2 InStr 1, <Expression>, <:>
  endif
  if ??Pos2 ne 0
    ??Pos3 InStr ??Pos2 + 1, <Expression>, <.>
  else
    if ??Pos1 ne 0
      ??Pos3 InStr ??Pos1 + 1, <Expression>, <.>
    else
      ??Pos3 InStr 1, <Expression>, <].>
      if ??Pos3 eq 0
        ??Pos3 InStr 1, <Expression>, <.>
      else
        ??Pos3 InStr ??Pos3 + 2, <Expression>, <.>
      endif
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ParseMtdExpr
; Purpose:    Parse an input expression for address macros.
; Arguments:  Arg1: Expression of the form: "InsName::NameSpace:ObjName.MtdName"
; Return:     TRUE if the parsing was successful, otherwise FALSE.
;             ??InsExpr, ??ObjExpr, ??MtdExpr. (??ObjExpr and ??MtdExpr are mangled).
; Notes:      The challange from this macro is to avoid symbol expansion. E.g. GetObject is the name
;             of a well known api. When we use it as the name of a method, it will get expanded to
;             __imp_GetObjectA, Which causes problems when parsing the input expression.
;             Possible syntax combinations:
;               - Ins::Nsp:Obj.Mtd
;               - Ins::Obj.Mtd
;               - Nsp:Obj.Mtd
;               - Obj.Mtd
;               - Mtd

$ParseMtdExpr macro Expression:req
  ;;Get ??MtdExpr
  if ??Pos3 ne 0
    ??MtdExpr CatStr ??MtdPfx, @SubStr(<Expression>, ??Pos3 + 1)
  else
    if ??Pos1 eq 0 and ??Pos2 eq 0
      ??MtdExpr textequ <Expression>
    endif
  endif

  ;;Get ??ObjExpr
  if ??Pos1 ne 0
    if ??Pos2 ne 0
      if ??Pos3 ne 0
        ??ObjExpr CatStr @SubStr(<Expression>, ??Pos1 + 2, ??Pos2 - ??Pos1 - 2), \
                         ??ObjPfxSep, \
                         @SubStr(<Expression>, ??Pos2 + 1, ??Pos3 - ??Pos2 - 1)
      else
        ??ObjExpr CatStr @SubStr(<Expression>, ??Pos1 + 2, ??Pos2 - ??Pos1 - 2), \
                         ??ObjPfxSep, \
                         @SubStr(<Expression>, ??Pos2 + 1)
      endif
    else
      if ??Pos3 ne 0
        ??ObjExpr CatStr ??ObjPfx, @SubStr(<Expression>, ??Pos1 + 2, ??Pos3 - ??Pos1 - 2)
      else
        @Err <ParseMtdExpr Error: invalid syntax in Expression>
        exitm <FALSE>
      endif
    endif
  else
    if ??Pos2 ne 0
      if ??Pos3 ne 0
        ??ObjExpr CatStr @SubStr(<Expression>, 1, ??Pos2 - 1), \
                         ??ObjPfxSep, \
                         @SubStr(<Expression>, ??Pos2 + 1, ??Pos3 - ??Pos2 - 1)
      else
        @Err <ParseMtdExpr Error: invalid syntax in Expression>
        exitm <FALSE>
      endif
    else
      if ??Pos3 ne 0
        ??ObjExpr CatStr ??ObjPfx, @SubStr(<Expression>, 1, ??Pos3 - 1)
      else
        ??ObjExpr textequ <Expression>
      endif
    endif
  endif

  ;;Get ??InsExpr
  if ??Pos1 ne 0
    ??InsExpr SubStr <Expression>, 1, ??Pos1 - 1
  endif
  exitm <TRUE>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ParseCallExpr
; Purpose:    Parse an input expression for ?Call macros.
; Arguments:  Arg1: Expression of the form: "InsName::NameSpace:ObjName.MtdName"
; Return:     TRUE if the parsing was successful, otherwise FALSE.
;             ??InsExpr, ??ObjExpr, ??MtdExpr. (??ObjExpr and ??MtdExpr are mangled).
; Notes:      The challange from this macro is to avoid symbol expansion. E.g. GetObject is the name
;             of a well known api. When we use it as the name of a method, it will get expanded to
;             __imp_GetObjectA, Which causes problems when parsing the input expression.
;             Possible syntax combinations:
;               - Ins::Nsp:Obj.Mtd
;               - Ins::Obj.Mtd
;               - Nsp:Obj.Mtd
;               - Ins.Mtd
;               - Mtd

$ParseCallExpr macro Expression:req
  ;;Get ??MtdExpr
  if ??Pos3 ne 0
    ??MtdExpr CatStr ??MtdPfx, @SubStr(<Expression>, ??Pos3 + 1)
  else
    if ??Pos1 eq 0 and ??Pos2 eq 0
      ??MtdExpr CatStr ??MtdPfx, <Expression>
    endif
  endif

  ;;Get ??InsExpr
  if ??Pos1 ne 0
    ??InsExpr SubStr <Expression>, 1, ??Pos1 - 1
  else
    if ??Pos2 eq 0 and ??Pos3 ne 0
      ??InsExpr SubStr <Expression>, 1, ??Pos3 - 1
    else
      ifnb ??ObjectContext
        ??InsExpr textequ <pSelf>
      endif
    endif
  endif

  ;;Get ??ObjExpr
  if ??Pos1 ne 0
    if ??Pos2 ne 0
      if ??Pos3 ne 0
        ??ObjExpr CatStr @SubStr(<Expression>, ??Pos1 + 2, ??Pos2 - ??Pos1 - 2), \
                         ??ObjPfxSep, \
                         @SubStr(<Expression>, ??Pos2 + 1, ??Pos3 - ??Pos2 - 1)
      else
        ??ObjExpr CatStr @SubStr(<Expression>, ??Pos1 + 2, ??Pos2 - ??Pos1 - 2), \
                         ??ObjPfxSep, \
                         @SubStr(<Expression>, ??Pos2 + 1)
      endif
    else
      if ??Pos3 ne 0
        ??ObjExpr CatStr ??ObjPfx, @SubStr(<Expression>, ??Pos1 + 2, ??Pos3 - ??Pos1 - 2)
      else
        exitm <FALSE>
      endif
    endif
  else
    if ??Pos2 ne 0
      if ??Pos3 ne 0
        ??ObjExpr CatStr @SubStr(<Expression>, 1, ??Pos2 - 1), \
                         ??ObjPfxSep, \
                         @SubStr(<Expression>, ??Pos2 + 1, ??Pos3 - ??Pos2 - 1)
      else
        exitm <FALSE>
      endif
    else
      ifidni ??InsExpr, <pSelf>
        ifnb ??ObjectContext
          ??ObjExpr textequ ??ObjectContext
        else
          exitm <FALSE>
        endif
      else
        $$Index = 0
        $$Count = 0
          %for $$Register, <??RegisterCasted>
          $$Count = $$Count + 1
            %ifidni <??InsExpr>, <$$Register>
            $$Index = $$Count
          endif
        endm

        if $$Index eq 0
          exitm <FALSE>
        else
          $$Count = 0
            %for $$Arg, <??ObjectAssumed>
            $$Count = $$Count + 1
            if $$Count eq $$Index
              ??ObjExpr textequ <$$Arg>
            endif
          endm
        endif
      endif
    endif
  endif

  exitm <TRUE>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ParseInstExpr
; Purpose:    Parse an input expression for some Debug macros.
; Arguments:  Arg1: Expression of the form: "InsName::NameSpace:ObjName.MtdName"
; Return:     TRUE if the parsing was successful, otherwise FALSE.
;             ??InsExpr, ??ObjExpr, ??MtdExpr. (??ObjExpr and ??MtdExpr are mangled).
; Notes:      Possible syntax combinations:
;               - Ins::Nsp:Obj
;               - Ins::Obj

$ParseInstExpr macro Expression:req
  if ??Pos3 ne 0
    exitm <FALSE>
  endif

  ;;Get ??ObjExpr
  if ??Pos1 ne 0
    if ??Pos2 ne 0
      ??ObjExpr CatStr @SubStr(<Expression>, ??Pos1 + 2, ??Pos2 - ??Pos1 - 2), \
                       ??ObjPfxSep, \
                       @SubStr(<Expression>, ??Pos2 + 1)
    else
      ??ObjExpr CatStr ??ObjPfx, @SubStr(<Expression>, ??Pos1 + 2)
    endif
  else
    exitm <FALSE>
  endif

  ;;Get ??InsExpr
  if ??Pos1 ne 0
    ??InsExpr SubStr <Expression>, 1, ??Pos1 - 1
  else
    ifnb ??ObjectContext
      ??InsExpr textequ <pSelf>
    else
      exitm <FALSE>
    endif
  endif

  exitm <TRUE>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $ParseObjExpr
; Purpose:    Parse an input expression for Object macro.
; Arguments:  Arg1: Expression of the form: "NameSpace:ObjName"
; Return:     TRUE if the parsing was successful, otherwise FALSE.
;             ??ObjExpr (mangled).
; Notes:      The challange from this macro is to avoid symbol expansion. E.g. GetObject is the name
;             of a well known api. When we use it as the name of a method, it will get expanded to
;             __imp_GetObjectA, Which causes problems when parsing the input expression.
;             Possible syntax combinations:
;               - Nsp:Obj
;               - Obj

$ParseObjExpr macro Expression:req
  if ??Pos1 ne 0 or ??Pos3 ne 0
    exitm <FALSE>
  endif

  ;;Get ??ObjExpr
  if ??Pos2 ne 0
    ??ObjExpr CatStr @SubStr(<Expression>, 1, ??Pos2 - 1), \
                     ??ObjPfxSep, \
                     @SubStr(<Expression>, ??Pos2 + 1)
  else
    ??ObjExpr CatStr ??ObjPfx, <Expression>
  endif

  exitm <TRUE>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      OCall / $OCall
; Purpose:    Call an object method.
; Arguments:  Arg1: "InsName::ObjName.MtdName" expression. See $ParseCallExpr.
;             Arg2: Method arguments.

OCall macro Expression:req, Args:vararg
  PreParseExpr Expression
  if $ParseCallExpr(Expression) eq FALSE
    @Err <OCall Error: invalid syntax in Expression>
  else
    %MethodInvoke FALSE, ??InsExpr, ??ObjExpr, ??MtdExpr, Args
  endif
endm

$OCall macro Args:vararg
  OCall Args
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      ACall / $ACall
; Purpose:    Call the ancestor method of an object.
; Arguments:  Arg1: "InsName::ObjName.MtdName" expression. See $ParseCallExpr.
;             Arg2: Method arguments.

ACall macro Expression:req, Args:vararg
  PreParseExpr Expression
  if $ParseCallExpr(Expression) eq FALSE
    .err <ACall - invalid syntax: Expression>
  else
    $$AName CatStr ??ObjExpr, <_Inherit>
    %MethodInvoke TRUE, ??InsExpr, $$AName, ??MtdExpr, Args
  endif
endm

$ACall macro Args:vararg
  ACall Args
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      TCall / $TCall
; Purpose:    Call a method using the address stored in the object template.
; Arguments:  Arg1: "InsName::ObjName.MtdName" expression. See $ParseCallExpr.
;             Arg2: Method arguments.

TCall macro Expression:req, Args:vararg
  PreParseExpr Expression
  if $ParseCallExpr(Expression) eq FALSE
    .err <TCall - invalid syntax: Expression>
  else
    %MethodInvoke TRUE, ??InsExpr, ??ObjExpr, ??MtdExpr, Args
  endif
endm

$TCall macro Args:vararg
  TCall Args
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      DCall / $DCall
; Purpose:    Call an object method directly like a normal procedure (like a static method).
; Arguments:  Arg1: "InsName::ObjName.MtdName" expression. See $ParseCallExpr.
;             Arg2: Method arguments.

DCall macro Expression:req, Args:vararg
  PreParseExpr Expression
  if $ParseCallExpr(Expression) eq FALSE
    .err <DCall - invalid syntax: Expression>
  else
    %GetMtdType ??ObjExpr, ??MtdExpr                    ;;Returns ??MtdType & ??ImpObj
    if ??MtdType eq ??MTDTYPE_UNKNOWN
      .err <DCall - unknown method: Expression>

    elseif ??MtdType eq ??MTDTYPE_INLINE
      ;;Save context assume values
      pushcontext assumes
      ;;Use standard proc assume values
      assume xax:NOTHING, xbx:NOTHING, xcx:NOTHING, xdx:NOTHING, xdi:NOTHING, xsi:NOTHING
      assume fs:ERROR, gs:ERROR, es:ERROR

      ;;Call macro
      %ifb <Args>
        @CatStr(%??ImpObj, %??MtdExpr, < >, %??InsExpr)
      else
        @CatStr(%??ImpObj, %??MtdExpr, < >, %??InsExpr, <,>, <Args>)
      endif

      ;:Restore context assume values
      popcontext assumes
    else
      $$DeclaredParamCount = $GetDeclaredParamCount(%??ImpObj, %??MtdExpr)
      if TARGET_BITNESS eq 32
        $$StackCorr = $PushMethodArgs32($$DeclaredParamCount, Args)
        $$IName textequ $GetInstance32(??InsExpr, edx)
        push $$IName
        SetVarargPassedParams <Args>
        call @CatStr(%??ImpObj, %??MtdExpr)
        if $$StackCorr gt 0
          add esp, $$StackCorr                          ;;Correct the stack in case of vararg
        endif
      else
        $$ProcType CatStr <TYPE_>, <&??ImpObj>, <&??MtdExpr>
        GetInstance64 ??InsExpr
        ifb <Args>
          %invoke $$ProcType ptr [0], rcx
        else
          %invoke $$ProcType ptr [0], rcx, Args
        endif
        org $ - 7                                       ;;Discard call instruction [FF142500000000]
        SetVarargPassedParams <Args>
        call @CatStr(%??ImpObj, %??MtdExpr)
      endif
    endif
  endif
endm

$DCall macro Args:vararg
  DCall Args
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      $GetParamCount
; Purpose:    Helper macro counts parameters in Args list.
; Arguments:  Arg1: Method parameter list.

$GetParamCount macro Args:vararg
  $$Sum = 0
  for $$Arg, <Args>
    $$Sum = $$Sum + 1
  endm
  %exitm <$$Sum>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     $GetImpIfc
; Purpose:   Get the implementing interface name.
; Arguments: Arg1: Interface name.
;            Arg2: Method name.

$GetImpIfc macro IName:req, MName:req
  ??sz1 textequ <&IName&&MName&>
  %ifdef ??sz1                                          ;;Check for this symbol
    exitm <IName>                                       ;;  (=> prototype from STD_METHOD)
  else
    ??Inher CatStr <IName>, <_Inherit>
    %ifdef ??Inher
      exitm <$GetImpIfc(%??Inher, MName)>               ;;Use recursion
    else
      exitm <>
    endif
  endif
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:     ICall / $ICall
; Purpose:   Interface method call.
; Arguments: Arg1: InstancePointer::InterfaceName.MethodName.
;            Arg2: Method arguments.

ICall macro Expression:req, Args:vararg
  PreParseExpr Expression

  if ??Pos1 le 1 or ??Pos2 ne 0 or ??Pos3 le 4
    .err <ICall - syntax error: Expression>
  else
    ??InsExpr SubStr <Expression>, 1, ??Pos1 - 1
    ??IfcExpr CatStr @SubStr(<Expression>, ??Pos1 + 2, ??Pos3 - ??Pos1 - 2)
    ??MtdExpr CatStr <_>, @SubStr(<Expression>, ??Pos3 + 1)

    ??ImpIfc textequ $GetImpIfc(@CatStr(%??IfcExpr, <Vtbl>), %??MtdExpr)     ;;<Interface>Vtbl
    ifnb ??ImpIfc
      %ifdef @CatStr(%??ImpIfc, %??MtdExpr, <_ArgCount>)
        ;;If it was previously calculated, then use that result.
        $$ArgCount = @CatStr(%??ImpIfc, %??MtdExpr, <_ArgCount>)
        ifdif <??ImpIfc>, @CatStr(%??IfcExpr, <Vtbl>)
          @CatStr(%??IfcExpr, <Vtbl>, %??MtdExpr, <_ArgCount>) = $$ArgCount
        endif
      else
        ;;Calculate $$ArgCount here to reduce the nesting level!
        $$sz1 textequ <>
        $$ArgCount = 0
        ifnb <Args>
          %for $$Arg:req, <@CatStr(%??ImpIfc, %??MtdExpr, <_Args>)>
            %ifidn <@SubStr(<$$Arg>, 1, 1)>, <:>        ;;Strip ":" to provide OA32 compatibility
              $$Strip SubStr <$$Arg>, 2
            else
              $$Strip textequ <$$Arg>
            endif

            $$Size1 SizeStr $$Strip
            %if $$Size1 ge 4
              $$Size1 = 4
              $$Size2 = 4
            else
              $$Size2 = 3
            endif

            $$ArgCount = $$ArgCount + 1
            $$sz1 CatStr $$sz1, <,:>, $$Strip
          endm
        endif
        @CatStr(%??IfcExpr, <Vtbl>, %??MtdExpr, <_ArgCount>) = $$ArgCount
      endif
      $$DeclaredParamCount = $$ArgCount                 ;;Does include the instance pointer

      if TARGET_BITNESS eq 32
        $$StackCorr = $PushMethodArgs32(%$$ArgCount - 1, Args)
        $$IName textequ $GetInstance32(%??InsExpr, edx)
        push $$IName
        mov edx, [$$IName]                              ;;Make indirection
        call (??ImpIfc ptr [edx]).??MtdExpr
        if $$StackCorr ne 0
          add esp, $$StackCorr                          ;;Correct the stack
        endif
      else
        $$ProcType CatStr <TYPE_>, ??ImpIfc, ??MtdExpr
        GetInstance64 ??InsExpr
        ifb <Args>
          %invoke $$ProcType ptr [0], rcx
        else
          %invoke $$ProcType ptr [0], rcx, Args
        endif

        org $ - 7                                       ;;Discard call instruction [FF142500000000]
        mov r11, [rcx]                                  ;;Make indirection
        call (??ImpIfc ptr [r11]).??MtdExpr
      endif
    else
      %.err <ICall - undefined !i!nterface method ??IfcExpr.&??MtdExpr>
      exitm
    endif
  endif
endm

$ICall macro Args:vararg
  ICall Args
  exitm <xax>
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      AddErrMsg
; Purpose:    Add an error message and creates the necessary Object Error Tables.
; Arguments:  Arg1: Symbol name describing the error, e.g. OBJ_OUT_OF_MEMORY.
;             Arg2: [Optional] Error description text.
;             Arg3: [Optional] Error ID. Sets the first ID in a series of error messages.

AddErrMsg macro SymName:req, Description:=<>, ErrID:=<>
  ifnb <ErrID>                                          ;;Check if an ID was specified
    ERROR_BASE = ErrID                                  ;; => overwrite previous value
  endif

  if DEBUGGING
    ??ObjErrTableCount = ??ObjErrTableCount + 1         ;;Track the number of error table entries
    S_OBJERR segment
      DWORD ERROR_BASE                                  ;;Add the ID to the object error table
      ifnb <Description>                                ;;If a description was specified,
        PSTRING $OfsTStrA("&SymName&: ", &Description)  ;; => add it into the 2nd const segment
      else
        PSTRING $OfsTStrA("&SymName&")                  ;; => alternatively store the Err name only
      endif
    S_OBJERR ends
  endif

  SymName equ ERROR_BASE                                ;;Declare the symbol
  ERROR_BASE = ERROR_BASE + 1                           ;;Increment for next declaration
endm

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Macro:      LockObjectAccess / UnlockObjectAccess
; Purpose:    These macros perform object locking for multithreaded access. The threads of a single
;             process can use a ObjLock for mutual-exclusion synchronization. There is no guarantee
;             about the order that threads obtain ownership of the ObjLock.
; Arguments:  Arg1: Object instance. Must be a non volatile register.

LockObjectAccess macro ObjInst:req
  local @@0, @@1

  @@0:
  invoke GetCurrentThreadId
  mov ecx, eax

  @@1:
  .if ObjInst.ObjLock.dOwnerTheadID == 0                ;;No lock?
    xor eax, eax
    lock cmpxchg ObjInst.ObjLock.dOwnerTheadID, ecx
    jnz @@1
    inc ObjInst.ObjLock.dLockCount
  .else
    .if ecx == ObjInst.ObjLock.dOwnerTheadID            ;;Continue thread execution
      inc ObjInst.ObjLock.dLockCount                    ;;Increment LockCount
    .else
      invoke Sleep, 0                                   ;;A value of zero causes the thread to
                                                        ;;relinquish the remainder of its time
                                                        ;;slice to any other thread of equal
                                                        ;;priority that is ready to run
      jmp @@0
    .endif
  .endif
endm

UnlockObjectAccess macro ObjInst:req
  dec ObjInst.ObjLock.dLockCount
  .if ZERO?
    lock and ObjInst.ObjLock.dOwnerTheadID, 0           ;;Should be a simple mov ********
  .endif
endm

;LockObjectAccess macro ObjInst:req                      ;;See P4 "IA-32 Intel® Architecture Optimi-
;  local @@0, @@1                                        ;;  zation Reference Manual" page 7-24
;
;  invoke GetCurrentThreadId
;  mov ecx, eax
;  xor eax, eax
;
;  @@0:
;  cmpxchg ObjInst.ObjLock.dOwnerTheadID, ecx            ;;Implicit lock prefix
;  ht                                                    ;;Override default
;  jz @@1
;  _Pause_                                               ;;Wait a bit
;  jmp @@0                                               ;;Spinn again
;  @@1:                                                    ;;Continue thread execution
;  inc ObjInst.ObjLock.dLockCount                        ;;Increment dLockCount
;endm
;
;UnlockObjectAccess macro ObjInst:req
;    dec ObjInst.ObjLock.dLockCount                      ;;Decrement dLockCount
;    cmovz ObjInst.ObjLock.dOwnerTheadID, 0              ;;If zero => reset ThreadID
;endm
;
;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:      MethodEpilogue
;; Purpose:    Helper macro that defines the method epilog.
;; Arguments:  Arg1: Procedure name
;;             Arg2: Flags.
;;             Arg3: Number of parameter bytes.
;;             Arg4: Number of local bytes.
;;             Arg5: Uses register list.
;;             Arg6: Additional macro arguments.
;
;MethodEpilogue macro ProcName, Flags, ParamBytes, LocalBytes, RegList, UserParams
;  if ??CurrFrame eq 1
;    ;;Restore registers declared with 'uses'; The list is just reversed
;    ifnb RegList
;      for $$Register, RegList                           ;;Pop off declared registers
;        pop $$Register                                  ;;They are in inverse order from
;      endm                                              ;;  the prologue call
;    endif
;
;    if (ParamBytes + LocalBytes) gt 0                   ;;Stack frame removement
;      if STKGUARDING ne FALSE
;        lea rsp, [rbp - @WordSize]
;        pop rbp                                         ;;ebp = Cookie
;        pushfd                                          ;;Save Flags in the place taken by the Cookie
;        cmp rbp, qStkGrdCookie                          ;;Is Cookie unchanged?
;        jz @F
;        sub rsp, LocalBytes + 20                        ;;Preserve Stack values for diagnosis
;        call StkGrdCallback
;        lea rsp, [rsp + LocalBytes + 20]
;        .if ZERO?
;          @CatStr(<int >, <3>)                          ;;Breakpoint to start debugging here
;        .endif
;@@
;        popfd                                           ;;Restore Flags
;        pop rbp
;      else
;        leave
;      endif
;    endif
;  endif
;
;  if TRACING ne FALSE
;    ??DbgTraceMtdTicks CatStr <MtdTck_>, <ProcName>
;    ;;Do the tracing job
;    pushfd
;    ifidn @SubStr(<ProcName>, @InStr(1, <ProcName>, <_Startup>)), <_Startup>
;      push rax
;      push rdx
;      rdtsc                                             ;;Get current tick count
;      add ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax      ;;Compute tick difference
;      adc ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
;      pop rdx
;      pop rax
;    else
;      ifidn @SubStr(<ProcName>, @InStr(1, <ProcName>, <_Shutdown>)), <_Shutdown>
;        push rax
;        push rdx
;        rdtsc                                           ;;Get current tick count
;        add ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax    ;;Compute tick difference
;        adc ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
;        pop rdx
;        pop rax
;      else
;        push rax
;        mov rax, POINTER ptr [rsp + 24]                 ;;Get instance POINTER from stack
;        .if rax == ??pDbgTraceInstance                  ;;Check if it is the correct instance
;          push rdx
;          rdtsc                                         ;;Get current tick count
;          add ??DbgTraceMtdTicks.QUADWORD.LoDWord, eax  ;;Compute tick difference
;          adc ??DbgTraceMtdTicks.QUADWORD.HiDWord, edx
;          pop rdx
;        .endif
;        pop rax
;      endif
;    endif
;    popfd
;  endif
;
;  ;;Correct stack or leave it to caller?
;  if (Flags and 010000y) or (ParamBytes eq 0)
;    ret
;  else
;    ret ParamBytes
;  endif
;endm
;
;; ——————————————————————————————————————————————————————————————————————————————————————————————————
;; Macro:      $StkGrdPrologue
;; Purpose:    Procedure Prolog macro.
;; Arguments:  Arg1: Procedure name.
;;             Arg2: Flags.
;;             Arg3: Number of parameter bytes.
;;             Arg4: Number of local bytes.
;;             Arg5: Uses register list.
;;             Arg6: Additional macro arguments.
;
;$StkGrdPrologue macro ProcName, Flags, ParamBytes, LocalBytes, RegList, UserParams
;  ;;Create stack frame
;  if (ParamBytes ne 0) or (LocalBytes ne 0)             ;;If both are zero, we can omit the stack frame
;    push rbp
;    mov rbp, rsp
;    push qStkGrdCookie                                  ;;Push the Cookie on the stack
;    if LocalBytes ne 0
;      add rsp, -LocalBytes
;    endif
;  endif
;
;  ;;Save registers declared with 'uses'
;  ifnb RegList
;    for $$Register, RegList                             ;;Push declared registers
;      push $$Register
;    endm
;  endif
;
;  exitm %LocalBytes + sizeof(qStkGrdCookie)             ;;Make Room for the Cookie
;endm
