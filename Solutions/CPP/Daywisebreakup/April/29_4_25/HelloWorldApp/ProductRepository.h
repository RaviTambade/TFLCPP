
#ifndef __PRODUCTREPOSITORY_H
#define __PRODUCTREPOSITORY_H
#include "Product.h"
#include <iostream>
#include <string>
#include "product.h"
# include "IProductRepository.h"
#include "ProductService.h"
using namespace std;

class ProductRepository:IProductRepository {
private:
	Product* products[100];
	int productCount;

public:
	ProductRepository();
	~ProductRepository();
	void addProduct(Product* product) override;
	Product* getProduct(int index) const override;
	Product* findProductById(int id) const override;
	Product* findProductByTitle(const std::string& title) const override;
	void removeProduct(int index) override;
	void updateProduct(int index, Product* product) override;
	void displayProducts() const override;
	void saveProducts()override;
};
#endif
