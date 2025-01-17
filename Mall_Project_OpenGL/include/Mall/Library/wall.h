

#pragma once
#include "Object.h"  
#include "Box.h"

class Wall : public Object {
public:
	Wall();
	void drawOpaque() override;
	void setTex();

private:
	Box wall,wall2,wall3,logo;
};
