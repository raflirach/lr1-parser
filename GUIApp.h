/***************************************************************
 * Name:      GUIApp.h
 * Purpose:   Defines Application Class
 * Author:    rafli (rafli060395@gmail.com)
 * Created:   2019-06-15
 * Copyright: rafli ()
 * License:
 **************************************************************/

#ifndef GUIAPP_H
#define GUIAPP_H

#include <wx/app.h>

class GUIApp : public wxApp
{
    public:
        virtual bool OnInit();
};

#endif // GUIAPP_H
