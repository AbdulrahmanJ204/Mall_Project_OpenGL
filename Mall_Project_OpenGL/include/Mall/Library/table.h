#pragma once
#include "Object.h"  
#include "Box.h"
#include <Cylinder.h>
#include "modelObject.h" 

class Table : public Object {
public:
	Table();
	void drawOpaque() override;
	void setTex();
	void onImguiRender();

private:
	//Box table;
	Cylinder table;
	ModelObject table_plant;
	
	
};
