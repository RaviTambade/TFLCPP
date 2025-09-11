#include <iostream>
#include <string>
#include <fstream>

#include "Product.h"

using namespace std;

//Implementation of Product class methods

Product::Product(int id) : productId(id), quantity(0), price(0.0) {}
Product::Product(int id, const string& t, const string& d, const string& c, int q, double p)
	: productId(id), title(t), description(d), category(c), quantity(q), price(p) {
}

Product::Product(int id, const string& t, const string& d, double p, int q)
	: productId(id), title(t), description(d), price(p), quantity(q) {
}
void Product::setTitle(const string& t) { 
    title = t; 
}
string Product::getTitle() const {
    return title; 
}

int Product::getProductId() const {
    return productId; 
}


string Product::getDescription() const 
{ 
    return description; 
}

void Product::setDescription(const string& d) { 
    description = d; 
}

string  Product::getCategory() const { return category; }
void Product::setCategory(const string& c) { category = c; }

int Product::getQuantity() const { return quantity; }
void Product::setQuantity(int q) { quantity = q; }

double Product::getPrice() const { return price; }
void Product::setPrice(double p) { price = p; }


	// Additional methods for calculating total price and discounted price
double Product::getTotalPrice() const { return quantity * price; }
double Product::getDiscountedPrice(double discount) const { return price - (price * discount / 100); }

 

//Serialization method to save product details to a binary file
void Product::save(std::ofstream& ofs) const {
    ofs.write(reinterpret_cast<const char*>(&productId), sizeof(productId)); // Replace 'id' with 'productId'
    ofs.write(reinterpret_cast<const char*>(&price), sizeof(price));

    size_t titleLength = title.size();
    ofs.write(reinterpret_cast<const char*>(&titleLength), sizeof(titleLength));
    ofs.write(title.c_str(), titleLength);
}



//DeSerialization method to load product details from a binary file
    void Product::load(std::ifstream& ifs) {

        int id; // Declare and initialize the local variable 'id'
        double price; // Declare and initialize the local variable 'price'
        size_t nameLength; // Declare and initialize the local variable 'nameLength'
        std::string name; // Declare and initialize the local variable 'name'

        ifs.read(reinterpret_cast<char*>(&id), sizeof(id));
        ifs.read(reinterpret_cast<char*>(&price), sizeof(price));

        ifs.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        name.resize(nameLength);
        ifs.read(&name[0], nameLength);

        // Assign the read values to the class members
        productId = id;
        this->price = price;
        title = name; // Assuming 'name' corresponds to the 'title' field
    }

	//Presentation method to display product details

void Product::display() const {
	cout << "Product ID: " << productId << endl;
	cout << "Title: " << title << endl;
	cout << "Description: " << description << endl;
	cout << "Category: " << category << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Price: $" << price << endl;
}
 