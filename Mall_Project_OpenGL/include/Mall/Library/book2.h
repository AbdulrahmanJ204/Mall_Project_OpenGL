 
#pragma once
#include "Object.h"
#include "Box.h"
class Book2 : public Object {
public:
	Book2();
	void drawOpaque() override;
	void setTex(const std::string&path);

private:
	Box book;
};
