
//namespace:
//logical collection of classes

#include <iostream>

using namespace std;
class Ticket{
    private:
        int ticketNo;
        string issuedTo;
        string source;
        string destination;
        float fare;
};


class Point{
    private:
            int x;
            int y;
    public:
            Point(){
                x=y=0;
            }
            Point(int a, int b)
            {
                x = a;
                y = b;
                cout<<"Point object created"<<endl;
            }
           
            ~Point()
            {
                cout<<"Point object destroyed"<<endl;
            }

            void show(){
                cout<<"Point details:"<<endl;
                cout<<"X:"<<x<<endl;
                cout<<"Y:"<<y<<endl;
            }
};


class Person
{
    //access specifiers:defines visibility of data members and member functions
    //private, protected, public
    private:
        //data members
        int age;
        string name;
    public:
        //member functions
        //Getters and Setters
        void setAge(int a)
        {
            age = a;
        }
        int getAge()
        {
            return age;
        }
        void setName(string n)
        {
            name = n;
        }
        string getName()
        {
            return name;
        }
        //constructor:defult constructor
        //constructor overloading
        Person()
        {
            cout<<"Person object created"<<endl;
        }
        //parameterized constructor
        Person(int ag, string nm)
        {
            age = ag;
            name = nm;
            cout<<"Person object created"<<endl;
        }

        void show()
        {
            cout<<"Name:"<<name<<" Age:"<<age<<endl;
        }

        void showDetails(){
            cout<<"Person details:"<<endl;
            cout<<"Name:"<<name<<endl;
            cout<<"Age:"<<age<<endl;
        }

        void performTask()
        {
            cout<<"Person performing task"<<endl;
            cout<<"doing very important task"<<endl;
        }
    
        //destructor
        ~Person()
        {
            cout<<"Person object destroyed"<<endl;
        }

    };


int main()
{
    cout << "Hello World!" << endl;

    Person p1;
    p1.setAge(20);
    p1.setName("John");
    cout<<p1.getAge()<<p1.getName()<<endl;

    Person p2;
    p2.setAge(28);
    p2.setName("Smith");
    cout<<p2.getAge()<<p2.getName()<<endl;
    Person p3(49,"Ravi T");
    p3.show();
    p3.showDetails();
    p3.performTask();



    Person *ptrPerson213=new Person();
    ptrPerson213->setAge(45);
    ptrPerson213->setName("Ravi");
    cout<<ptrPerson213->getAge()<<ptrPerson213->getName()<<endl;
    ptrPerson213->show();
    delete ptrPerson213;


    Point startPoint(45,67);
    Point endPoint;
    return 0;
}