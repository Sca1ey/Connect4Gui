#pragma once
#include "Game.h"
#include <wx/wx.h>

class MainFrame : public wxFrame
{
    public:
        MainFrame(const wxString& title);

    private:
        void CreateMenus();
        void CreateControls();
        void BindMenuEventHandlers();
        void BindButtonEventHandlers();
        void UnbindButtonEventHandlers();
        void PlayPosition(wxButton*, int, int);
    
        void OnAbout(wxCommandEvent& event);
        void OnReset(wxCommandEvent& event);
        void OnExit(wxCommandEvent& event);

        void Button1(wxCommandEvent& event);
        void Button2(wxCommandEvent& event);
        void Button3(wxCommandEvent& event);
        void Button4(wxCommandEvent& event);
        void Button5(wxCommandEvent& event);
        void Button6(wxCommandEvent& event);
        void Button7(wxCommandEvent& event);
        void Button8(wxCommandEvent& event);
        void Button9(wxCommandEvent& event);
        
        wxGridSizer* grid;
        
        wxButton* button1;
        wxButton* button2;
        wxButton* button3;
        wxButton* button4;
        wxButton* button5;
        wxButton* button6;
        wxButton* button7;
        wxButton* button8;
        wxButton* button9;

        wxGridSizer* border;
};