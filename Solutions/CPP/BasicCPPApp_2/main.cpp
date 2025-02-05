#include <iostream>
using namespace  std;

//class consist of two types of variables
//1. instance variables ---------  members of object
//2. static variables   ---------  members of Class

class Point{
	private:  int x, y;	  //instance variables  or non-static	  
 	public:
 		static int count; //shared variables or static variables or class variables
		Point() { 
					 x=y=0;  //data member initialized
					 count++; //increment count static variable
		 } 
		 
		Point(int xx, int yy) {
					 this->x=xx; this->y=yy; 
					 count ++; //increment count static variable
		}
		~Point() { 
				  count --;
			cout<<"\n deinitializing code";  //decrement count static variable
		}
		int getX(){	return this->x; }
		void setX(int xx) { this->x=xx; }	
		int getY(){ return this->y; }
		void setY(int yy){ this->y=yy; }
};
 
//Definition of the static variable is initialized at global level

int Point::count =0;
 	
int main(int argc, char** argv) {
	printf( "Hello \n");
	printf( "\n static variable of Point count= %d \n", Point::count);
	Point pt1;
	Point pt2;
	Point startPoint;    
	Point endPoint(45,56);  
	cout<<startPoint.getX()<< " , "<<startPoint.getY() << "\n";
	cout<< endPoint.getX()<< " , "<<endPoint.getY() << "\n";
	Point *ptrPoint = new Point(76,67);  
 	cout<< 	ptrPoint->getX()<< " , "<<	ptrPoint->getY() << "\n";
 	
 	printf( "\n static variable of Point count= %d \n", Point::count);
 		
	delete ptrPoint;
	printf( "\n static variable of Point count= %d \n", Point::count);
	return 0;
}
