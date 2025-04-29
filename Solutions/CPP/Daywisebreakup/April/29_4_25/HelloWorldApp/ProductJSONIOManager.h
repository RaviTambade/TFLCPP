#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include  "IPersistManager.h"

using namespace std;
#include "Product.h"
// Pure Abstract Base Class


class ProductJSONIOManager :public IPersistManager
{
public:
	void saveProducts( const std::vector<Product>& products) override;
	std::vector<Product> loadProducts() override;
	void displayProducts(const std::vector<Product>& products) override;
	void addProduct(std::vector<Product>& products, const Product& product) override;
	void removeProduct(std::vector<Product>& products, int productId) override;
	void updateProduct(std::vector<Product>& products, const Product& updatedProduct)override;
};

