
#ifndef __PRODUCTREPOSITORY_H
#define __PRODUCTREPOSITORY_H
#include "Product.h"
#include <iostream>
#include <string>
#include "product.h"
#include "ProductService.h"
using namespace std;

class ProductRepository {
private:
	Product* products[100];
	int productCount;

public:
	ProductRepository();
	~ProductRepository();
	void addProduct(Product* product);
	Product* getProduct(int index) const;
	Product* findProductById(int id) const;
	Product* findProductByTitle(const std::string& title) const;
	void removeProduct(int index);
	void updateProduct(int index, Product* product);
	void displayProducts() const;
};
#endif
