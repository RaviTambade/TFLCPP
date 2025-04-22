#include <iostream>
#include <string>
#include <vector>
#include "ProductRepository.h"

#include "Product.h"
#include "IPersistManager.h"
#include "ProductTextIOManager.h"


using namespace std;

// Constructor and Destructor
ProductRepository::ProductRepository() : productCount(0) {}

ProductRepository::~ProductRepository() {
		for (int i = 0; i < productCount; i++) {
			delete products[i];
		}
	}

	void ProductRepository::addProduct(Product* product) {
		if (productCount < 100) {
			cout << "product count" << productCount << endl;
			products[productCount++] = product;
		}
		else {
			cout << "Product repository is full!" << std::endl;
		}
	}

	Product* ProductRepository::getProduct(int index) const {
		if (index >= 0 && index < productCount) {
			return products[index];
		}
		return nullptr;
	}

	Product* ProductRepository::findProductById(int id) const {
		for (int i = 0; i < productCount; i++) {
			if (products[i]->getProductId() == id) {
				return products[i];
			}
		}
		return nullptr;
	}
	Product* ProductRepository::findProductByTitle(const std::string& title) const {
		for (int i = 0; i < productCount; i++) {
			if (products[i]->getTitle() == title) {
				return products[i];
			}
		}
		return nullptr;
	}

	void ProductRepository::removeProduct(int index) {
		if (index >= 0 && index < productCount) {
			delete products[index];
			for (int i = index; i < productCount - 1; i++) {
				products[i] = products[i + 1];
			}
			productCount--;
		}
		else {
			std::cout << "Invalid index!" << std::endl;
		}
	}

	void ProductRepository::updateProduct(int index, Product* product) {
		if (index >= 0 && index < productCount) {
			products[index]->setTitle(product->getTitle());
			products[index]->setDescription(product->getDescription());
			products[index]->setCategory(product->getCategory());
			products[index]->setQuantity(product->getQuantity());
			products[index]->setPrice(product->getPrice());
		}
		else {
			std::cout << "Invalid index!" << std::endl;
		}
	}

	void ProductRepository::displayProducts() const {
		for (int i = 0; i < productCount; i++) {
			products[i]->display();
			std::cout << "------------------------" << std::endl;
		}
	
	}

	void ProductRepository::saveProducts() {
		std::string filename = "products.txt";
		std::vector<Product> tempProducts;
		
		for (int i = 0; i < productCount; i++) {
			//products[i]->display();
			tempProducts.push_back(*(products[i]));
			std::cout << "------------------------" << std::endl;
		}
		
		// Save products to file using ProductIOManager
		//create derived class and point to base class
		IPersistManager* ptrMgr = new ProductTextIOManager();
		
		ptrMgr->saveProducts(tempProducts);   //Polymorphism 
	}

