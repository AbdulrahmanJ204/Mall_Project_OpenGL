#pragma once
#include "Parent.h"

class chair : public Parent { // Use public inheritance
public:
    chair();
    void draw() override;
    void setTex();
private:
    Box rjl;
    Box seat;
};
