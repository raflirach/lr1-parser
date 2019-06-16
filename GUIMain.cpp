/***************************************************************
 * Name:      GUIMain.cpp
 * Purpose:   Code for Application Frame
 * Author:    rafli (rafli060395@gmail.com)
 * Created:   2019-06-15
 * Copyright: rafli ()
 * License:
 **************************************************************/

#include "GUIMain.h"
#include <wx/msgdlg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


char stack[40],string[40],input[40],action[40];
int i=0,c = 0, x=0, pos=0;

//(*InternalHeaders(GUIFrame)
#include <wx/bitmap.h>
#include <wx/font.h>
#include <wx/icon.h>
#include <wx/image.h>
#include <wx/intl.h>
#include <wx/string.h>
//*)

//helper functions
enum wxbuildinfoformat {
    short_f, long_f };

wxString wxbuildinfo(wxbuildinfoformat format)
{
    wxString wxbuild("");

    if (format == long_f )
    {
#if defined(__WXMSW__)
        wxbuild << _T("10116102\tMOHAMMAD RIZKI RAMADHAN\n");
        wxbuild << _T("10116110\tMUHAMAD IBNU TRI YUONO\n");
        wxbuild << _T("10116115\tADITYA KOMARA RAMADHAN\n");
        wxbuild << _T("10116127\tJEREMIA WELLY JUNIRO\n");
        wxbuild << _T("10116132\tRAFLI RACHMAWANDI\n");
        wxbuild << _T("\nRepository : \nhttps://github.com/raflirach/lr1-parser");
#elif defined(__UNIX__)
        wxbuild << _T("-Linux");
#endif

#if wxUSE_UNICODE
        wxbuild << _T("");
#else
        wxbuild << _T("-ANSI build");
#endif // wxUSE_UNICODE
    }

    return wxbuild;
}

//(*IdInit(GUIFrame)
const long GUIFrame::ID_GRID1 = wxNewId();
const long GUIFrame::ID_TEXTCTRL1 = wxNewId();
const long GUIFrame::ID_BUTTON1 = wxNewId();
const long GUIFrame::ID_STATICTEXT1 = wxNewId();
const long GUIFrame::ID_TEXTCTRL2 = wxNewId();
const long GUIFrame::ID_GRID2 = wxNewId();
const long GUIFrame::ID_RICHTEXTCTRL1 = wxNewId();
const long GUIFrame::ID_STATICTEXT2 = wxNewId();
const long GUIFrame::ID_STATICTEXT3 = wxNewId();
const long GUIFrame::ID_PANEL1 = wxNewId();
const long GUIFrame::ID_MENUITEM1 = wxNewId();
const long GUIFrame::idMenuAbout = wxNewId();
const long GUIFrame::ID_STATUSBAR1 = wxNewId();
//*)

BEGIN_EVENT_TABLE(GUIFrame,wxFrame)
    //(*EventTable(GUIFrame)
    //*)
END_EVENT_TABLE()

GUIFrame::GUIFrame(wxWindow* parent,wxWindowID id)
{
    //(*Initialize(GUIFrame)
    wxMenu* Menu1;
    wxMenu* Menu2;
    wxMenuBar* MenuBar1;
    wxMenuItem* MenuItem1;
    wxMenuItem* MenuItem2;

    Create(parent, wxID_ANY, _("LR(1) Parser"), wxDefaultPosition, wxDefaultSize, wxDEFAULT_FRAME_STYLE, _T("wxID_ANY"));
    SetClientSize(wxSize(800,600));
    {
    	wxIcon FrameIcon;
    	FrameIcon.CopyFromBitmap(wxBitmap(wxImage(_T("C:\\Users\\rafli\\Pictures\\logo.png"))));
    	SetIcon(FrameIcon);
    }
    Panel1 = new wxPanel(this, ID_PANEL1, wxDefaultPosition, wxSize(800,600), wxTAB_TRAVERSAL, _T("ID_PANEL1"));
    Panel1->SetBackgroundColour(wxColour(228,252,236));
    Grid1 = new wxGrid(Panel1, ID_GRID1, wxPoint(320,288), wxSize(469,264), wxVSCROLL, _T("ID_GRID1"));
    Grid1->CreateGrid(20,3);
    Grid1->EnableEditing(false);
    Grid1->EnableGridLines(true);
    Grid1->SetRowLabelSize(1);
    Grid1->SetDefaultColSize(150, true);
    Grid1->SetColLabelValue(0, _("STACK"));
    Grid1->SetColLabelValue(1, _("STRING"));
    Grid1->SetColLabelValue(2, _("ACTION"));
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    TextInput = new wxTextCtrl(Panel1, ID_TEXTCTRL1, _("abb"), wxPoint(450,160), wxSize(136,26), 0, wxDefaultValidator, _T("ID_TEXTCTRL1"));
    TextInput->SetFocus();
    wxFont TextInputFont(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    TextInput->SetFont(TextInputFont);
    Button1 = new wxButton(Panel1, ID_BUTTON1, _("Check String"), wxPoint(320,200), wxSize(160,34), 0, wxDefaultValidator, _T("ID_BUTTON1"));
    wxFont Button1Font(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Button1->SetFont(Button1Font);
    StaticText1 = new wxStaticText(Panel1, ID_STATICTEXT1, _("Input String :"), wxPoint(320,160), wxDefaultSize, 0, _T("ID_STATICTEXT1"));
    wxFont StaticText1Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText1->SetFont(StaticText1Font);
    txtStatus = new wxTextCtrl(Panel1, ID_TEXTCTRL2, _("NOT CHECKED"), wxPoint(320,248), wxSize(168,24), wxTE_READONLY|wxTE_CENTRE|wxNO_BORDER, wxDefaultValidator, _T("ID_TEXTCTRL2"));
    txtStatus->SetBackgroundColour(wxColour(255,0,0));
    wxFont txtStatusFont(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    txtStatus->SetFont(txtStatusFont);
    Grid2 = new wxGrid(Panel1, ID_GRID2, wxPoint(16,48), wxSize(285,497), 0, _T("ID_GRID2"));
    Grid2->CreateGrid(10,5);
    wxFont Grid2Font(16,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    Grid2->SetFont(Grid2Font);
    Grid2->EnableEditing(false);
    Grid2->EnableGridLines(true);
    Grid2->SetRowLabelSize(30);
    Grid2->SetDefaultRowSize(46, true);
    Grid2->SetDefaultColSize(50, true);
    Grid2->SetColLabelValue(0, _("a"));
    Grid2->SetColLabelValue(1, _("b"));
    Grid2->SetColLabelValue(2, _("$"));
    Grid2->SetColLabelValue(3, _("S"));
    Grid2->SetColLabelValue(4, _("A"));
    Grid2->SetRowLabelValue(0, _("i0"));
    Grid2->SetRowLabelValue(1, _("i1"));
    Grid2->SetRowLabelValue(2, _("i2"));
    Grid2->SetRowLabelValue(3, _("i3"));
    Grid2->SetRowLabelValue(4, _("i4"));
    Grid2->SetRowLabelValue(5, _("i5"));
    Grid2->SetRowLabelValue(6, _("i6"));
    Grid2->SetRowLabelValue(7, _("i7"));
    Grid2->SetRowLabelValue(8, _("i8"));
    Grid2->SetRowLabelValue(9, _("i9"));
    Grid2->SetCellValue(0, 0, _("s3"));
    Grid2->SetCellValue(0, 1, _("s4"));
    Grid2->SetCellValue(0, 2, wxEmptyString);
    Grid2->SetCellValue(0, 3, _("1"));
    Grid2->SetCellValue(0, 4, _("2"));
    Grid2->SetCellValue(1, 0, wxEmptyString);
    Grid2->SetCellValue(1, 1, wxEmptyString);
    Grid2->SetCellValue(1, 2, _("ACC"));
    Grid2->SetCellValue(1, 3, wxEmptyString);
    Grid2->SetCellValue(1, 4, wxEmptyString);
    Grid2->SetCellValue(2, 0, _("s6"));
    Grid2->SetCellValue(2, 1, _("s7"));
    Grid2->SetCellValue(2, 2, wxEmptyString);
    Grid2->SetCellValue(2, 3, wxEmptyString);
    Grid2->SetCellValue(2, 4, _("5"));
    Grid2->SetCellValue(3, 0, _("s3"));
    Grid2->SetCellValue(3, 1, _("s4"));
    Grid2->SetCellValue(3, 2, wxEmptyString);
    Grid2->SetCellValue(3, 3, wxEmptyString);
    Grid2->SetCellValue(3, 4, _("8"));
    Grid2->SetCellValue(4, 0, _("r3"));
    Grid2->SetCellValue(4, 1, _("r3"));
    Grid2->SetCellValue(4, 2, wxEmptyString);
    Grid2->SetCellValue(4, 3, wxEmptyString);
    Grid2->SetCellValue(4, 4, wxEmptyString);
    Grid2->SetCellValue(5, 0, wxEmptyString);
    Grid2->SetCellValue(5, 1, wxEmptyString);
    Grid2->SetCellValue(5, 2, _("r1"));
    Grid2->SetCellValue(5, 3, wxEmptyString);
    Grid2->SetCellValue(5, 4, wxEmptyString);
    Grid2->SetCellValue(6, 0, _("s6"));
    Grid2->SetCellValue(6, 1, _("s7"));
    Grid2->SetCellValue(6, 2, wxEmptyString);
    Grid2->SetCellValue(6, 3, wxEmptyString);
    Grid2->SetCellValue(6, 4, _("9"));
    Grid2->SetCellValue(7, 0, wxEmptyString);
    Grid2->SetCellValue(7, 1, wxEmptyString);
    Grid2->SetCellValue(7, 2, _("r3"));
    Grid2->SetCellValue(7, 3, wxEmptyString);
    Grid2->SetCellValue(7, 4, wxEmptyString);
    Grid2->SetCellValue(8, 0, _("r2"));
    Grid2->SetCellValue(8, 1, _("r2"));
    Grid2->SetCellValue(8, 2, wxEmptyString);
    Grid2->SetCellValue(8, 3, wxEmptyString);
    Grid2->SetCellValue(8, 4, wxEmptyString);
    Grid2->SetCellValue(9, 0, wxEmptyString);
    Grid2->SetCellValue(9, 1, wxEmptyString);
    Grid2->SetCellValue(9, 2, _("r2"));
    Grid2->SetDefaultCellFont( Grid2->GetFont() );
    Grid2->SetDefaultCellTextColour( Grid2->GetForegroundColour() );
    RichTextCtrl1 = new wxRichTextCtrl(Panel1, ID_RICHTEXTCTRL1, _("[1] : S -> A A\n[2] : a -> a A\n[3] : a -> b"), wxPoint(320,48), wxSize(456,104), wxRE_MULTILINE, wxDefaultValidator, _T("ID_RICHTEXTCTRL1"));
    wxRichTextAttr rchtxtAttr_1;
    rchtxtAttr_1.SetBulletStyle(wxTEXT_ATTR_BULLET_STYLE_ALIGN_LEFT);
    wxFont Font_1(12,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_NORMAL,false,_T("Arial"),wxFONTENCODING_DEFAULT);
    rchtxtAttr_1.SetFontFaceName(Font_1.GetFaceName());
    rchtxtAttr_1.SetFontSize(Font_1.GetPointSize());
    rchtxtAttr_1.SetFontStyle(Font_1.GetStyle());
    rchtxtAttr_1.SetFontUnderlined(Font_1.GetUnderlined());
    rchtxtAttr_1.SetFontWeight(Font_1.GetWeight());
    RichTextCtrl1->SetBasicStyle(rchtxtAttr_1);
    RichTextCtrl1->Disable();
    StaticText2 = new wxStaticText(Panel1, ID_STATICTEXT2, _("PARSER TABLE"), wxPoint(16,16), wxSize(82,13), 0, _T("ID_STATICTEXT2"));
    wxFont StaticText2Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText2->SetFont(StaticText2Font);
    StaticText3 = new wxStaticText(Panel1, ID_STATICTEXT3, _("RULE"), wxPoint(320,16), wxDefaultSize, 0, _T("ID_STATICTEXT3"));
    wxFont StaticText3Font(14,wxFONTFAMILY_SWISS,wxFONTSTYLE_NORMAL,wxFONTWEIGHT_BOLD,false,wxEmptyString,wxFONTENCODING_DEFAULT);
    StaticText3->SetFont(StaticText3Font);
    MenuBar1 = new wxMenuBar();
    Menu1 = new wxMenu();
    MenuItem1 = new wxMenuItem(Menu1, ID_MENUITEM1, _("Quit\tAlt-F4"), _("Quit the application"), wxITEM_NORMAL);
    Menu1->Append(MenuItem1);
    MenuBar1->Append(Menu1, _("&File"));
    Menu2 = new wxMenu();
    MenuItem2 = new wxMenuItem(Menu2, idMenuAbout, _("About\tF1"), _("Show info about this application"), wxITEM_NORMAL);
    Menu2->Append(MenuItem2);
    MenuBar1->Append(Menu2, _("Help"));
    SetMenuBar(MenuBar1);
    StatusBar1 = new wxStatusBar(this, ID_STATUSBAR1, 0, _T("ID_STATUSBAR1"));
    int __wxStatusBarWidths_1[1] = { -1 };
    int __wxStatusBarStyles_1[1] = { wxSB_NORMAL };
    StatusBar1->SetFieldsCount(1,__wxStatusBarWidths_1);
    StatusBar1->SetStatusStyles(1,__wxStatusBarStyles_1);
    SetStatusBar(StatusBar1);
    Center();

    Connect(ID_GRID1,wxEVT_GRID_CELL_LEFT_CLICK,(wxObjectEventFunction)&GUIFrame::OnGrid1CellLeftClick1);
    Connect(ID_BUTTON1,wxEVT_COMMAND_BUTTON_CLICKED,(wxObjectEventFunction)&GUIFrame::OnButton1Click);
    Connect(ID_MENUITEM1,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GUIFrame::OnQuit);
    Connect(idMenuAbout,wxEVT_COMMAND_MENU_SELECTED,(wxObjectEventFunction)&GUIFrame::OnAbout);
    //*)
}

GUIFrame::~GUIFrame()
{
    //(*Destroy(GUIFrame)
    //*)
}

void GUIFrame::OnQuit(wxCommandEvent& event)
{
    Close();
}

void GUIFrame::OnAbout(wxCommandEvent& event)
{
    wxString msg = wxbuildinfo(long_f);
    wxMessageBox(msg, _("Anggota Kelompok..."));
}


void GUIFrame::OnGrid1CellLeftClick1(wxGridEvent& event)
{

}

void check_reduce()
{
    if(stack[strlen(stack)-1] == 'A' && stack[strlen(stack)-2] == '0')
        {
            stack[strlen(stack)] = '2';
            stack[strlen(stack)] = '\0';
        }
        else if(stack[strlen(stack)-1] == 'A' && stack[strlen(stack)-2] == '2')
        {
            stack[strlen(stack)] = '5';
            stack[strlen(stack)] = '\0';
        }
        else if(stack[strlen(stack)-1] == 'A' && stack[strlen(stack)-2] == '3')
        {
            stack[strlen(stack)] = '8';
            stack[strlen(stack)] = '\0';
        }
        else if(stack[strlen(stack)-1] == 'A' && stack[strlen(stack)-2] == '6')
        {
            stack[strlen(stack)] = '9';
            stack[strlen(stack)] = '\0';
        }
}
void check()
{
    if((stack[strlen(stack)-1] == '0' && string[pos]=='a')
       ||(stack[strlen(stack)-1] == '3' && string[pos]=='a'))
    {
        strcpy(action, "s3");
        stack[strlen(stack)] = string[pos];
        stack[strlen(stack)] = '3';
        stack[strlen(stack)+1] = '\0';

        string[pos] = ' ';
        pos=pos+1;
    }
    else if((stack[strlen(stack)-1] == '0' && string[pos]=='b')
            ||(stack[strlen(stack)-1] == '3' && string[pos]=='b'))
    {
        strcpy(action, "s4");
        stack[strlen(stack)] = string[pos];
        stack[strlen(stack)] = '4';
        stack[strlen(stack)+1] = '\0';

        string[pos] = ' ';
        pos=pos+1;
    }
    else if((stack[strlen(stack)-1] == '2' && string[pos]=='a')
            ||(stack[strlen(stack)-1] == '6' && string[pos]=='a'))
    {
        strcpy(action, "s6");
        stack[strlen(stack)] = string[pos];
        stack[strlen(stack)] = '6';
        stack[strlen(stack)] = '\0';

        string[pos] = ' ';
        pos=pos+1;
    }
    else if((stack[strlen(stack)-1] == '2' && string[pos]=='b')
            ||(stack[strlen(stack)-1] == '6' && string[pos]=='b'))
    {
        strcpy(action, "s7");
        stack[strlen(stack)] = string[pos];
        stack[strlen(stack)] = '7';
        stack[strlen(stack)] = '\0';

        string[pos] = ' ';
        pos=pos+1;
    }
    else if((stack[strlen(stack)-1] == '4' && string[pos]=='b')
            ||(stack[strlen(stack)-1] == '4' && string[pos]=='a')
            ||(stack[strlen(stack)-1] == '7' && string[pos]=='$'))
    {
        strcpy(action, "r3");
        stack[strlen(stack)-2] = 'A';
        stack[strlen(stack)-1] = '\0';
        stack[strlen(stack)+1] = '\0';

        check_reduce();
    }
    else if((stack[strlen(stack)-1] == '8' && string[pos]=='b')
            ||(stack[strlen(stack)-1] == '8' && string[pos]=='a')
            ||(stack[strlen(stack)-1] == '9' && string[pos]=='$'))
    {
        strcpy(action, "r2");
        stack[strlen(stack)-4] = 'A';
        stack[strlen(stack)-3] = '\0';
        stack[strlen(stack)+1] = '\0';
        stack[strlen(stack)+2] = '\0';

        check_reduce();
    }
    else if(stack[strlen(stack)-1] == '5' && string[pos]=='$')
    {
        strcpy(action, "r1");
        stack[strlen(stack)-4] = 'S';
        stack[strlen(stack)-3] = '1';
        stack[strlen(stack)-2] = '\0';
        stack[strlen(stack)+1] = '\0';
    }
    else if(stack[strlen(stack)-1] == '1' && string[pos]=='$')
    {
        strcpy(action, "ACCEPTED");
        x=x+1;
        pos=pos+1;
    }
    else
    {
        strcpy(action, "REJECTED");
    }
    return;
}

void GUIFrame::OnButton1Click(wxCommandEvent& event)
{
    //clear
    Grid1->DeleteCols(0,3,true);
    Grid1->DeleteRows(0,20,true);
    Grid1 = new wxGrid(Panel1, ID_GRID1, wxPoint(320,288), wxSize(469,264), wxVSCROLL, _T("ID_GRID1"));
    Grid1->CreateGrid(20,3);
    Grid1->EnableEditing(false);
    Grid1->EnableGridLines(true);
    Grid1->SetRowLabelSize(1);
    Grid1->SetDefaultColSize(150, true);
    Grid1->SetColLabelValue(0, _("STACK"));
    Grid1->SetColLabelValue(1, _("STRING"));
    Grid1->SetColLabelValue(2, _("ACTION"));
    Grid1->SetDefaultCellFont( Grid1->GetFont() );
    Grid1->SetDefaultCellTextColour( Grid1->GetForegroundColour() );
    for(i = 0; stack[i] != '\0'; ++i)
    {
        stack[i] = '\0';
    };
    for(i = 0; string[i] != '\0'; ++i)
    {
        string[i] = '\0';
    };
    for(i = 0; action[i] != '\0'; ++i)
    {
        action[i] = '\0';
    };
    pos=0;
    i=0;

    //start
    strcpy(string, TextInput->GetValue());
    c = strlen(string);
    string[c]='$';
    strcpy(stack, "0");

    while(strcmp(action,"ACCEPTED") && strcmp(action,"REJECTED"))
	{
       Grid1->SetCellValue(i, 0, _(stack));
       Grid1->SetCellValue(i, 1, _(string));
       check();
       Grid1->SetCellValue(i, 2, _(action));
       i++;
    }
    txtStatus->SetValue(action);
}


