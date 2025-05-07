#ifndef  __IPRODUCTSERVICE_H
#define __IPRODUCTSERVICE_H

#include <iostream>
#include <string>
#include "Product.h"
 

 

using namespace std;
#pragma once
class IProductService {

public: 
	virtual void applyDiscount(int productId, double discount)=0;
	virtual void calculateTotalPrice(int productId)=0;
	virtual void searchProductByTitle(const std::string& title)=0;
	virtual void saveProducts()=0;
};


#endif // ! __IPRODUCTSERVICE_H