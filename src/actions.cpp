#include "actions.h"

Action::Action(){
    try{
        app = Application::get_application();
    }        
    catch(const AppCreateException& e){
        throw NoApplicationToActException();
    }
}