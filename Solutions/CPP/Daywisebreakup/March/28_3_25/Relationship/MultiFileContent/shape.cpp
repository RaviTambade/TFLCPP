# include  <iostream>
# include <string>
#include "shape.h"

using namespace std;
namespace Drawing {
    
    Shape::Shape(){
        thickness=1;
        color="black";
    }

    Shape::Shape(int t, string c){
        thickness=t;
        color=c;
    }

    void Shape::display(){
        cout<< "Shappe attributes"<<endl;
        cout<<"Thickness: "<<thickness <<endl;
        cout<<"Color: "<<color <<endl;   
    }
}