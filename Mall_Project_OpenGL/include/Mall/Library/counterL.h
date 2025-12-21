 
#pragma once
#include "Object.h"
#include "Box.h"
class Counter : public Object {
public:
	Counter();
	void drawOpaque() override;
	void setTex();

private:
	Box counter1,counter2;
};
