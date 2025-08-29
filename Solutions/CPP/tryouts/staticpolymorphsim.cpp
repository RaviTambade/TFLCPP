

# include <iostream>
using namespace std;

class HRPayrollCalculator{

    public :
    //computepay function is overloaded
    //method overloading, function overloading
    //static polymorphism

         double computePay(){
            return 45000;
         }
           double computePay(double salary, double tax, double incentive){
            return  salary-tax+ incentive;
         }

};

int main(){

    HRPayrollCalculator calculator;
    double package=calculator.computePay();
    cout<<" Package="<<package;

    double packageIshwari=calculator.computePay(67000, 4000, 1250);
    cout<<" Package="<<packageIshwari;



    return 0;
}