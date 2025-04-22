#include <iostream>
#include <string>

using namespace std;
namespace HR {
    class Person{
        private:
                int id;
                string name;
                int age;
        public :
                Person(){
                    id=45;
                   name="Ravi Tambade";
                    age=49;
                }
    
                Person(int i, string nm, int a){
                    id=i;
                    name=nm;
                    age=a;
                }
    
            //Operator Overloading 
            //insertion operator and extraction operator
            friend  istream&  operator>>(istream& is,   Person& prn)
            {
                cout << "Person Detail Accept from EndUser :"<<endl;
                cout<<"Enter your name:  ";
                is >> prn.name ;
                cout<<endl <<"Enter your are:  ";
                is >> prn.age;
                return is;
            }  
            
            friend  ostream&  operator<<(ostream& os, const Person& prn)
            {
                os<<"Person object: "<<prn.name << " Age: "<<prn.age << endl;
                return os;
            }

    };
}


 

using namespace HR;
int main(){
  
    int count=78;  //primitive datatypes operator << >> have already logic
    cout<<"Enter the Count value"<<endl;
    cin>>count;   //Cin insertion operator  
    cout<< "Count ="<<count<<endl;

    Person p1;
    Person p2(65, "Nikita Bansode",22);
    cout<<p1<<endl;
    cout<<p2<<endl;

    cin>>p1;
    cout<<p1<<endl;

}