 
#pragma once
#include "Object.h"  
#include "Box.h" 

class Booklab : public Object {
public:
	Booklab();
	void drawOpaque() override;
	void setTex();

private:
	Box wall, raf, column;
};
