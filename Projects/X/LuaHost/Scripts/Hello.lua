Output.Clear()
MyString = " Hello World from ObjAsm Host "

Output.SetTextColor(RGB(255,255,0))
Output.SetBackColor(RGB(255,0,0))
Output.SetFont("Arial", 20, FONT_BOLD)
Output.Write(MyString)
Output.SetFont("Arial", 20, FONT_SUPERSCRIPT)
Output.WriteLn("TM ")
 