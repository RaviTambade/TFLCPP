#include "GeometricShape.h"

/*

Multiple inheritance in C++ allows a class to inherit from multiple base classes. 
This can be useful when you want to combine the functionality of 
multiple classes into a single derived class. 
However, multiple inheritance can lead to complexities, 
such as the diamond problem, 
where ambiguity arises due to the presence of two or more base classes
with a common ancestor.

When it comes to "interface inheritance," 
it usually refers to inheriting from abstract classes, 
where the derived class promises to provide implementations 
for the pure virtual functions declared in the base classes.



*/
int mainDrawing() {
    GeometricShape shape;
    shape.draw();
    shape.serialize();
    return 0;
}
