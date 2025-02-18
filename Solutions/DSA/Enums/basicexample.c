#include <stdio.h>

 //Enums are used to represent a fixed set of related constants
enum Day{ Ravivar, Somwar,Mangalwar, Budhwar, Gurwar, Shukrwar, Shanivar};
enum Color{Red, Green, blue};
enum switchState{ On, Off};
enum Month{Jan, Feb, Mar, Apr, May, June, July, August, Sept, Oct, Nov, Dec};
enum Flower {Rose, Jasmine, Lotus, Marigold, Orhid, Lily, Sunflower};
enum Engine {TwoStrok, FourStroke};
enum ElectronicComponent {Capacitor, Diode, Register, Transistor, Relay, Amplifier, Transformer};
enum Card{Credit, Debit};
enum TrafficLight{Red, Yellow, Green};



int main(){

    //Week: is of 7 days

    //provide meaningful name to index value
    /*
        int today=1;
        int yesterday=2;
        int tomorrow=3;

        if(today ==1){
        printf( "Yes today is Tuesday \n");
        }
        else{
         printf( "Yes today is not Tuesday \n");
        }

    */
    enum Day today=Mangalwar;
    enum Day yesterday=Somwar;
    enum Day tomorrow=Budhwar;
    if(today==Mangalwar){
        printf( "Yes today is Tuesday \n");
    }
    else{
        printf( "Yes today is not Tuesday \n");
    }


    //Year: is of 12 months
    
    int firstMonth=1;
    int secondMonth=2;

}

// Advatnage of using Enum in Programming
// Readability:
// Maintainaability:
// Error prevention
