-- Purpose: Testing.
 
--Application.FreezeUI()
hEdit = Application.NewEditor("Test_Big_1.txt")
Editor.Show(hEdit)
Editor.SelSet(hEdit, 10,3,-1,11)
CharIndex, LineNumber = Editor.GetViewLocation(hEdit, 0)
Application.DbgPrintLn("", CharIndex..","..LineNumber)
Editor.SetViewLocation(hEdit, 0, 10, 10)
--Application.UnfreezeUI()
