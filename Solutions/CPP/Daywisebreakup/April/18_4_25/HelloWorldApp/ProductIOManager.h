#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include "Product.h"

//Here is the ProductIOManager class that handles file operations for products:
// This class is responsible for
/*saving, loading, displaying, adding, removing, and updating products in a file.*/

// It provides static methods to perform these operations, 
// //making it easy to manage product data.
class ProductIOManager
{
public:
	static void saveProductsToFile(const std::string& filename, const std::vector<Product>& products);
	static std::vector<Product> loadProductsFromFile(const std::string& filename);
	static void displayProducts(const std::vector<Product>& products);
	static void addProduct(std::vector<Product>& products, const Product& product);
	static void removeProduct(std::vector<Product>& products, int productId);
	static void updateProduct(std::vector<Product>& products, const Product& updatedProduct);
};

