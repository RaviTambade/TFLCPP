#include <iostream>
#include <fstream>
#include <string>

using namespace std;
namespace HR {
    class Person{
        private:
                int id;
                string name;
                int age;
        public :
            Person(int i=0, string nm="", int a=0):id(i), name(nm), age(a){   }
    
            friend  istream&  operator>>(istream& is,   Person& prn)
            {
                is>>prn.id;
                is.ignore();
                getline(is, prn.name);
                is>>prn.age;
                is.ignore();
                return is;
            }  
            
            friend  ostream&  operator<<(ostream& os, const Person& prn)
            {
                os<<prn.id<<endl;
                os<<prn.name<<endl;
                os<<prn.age<<endl;
                return os;
            }
    };
}

using namespace HR;


//Serialization is a process of storing state of object into persistent media

void serialize(Person person){
    ofstream outFile("people.txt");
    if(outFile.is_open())
    {
        outFile<<person;
        outFile.close();
    }
    else{
        cerr<<"File opening Error for writing"<<endl;
    }
}

//DeSerialization is a process of restore state of object from persistent media

void  deSerialize(Person & person){
    ifstream inFile("people.txt");
    if(inFile.is_open())
    {
        inFile>>person;
        inFile.close();
    }
}


int main(){ 
    Person p2(112, "Sarthak Kadam",22);
    serialize(p2); 
    Person p3;
    deSerialize(p3);
    cout<<"Object Retrived from File people.txt";
    cout<<endl<<p3<<endl;
}