#ifndef  __PRODUCTSERVICE_H
#define __PRODUCTSERVICE_H

#include <iostream>
#include <string>
 #include "Product.h"
#include "ProductRepository.h"	
 

// Forward declaration of ProductRepository
class ProductRepository;

using namespace std;
#pragma once
class ProductService {

private:
	ProductRepository& repo; 

public:
	ProductService(ProductRepository& r);
	void applyDiscount(int productId, double discount);
	void calculateTotalPrice(int productId);
	void searchProductByTitle(const std::string& title);
};

#endif // ! __PRODUCTSERVICE_H