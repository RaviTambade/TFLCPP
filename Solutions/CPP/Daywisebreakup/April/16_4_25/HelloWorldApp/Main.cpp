#include <iostream>
#include <string>
#include <vector>
#include "Product.h"
#include "ProductRepository.h"
#include "ProductService.h"
#include "ProductsController.h"
#include "ProductIOManager.h"
#include "UIManager.h"

using namespace std;


int main()
{
    
	std::cout << "Welcome to Transflower Store!\n";
	/*
	ProductRepository repo;
	Product* product1 = new Product(1, "Gerbera", "Wedding Flower", "Flower", 10, 19.99);
	Product* product2 = new Product(2, "Rose", "Valentine Flower", "Flower", 5, 29.99);
	Product* product3 = new Product(3, "Jasmine", "Smelling Flower", "Flower", 20, 39.99);
	Product* product4 = new Product(4, "Mango", " Devgad Alphanso", "Fruit", 15, 49.99);

	repo.addProduct(product1);
	repo.addProduct(product2);
	repo.addProduct(product3);
	repo.addProduct(product4);

	repo.displayProducts();

	cout << "Apply Discount and Calculate Total Price\n";


	ProductService service(repo);
	service.applyDiscount(1, 10); // Apply 10% discount to product with ID 1
	service.calculateTotalPrice(1); // Calculate total price for product with ID 1
	service.searchProductByTitle("Rose"); // Search for product by title

	cout <<endl<< "Adding a new product...\n";

	ProductsController controller(repo, service);
	controller.addProduct(5, "Tulip", "Spring Flower", "Flower", 8, 15.99);
	controller.displayProducts(); // Display all products after adding a new one

	cout << "Updating product at index 1...\n";
	
	controller.updateProduct(1, new Product(2, "Lily", "Summer Flower", "Flower", 12, 25.99)); // Update product at index 1
	controller.displayProducts(); // Display all products after update
 
	UIManager uiManager;
	uiManager.displayWelcomeMessage();
	uiManager.handleUserInput(controller); // Handle user input through the UIManager
	uiManager.displayGoodbyeMessage();
	// Cleanup
	for (int i = 0; i < 100; i++) {
		delete repo.getProduct(i); // Delete each product in the repository
	}
	*/
	// Load products from file
	std::string filename = "products.txt";
	std::vector<Product> products;

	Product newProduct1(1, "Gerbera", "Wedding Flower", "Flower", 8, 15.99);
	ProductIOManager::addProduct(products, newProduct1);
	Product newProduct2(2, "Rose", "Valentine Flower", "Flower", 8, 15.99);
	ProductIOManager::addProduct(products, newProduct2);
	Product newProduct3(3, "Lotus", "Worship Flower", "Flower", 8, 15.99);
	ProductIOManager::addProduct(products, newProduct3);
	Product newProduct4(4, "Jasmine", "Semlling Flower", "Flower", 8, 15.99);
	ProductIOManager::addProduct(products, newProduct4);
	// Display products
	ProductIOManager::displayProducts(products);

	// Save products to file
	ProductIOManager::saveProductsToFile(filename, products);
	
	
	// Load products from file
	
	products = ProductIOManager::loadProductsFromFile(filename);
	// Remove a product
	ProductIOManager::removeProduct(products, 2); // Remove product with ID 2
	// Update a product
	Product updatedProduct(3, "Jasmine", "Updated Smelling Flower", "Flower", 20, 39.99);
	ProductIOManager::updateProduct(products, updatedProduct);
	// Display updated products
	ProductIOManager::saveProductsToFile(filename, products);
	std::cout << "Updated Products:\n";
	ProductIOManager::displayProducts(products);

	std::cout << "Thank you for visiting Transflower Store!\n";
	return 0;
}
