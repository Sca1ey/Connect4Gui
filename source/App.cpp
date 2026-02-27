#include "App.h"
#include "MainFrame.h"

// Initialise the App and call MyFrame 
wxIMPLEMENT_APP(App);
 
bool App::OnInit()
{
    MainFrame* mainFrame = new MainFrame("Connect 4");
    mainFrame->SetClientSize(600,600);
    mainFrame->Center();
    mainFrame->Show();
    
    return true;
}