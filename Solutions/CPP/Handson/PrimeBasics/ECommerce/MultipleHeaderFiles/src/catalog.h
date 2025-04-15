
//Apply Abstraction concept of Object Oriented Programming

namespace Catalog{
    class Product{
        public :     //access Specifiers (public/ private/ protected)
                //data members
                int id;
                char title[10];
                char description[200];
                int stock;
    };

    class Categoy{
        public: 
                int id;
                char title[20];
    };
}