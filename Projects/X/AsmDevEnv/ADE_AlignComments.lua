-- Title: ADE_Tab2Spc.lua
-- Purpose: Align comments that dont start at the line begin to a given position each line.
-- Author: G. Friedrich
-- Version 1.0, July 2025

CommentPos = 57

Application.FreezeUI()
hEdit = Application.GetActiveEditor()  
if hEdit ~= nil then
  Editor.Show(hEdit)
  for i = 1, Editor.GetLineCount(hEdit)
  do
    LineContent = Editor.GetLineText(hEdit, i)
    StartPos = string.find(LineContent, ";", 50, true)
    if StartPos ~= nil then
      if StartPos < CommentPos then
        Editor.SetLineText(hEdit, i, string.sub(LineContent, 1, StartPos - 1)..string.rep(" ", CommentPos-StartPos)..string.sub(LineContent, StartPos, -1))
      end
    end
  end
else
  Application.MsgBox("There is no active window", "Error", 16)
end
Application.UnfreezeUI()

