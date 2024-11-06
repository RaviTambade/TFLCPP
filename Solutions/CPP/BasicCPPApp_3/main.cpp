#include <iostream>
using namespace  std;
//object oriented programming
//1.Abstraction
//2.Encapsulation		: data hiding   C++ is not pure object oriented programming
//3.Inheritance  

class Box{
	private :
			double  width;
	public:
			//constructor : member function (initialization)
			//private variable (instance variable) can be ACCESSED  by  memeber function of object
			Box(double w){
				this->width=w;
			}
			
			friend void printWidth( Box box);
};

void printWidth( Box box){
	cout<< " Width of Box"<<box.width;
}

 class Point {
 	private: 
 			int x,y;
 	public:
 			Point(int xx, int yy){
 				this->x=xx;
 				this->y=yy;
			 }
		 
			 
 			void display(){
 				cout<< "X="<<this->x<<" , Y="<< this->y<<"\n"; 
			 }
			 
			 friend  Point operator+ ( Point p1, Point p2);
			 friend  Point operator- ( Point p1, Point p2);
 };


Point operator+ ( Point p1, Point p2){
	Point temp(0,0);
	temp.x=p1.x + p2.x;
	temp.y=p1.y + p2.y;
	return temp;
}


Point operator- ( Point p1, Point p2){
	Point temp(0,0);
	temp.x=p1.x - p2.x;
	temp.y=p1.y - p2.y;
	return temp;
}



//Complex number
// real + imaginary j
// j = sqroot(-1)

//real  imaginary value
//4+5j
//6+8j
//10+ 13j

class Complex{
	private: 
			int real, imag;
	public:
		   Complex(){
		   	real=imag=0;
		   }
		   Complex(int r, int i){
		   	real=r; imag=i;
		   }
		
		   	void display(){
 				cout<< this->real<<" + "<< this->imag<<" j \n"; 
			 }
			 
		   friend Complex operator+ ( Complex c1, Complex c2);
};

Complex operator+( Complex c1, Complex c2){
	Complex temp;
	temp.x=c1.x+ c2.x;
	temp.y=c1.y+ c2.y
	return temp;
}
int main(int argc, char** argv) {
	printf( "Hello \n");
//	Box box(56.7);
//	printWidth(box);
	Point pt1(50,20);
	Point pt2(30,10);
	//arithmatic operator +, - , * , /
	Point pt3=pt1 + pt2;
	pt3.display();  // 80 ,30
	
	Point p4=pt1-pt2;
	p4.display();   // 20,10
	
	Complex c1(6,8);   // 6+ 8j
	Complex c2(77,66); // 11+ 6j
	
	Complex c3=c1+c2;  // 17 + 14j
	c3.display();	
	
	}
