//Macro:
//Macro to prevent multiple inclusions of the header file
//This is a common practice in C++ to avoid redefinition errors
//when the same header file is included multiple times in a project.
//The macro __PRODUCTSCONTROLLER_H is defined at the beginning of the file

#ifndef __PRODUCTSCONTROLLER_H
#define __PRODUCTSCONTROLLER_H

#include <iostream>
#include <string>
#include "ProductRepository.h"
#include "ProductService.h"
#include "Product.h"
using namespace std;

class ProductsController {

private:
	//state
	ProductRepository& repo;
	ProductService& service;

public:
	//behavior

	ProductsController(ProductRepository& r, ProductService& s);
	void addProduct(int id, const string& title, const string& description, const string& category, int quantity, double price);
	void removeProduct(int index);
	void updateProduct(int index, Product* product);
	void displayProducts() const;
	void applyDiscount(int productId, double discount);
	void calculateTotalPrice(int productId);
	void searchProductByTitle(const string& title);
	void getProductId(int& productId);
	void getProductIndex(int& index);
	void getProductTitle(string& title);
};
#endif

