/*
Copyright (c) 2004, 2005, 2006 The FlameRobin Development Team

Permission is hereby granted, free of charge, to any person obtaining
a copy of this software and associated documentation files (the
"Software"), to deal in the Software without restriction, including
without limitation the rights to use, copy, modify, merge, publish,
distribute, sublicense, and/or sell copies of the Software, and to
permit persons to whom the Software is furnished to do so, subject to
the following conditions:

The above copyright notice and this permission notice shall be included
in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND,
EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF
MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.
IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY
CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT,
TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE
SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.


  $Id$

*/

#ifndef FR_DATAGRID_H
#define FR_DATAGRID_H

#include <wx/wx.h>
#include <wx/grid.h>

//----------------------------------------------------------------------
class DataGrid: public wxGrid {
public:
    DataGrid(wxWindow* parent, wxWindowID id);
    ~DataGrid();

    void fill(const wxString& connectionCharset);

public:
    enum { ID_MENU_CELLFONT, ID_MENU_LABELFONT,
        ID_MENU_COPYTOCLIPBOARD, ID_MENU_COPYTOCLIPBOARDASINSERT,
        ID_MENU_SAVEASHTML };

    void OnMouseWheel(wxMouseEvent& event);
    void OnThumbRelease(wxScrollWinEvent& event);
    void OnContextMenu(wxContextMenuEvent& event);
    void OnGridCellRightClick(wxGridEvent& event);
    void OnGridLabelRightClick(wxGridEvent& event);
    void OnIdle(wxIdleEvent& event);
    void OnMenuCellFont(wxCommandEvent& event);
    void OnMenuCopyToCB(wxCommandEvent& event);
    void OnMenuCopyToCBAsInsert(wxCommandEvent& event);
    void OnMenuLabelFont(wxCommandEvent& event);
    void OnMenuSaveAsHTML(wxCommandEvent& event);
    void OnMenuUpdateIfHasSelection(wxUpdateUIEvent& event);
private:
    void copyToClipboard(const wxString cbText);
    void showPopMenu(wxPoint cursorPos);
    void updateRowHeights();

    DECLARE_EVENT_TABLE()
};
//----------------------------------------------------------------------
#endif