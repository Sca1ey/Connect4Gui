#include "MainFrame.h"
#include "App.h"
#include <wx/wx.h>
//#include "Game.h"

//Game* game = new Game();

//MainFrame Constructor
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{       
    MainFrame::CreateControls();
}

MainFrame::CreateControls()
{
    
}