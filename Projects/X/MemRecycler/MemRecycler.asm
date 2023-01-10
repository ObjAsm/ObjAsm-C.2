; ==================================================================================================
; Title:      MemRecycler.asm
; Author:     G. Friedrich
; Version:    1.0.0
; Purpose:    ObjAsm MemRecycler demo.
; Notes:      Version 1.0.0, July 2006
;               - First release.
; ==================================================================================================


% include @Environ(OBJASM_PATH)\Code\Macros\Model.inc
SysSetup OOP, NUI64, ANSI_STRING, DEBUG(WND)

% include &MacPath&fMath.inc                            ;Include coprocessor math macros
% include &MacPath&SDLL.inc                             ;List macros for DataPool

MakeObjects Primer, Stream
MakeObjects TickCounter, DataPool

ELEMENTS = 50000
DATASIZE = 5

start proc uses xbx xdi xsi
  local TC:$Obj(TickCounter), Pool:$Obj(DataPool)
  local pMemBlock:POINTER, cBuffer[1024]:CHR

  SysInit

  DbgClearAll
  DbgWriteF,, "Number of elements = 各D, Data size = 各D", ELEMENTS, DATASIZE

  New TC::TickCounter
  OCall TC::TickCounter.Init, NULL
  New Pool::DataPool
  OCall Pool::DataPool.Init, NULL, DATASIZE, 10000, 1

  mov eax, ELEMENTS
  shl eax, $Log2(sizeof(POINTER))
  mov pMemBlock, $MemAlloc(eax)

  OCall TC::TickCounter.Start

  ;Allocation test
  mov xdi, pMemBlock
  mov ebx, ELEMENTS
  test ebx, ebx
  .while !ZERO?
    OCall Pool::DataPool.NewItem
    mov [xdi], xax
    add xdi, sizeof(POINTER)
    dec ebx
  .endw

  mov xdi, pMemBlock
  mov ebx, ELEMENTS
  test ebx, ebx
  .while !ZERO?
    OCall Pool::DataPool.FreeItem, POINTER ptr [xdi]
    add xdi, sizeof(POINTER)
    dec ebx
  .endw

  OCall TC::TickCounter.Stop
  OCall TC::TickCounter.GetTicks

  fildReg xax
  mov xsi, xax
  DbgWriteF,, "DataPool = 各X CPU ticks", xsi

  OCall TC::TickCounter.Reset
  OCall TC::TickCounter.Start

  mov xdi, pMemBlock
  mov ebx, ELEMENTS
  test ebx, ebx
  .while !ZERO?
    MemAlloc DATASIZE, MEM_NO_SERIALIZE
    mov [xdi], xax
    add xdi, sizeof(POINTER)
    dec ebx
  .endw

  mov xdi, pMemBlock
  mov ebx, ELEMENTS
  test ebx, ebx
  .while !ZERO?
    MemFree POINTER ptr [xdi]
    add xdi, sizeof(POINTER)
    dec ebx
  .endw

  OCall TC::TickCounter.Stop
  OCall TC::TickCounter.GetTicks

  fildReg xax
  mov xsi, xax
  DbgWriteF ,, "ProcHeap = 各X CPU ticks", xsi 

  MemFree pMemBlock

  lea xsi, cBuffer
  fdivrp st(1), st(0)
  invoke St0ToStr, xsi, 0, 5, f_NOR
  fUnload
  DbgWriteF DbgColorBlue,, "Performance ratio = 吁T", xsi

;    OCall [xsi].pPool::DataPool.Shrink

  SysDone                                               ;Runtime finalization of the OOP model
  invoke ExitProcess, 0                                 ;Exit program returning 0 to the OS
start endp

end