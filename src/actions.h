class Action{
protected:
    virtual void execute() = 0;
    Application* app;
public:
    Action();
};