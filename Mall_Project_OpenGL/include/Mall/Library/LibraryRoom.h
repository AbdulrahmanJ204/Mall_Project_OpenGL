#pragma once
#include "Object.h"  
#include "Library/floor.h"
#include "Library/shelf.h"
#include "Library/book.h"
#include "Library/wall.h"
#include "modelObject.h"  // Include the model object class
#include "Library/table.h"
#include "Library/signboard.h"
#include "Library/rectable.h"
#include "Library/ceil.h"

class LibraryRoom : public Object {
public:
    LibraryRoom();
    void drawOpaque() override;
    void onImguiRender() override;

private:
    Floor floor;
    Book book;
    Shelf shelf;
    Wall wall;
    ModelObject model;  // Declare the model
    Table table;
    Signboard signboard;
    ModelObject chair;
    Rectable rectable;
    ModelObject arm_chair;
    Ceil ceil;
   // ModelObject sofa;
};
