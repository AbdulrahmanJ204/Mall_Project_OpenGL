 
#pragma once
#include "Object.h"  
#include "Box.h"
#include <Cylinder.h> 

class Clock : public Object {
public:
	Clock();
	void drawOpaque() override;
	void setTex(); 

private: 
	Cylinder clock; 

};
