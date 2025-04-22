#include "Product.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "IPersistManager.h"

#pragma once



//Provider
//concrete class for binary file I/O management
// This class implements the IPersistManager interface for binary file I/O
// It provides methods for saving, loading, displaying, adding, removing, and updating products
// This class is responsible for managing product data in a binary file format

class ProductBinaryIOManager : public IPersistManager
{
public:

	//Implementation of rules defiend in the base class here 

	void saveProducts(const std::vector<Product>& products) override;
	std::vector<Product> loadProducts() override;
	void displayProducts(const std::vector<Product>& products) override;
	void addProduct(std::vector<Product>& products, const Product& product) override;
	void removeProduct(std::vector<Product>& products, int productId) override;
	void updateProduct(std::vector<Product>& products, const Product& updatedProduct) override;
};
