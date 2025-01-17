 
#include "Object.h"  
#include "Box.h"

class Rectable : public Object {
public:
	Rectable();
	void drawOpaque() override;
	void setTex();

private:
	Box side, board, back;
	Box book;
};
