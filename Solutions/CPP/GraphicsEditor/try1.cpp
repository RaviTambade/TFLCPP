#include <iostream>
#define PI 4.56
#define OFF 0
#define ON 1

int count=56;
using namespace std;
class Student{
    //Encapsulation

    private:
        int rollno;
        string  name;
        float marks;

    public:
        //associated member
        //functions of Student

        //getter amd setter function
        void setRollNo(int no){
            rollno=no;
        }
         
        int getRollNo(){
            return rollno;
        }

        void setName(string nm){
            name=nm;
        }
         
        string getName(){
            return name;
        }


        void setMarks(int m){
            marks=m;
        }
         
        int getMarks(){
            return marks;
        }

};


int main(){

    cout<<"Welcome to Transflower"<<endl;
    cin>>count;

    Student s1;
    s1.setRollNo(34); //use setter
    s1.setMarks(65);
    s1.setName("Aditya");


    cout<<"Roll No :"<<s1.getRollNo() <<endl;
    cout<<"Name :"<<s1.getName()<<endl;
    cout<<"Marks"<<s1.getMarks()<<endl;
}