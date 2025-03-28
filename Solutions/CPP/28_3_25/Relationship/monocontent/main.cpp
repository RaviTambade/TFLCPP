#include <iostream>
#include <string>

using namespace std;

class Point{
    private :
            int x,y;
     public:
            void setX(int xx){
                x=xx;
            }
            int getX(){
                return x;
            }
           
            void setY(int yy){
                y=yy;
            }
            int getY(){
                return y;
            }

            Point(){
                x=y=0;
            }

            Point(int xx, int yy){
                x=xx;
                y=yy;
            }

            void display() const{
                    cout<< "( "<<x<< ", " <<y<< ")"<<endl;
            }
};

//Base class  (Super Class ) (Parent class)
class Shape{

    protected:
        int thickness;
        string color;

    public:
            Shape(){
                thickness=1;
                color="black";
            }

            Shape(int t, string c){
                thickness=t;
                color=c;
            }

            void display(){
                cout<< "Shappe attributes"<<endl;
                cout<<"Thickness: "<<thickness <<endl;
                cout<<"Color: "<<color <<endl;   
            }
};

//Derived Class ( Sub Class ) (Child Class)

class Line:Shape   //Is a relationship  (inheritance)
{

    public : 
            //Has a reltionship between Line and Point class
            Point startPoint;
            Point endPoint;

            Line(){
                Point pt(0,0);
                startPoint=pt;
                endPoint=pt;
                thickness=1;
                color="black";
            }

            Line(Point pt1, Point pt2, int t, string c){
                startPoint=pt1;
                endPoint=pt2;
                thickness=t;
                color=c;
            }

            void display(){
                cout<< "Line  attributes"<<endl;
                cout<<"StartPoint: ("<< startPoint.getX()<< ", "<<startPoint.getY()<< ")"<<endl;
                cout<<"EndPoint: ("<< endPoint.getX()<< ", "<<endPoint.getY()<< ")"<<endl;
                cout<<"Thickness: "<<thickness <<endl;
                cout<<"Color: "<<color <<endl;  
            }
};


class Circle:Shape{

    public :
            Point center;
            int radius;

            Circle(){
                Point pt(0,0);
                center=pt;
                thickness=1;
                color="black";
            }
            
            Circle(Point pt, int r,  int t, string c){
                center=pt;
                radius=r;
                thickness=t;
                color=c;
            }

            void display(){
                cout<< "Circle  attributes"<<endl;
                cout<<"Center: ("<< center.getX()<< ", "<<center.getY()<< ")"<<endl;
                cout<<"Radius: "<<radius <<endl;
                cout<<"Thickness: "<<thickness <<endl;
                cout<<"Color: "<<color <<endl;  
            }
};


int main(){
    cout <<"Reusibility using Inheritance"<<endl;


}