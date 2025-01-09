#pragma once
#include "Object.h"
#include "Box.h"
class Floor : public Object {
public:
	Floor();
	void drawOpaque() override;
	void setTex();

private:
	Box floor;
};
