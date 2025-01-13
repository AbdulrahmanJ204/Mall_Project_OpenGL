#pragma once
#include "Object.h"  
#include "Box.h"
#include <Cylinder.h>

class Table : public Object {
public:
	Table();
	void drawOpaque() override;
	void setTex();

private:
	//Box table;
	Cylinder table;
	
};
