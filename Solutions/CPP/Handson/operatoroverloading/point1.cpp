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
       
        friend Point operator+(Point& point1, Point & point2);
};



Point operator+(Point& point1, Point & point2)
{
    Point temp;
    temp.x=point1.x+point2.x;
    temp.y=point1.y+point2.y;
    return temp;
}

int main()
{
    Point p1;
    Point p2;
 
    cout<<"Enter the first point :"<<endl;
    cin>>p1;

    cout<<"Enter the second point :"<<endl;
    cin>>p2;

    Point p3=p1+p2;
    cout<< "Point 1"<<p1 <<endl;
    cout<< "Point 2"<<p2 <<endl;
    cout<< "Point 3"<<p3 <<endl;
    return 0;
}