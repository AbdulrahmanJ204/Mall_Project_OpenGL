#pragma once
#include "Parent.h"

class Chair : public Parent { // Use public inheritance
public:
    Chair();
    void draw() override;
    void onImguiRender() override {};
    void setTex();

private:
    Box rjl;
    Box seat;
};
