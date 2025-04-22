#include<iostream>
using namespace std;

class Point
{
    private:
            int x,y;
    public:
        Point() { x,y=0; }
        friend ostream& operator<<(ostream&os ,Point& P)
        {   os<<"("<<P.x<<","<<P.y<<")";
            return os;
        }

        friend istream& operator>>(istream&is, Point& P)
        {   cout<<"Enter the x co-ordinate :"<<endl;
            is>>P.x;
            cout<<"Enter the y co-ordinate :"<<endl;
            is>>P.y;
            return is;
        }
       
        //p2.operator+(p1);
        Point operator+( const Point & other)
        {
            Point temp;
            temp.x=this->x+other.x;
            temp.y=this->y+other.y;
            return temp;
        }
};



int main()
{
    Point p1;
    Point p2;
 
    cout<<"Enter the first point :"<<endl;
    cin>>p1;

    cout<<"Enter the second point :"<<endl;
    cin>>p2;

    Point p3=p1+p2;

    //Point p3 = p1.operator+ (p2)
    
    cout<< "Point 1"<<p1 <<endl;
    cout<< "Point 2"<<p2 <<endl;
    cout<< "Point 3"<<p3 <<endl;
    return 0;
}