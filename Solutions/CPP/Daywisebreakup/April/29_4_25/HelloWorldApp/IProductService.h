#ifndef __IPRODUCTSERVICE_H
#define __IPRODUCTSERVICE_H

#include <iostream>
#include <string>
#include "Product.h"
#include "ProductRepository.h"	


// Forward declaration of ProductRepository
class ProductRepository;

using namespace std;
#pragma once
class IProductService {

private:
	ProductRepository& repo;

public:
	
	//Pure virutal function enforces the derived classes to implement these functions
	virtual void applyDiscount(int productId, double discount)=0;
	virtual void calculateTotalPrice(int productId)=0;
	virtual void searchProductByTitle(const std::string& title)=0;
	virtual void saveProducts()=0;
};


#endif // ! __PRODUCTSERVICE_H