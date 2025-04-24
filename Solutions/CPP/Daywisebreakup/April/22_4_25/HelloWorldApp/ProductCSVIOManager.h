#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include  "IPersistManager.h"

using namespace std;
#include "Product.h"
#pragma once


class ProductCSVIOManager :public IPersistManager
{
public:
	std::vector<Product> loadProducts() override; // Pure virtual function for loading products from a file
	void saveProducts(const std::vector<Product>& products) override;

	void displayProducts(const std::vector<Product>& products) override;
	void addProduct(std::vector<Product>& products, const Product& product) override;
	void removeProduct(std::vector<Product>& products, int productId) override;
	void updateProduct(std::vector<Product>& products, const Product& updatedProduct)override;
};


 
