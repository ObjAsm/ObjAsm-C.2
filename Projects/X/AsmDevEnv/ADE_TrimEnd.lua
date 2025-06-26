-- Purpose: Trim spaces at the end of each line.
 
Application.FreezeUI()
--Input = Application.InpBox("Enter the file name", "Input")
--Application.DbgPrintLn("Input", Input) 
hEdit = Application.NewEditor("Test_Big_1.txt")
Editor.Show(hEdit)
for i = 1, Editor.GetLineCount(hEdit), 1
do
  LineContent = Editor.GetLineText(hEdit, i)
  j = string.len(LineContent)
  k = j
  while (j > 0) 
  do
    if string.sub(LineContent, j, j) ~= " " then break end
    j = j - 1
  end
  if k ~= j then Editor.SetLineText(hEdit, i, string.sub(LineContent, 1, j)) end
end
--Editor.Close(hEdit)
Application.UnfreezeUI()
--Application.MsgBox("Operation successfully finished.", "Information", 0)


--1156 ms for 250000 lines
--JJ: 32 ms for 48370 lines => 165 ms for 250000 lines
