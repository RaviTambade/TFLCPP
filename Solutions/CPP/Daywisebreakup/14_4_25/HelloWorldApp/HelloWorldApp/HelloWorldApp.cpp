#include <iostream>
#include <string>
 
//Application  using layered architecture
// This is a simple C++ program that demonstrates a layered architecture for a flower store application.
// The program consists of three main layers: Model, Service, and Controller.
// The Model layer contains the Product class and ProductRepository class.
// The Service layer contains the ProductService class.
// The Controller layer contains the ProductController class.
// The main function demonstrates the functionality of the application by creating products, applying discounts, and displaying product information.

using namespace std;

//Each class has its own responsibility

//Product class represents a product in the store
//ProductRepository class manages a collection of products
//ProductService class handles business logic related to products
//ProductController class manages the interaction between the ProductRepository and ProductService
//UIManager class handles user interface interactions


//Abstraction
// 
//Namespace to encapsulate the classes and avoid naming conflicts

namespace Catalog {

	class Product {


	//Encapsulation
	private:

		//state
		// Attributes of the Product class
		int productId;
		string title;
		string description;
		string category;
		int quantity;
		double price;

	public:
		//Behavior
		//Member functions

		//constructors
		Product(int id) : productId(id), quantity(0), price(0.0) {}

		Product(int id, const string& t, const string& d, const string& c, int q, double p)
			: productId(id), title(t), description(d), category(c), quantity(q), price(p) {
		}


		// Getters and Setters for other attributes

		int getProductId() const { return productId; }

		string getTitle() const { return title; }
		void setTitle(const string& t) { title = t; }

		string getDescription() const { return description; }
		void setDescription(const string& d) { description = d; }

		string  getCategory() { return category; }
		void setCategory(const string& c) { category = c; }

		int getQuantity() const { return quantity; }
		void setQuantity(int q) { quantity = q; }

		double getPrice() const { return price; }
		void setPrice(double p) { price = p; }


		// Additional methods for calculating total price and discounted price
		double getTotalPrice() const { return quantity * price; }
		double getDiscountedPrice(double discount) const { return price - (price * discount / 100); }

		//Presentation method to display product details

		void display() const {
			cout << "Product ID: " << productId << endl;
			cout << "Title: " << title << endl;
			cout << "Description: " << description << endl;
			cout << "Category: " << category << endl;
			cout << "Quantity: " << quantity << endl;
			cout << "Price: $" << price << endl;
		}
	};

	class ProductRepository {

	private:

		// Array of pointers to Product objects
		Product* products[100];
		int productCount;
	
	public:

		// Constructor and Destructor
		ProductRepository() : productCount(0) {}

		~ProductRepository() {
			for (int i = 0; i < productCount; i++) {
				delete products[i];
			}
		}

		void addProduct(Product* product) {
			if (productCount < 100) {
				cout << "product count" << productCount<<endl;
				products[productCount++] = product;
			}
			else {
				cout << "Product repository is full!" << std::endl;
			}
		}

		Product* getProduct(int index) const {
			if (index >= 0 && index < productCount) {
				return products[index];
			}
			return nullptr;
		}

		Product* findProductById(int id) const {
			for (int i = 0; i < productCount; i++) {
				if (products[i]->getProductId() == id) {
					return products[i];
				}
			}
			return nullptr;
		}
		Product* findProductByTitle(const std::string& title) const {
			for (int i = 0; i < productCount; i++) {
				if (products[i]->getTitle() == title) {
					return products[i];
				}
			}
			return nullptr;
		}

		void removeProduct(int index) {
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

		void updateProduct(int index, Product* product) {
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

		void displayProducts() const {
			for (int i = 0; i < productCount; i++) {
				products[i]->display();
				std::cout << "------------------------" << std::endl;
			}
		}

	};

	// ProductService class to handle business logic related to products
	// This class can be used to implement business logic related to products
	// For example, applying discounts, calculating total price, etc.

	class ProductService {

	private:
		ProductRepository& repo; // Reference to the ProductRepository

	public:
		ProductService(ProductRepository& r) : repo(r) {}

		void applyDiscount(int productId, double discount) {
			Product* product = repo.findProductById(productId);
			if (product) {
				double discountedPrice = product->getDiscountedPrice(discount);
				product->setPrice(discountedPrice);
			}
			else {
				std::cout << "Product not found!" << std::endl;
			}
		}


		void calculateTotalPrice(int productId) {
			Product* product = repo.findProductById(productId);
			if (product) {
				double totalPrice = product->getTotalPrice();
				std::cout << "Total Price for " << product->getTitle() << ": $" << totalPrice << std::endl;
			}
			else {
				std::cout << "Product not found!" << std::endl;
			}
		}

		void searchProductByTitle(const std::string& title) {
			Product* product = repo.findProductByTitle(title);
			if (product) {
				product->display();
			}
			else {
				std::cout << "Product not found!" << std::endl;
			}
		}
	};


	class ProductController {

		// This class acts as a controller to manage the interaction between the ProductRepository and ProductService
	private:
		//state
		ProductRepository& repo;
		ProductService& service;

	public:
		//behavior

		ProductController(ProductRepository& r, ProductService& s) : repo(r), service(s) {}

		void addProduct(int id, const string& title, const string& description, const string& category, int quantity, double price) {
			Product* product = new Product(id, title, description, category, quantity, price);
			repo.addProduct(product);
		}
		void removeProduct(int index) {
			repo.removeProduct(index);
		}
		void updateProduct(int index, Product* product) {
			repo.updateProduct(index, product);
		}
		void displayProducts() const {
			repo.displayProducts();
		}
		void applyDiscount(int productId, double discount) {
			service.applyDiscount(productId, discount);
		}

		void calculateTotalPrice(int productId) {
			service.calculateTotalPrice(productId);
		}


		void searchProductByTitle(const string& title) {
			service.searchProductByTitle(title);
		}

		void getProductId(int& productId) {
			std::cout << "Enter Product ID: ";
			std::cin >> productId;
		}

		void getProductIndex(int& index) {
			std::cout << "Enter Product Index: ";
			std::cin >> index;
		}

		void getProductTitle(string& title) {
			std::cout << "Enter Product Title: ";
			std::cin.ignore();
			std::getline(std::cin, title);
		}
	};


	class UIManager {
		// This class can be used to manage the user interface
		// For simplicity, we are not implementing a UI in this example
	public:

		void displayWelcomeMessage() {
			std::cout << "Welcome to Transflower Store!" << std::endl;
		}
		void displayGoodbyeMessage() {
			std::cout << "Thank you for visiting Transflower Store!" << std::endl;
		}
		void displayErrorMessage(const std::string& message) {
			std::cout << "Error: " << message << std::endl;
		}
		void displaySuccessMessage(const std::string& message) {
			std::cout << "Success: " << message << std::endl;
		}


		void displayProductDetails(const Product& product) {
			product.display();
		}

		void displayProducts(const ProductRepository& repo) {
			repo.displayProducts();
		}

		void displayProductNotFound() {
			std::cout << "Product not found!" << std::endl;
		}

		void displayProductAdded() {
			std::cout << "Product added successfully!" << std::endl;
		}


		//Console Menu Driven Display
		void displayMenu() {
			std::cout << "1. Add Product" << std::endl;
			std::cout << "2. Update Product" << std::endl;
			std::cout << "3. Remove Product" << std::endl;
			std::cout << "4. Display Products" << std::endl;
			std::cout << "5. Apply Discount" << std::endl;
			std::cout << "6. Calculate Total Price" << std::endl;
			std::cout << "7. Search Product by Title" << std::endl;
			std::cout << "8. Exit" << std::endl;
		}

		void getProductDetails(int& id, string& title, string& description, string& category, int& quantity, double& price) {
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

		void getDiscountDetails(int& productId, double& discount) {
			std::cout << "Enter Product ID: ";
			std::cin >> productId;
			std::cout << "Enter Discount Percentage: ";
			std::cin >> discount;
		}


		void getProductId(int& productId) {
			std::cout << "Enter Product ID: ";
			std::cin >> productId;
		}


		void getProductIndex(int& index) {
			std::cout << "Enter Product Index: ";
			std::cin >> index;
		}


		void getProductTitle(string& title) {
			std::cout << "Enter Product Title: ";
			std::cin.ignore();
			std::getline(std::cin, title);
		}


		//Menu driven function to handle user input
		//switch code

		void handleUserInput(ProductController& controller) {
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
				default:
					std::cout << "Invalid choice! Please try again." << std::endl;
				}
			} while (choice != 8);
		}


	};
}


using  namespace Catalog;
// Main function to demonstrate the functionality
int main()
{
    
	std::cout << "Welcome to Transflower Store!\n";

	// Create a ProductRepository and add some products

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

	ProductController controller(repo, service);
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
	
	std::cout << "Thank you for visiting Transflower Store!\n";
	return 0;
}
