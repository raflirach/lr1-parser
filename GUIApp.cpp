/***************************************************************
 * Name:      GUIApp.cpp
 * Purpose:   Code for Application Class
 * Author:    rafli (rafli060395@gmail.com)
 * Created:   2019-06-15
 * Copyright: rafli ()
 * License:
 **************************************************************/

#include "GUIApp.h"

//(*AppHeaders
#include "GUIMain.h"
#include <wx/image.h>
//*)

IMPLEMENT_APP(GUIApp);

bool GUIApp::OnInit()
{
    //(*AppInitialize
    bool wxsOK = true;
    wxInitAllImageHandlers();
    if ( wxsOK )
    {
    	GUIFrame* Frame = new GUIFrame(0);
    	Frame->Show();
    	SetTopWindow(Frame);
    }
    //*)
    return wxsOK;

}
