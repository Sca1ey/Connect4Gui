#include "MainFrame.h"
#include "App.h"
#include <wx/wx.h>
#include <vector>
#include "Game.h"

//Game* game = new Game();

enum {
    ID_Reset = 1
};

Game* game = new Game();

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

//event handler for Quit
void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
    
//event handler for the About menu option
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets version of Connect 4",
        "About Connect 4", wxOK | wxICON_INFORMATION);
}

//event handler for the Reset menu option
void MainFrame::OnReset(wxCommandEvent& event)
{
    SetStatusText(wxString::Format(wxT("Reset!")));
}

void MainFrame::CreateControls()
{   
    //create a panel to hold the controls
    wxPanel* panel = new wxPanel(this);
    
    //create a vector to hold the buttons
    std::vector<wxButton*> buttons;

    //generate buttons to fill the 6 * 7 grid of the connect 4 board
    for (int i = 0; i < 6 * 7; i++){
        int x = i % 7; //column
        int y = i / 7; //row
        wxString label = wxString::Format("x:%d / y:%d", x , y);
        wxButton* button = new wxButton(panel, i, label, wxDefaultPosition, wxSize(50,50));
        buttons.push_back(button);
    }
    
    //create a grid sizer with 7 columns, and add the buttons.
    wxGridSizer* gridSizer = new wxGridSizer(7);
    wxSizerFlags flags = wxSizerFlags().Border(wxALL,10).Expand(); //buttons have a border and fill their position
    for (wxButton* button : buttons){
        gridSizer->Add(button, flags);
    };
      
    //create a border box using a grid sizer of 1 column and add the grid sizer to it
    wxGridSizer* borderSizer = new wxGridSizer(1);
    borderSizer->Add(gridSizer,wxSizerFlags().Border(wxALL, 10).Expand());
    
    //add the sizers to the panel and set the size hints so the panel and frame size correctly
    panel->SetSizer(borderSizer);
    borderSizer->SetSizeHints(this);
  
    //bind the button events to the event handler
    for (wxButton* button : buttons){
        Bind(wxEVT_BUTTON, &MainFrame::OnButtonPress, this);
    };
}

//event handler for the buttons
void MainFrame::OnButtonPress(wxCommandEvent& event){
    int column = event.GetId() % 7;
    SetStatusText(wxString::Format("%d", column));
}