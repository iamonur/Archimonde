#include "actions.h"

Action::Action(){
    try{
        app = Application::get_application();
    }        
    catch(const AppCreateException& e){
        throw NoApplicationToActException();
    }
}

Action_Change_Screen::Action_Change_Screen(Screen* screen2Activate = NULL, int nextScreenNum = -1, int deltaScreen = 0){
    if(screen2Activate != NULL) screenToActivate = screen2Activate;
    else if(nextScreenNum != -1) screenToActivate = app->getScreen(nextScreenNum);
    else if(deltaScreen != 0) screenToActivate = app->getScreen((app->getScreenNumber()) + deltaScreen);
    else throw actionCreateException();
    if(screenToActivate == NULL) throw actionCreateException();
}

void Action_Change_Screen::execute(){

}