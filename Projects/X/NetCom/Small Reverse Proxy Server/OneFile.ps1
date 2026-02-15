$files = @(
    "$env:OBJASM_PATH\Code\Objects\NetCom.inc"
    "$env:OBJASM_PATH\Code\Objects\NetComEngine.inc"
    "$env:OBJASM_PATH\Code\Objects\NetComConnection.inc"
	"$env:OBJASM_PATH\Code\Objects\NetComConnectionPool.inc"
	"$env:OBJASM_PATH\Code\Objects\NetComIOSockJobPool.inc"
	"$env:OBJASM_PATH\Code\Objects\NetComProtocol.inc"
	"$env:OBJASM_PATH\Code\Objects\NetComAddrCollection.inc"
	"$env:OBJASM_PATH\Projects\X\NetCom\Small Reverse Proxy Server\SRPS.asm"
	"$env:OBJASM_PATH\Projects\X\NetCom\Small Reverse Proxy Server\SRPS_Main.inc"
	"$env:OBJASM_PATH\Projects\X\NetCom\Small Reverse Proxy Server\SRPS_Protocol.inc"
)

Get-Content $files -Raw | Set-Content "$env:OBJASM_PATH\Projects\X\NetCom\Small Reverse Proxy Server\SRPS_Combined.txt"