; ==================================================================================================
; Title:      CudaApp_Main.inc
; Author:     G. Friedrich
; Version:    See Application.asm
; Purpose:    ObjAsm CUDA application.
; ==================================================================================================


; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Object:     Application
; Purpose:    Dialog main application.

Object Application,, DlgApp
  RedefineMethod    Init

  VirtualEvent      OnClose,    WM_CLOSE, WM_QUERYENDSESSION
ObjectEnd


;Runs on a NVIDIA GeForce GTX 660
;Architectur        = Kepler
;Shader Model       = 5.1
;Compute capability = 3.0
;Shader Model       = 5.1
;CUDA Cores         = 960
;Warp size          = 32
;Block dimemsions   = 1024x1024x64
;Threads / Block    = 1024
;Texture units      = 80
;ROPs               = 24
;Base Clock         = 980 MHz
;Boost Clock        = 1033 MHz
;Texture Fill Rate  = 78.4 billion/sec

;Memory:
;VRAM               = 2048 MB
;L2 cache           = 384KB
;Shared / Block     = 48 KB
;Total constant     = 64 KB
;Controllers        = 3x64bit
;Tex. alignment     = 512 Bytes


;log_2(*inout, length):
;xind =  %ctaid.x * %ntid.x + %tid.x
;if xind < length , [inout + 4 * xind] = log2([inout + 4 * xind])
;return

CStr MessageFormat, "%16.7f"

.code
; ==================================================================================================
;    Application implementation
; ==================================================================================================

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Procedure:  LoadPtxRes
; Purpose:    Load a PTX from a resource.
; Arguments:  Arg1: Module instance handle where the resource is placed.
;             Arg2: -> Resource name.
; Return:     eax -> PTX.

LoadPtxRes proc hInst:HANDLE, pResName:PSTRING
  invoke FindResource, hInst, pResName, $OfsCStr("PTX")
  test xax, xax
  jz @F
  invoke LoadResource, hInst, xax
  test xax, xax
  jz @F
  invoke LockResource, xax
@@:
  ret
LoadPtxRes endp

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.Init
; Purpose:    Initialize the application object.
; Arguments:  None.
; Return:     Nothing.

CudaCheckResult macro
  test eax, eax
  jz @F
  DbgDec eax, "CUDA error number"
  lea xdx, pErrStr
  invoke cuGetErrorString, eax, xdx
  test eax, eax
  .if ZERO?
    DbgStrA pErrStr
  .endif
@@:
endm

Method Application.Init, uses xbx xdi xsi
  local CudaDevice:CUdevice, CudaModule:CUmodule, CudaFunction:CUfunction
  local CudaContext:CUcontext, CudaContextversion:DWORD
  local NumberArray       [256*sizeof(REAL4)]:REAL4
  local LogNumberArray    [256*sizeof(REAL4)]:REAL4
  local CudaLogNumberArray[256*sizeof(REAL4)]:REAL4, pCudaNumberArray:CUdeviceptr
  local Temp[32]:CHR, Message[1024*sizeof CHR]:CHR, pErrStr:PSTRING

  SetObject xsi
  ACall xsi.Init
  
  ;Fill in NumberArray and LogNumberArray with x87 calculations for comparision
  fld1
  fld1
  mov ecx, 256*sizeof(REAL4)
  lea xax, NumberArray
  add xax, xcx
  lea xbx, LogNumberArray
  add xbx, xcx
  neg xcx
  .while !ZERO?
    fst REAL4 ptr [xax + xcx]
    fld1
    fld  st(1)
    fyl2x
    fstp REAL4 ptr [xbx + xcx]
    fadd st, st(1)
    add xcx, sizeof(REAL4)
  .endw
  fcompp

  ;Initialize
  invoke cuInit, 0
  test eax, eax
  jnz @F
  invoke cuDeviceGet, addr CudaDevice, 0                  ;Returns a handle to a compute device
  CudaCheckResult
  invoke cuCtxCreate, addr CudaContext, CU_CTX_SCHED_SPIN or CU_CTX_MAP_HOST, CudaDevice  ;Get a CUDA context
  CudaCheckResult
  invoke cuCtxGetApiVersion, CudaContext, addr CudaContextversion
  CudaCheckResult

  ;Setup
  invoke cuMemAlloc, addr pCudaNumberArray, 256*sizeof(REAL4) ;Allocates n bytes of linear memory on the device
  CudaCheckResult
  if TARGET_BITNESS eq 32
    invoke LoadPtxRes, hInstance, $OfsCStr("LOG2_32")
  else
    invoke LoadPtxRes, hInstance, $OfsCStr("LOG2_64")
  endif
  invoke cuModuleLoadData, addr CudaModule, xax           ;offset @CatStr(<PTX_Log2_>, %TARGET_BITNESS)
  CudaCheckResult
  invoke cuModuleGetFunction, addr CudaFunction, CudaModule, $OfsCStrA("log_2")
  CudaCheckResult
  invoke cuMemcpyHtoD, pCudaNumberArray, addr NumberArray, 256*sizeof(REAL4)
  CudaCheckResult
  mov edi, sizeof(POINTER) + sizeof(DWORD)                ;Size of first & second agument
  invoke cuParamSetSize, CudaFunction, edi
  CudaCheckResult
  m2m POINTER ptr [Message + 0], pCudaNumberArray, xax    ;Fill in the arguments
  mov DWORD ptr [Message + sizeof(POINTER)], 256
  invoke cuParamSetv, CudaFunction, 0, addr Message, edi  ;Adds data to the function's argument list
  CudaCheckResult
  invoke cuFuncSetBlockShape, CudaFunction, 256, 1, 1     ;Sets the block-dimensions for the function
  CudaCheckResult

  ;Calculate
  invoke cuLaunchGrid, CudaFunction, 1, 1                 ;Invokes the kernel on a 1 x 1 x 1 grid of blocks
  CudaCheckResult
  invoke cuCtxSynchronize                                 ;Blocks until the device has completed all preceding requested tasks
  CudaCheckResult
  invoke cuMemcpyDtoH, addr CudaLogNumberArray, pCudaNumberArray, 256*sizeof(REAL4)
  CudaCheckResult

  ;Clean up
  invoke cuMemFree, pCudaNumberArray                      ;Frees device memory
  CudaCheckResult
  invoke cuCtxDestroy, CudaContext                        ;Destroy a CUDA context
  CudaCheckResult

  ;Build output message
  lea xdi, Message
  mov CHR ptr [xdi], 0                                    ;Set ZTC

  FillString CHR ptr [xdi], < 32bit floats: x       lg2.approx.f32(x)        fyl2x(x,1.0)>
  add xdi, 60*sizeof(CHR)
  mov CHR ptr [xdi], 10
  add xdi, sizeof(CHR)

  xor ebx, ebx
  .repeat
    lea xax, NumberArray
    fld REAL4 ptr [xax + sizeof(REAL4)*xbx]
    invoke St0ToStr, xdi, 0, 6, f_SCI
    fUnload
    invoke StrEnd, xdi
    mov DCHR ptr [xax], " " shl (8*sizeof(CHR)) + " "
    lea xdi, [xax + 2*sizeof(CHR)]

    lea xax, CudaLogNumberArray
    fld REAL4 ptr [xax + sizeof(REAL4)*xbx]
    invoke St0ToStr, xdi, 0, 6, f_SCI
    fUnload
    invoke StrEnd, xdi
    mov DCHR ptr [xax], " " shl (8*sizeof(CHR)) + " "
    lea xdi, [xax + 2*sizeof(CHR)]

    lea xax, LogNumberArray
    fld REAL4 ptr [xax + sizeof(REAL4)*xbx]
    invoke St0ToStr, xdi, 0, 6, f_SCI
    fUnload
    invoke StrEnd, xdi
    mov CHR ptr [xax], 10
    lea xdi, [xax + sizeof(CHR)]

    inc ebx
  .until ebx == 40
  mov CHR ptr [xdi], 0                                  ;Set ZTC

@@:

  invoke CreateDialogParam, hInstance, IDD_DLG_MAIN, 0, $MethodAddr(DlgApp.WndProc), xsi
  invoke SetDlgItemText, [xsi].hWnd, IDC_STC_MESSAGE, addr Message

MethodEnd

; ——————————————————————————————————————————————————————————————————————————————————————————————————
; Method:     Application.OnClose
; Purpose:    Event procedure for WM_CLOSE message.
; Arguments:  Arg1: First message parameter.
;             Arg2: Second message parameter.
; Return:     eax = Zero if handled.

Method Application.OnClose, uses xsi, wParam:WPARAM, lParam:LPARAM
  SetObject xsi
  invoke MessageBox, [xsi].hWnd, $OfsCStr("Are you sure ?"), $OfsCStr("Application exit"), \
                     MB_YESNO or MB_ICONQUESTION
  .if eax == IDNO
    xor eax, eax
  .else
    invoke DefWindowProc, [xsi].hWnd, WM_CLOSE, wParam, lParam
  .endif
MethodEnd