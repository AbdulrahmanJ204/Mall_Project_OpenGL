#pragma once
#include "Object.h"
#include "Box.h"
class Book : public Object {
public:
	Book();
	void drawOpaque() override; 
	void setTex();

private:
	Box book;
};
