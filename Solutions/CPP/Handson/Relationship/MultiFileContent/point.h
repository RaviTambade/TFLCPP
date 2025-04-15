#ifndef __POINT_H
#define __POINT_H

namespace Drawing
{
    class Point{
        private :
                int x,y;
        public:
                void setX(int xx);
                int getX();
                void setY(int yy);
                int getY();
                Point();
                Point(int xx, int yy);
                void display() const;
    };
}
#endif