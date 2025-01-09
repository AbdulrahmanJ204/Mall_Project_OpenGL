 
#pragma once
#include "Object.h" 
#include "Library/floor.h"
#include "Library/shelf.h"
#include "Library/book.h"
#include "Library/wall.h"
class LibraryRoom : public Object {
public:
	LibraryRoom();
	void drawOpaque() override; 

private:
	 Floor floor;
	 Book book;
	 Shelf shelf;
	 Wall wall; 
};
