#ifndef RENDER_ENGINE_H
#define RENDER_ENGINE_H
#include "elements.h"
class RenderEngine{
public:
    void Render(Item* toRender);
};

class RenderToTextEngine : public RenderEngine{

};


#endif //RENDER_ENGINE_H