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

namespace Catalog {

	class Product {

	private:
		int productId;
		string title;
		string description;
		string category;
		int quantity;
		double price;

	public:

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
		ProductRepository& repo;
		ProductService& service;

	public:

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


 

	
	std::cout << "Thank you for visiting Transflower Store!\n";
	return 0;
}
