$listener = [System.Net.Sockets.TcpListener]2323
$listener.Start()
$client = $listener.AcceptTcpClient()
$stream = $client.GetStream()
$writer = New-Object System.IO.StreamWriter($stream)
$reader = New-Object System.IO.StreamReader($stream)

$writer.AutoFlush = $true
$writer.WriteLine("Connected to Windows test server")

while ($true) {
    $line = $reader.ReadLine()
    if ($line -eq $null) { break }
    $writer.WriteLine("You said: $line")
}