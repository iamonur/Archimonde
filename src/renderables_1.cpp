#include "elements.h"

class Text : public Renderable{
public:
    Text(Item* parent);
};

class Img : public Renderable{
public:
    Img(Item* parent);
};

class Fill : public Renderable{
public:
    Fill(Item* parent);
};

class Polygon : public Renderable{
public:
    Polygon(Item* parent);
};
