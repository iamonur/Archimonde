#ifndef ELEMENTS_H
#define ELEMENTS_H

#include <string>
#include <vector>
#include "render_engine.h"
#include "events.h"
#include "actions.h"
//Application class is developed as a singleton. Because:
//One app to rule them items all,
//One app to find them
//One app to bring them all
//And in the darkness bind them. (Pretty literal)

class Application{
    static RenderEngine* my_renderer;
    std::vector<Screen*> screens;
    static int my_x_res;
    static int my_y_res;
    int active_screen;
    static Application* my_instance;
    Application(RenderEngine* renderer, int xres, int yres);
    void re_render(); //Re-rendering is a decision that we need to make for us.
public:
    void attach_screen(Screen* tb_attached);
    int get_xres();
    int get_yres();
    void receive_event(Event* received);
    RenderEngine* get_renderer();
    static Application* get_application(RenderEngine* renderer, int xres, int yres);
    static Application* get_application();
};

typedef struct positon_data{
    int x_pos;
    int y_pos;
    int x_len;
    int y_len;
}POS_DATA;

struct NoActiveScreenException : public std::exception{
    const char* what const throw(){
        return "There is no active screen to render";
    }
}

struct AppCreateException : public std::exception{
    const char* what const throw(){
        return "Wrong parameters or no parameters when needed";
    }
};

struct ItemCreateException : public std::exception{
    const char* what() const throw(){
        return "Failure at item creation";
    }
};

struct NoApplicationToActException : public std::exception{
    const char* what() const throw(){
        return "There is no application to act upon.";
    }
};

class Item{
protected:
    POS_DATA my_positions;
    std::vector<Item*> subItems;
    Item* parentItem;
    Application* root;
    bool isRenderable;
    bool isTransparent;
public:
    virtual std::string returnLowestType() = 0;
    void attachSubItem(Item* newSubItem);
    POS_DATA getMyPositions();
    Application* getMyRoot();
    void render();
};

class Screen : public Item{
    
public:
    std::string returnLowestType();
    Screen(Application* parent);
};

class Layer : public Item{
public:
    std::string returnLowestType();
    Layer(Item* parent, POS_DATA itemPositions);
    Layer(Item* parent);//A fullscreen layer
};

class Control : public Item{
public:
    std::string returnLowestType();
    Control(Item* parent, POS_DATA itemPositions);
    Control(Item* parent);//A full-layer control, which can be a background area.
};

class Renderable : public Item{
public:
    std::string returnLowestType();
    Renderable(Item* parent, POS_DATA itemPositions);
    Renderable(Item* parent); //A full-control renderable, probably an img or a fill.

};



#endif 