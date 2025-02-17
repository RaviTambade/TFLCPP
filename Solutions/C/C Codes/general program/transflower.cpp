# include<iostream>
# include<string>
using namespace std;
class Person{
    public:
        int age;
        string name;
        Person(int age, string name){
            this->age = age;
            this->name = name;
        }
        void display(){
            cout << "Name: " << name << " Age: " << age;
        }
};

int main(){
   cout << "hello";
   Person person1(20, "Sarthak");
   Person person1(20, "Sanika");
   Person person1(20, "Sejal ");
    return 0;
}