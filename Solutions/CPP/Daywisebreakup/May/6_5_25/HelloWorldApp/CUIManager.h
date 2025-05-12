
#include <iostream>
#include <string>
#include "Product.h"
#include "IUIManager.h"
#include "ProductRepository.h"
#include "ProductsController.h"
#include "ProductService.h"

using namespace std;
class CUIManager : public IUIManager
{

	public:

		void displayWelcomeMessage() override;
		void displayGoodbyeMessage() override;
		void displayErrorMessage(const std::string& message) override;
		void displaySuccessMessage(const std::string& message) override;


		void displayProductDetails(const Product& product) override;
		void displayProducts(const ProductRepository& repo) override;
		void displayProductNotFound() override;
		void displayProductAdded() override;
		void displayMenu() override;
		void getProductDetails(int& id, string& title, string& description, string& category, int& quantity, double& price) override;
		void getDiscountDetails(int& productId, double& discount) override;

		void getProductId(int& productId) override;
		void getProductIndex(int& index) override;
		void getProductTitle(string& title) override ;
		void handleUserInput(ProductsController& controller) override ;
};
