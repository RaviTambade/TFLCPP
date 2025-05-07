
#include <iostream>
#include <string>
#include "Product.h"
#include "ProductRepository.h"
#include "ProductsController.h"
#include "ProductService.h"

using namespace std;
class CUIManager{

	public:

		void displayWelcomeMessage();
		void displayGoodbyeMessage();
		void displayErrorMessage(const std::string& message);
		void displaySuccessMessage(const std::string& message);


		void displayProductDetails(const Product& product);
		void displayProducts(const ProductRepository& repo);
		void displayProductNotFound();
		void displayProductAdded();
		void displayMenu();
		void getProductDetails(int& id, string& title, string& description, string& category, int& quantity, double& price);
		void getDiscountDetails(int& productId, double& discount);

		void getProductId(int& productId);
		void getProductIndex(int& index);
		void getProductTitle(string& title);
		void handleUserInput(ProductsController& controller);
};
