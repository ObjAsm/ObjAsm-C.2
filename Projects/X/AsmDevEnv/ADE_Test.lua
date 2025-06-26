-- Purpose: Testing.
 
--Application.FreezeUI()
hEdit = Application.NewEditor("Test_Big_1.txt")
for x=5,15,1
do
  Attr = Editor.GetLineAttr(hEdit, x)
  Attr = Attr & 64
  Editor.SetLineAttr(hEdit, x, Attr)
end

for x=5,15,1
do
  Attr = Editor.GetLineAttr(hEdit, x)
  Attr = Attr & (-64-1)
  Application.DbgPrintLn("",Attr)
  Editor.SetLineAttr(hEdit, x, Attr)
end
  
Editor.Show(hEdit)
--Application.UnfreezeUI()
