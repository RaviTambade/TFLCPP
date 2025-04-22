#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include "Product.h"


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

