#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "ProductRepository.h"
#include "ProductService.h"
#include "ProductsController.h"
#include  "IPersistManager.h"
#include "ProductTextIOManager.h"
#include "ProductBinaryIOManger.h"
#include "ProductJSONIOManager.h"
#include "UIManager.h"

using namespace std;

//Consumer code for the Product Management System
// This code demonstrates the use of the Product Management System

int main()
{

	//Loosely Coupled  , Highly Cohesive Application structure
	//Use of Interfaces and Abstract Classes
	//Use of Concrete Classes
	//Method invocation using Polymorphism

	std::cout << "Welcome to Transflower Store!\n";

	// Load products  into Vector container from file

	std::vector<Product> products;

	//Interface is pointing to the implementation class ProductTextIOManager
	//This allows for different implementations of Product Persistence Management
	//IPersistManager *ptrMgr=new ProductTextIOManager();

	//Interface is pointing to the implementation class ProductBinaryIOManager
	// This allows for different implementations of Product Persistence Management

	//IPersistManager* ptrMgr = new ProductTextIOManager();
	//IPersistManager* ptrMgr = new ProductBinaryIOManager();
	IPersistManager* ptrMgr = new ProductJSONIOManager();
	products = ptrMgr->loadProducts();
	

	// Add products to the repository  from vector container
	ProductRepository repo;
	for (const auto& product : products) {
		Product* pProduct = new Product(product.getProductId(), product.getTitle(), product.getDescription(), product.getCategory(), product.getQuantity(), product.getPrice());
		repo.addProduct(pProduct);
	}

	//Set up User Interface
	UIManager uiManager;  ///View
	ProductService service(repo); //service
	ProductsController controller(repo, service); //controller

	// Display the menu and handle user input
	//Console Menu Driven  User ineraction
	uiManager.displayWelcomeMessage(); // Display welcome message
	uiManager.handleUserInput(controller); // Handle user input through the UIManager
	return 0;
}


/*
	/*
	cout <<endl<< "Adding a new product...\n";

	controller.addProduct(5, "Tulip", "Spring Flower", "Flower", 8, 15.99);
	controller.displayProducts(); // Display all products after adding a new one

	cout << "Updating product at index 1...\n";

	controller.updateProduct(1, new Product(2, "Lily", "Summer Flower", "Flower", 12, 25.99)); // Update product at index 1
	controller.displayProducts(); // Display all products after update

	// Cleanup
	for (int i = 0; i < 100; i++) {
		delete repo.getProduct(i); // Delete each product in the repository
	}

	// Load products from file

	ProductIOManager::saveProductsToFile(filename, products);
	*/


/*
	service.applyDiscount(1, 10); // Apply 10% discount to product with ID 1
	service.calculateTotalPrice(1); // Calculate total price for product with ID 1
	service.searchProductByTitle("Rose"); // Search for product by title

	*/
