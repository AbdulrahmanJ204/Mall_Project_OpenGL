 
#pragma once
#include "Object.h"
#include "Box.h"
class Ceil: public Object {
public:
	Ceil();
	void drawOpaque() override;
	void setTex();

private:
	Box ceil;
};
