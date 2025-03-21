#include <iostream>
using namespace std;

class Point{
    private:
            int x;
            int y;
    public:
            Point(){
                x=y=0;
            }
            Point(int a, int b)
            {
                x = a;
                y = b;
                cout<<"Point object created"<<endl;
            }
           
            ~Point()
            {
                cout<<"Point object destroyed"<<endl;
            }

            void show(){
                cout<<"Point details:"<<endl;
                cout<<"X:"<<x<<endl;
                cout<<"Y:"<<y<<endl;
            }
};



//abstract class (Parent/Super/Base)
class Shape{
    protected:
           string style;
           string color;
           string thickness;
    public:
            //pure virutal function
            virtual  void draw()=0;

};

//concrete class
//child class/ derived class/ sub class
class Line:Shape{       
    private:
        Point startPoint;
        Point endPoint;
    public:
        void draw(){
                cout<<"Drawing Line"<<endl;
        }
    
};
class Traingle:Shape{
    private:
        Point point1;
        Point point2;
        Point point3;
    public:
    void draw(){
        cout<<"Drawing Triangle"<<endl;
    }
};

int main(){
    Line l1;
    Traingle t1;
    //l1.draw();
    //t1.draw();
    Shape *ptrShape=NULL;
    ptrShape=(Shape *)&l1;
    ptrShape->draw();
    ptrShape=(Shape *)&t1;
    ptrShape->draw();
    cout<<"Welcome to Graphics"<<endl;
}