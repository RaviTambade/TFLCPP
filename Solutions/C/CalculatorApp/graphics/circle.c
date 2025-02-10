#include "circle.h"

float calculateArea(int radius){
  float area=0;
  float pi=3.14f;
  area=pi * radius * radius;
  return area;
}

float calculateCicumference(int radius){
  float circumference=0;
  float pi=3.14f;
  circumference=pi * radius * 2;
  return circumference;
}
