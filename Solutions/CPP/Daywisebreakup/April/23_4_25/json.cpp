#include <iostream>
#include "json.hpp"

//json.hpp is a single header file library for JSON parsing and serialization in C++
// It is a part of the nlohmann/json library, which is widely used for handling JSON data in C++ applications.

using json = nlohmann::json;

class Product {

    public:
    int id;
    std::string name;
    double price;
    Product(){}
    Product(int i, const std::string& n, double p) : id(i), name(n), price(p){ }
    void display() const {
        std::cout << "ID: " << id << ", Name: " << name << ", Price: " << price << std::endl;
    }
};


int main() {
    
    //R "Raw" is a raw string literal in C++ that allows you to include characters without needing to escape them.
    // It is useful for including strings that contain backslashes, quotes, or other special characters.
    
    std::string data = R"({"id": 101, "name": "Laptop", "price": 899.99})";
    json j = json::parse(data);

    Product p;
    p.id = j["id"];
    p.name = j["name"];
    p.price = j["price"];
 
    p.display();
    return 0;
}