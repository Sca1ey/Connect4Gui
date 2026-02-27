#include "MainFrame.h"
#include "App.h"
#include <wx/wx.h>
#include <vector>
//#include "Game.h"

//Game* game = new Game();

enum {
    ID_Reset = 1
};

//MainFrame Constructor
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{       
    MainFrame::CreateMenus();
    MainFrame::CreateControls();
}

void MainFrame::CreateMenus()
{
    //File menu
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Reset, "&Reset\tCtrl-R","Reset the game!");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
        
    //Help Menu
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    
    //Add menus to menu bar
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile, "&File");
    menuBar->Append(menuHelp, "&Help");
    
    //Add menubar to frame
    SetMenuBar( menuBar );
    
    //Create Status bar and set inital text
    CreateStatusBar();
    int currPlayer = 1; //game->GetPlayer();
    SetStatusText(wxString::Format(wxT("Player %d's turn."),currPlayer));

    //Bind event handlers for menu 
    Bind(wxEVT_MENU, &MainFrame::OnReset, this, ID_Reset);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
}

void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
    
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets version of Connect 4",
        "About Connect 4", wxOK | wxICON_INFORMATION);
}
        
void MainFrame::OnReset(wxCommandEvent& event)
{
    SetStatusText(wxString::Format(wxT("Reset!")));
}

void MainFrame::CreateControls()
{   
    wxPanel* panel = new wxPanel(this);
    std::vector<wxButton*> buttons;

    for (int i = 0; i < 6 * 7; i++){
        int remainder = i % 7;
        wxString label = wxString::Format("B %d", remainder);
        wxButton* button = new wxButton(panel, i, label, wxDefaultPosition, wxSize(50,50));
        buttons.push_back(button);
    }
    
    wxGridSizer* gridSizer = new wxGridSizer(7);
    wxSizerFlags flags = wxSizerFlags().Border(wxALL,10).Expand();
    for (wxButton* button : buttons){
        gridSizer->Add(button, flags);
    };
      
    wxGridSizer* borderSizer = new wxGridSizer(1);
    borderSizer->Add(gridSizer,wxSizerFlags().Border(wxALL, 10).Expand());
    panel->SetSizer(borderSizer);
    borderSizer->SetSizeHints(this);
  
    for (wxButton* button : buttons){
        Bind(wxEVT_BUTTON, &MainFrame::OnButtonPress, this);
    };
}

void MainFrame::OnButtonPress(wxCommandEvent& event){
    int column = event.GetId() % 7;
    SetStatusText(wxString::Format("%d", column));
}