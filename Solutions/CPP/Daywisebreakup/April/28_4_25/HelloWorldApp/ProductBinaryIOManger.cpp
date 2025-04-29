#include "ProductBinaryIOManger.h"
#include "Product.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

//Binary I/O Manager for Product using dat file
// Save products to a file
void ProductBinaryIOManager::saveProducts(const std::vector<Product>& products) {
	// Open the file in write mode
	std::string filename = "products.dat";
	//binary file data write

	std::ofstream ofs(filename, std::ios::binary);
	if (!ofs) {
		std::cerr << "Failed to open file for writing: " << filename << "\n";
		return;
	}

	size_t size = products.size();
	ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));
	for (const auto& product : products) {
		product.save(ofs);
	}
	std::cout << "Products saved to file: " << filename << std::endl;
}

// Load products from a file
std::vector<Product> ProductBinaryIOManager::loadProducts() {
	
	// Open the file in read mode
	std::string filename = "products.dat";
	std::ifstream ifs(filename, std::ios::binary);
	if (!ifs) {
		std::cerr << "Failed to open file for reading: " << filename << "\n";
		return {};
	}

	size_t size;
	ifs.read(reinterpret_cast<char*>(&size), sizeof(size));

	std::vector<Product> products(size);
	for (auto& product : products) {
		product.load(ifs);
	}
	return products;
	
}

// Display products in the console
void ProductBinaryIOManager::displayProducts(const std::vector<Product>& products) {
	std::cout << "Product List:" << std::endl;
	for (const auto& product : products) {
		product.display();
	}
}

void ProductBinaryIOManager::addProduct(std::vector<Product>& products, const Product& product) {
	products.push_back(product);
	std::cout << "Product added: " << product.getTitle() << std::endl;
}
void ProductBinaryIOManager::removeProduct(std::vector<Product>& products, int productId) {
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
void ProductBinaryIOManager::updateProduct(std::vector<Product>& products, const Product& updatedProduct) {
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