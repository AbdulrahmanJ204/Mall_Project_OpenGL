 
#pragma once
#include "Object.h"  
#include "Box.h"

class Signboard : public Object {
public:
	Signboard();
	void drawOpaque() override;
	void setTex();

private:
	Box board;
};
