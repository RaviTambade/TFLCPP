#pragma once

#include <iostream>
#include <string>
#include "Product.h"
#include "ProductsController.h"

using namespace std;
class IProductUIManager {

public:

	 
	virtual void displayWelcomeMessage()=0;
	virtual void displayGoodbyeMessage() = 0;
	virtual void displayErrorMessage(const std::string& message) = 0;
	virtual void displaySuccessMessage(const std::string& message) = 0;


	virtual void displayProductDetails(const Product& product) = 0;
	virtual void displayProducts(const ProductRepository& repo) = 0;
	virtual void displayProductNotFound() = 0;
	virtual void displayProductAdded()=0;
	virtual void displayMenu() = 0;
	virtual void getProductDetails(int& id, string& title, string& description, string& category, int& quantity, double& price) = 0;
	virtual void getDiscountDetails(int& productId, double& discount) = 0;

	virtual void getProductId(int& productId) = 0;
	virtual void getProductIndex(int& index) = 0;
	virtual void getProductTitle(string& title) = 0;
	virtual void handleUserInput(ProductsController& controller) = 0;
};
