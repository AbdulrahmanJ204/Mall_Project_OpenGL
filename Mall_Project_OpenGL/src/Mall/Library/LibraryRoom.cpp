#include "Library/libraryRoom.h" 


LibraryRoom::LibraryRoom() :
    Object() 
{ 

}

void LibraryRoom::drawOpaque()
{ 
    floor.setParentModel(getModel());
    floor.drawOpaque();
    shelf.setParentModel(getModel());
    shelf.drawOpaque();
    book.setParentModel(getModel());
    book.drawOpaque();  
    //shelf.setPosition(glm::vec3(10.0f, 10.0f, 0.0f));
}
 
 
