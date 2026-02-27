#pragma once
//#include "Game.h"
#include <wx/wx.h>

class MainFrame : public wxFrame
{
    public:
        MainFrame(const wxString& title);

        void OnAbout(wxCommandEvent& event);
        void OnReset(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);

    private:
        void CreateMenus();
        void CreateControls();
};