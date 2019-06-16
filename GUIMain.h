/***************************************************************
 * Name:      GUIMain.h
 * Purpose:   Defines Application Frame
 * Author:    rafli (rafli060395@gmail.com)
 * Created:   2019-06-15
 * Copyright: rafli ()
 * License:
 **************************************************************/

#ifndef GUIMAIN_H
#define GUIMAIN_H

//(*Headers(GUIFrame)
#include <wx/button.h>
#include <wx/frame.h>
#include <wx/grid.h>
#include <wx/menu.h>
#include <wx/panel.h>
#include <wx/richtext/richtextctrl.h>
#include <wx/stattext.h>
#include <wx/statusbr.h>
#include <wx/textctrl.h>
//*)

class GUIFrame: public wxFrame
{
    public:

        GUIFrame(wxWindow* parent,wxWindowID id = -1);
        virtual ~GUIFrame();

    private:

        //(*Handlers(GUIFrame)
        void OnQuit(wxCommandEvent& event);
        void OnAbout(wxCommandEvent& event);
        void OnGrid1CellLeftClick(wxGridEvent& event);
        void OnGrid1CellLeftClick1(wxGridEvent& event);
        void OnTextCtrl1Text(wxCommandEvent& event);
        void OnButton1Click(wxCommandEvent& event);
        void OnRichTextCtrl1Text(wxCommandEvent& event);
        //*)

        //(*Identifiers(GUIFrame)
        static const long ID_GRID1;
        static const long ID_TEXTCTRL1;
        static const long ID_BUTTON1;
        static const long ID_STATICTEXT1;
        static const long ID_TEXTCTRL2;
        static const long ID_GRID2;
        static const long ID_RICHTEXTCTRL1;
        static const long ID_STATICTEXT2;
        static const long ID_STATICTEXT3;
        static const long ID_PANEL1;
        static const long ID_MENUITEM1;
        static const long idMenuAbout;
        static const long ID_STATUSBAR1;
        //*)

        //(*Declarations(GUIFrame)
        wxButton* Button1;
        wxGrid* Grid1;
        wxGrid* Grid2;
        wxPanel* Panel1;
        wxRichTextCtrl* RichTextCtrl1;
        wxStaticText* StaticText1;
        wxStaticText* StaticText2;
        wxStaticText* StaticText3;
        wxStatusBar* StatusBar1;
        wxTextCtrl* TextInput;
        wxTextCtrl* txtStatus;
        //*)

        DECLARE_EVENT_TABLE()
};

#endif // GUIMAIN_H
