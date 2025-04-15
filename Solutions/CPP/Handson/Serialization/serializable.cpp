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
                is.ignore();
                is>>prn.age;
                return is;
            }  
            
            friend  ostream&  operator<<(ostream& os, const Person& prn)
            {
                os<<prn.id<<endl;
                os<<prn.name<<endl;
                os<<prn.age<<endl;
                return os;
            }
    
             // Serialize the object into an output stream (file or memory)
            void serialize(std::ofstream& outFile) {
                outFile << id << std::endl;
                outFile << name << std::endl;
                outFile << age << std::endl;
            }

             // Deserialize the object from an input stream (file or memory)
            void deserialize(std::ifstream& inFile) {
                inFile>>id;
                inFile.ignore();
                getline(inFile, name);  // Read the name (with spaces if any)
                inFile >> age;              
            }

            void display() const {
                std::cout <<"Id: "<<id<< ", Name: " << name << ", Age: " << age << std::endl;
            }
        };
}

using namespace HR;
int main(){ 
    Person person(77,"Shitaram Kesari", 70);

    // Serialize the object to a file
    ofstream outFile("people.dat");
    if (outFile.is_open()) {
        person.serialize(outFile);
        outFile.close();
        cout << "Object serialized to people.dat" << std::endl;
    }

    Person person2;

    // Deserialize the object from the file
   ifstream inFile("people.dat");
    if (inFile.is_open()) {
        person2.deserialize(inFile);
        inFile.close();
       cout << "Object deserialized from people.dat" << std::endl;
    }

    // Display the deserialized person object
    person2.display();
}