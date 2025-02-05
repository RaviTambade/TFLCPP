#include <iostream>
using namespace  std;
//access Specifiers: public, private, protected
//Public:  the variable can be accessed by any entity
//Private: only member functions can access variable or another function
//protecd: only access by child classes 

class Point{
	//data members
	//Encapsulation: data hiding
	private:
		int x, y;
	
	//member function
	public:
		 // default constructor
		 // special kind of function is automatically invoked as soon as object is create
		 // initializer 	
		//What do you mean by this Pointer ?
		// self reference of an object
		
		Point() {
				//this is used to represnt self object
				//it is implicit pointer pointing to the object itself
			 x=y=0;
		} 
		
		//parameterized constructor
		Point(int xx, int yy) {
			this->x=xx;
			this->y=yy;
		}
		
		//destructor
		~Point() {
			//clean up code to called before object is removed from memory
			cout<<"\n deinitializing code";
		}
		
		//gettter and setter for x(private) data member
		void setX(int xx) {
			this->x=xx;
		}
		
		int getX(){
			return this->x;
		}
		
		//gettter and setter for y(private) data member
		void setY(int yy){
			this->y=yy;
		}
		
		int getY(){
			return this->y;
		}
};
 
int main(int argc, char** argv) {
	printf( "Hello \n");
	Point startPoint;   //object of Point is created on stack using default constructor
	Point endPoint(45,56); //object of Point is created on stack using parameterized constructor
	cout<< startPoint.getX()<< " , "<<startPoint.getY() << "\n";
	cout<< endPoint.getX()<< " , "<<endPoint.getY() << "\n";
	
	
	//For dynamic memory allocation we use new operator
	Point *ptrPoint = new Point(76,67); //object of Point is created on heap using parameterized constructor
	cout<< 	ptrPoint->getX()<< " , "<<	ptrPoint->getY() << "\n";
	
	//releasing memory before application terminate, use delete operator
	delete ptrPoint;
	return 0;
}
