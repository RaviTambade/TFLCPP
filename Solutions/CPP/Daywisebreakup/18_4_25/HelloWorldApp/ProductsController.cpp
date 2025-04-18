
#include "ProductRepository.h"
#include"ProductsController.h"
#include <iostream>
#include <string>


using namespace std;


ProductsController::ProductsController(ProductRepository& r, ProductService& s) : repo(r), service(s)  // Constructor implementation
{
	 
}

void ProductsController::addProduct(int id, const string& title, const string& description, const string& category, int quantity, double price) {
	Product* product = new Product(id, title, description, category, quantity, price);
	repo.addProduct(product);
}
	void ProductsController::removeProduct(int index) {
		repo.removeProduct(index);
	}
	void ProductsController::updateProduct(int index, Product* product) {
		repo.updateProduct(index, product);
	}
	void ProductsController::displayProducts() const {
		repo.displayProducts();
	}
	void ProductsController::applyDiscount(int productId, double discount) {
		service.applyDiscount(productId, discount);
	}

	void ProductsController::calculateTotalPrice(int productId) {
		service.calculateTotalPrice(productId);
	}


	void ProductsController::searchProductByTitle(const string& title) {
		service.searchProductByTitle(title);
	}

	void ProductsController::getProductId(int& productId) {
		std::cout << "Enter Product ID: ";
		std::cin >> productId;
	}

	void ProductsController::getProductIndex(int& index) {
		std::cout << "Enter Product Index: ";
		std::cin >> index;
	}

	void ProductsController::getProductTitle(string& title) {
		std::cout << "Enter Product Title: ";
		std::cin.ignore();
		std::getline(std::cin, title);
	}

	// Destructor
	ProductsController::~ProductsController() {
		// Clean up resources if needed
	}
	