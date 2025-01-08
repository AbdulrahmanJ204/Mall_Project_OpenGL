#pragma once
#include "Object.h"
#include "Box.h"

class Chair : public Object { // Use public inheritance
public:
    Chair();
    void drawOpaque() override;
    void getTransparent() override;
    void onImguiRender() override;
    void setTex();

private:
    std::vector<Box> rjls;
    Box seat;
    
};
