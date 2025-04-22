#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include "Product.h"

//Pure Abstract Base Class
// This class defines the interface for product persistence management
// It declares methods for saving, loading, displaying, adding, removing, and updating products
// The actual implementation of these methods will be provided by derived classes
// This allows for different implementations of Product Persistence Management
// such as text file, binary file, or JSON file management
class IPersistManager
{
public:
	virtual ~IPersistManager() {} // Virtual destructor for proper cleanup of derived classesstd::vector<Product> loadProductsFromFile(const std::string& filename) override;
	//define rules for derived classes
	// Pure virtual function for saving products to a file

	
	virtual std::vector<Product> loadProducts() = 0; // Pure virtual function for loading products from a file
	virtual  void saveProducts(const std::vector<Product>&products) = 0;
	virtual void displayProducts(const std::vector<Product>& products) = 0;
	virtual  void addProduct(std::vector<Product>& products, const Product& product)=0;
	virtual void removeProduct(std::vector<Product>& products, int productId)=0;
	virtual void updateProduct(std::vector<Product>& products, const Product& updatedProduct) = 0;
};

#pragma once
