#if !defined(ENTITY_PRODUCT_H)
#define ENTITY_PRODUCT_H

#include <string>

using namespace std;

class Product {
public:
    int id;
    string title;
    string description;
    string category;
    double price;

    Product(int id, string title, string description, string category, double price)
        : id(id), title(title), description(description), category(category), price(price) {}
};

#endif // ENTITY_PRODUCT_H