#include <iostream>
using namespace std;


//Blue Print
class Point3D{
    private : 
             int x, y,z;
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

        void setZ(int zz){
            z=zz;
        }
        int getZ(){
            return z;
        }
};

class Pyramid{
    private:
        Point3D apex;
        Point3D basePoints[4];
    public:
        void setApex(Point3D p){
            apex=p;
        }

        Point3D getApex(){
            return apex;
        }

        void setBasePoints(Point3D points[]){
            for(int i=0;i<=4;i++){
                basePoints[i]=points[i];
            }
        }

        Point3D * getBasePoints(){
            return basePoints;
        }

        void show(){
            //Show all points part of Pyramid

        }
    };

int main(){
    Point3D apx;

    apx.setX(45);
    apx.setY(67);
    apx.setZ(88);

    Point3D basePoints[4];

    basePoints[0].setX(45);
    basePoints[0].setY(22);
    basePoints[0].setZ(11);

    basePoints[1].setX(145);
    basePoints[1].setY(82);
    basePoints[1].setZ(51);

    basePoints[2].setX(4);
    basePoints[2].setY(76);
    basePoints[2].setZ(56);
 
    basePoints[3].setX(25);
    basePoints[3].setY(12);
    basePoints[3].setZ(1);

    basePoints[4].setX(11);
    basePoints[4].setY(43);
    basePoints[4].setZ(56);

    Pyramid pd;
    pd.setApex(apx);
    pd.setBasePoints(basePoints);
}