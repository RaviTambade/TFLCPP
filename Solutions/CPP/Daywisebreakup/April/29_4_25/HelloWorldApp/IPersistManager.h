#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include "Product.h"


//Pure Abstract class (Interface) for Product Persistence Manager

class IPersistManager
{
public:
	virtual ~IPersistManager() {} 
	
	//Pure virtual functions
	virtual std::vector<Product> loadProducts() = 0; 
	virtual  void saveProducts(const std::vector<Product>&products) = 0;
	virtual void displayProducts(const std::vector<Product>& products) = 0;
	virtual  void addProduct(std::vector<Product>& products, const Product& product)=0;
	virtual void removeProduct(std::vector<Product>& products, int productId)=0;
	virtual void updateProduct(std::vector<Product>& products, const Product& updatedProduct) = 0;
};

#pragma once
