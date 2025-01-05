#pragma once
#include "Parent.h"

class Book : public Parent { // Use public inheritance
public:
    Book();
    ~Book();
    void draw() override;
    void onImguiRender() override {};
    void setTex();

private:
    Box book;
};
