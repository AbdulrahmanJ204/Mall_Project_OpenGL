#pragma once
#include "Object.h"  
#include "Box.h"

class Shelf : public Object {
public:
	Shelf();
	void drawOpaque() override;
	void setTex();

private:
	Box wall, raf, column;
};
