#include "elements.h"

enum action_levels{
    AL_APP,
    AL_SCR,
    AL_LYR,
    AL_CNT,
    AL_RND
};
struct actionCreateException : public std::exception{
    const char* what() const throw(){
        return "Illegal action creation.";
    }
};
class Action{
protected:
    
    Application* app;
public:
    virtual void execute() = 0;
    Action();
};

class Action_Change_Screen : public Action{
    Screen* screenToActivate;
public:
    void execute();
    Action_Change_Screen(Screen* screen2Activate = NULL, int nextScreenNum = -1, int deltaScreen = 0);
};