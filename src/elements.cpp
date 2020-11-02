#include "elements.h"

Application* Application::my_instance = NULL;

Application::Application(RenderEngine* renderer, int xres, int yres){
    my_x_res = xres;
    my_y_res = yres;
    my_renderer = renderer;
    active_screen = -1;
    //Active screen is an index. When the first screen is pushed on, activate it.
}

Application* Application::get_application(RenderEngine* renderer, int xres, int yres){
    if (!my_instance) my_instance = new Application(renderer, xres, yres);
    else if (renderer != my_renderer && xres != my_x_res && yres != my_y_res) throw AppCreateException();
    return my_instance;
}

Application* Application::get_application(){
    if (!my_instance) throw AppCreateException();
    return my_instance;
}

Screen* Application::getScreen(int screenNumber){
    if(screenNumber > (screens.size()-1)) return NULL;
    return screens[screenNumber];
}

int Application::getScreenNumber(){
    return active_screen;
}

void Application::change_screen(Screen* tb_activated){
    int temp = active_screen;
    for(int i = 0; i < screens.size(); i++) if(tb_activated == screens[i]) active_screen = i;
    if(temp != active_screen) re_render();
}

void Application::attach_screen(Screen* tb_attached){
    screens.push_back(tb_attached);
    if(active_screen == -1) active_screen = 0;
}

void Application::re_render(){
    if(active_screen == -1) throw NoActiveScreenException();
    screens[active_screen]->render();
}

int Application::get_xres(){
    return my_x_res;
}

int Application::get_yres(){
    return my_y_res;
}

RenderEngine* Application::get_renderer(){
    return my_renderer;
}

void Item::attachSubItem(Item* newSubItem){
    subItems.push_back(newSubItem);
}

void Item::render(){
    root->get_renderer()->Render(this);
    for (int i = 0; i < subItems.size(); i++)
        subItems[i]->render();
}

POS_DATA Item::getMyPositions(){
    return my_positions;
}

Application* Item::getMyRoot(){
    return root;
}

Screen::Screen(Application* parent){
    // A screen must be full-screen, right
    my_positions.x_len = parent->get_xres();
    my_positions.y_len = parent->get_yres();
    my_positions.x_pos = 0;
    my_positions.y_pos = 0;

    parentItem = NULL;
    root = parent;
    isRenderable = false;
    isTransparent = true;
}

std::string Screen::returnLowestType(){
    return "Screen";
}

Layer::Layer(Item* parent){// A layer which is full-screen.
    root = parent->getMyRoot();
    parentItem = parent;
    my_positions = parent->getMyPositions();
}

Layer::Layer(Item* parent, POS_DATA itemPositions){ //Not a dimension-inheriting layer.
    root = parent->getMyRoot();
    parentItem = parent;
    my_positions = itemPositions;
}

std::string Layer::returnLowestType(){
    return "Layer";
}

std::string Control::returnLowestType(){
    return "Control";
}

Control::Control(Item* parent){
    root = parent->getMyRoot();
    parentItem = parent;
    my_positions = parent->getMyPositions();
}

Control::Control(Item* parent, POS_DATA itemPositions){
    root = parent->getMyRoot();
    parentItem = parent;
    my_positions = itemPositions;
}

std::string Renderable::returnLowestType(){
    return "Renderable";
}

Renderable::Renderable(Item* parent){
    root = parent->getMyRoot();
    parentItem = parent;
    my_positions = parent->getMyPositions();
}

Renderable::Renderable(Item* parent, POS_DATA itemPositions){
    root = parent->getMyRoot();
    parentItem = parent;
    my_positions = itemPositions;
}




