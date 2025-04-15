#include <iostream>
#include <string>
using namespace std;
class Date{
    public:
          int day, month, year;
          Date(int d, int m , int y){
            this->day=d;
            this->month=m;
            this->year=y;
          }
};

class Employee{
    public: 
            string name;
            Date *ptrJoinDate;

            Employee(string nm, Date *ptrJndate){
                this->name=nm;
                this->ptrJoinDate=ptrJndate;
            }

            //Explicitly added copy constructor for deep copy of Date and name
            Employee( Employee & emp){
                this->name=emp.name;
                this->ptrJoinDate=new Date(emp.ptrJoinDate->day,emp.ptrJoinDate->month, emp.ptrJoinDate->year);
            }

};

int main(){
    Date d1(11,4,2025);
    Employee e1("Pranav",&d1);
    Employee e2(e1);
    e2.name="Sarthak";

    Date * ptrDatePranav=e1.ptrJoinDate;
    Date * ptrDateSarthak=e2.ptrJoinDate;

    cout<< e2.name<<":  Join Date: " <<ptrDateSarthak->day<<":"<<ptrDateSarthak->month<<":"<<ptrDateSarthak->year <<endl;
    cout<<e1.name<<" :  Join Date: "<<ptrDatePranav->day<<":"<<ptrDatePranav->month<<":"<<ptrDatePranav->year <<endl;

    ptrDatePranav->day=13;
    ptrDatePranav->month=3;
    ptrDatePranav->year=2003;

    cout<<"After changing  joining date of Pranav "<<endl;
    cout<< e2.name<<":  Join Date: " <<ptrDateSarthak->day<<":"<<ptrDateSarthak->month<<":"<<ptrDateSarthak->year <<endl;
    cout<<e1.name<<" :  Join Date: "<<ptrDatePranav->day<<":"<<ptrDatePranav->month<<":"<<ptrDatePranav->year <<endl;


}