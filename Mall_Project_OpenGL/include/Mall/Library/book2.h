 
#pragma once
#include "Object.h"
#include "Box.h"
class Book2 : public Object {
public:
	Book2();
	void drawOpaque() override;
	void setTex();

private:
	Box book;
};
