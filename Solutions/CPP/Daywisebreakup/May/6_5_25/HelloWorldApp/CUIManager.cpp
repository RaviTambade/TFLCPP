
#include <iostream>
#include <string>
#include "UIManager.h"
#include "Product.h"
#include "ProductRepository.h"

using namespace std;

 
	void CUIManager::displayWelcomeMessage() {
		std::cout << "Welcome to Transflower Store!" << std::endl;
	}
	void CUIManager::displayGoodbyeMessage() {
		std::cout << "Thank you for visiting Transflower Store!" << std::endl;
	}
	void CUIManager::displayErrorMessage(const std::string& message) {
		std::cout << "Error: " << message << std::endl;
	}
	void CUIManager::displaySuccessMessage(const std::string& message) {
		std::cout << "Success: " << message << std::endl;
	}


	void CUIManager::displayProductDetails(const Product& product) {
		product.display();
	}

	void CUIManager::displayProducts(const ProductRepository& repo) {
		repo.displayProducts();
	}

	void CUIManager::displayProductNotFound() {
		std::cout << "Product not found!" << std::endl;
	}

	void UCIManager::displayProductAdded() {
		std::cout << "Product added successfully!" << std::endl;
	}


	void CUIManager::displayMenu() {
		std::cout << "1. Add Product" << std::endl;
		std::cout << "2. Update Product" << std::endl;
		std::cout << "3. Remove Product" << std::endl;
		std::cout << "4. Display Products" << std::endl;
		std::cout << "5. Apply Discount" << std::endl;
		std::cout << "6. Calculate Total Price" << std::endl;
		std::cout << "7. Search Product by Title" << std::endl;
		std::cout << "8. Exit" << std::endl;
		std::cout << "9. Add To File" << std::endl;
	}

	void CUIManager::getProductDetails(int& id, string& title, string& description, string& category, int& quantity, double& price) {
		std::cout << "Enter Product ID: ";
		std::cin >> id;
		std::cout << "Enter Title: ";
		std::cin.ignore();
		std::getline(std::cin, title);
		std::cout << "Enter Description: ";
		std::getline(std::cin, description);
		std::cout << "Enter Category: ";
		std::getline(std::cin, category);
		std::cout << "Enter Quantity: ";
		std::cin >> quantity;
		std::cout << "Enter Price: ";
		std::cin >> price;
	}

	void CUIManager::getDiscountDetails(int& productId, double& discount) {
		std::cout << "Enter Product ID: ";
		std::cin >> productId;
		std::cout << "Enter Discount Percentage: ";
		std::cin >> discount;
	}


	void CUIManager::getProductId(int& productId) {
		std::cout << "Enter Product ID: ";
		std::cin >> productId;
	}


	void UIManager::getProductIndex(int& index) {
		std::cout << "Enter Product Index: ";
		std::cin >> index;
	}


	void CUIManager::getProductTitle(string& title) {
		std::cout << "Enter Product Title: ";
		std::cin.ignore();
		std::getline(std::cin, title);
	}

	void CUIManager::handleUserInput(ProductsController& controller) {
		int choice;
		do {
			displayMenu();
			std::cout << "Enter your choice: ";
			std::cin >> choice;
			switch (choice) {
			case 1: {
				int id, quantity;
				string title, description, category;
				double price;
				getProductDetails(id, title, description, category, quantity, price);
				controller.addProduct(id, title, description, category, quantity, price);
				displayProductAdded();
				break;
			}
			case 2: {
				int index;
				getProductIndex(index);
				Product* product = new Product(0); // Create a temporary product object
				int id, quantity;
				string title, description, category;
				double price;
				getProductDetails(id, title, description, category, quantity, price);
				product->setTitle(title);
				product->setDescription(description);
				product->setCategory(category);
				product->setQuantity(quantity);
				product->setPrice(price);
				controller.updateProduct(index, product);
				break;
			}
			case 3: {
				int index;
				getProductIndex(index);
				controller.removeProduct(index);
				break;
			}
			case 4:
				controller.displayProducts();
				break;
			case 5: {
				int productId;
				double discount;
				getDiscountDetails(productId, discount);
				controller.applyDiscount(productId, discount);
				break;
			}
			case 6: {
				int productId;
				controller.getProductId(productId);
				controller.calculateTotalPrice(productId);
				break;
			}
			case 7: {
				string title;
				getProductTitle(title);
				controller.searchProductByTitle(title);
				break;
			}
			case 8:
				std::cout << "Exiting..." << std::endl;
				break;

			case 9:
			{
				cout << "Save to File" << endl;
				controller.saveProducts();
			}
				break;
			default:
				std::cout << "Invalid choice! Please try again." << std::endl;
			}
		} while (choice != 8);
	}

 