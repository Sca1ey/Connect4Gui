#include "App.h"
#include "MainFrame.h"

// Initialise the App and call MyFrame 
wxIMPLEMENT_APP(App);
 
bool App::OnInit()
{
    MainFrame* mainFrame = new MainFrame("Noughts and Crosses");
    mainFrame->SetClientSize(300,150);
    mainFrame->Center();
    mainFrame->Show();
    
    return true;
}