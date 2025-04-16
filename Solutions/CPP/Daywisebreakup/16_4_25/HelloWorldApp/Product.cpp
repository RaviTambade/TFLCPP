
#include <iostream>
#include <string>

#include "Product.h"

using namespace std;

//Implementation of Product class methods

Product::Product(int id) : productId(id), quantity(0), price(0.0) {}


int Product::getProductId() const { return productId; }

void Product::setTitle(const string& t) { title = t; }

string Product::getDescription() const { return description; }
void Product::setDescription(const string& d) { description = d; }

string  Product::getCategory() { return category; }
void Product::setCategory(const string& c) { category = c; }

int Product::getQuantity() const { return quantity; }
void Product::setQuantity(int q) { quantity = q; }

double Product::getPrice() const { return price; }
void Product::setPrice(double p) { price = p; }


	// Additional methods for calculating total price and discounted price
double Product::getTotalPrice() const { return quantity * price; }
double Product::getDiscountedPrice(double discount) const { return price - (price * discount / 100); }

	//Presentation method to display product details

void Product::display() const {
	cout << "Product ID: " << productId << endl;
	cout << "Title: " << title << endl;
	cout << "Description: " << description << endl;
	cout << "Category: " << category << endl;
	cout << "Quantity: " << quantity << endl;
	cout << "Price: $" << price << endl;
}
 