
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
    };
}