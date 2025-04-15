#include<iostream>
using namespace std;

class Point
{
    private:
            int x,y;
    public:


        Point() { x,y=0; }
        Point (int xx, int yy){
            x=xx;
            y=yy;
        }

        
        

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
    Point p1(56,12);
    Point p2(5,7);
 

    Point p3=p1;
    
    cout<<p1<<endl;
    cout<<p3<<endl;

    p1.setX(100);
    p1.setY(50);

    cout<<"After setting new values"<<endl;
    cout<<p1<<endl;
    cout<<p3<<endl;
    
    return 0;
}