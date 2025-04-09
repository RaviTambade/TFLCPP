#include <iostream>
#include <thread>
#include <chrono>
#include <future>
using namespace std;

//Publisher
//Provider 
void  processSalary( promise<int> & p){  
    //produce data 
    this_thread::sleep_for(chrono::seconds(2));
    cout<<"Enter your Salary"<<endl;
    int salary;
    cin>>salary;
    p.set_value(salary);
}

//Consumers
//handler
//Subscriber
void payIncomeTax( future<int> p){
    cout<<"Income tax deduction Logic"<<endl;
    int result=p.get();
    if(result < 500000)
    {
        cout<<"You amount does not come under Taxable Income"<<endl;
    }
    else{
    float proertyTax=result * (0.03);
        cout<<"Income Tax="<<proertyTax<<endl;
    }
}


/*
void payGSTTax( future<int> p){
    //consume data
    cout<<"GST tax deduction Logic"<<endl;
    int result=p.get();
    float proertyTax=result * (0.02);
    cout<<"GST Tax="<<proertyTax<<endl;
}

void payPropertyTax( future<int> p){
    //consume data
    cout<<"Property tax deduction Logic"<<endl;
    int result=p.get();
    float proertyTax=result * (0.04);
    cout<<"Property Tax="<<proertyTax<<endl;
}


*/

//entry point
int main() {
    cout<<"Main processing started"<<endl;
    promise<int> p;
    future<int> f=p.get_future();

    thread  thSalaryCalcuator(processSalary,ref(p));   // Publisher
    thread  thIncomeTaxDeductor(payIncomeTax,move(f));  //consumer Thread
   
    thSalaryCalcuator.join();
    thIncomeTaxDeductor.join();


    cout<<"Main processing is getting over"<<endl;

}