#pragma once
#include "Parent.h"

class Board : public Parent {  
public:
    Board();
    void draw() override;
    void onImguiRender() override {};
    void setTex();

private:
    Box wall,raf,column;
};
