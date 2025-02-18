#include <stdio.h>

union Shape{
    struct  {float radius;} circle;
    struct  {float length, width; } reactangle;
  
    struct  {float base, height; } triangle;
};

union SensorData{
    float temperature;
    float presssure;
    float humidity;
    float luminocity;
    float waterMoistureLevel;
    float waterLevelIntax;
    float waterInTank;
};

union Vehicle{
    struct { int wheels; int doors;} car;
    struct {int wheels;} bike;
    struct {int wheel; int capacity;} bus;
};


int main(){

    int count=34;
    union Shape geometricShape;
    geometricShape.circle.radius=25;
    geometricShape.reactangle.length=45;
    geometricShape.reactangle.width=75;
    geometricShape.triangle.base=23;
    geometricShape.triangle.height=15;

    printf( "Circle Radius= % .2f\n", geometricShape.circle.radius);
    printf( "Rectangle lengith= % .2f,  width=% .2f\n",geometricShape.reactangle.length,geometricShape.reactangle.width);
    printf( "triangle base= % .2f,  height=% .2f\n",geometricShape.triangle.base,geometricShape.triangle.height);

}