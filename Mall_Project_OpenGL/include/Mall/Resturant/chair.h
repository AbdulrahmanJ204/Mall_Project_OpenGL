#pragma once
#include "Object.h"
#include "Box.h"

class Chair : public Object { // Use public inheritance
public:
    Chair();
    void drawOpaque() override;
    void drawTransparent() override;
    void onImguiRender() override;
    void setTex();

private:
    Box rjl;
    Box seat;
};
