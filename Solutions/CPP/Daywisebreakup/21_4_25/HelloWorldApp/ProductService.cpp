

#include <iostream>
#include <string>
 
#include "ProductService.h"
#include "Product.h"

 
ProductService::ProductService(ProductRepository& r):repo(r) {
}

void ProductService::applyDiscount(int productId, double discount) {
}
void ProductService::calculateTotalPrice(int productId) {
}
void ProductService::searchProductByTitle(const std::string& title){

};
void ProductService::saveProducts() {
	this->repo.saveProducts();
}

