#pragma once
#include <wx/wx.h>
#include "App.h"
#include "Game.h"
#include <vector>

class MainFrame : public wxFrame
{
    public:
        MainFrame(const wxString& title);

        void OnAbout(wxCommandEvent& event);
        void OnReset(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);
        void OnButtonPress(wxCommandEvent& event);
        void BindButtons();
        void UnbindButtons();

    private:
        void CreateMenus();
        void CreateControls();
        
        std::vector<wxButton*> buttons;
};