-- Title: ADE_LowerCase.lua
-- Purpose: Converts the selection to lowercase.
-- Author: G. Friedrich
-- Version 1.0, July 2025

Application.FreezeUI()
hEdit = Application.GetActiveEditor()
if hEdit ~= nil then
  Editor.Show(hEdit)
  FirstLine, LastLine = Editor.GetSelLineRange(hEdit)
  if FirstLine ~= 0 then 
    for i = FirstLine, LastLine, 1
    do
      LineText = Editor.GetLineText(hEdit, i)
      FirstChar, LastChar = Editor.GetLineSelRange(hEdit, i)
      if LastChar == -1 then
        LastChar = string.len(LineText) - 1
      end
      LineText = string.sub(LineText, 1, FirstChar)..string.lower(string.sub(LineText, FirstChar + 1, LastChar + 1))..string.sub(LineText, LastChar + 2, -1)
      Editor.SetLineText(hEdit, i, LineText)
    end
  else
    Application.MsgBox("There is no selection in the active editor", "Error", 16)
  end
else
  Application.MsgBox("There is no active window", "Error", 16)
end            
Application.UnfreezeUI()    
