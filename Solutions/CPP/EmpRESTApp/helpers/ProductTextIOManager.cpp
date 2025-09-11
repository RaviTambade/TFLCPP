#include "ProductTextIOManager.h"
#include "Product.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

//
// ProductTextIOManager class implementation to store data in text file

// Save products to a file
void ProductTextIOManager::saveProducts( const std::vector<Product>& products) {
	// Open the file in write mode
	std::string filename = "products.txt";
	std::ofstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error opening file for writing: " << filename << std::endl;
		return;
	}
	// Write the products to the file
	for (const auto& product : products) {
		file << product.getProductId() << ","
			<< product.getTitle() << ","
			<< product.getDescription() << ","
			<< product.getPrice() << ","
			<< product.getQuantity() << "\n";
	}
	// Close the file
	file.close();
	std::cout << "Products saved to file: " << filename << std::endl;
}

// Load products from a file
std::vector<Product> ProductTextIOManager::loadProducts() {
	
	std::string filename = "products.txt";
	std::vector<Product> products;
	// Open the file in read mode
	std::ifstream file(filename);
	if (!file.is_open()) {
		std::cerr << "Error opening file for reading: " << filename << std::endl;
		return products;
	}
	// Read the products from the file
	std::string line;
	while (std::getline(file, line)) {
		std::istringstream iss(line);
		int id, quantity;
		std::string title, description;
		double price;
		if (iss >> id && iss.ignore() && std::getline(iss, title, ',') &&
			std::getline(iss, description, ',') &&
			iss >> price && iss.ignore() &&
			iss >> quantity) {
			Product product(id, title, description, price, quantity);
			products.push_back(product);
		}
	}
	// Close the file
	file.close();
	std::cout << "Products loaded from file: " << filename << std::endl;
	return products;
}

// Display products in the console
void ProductTextIOManager::displayProducts(const std::vector<Product>& products) {
	std::cout << "Product List:" << std::endl;
	for (const auto& product : products) {
		product.display();
	}
}

void ProductTextIOManager::addProduct(std::vector<Product>& products, const Product& product) {
	products.push_back(product);
	std::cout << "Product added: " << product.getTitle() << std::endl;
}

void ProductTextIOManager::removeProduct(std::vector<Product>& products, int productId) {
	auto it = std::remove_if(products.begin(), products.end(),
		[productId](const Product& product) { return product.getProductId() == productId; });
	if (it != products.end()) {
		std::cout << "Product removed: " << it->getTitle() << std::endl;
		products.erase(it, products.end());
	}
	else {
		std::cout << "Product with ID " << productId << " not found." << std::endl;
	}
}

void ProductTextIOManager::updateProduct(std::vector<Product>& products, const Product& updatedProduct) {
	auto it = std::find_if(products.begin(), products.end(),
		[updatedProduct](const Product& product) { return product.getProductId() == updatedProduct.getProductId(); });
	if (it != products.end()) {
		*it = updatedProduct;
		std::cout << "Product updated: " << updatedProduct.getTitle() << std::endl;
	}
	else {
		std::cout << "Product with ID " << updatedProduct.getProductId() << " not found." << std::endl;
	}
}

