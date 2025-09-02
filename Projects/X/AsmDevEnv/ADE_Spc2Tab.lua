-- Title: ADE_Tab2Spc.lua
-- Purpose: Replace spaces with tabs in each line.
-- Author: G. Friedrich
-- Version 1.0, July 2025

Application.FreezeUI()
hEdit = Application.GetActiveEditor()
if hEdit ~= nil then
  Editor.Show(hEdit)
  for i = 1, Editor.GetLineCount(hEdit), 1
  do
    LineContent = Editor.GetLineText(hEdit, i)
    LineContent, j = string.gsub(LineContent, string.rep(" ", 2), string.char(9))
    if j ~= 0 then Editor.SetLineText(hEdit, i, LineContent) end
  end
else
  Application.MsgBox("There is no active window", "Error", 16)
end
Application.UnfreezeUI()

