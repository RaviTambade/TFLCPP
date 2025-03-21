//Apply Encapsulation concept of Object Oriented Programming
//Hiding complexity
//Hiding data using private access specified

#include <iostream>
#include <string>

using namespace std;

namespace Catalog{
    class Product{
        private :     //access Specifiers (public/ private/ protected)
                //data members
                int id;
                string title;
                string description;
                int stock;
        public:
                //getter and setter
                void setId(int i){
                    id=i;
                }
                int getId(){
                    return id;
                }

                void setTitle(string str){
                    title=str;
                }
                string getTitle(){
                    return title;
                }

                void setDescription(string desc){      
                    description=desc;
                }
                string getDescription(){
                    return description;
                }

                void setStock(int stk){
                    stock=stk;
                }
                int getStock(){
                    return stock;
                }

                //Constuctor
                //It is a special kind of function which is automatically called
                //once object is created.
                

                //Constructor Overloading: more than one constructors in a class
                //default constructor
                Product(){
                    id=34;
                    title="Rose";
                    description="Valentine Flower";
                    stock=5600;
                }

                //Parametrized constructor
                Product(int i, string t, string d, int s){
                    id=i;
                    title=t;
                    description=d;
                    stock=s;
                }

                //destructor is special kind of function automatically
                //called before object is removed from memory
                
                ~Product(){
                    cout<<"Object is getting deinitialized...."<<endl;
                }
    };
}