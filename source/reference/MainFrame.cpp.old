#include "MainFrame.h"
#include "App.h"
#include <wx/wx.h>
#include "Game.h"

Game* game = new Game();

enum {
    ID_Reset = 1
};

// Define the contents of the Frame in its constructor
MainFrame::MainFrame(const wxString& title) : wxFrame(nullptr, wxID_ANY, title)
{       
    MainFrame::CreateMenus();
    MainFrame::CreateControls();
    MainFrame::BindMenuEventHandlers();
    MainFrame::BindButtonEventHandlers();
    game->InitBoard();
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
    int currPlayer = game->GetPlayer();
    SetStatusText(wxString::Format(wxT("Player %d's turn."),currPlayer));
}

void MainFrame::CreateControls()
{
    //Create GridSizer with 3 columns
    grid = new wxGridSizer(3,10,10);
    
    //create buttons
    button1 = new wxButton(this, wxID_ANY,"");
    button2 = new wxButton(this, wxID_ANY,"");
    button3 = new wxButton(this, wxID_ANY,"");
    button4 = new wxButton(this, wxID_ANY,"");
    button5 = new wxButton(this, wxID_ANY,"");
    button6 = new wxButton(this, wxID_ANY,"");
    button7 = new wxButton(this, wxID_ANY,"");
    button8 = new wxButton(this, wxID_ANY,"");
    button9 = new wxButton(this, wxID_ANY,"");
    
    //Add buttons to grid
    wxSizerFlags flags = wxSizerFlags().Expand();    
    grid->Add(button1, flags);
    grid->Add(button2, flags);
    grid->Add(button3, flags);
    grid->Add(button4, flags);
    grid->Add(button5, flags);
    grid->Add(button6, flags);
    grid->Add(button7, flags);
    grid->Add(button8, flags);
    grid->Add(button9, flags);
    
    border = new wxGridSizer(1);
    border->Add(grid, wxSizerFlags().Border(wxALL, 10).Expand());
    
    this->SetSizer(border);
    border->SetSizeHints(this);
}

void MainFrame::BindMenuEventHandlers()
{
    //Bind event handlers for menu 
    Bind(wxEVT_MENU, &MainFrame::OnReset, this, ID_Reset);
    Bind(wxEVT_MENU, &MainFrame::OnAbout, this, wxID_ABOUT);
    Bind(wxEVT_MENU, &MainFrame::OnExit, this, wxID_EXIT);
}

void MainFrame::BindButtonEventHandlers()
{
    button1->Bind(wxEVT_BUTTON, &MainFrame::Button1, this);
    button2->Bind(wxEVT_BUTTON, &MainFrame::Button2, this);
    button3->Bind(wxEVT_BUTTON, &MainFrame::Button3, this);
    button4->Bind(wxEVT_BUTTON, &MainFrame::Button4, this);
    button5->Bind(wxEVT_BUTTON, &MainFrame::Button5, this);
    button6->Bind(wxEVT_BUTTON, &MainFrame::Button6, this);
    button7->Bind(wxEVT_BUTTON, &MainFrame::Button7, this);
    button8->Bind(wxEVT_BUTTON, &MainFrame::Button8, this);
    button9->Bind(wxEVT_BUTTON, &MainFrame::Button9, this);
}

void MainFrame::UnbindButtonEventHandlers()
{
    //Bind event handlers for buttons
    button1->Unbind(wxEVT_BUTTON, &MainFrame::Button1, this);
    button2->Unbind(wxEVT_BUTTON, &MainFrame::Button2, this);
    button3->Unbind(wxEVT_BUTTON, &MainFrame::Button3, this);
    button4->Unbind(wxEVT_BUTTON, &MainFrame::Button4, this);
    button5->Unbind(wxEVT_BUTTON, &MainFrame::Button5, this);
    button6->Unbind(wxEVT_BUTTON, &MainFrame::Button6, this);
    button7->Unbind(wxEVT_BUTTON, &MainFrame::Button7, this);
    button8->Unbind(wxEVT_BUTTON, &MainFrame::Button8, this);
    button9->Unbind(wxEVT_BUTTON, &MainFrame::Button9, this);
}
    
void MainFrame::OnExit(wxCommandEvent& event)
{
    Close(true);
}
    
void MainFrame::OnAbout(wxCommandEvent& event)
{
    wxMessageBox("This is a wxWidgets version of Noughts and Crosses",
        "About Noughts and Crosses", wxOK | wxICON_INFORMATION);
}
        
void MainFrame::OnReset(wxCommandEvent& event)
{
    game->InitBoard();
    game->ResetTurns();
    button1->SetLabel("");
    button2->SetLabel("");
    button3->SetLabel("");
    button4->SetLabel("");
    button5->SetLabel("");
    button6->SetLabel("");
    button7->SetLabel("");
    button8->SetLabel("");
    button9->SetLabel("");
    BindButtonEventHandlers();
    int currPlayer = game->GetPlayer();
    if(currPlayer == 2){currPlayer = game->SwitchPlayer();}
    SetStatusText(wxString::Format(wxT("Player %d's turn."),currPlayer));
}

void MainFrame::PlayPosition(wxButton* button, int x, int y)
{
    if(game->GetPosition(x,y) == 0){
        game->SetPosition(x,y,game->GetPlayer());
        int turnsPlayed = game->AddTurn();
        
        int currPlayer = game->GetPlayer();
        char buttonLabel;
        if(currPlayer == 1){buttonLabel = 'O';} else {buttonLabel = 'X';};
        button->SetLabel(buttonLabel);
        
        if(game->CheckWin() == true){
            wxMessageBox(wxString::Format(wxT("Player %d Wins!\nReset to Play again!"),currPlayer));
            SetStatusText("Reset to play again.");
            UnbindButtonEventHandlers();
        } else if (turnsPlayed == 9){
            wxMessageBox(wxString::Format(wxT("It's a draw!\nReset to Play again!")));
            SetStatusText("Reset to play again.");
            UnbindButtonEventHandlers();
        } else { 
            int nextPlayer = game->SwitchPlayer();
            SetStatusText(wxString::Format(wxT("Player %d's turn."),nextPlayer));
        }
    };
}

void MainFrame::Button1(wxCommandEvent& event)
{   
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    MainFrame::PlayPosition(button, 0, 0);
}

void MainFrame::Button2(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    MainFrame::PlayPosition(button, 1, 0);
}

void MainFrame::Button3(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    MainFrame::PlayPosition(button, 2, 0);
}

void MainFrame::Button4(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    MainFrame::PlayPosition(button, 0, 1);
}

void MainFrame::Button5(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    MainFrame::PlayPosition(button, 1, 1);
}

void MainFrame::Button6(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    MainFrame::PlayPosition(button, 2, 1);
}

void MainFrame::Button7(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    MainFrame::PlayPosition(button, 0, 2);
}

void MainFrame::Button8(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    MainFrame::PlayPosition(button, 1, 2);
}

void MainFrame::Button9(wxCommandEvent& event)
{
    wxButton *button = wxDynamicCast(event.GetEventObject(),wxButton);
    MainFrame::PlayPosition(button, 2, 2);
}