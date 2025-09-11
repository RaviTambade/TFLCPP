#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include "Customer.h"

class IPersistCustomerManager
{
public:

	virtual std::vector<Customer> loadCustomer() = 0;
	virtual  void saveCustomer( std::vector<Customer>& customers) = 0;

	virtual void displayCustomer(const std::vector<Customer>& customers) = 0;

	virtual  void addCustomer(std::vector<Customer>& customers, const Customer& customer) = 0;
	virtual void removeCustomer(std::vector<Customer>& customers, int customerId) = 0;
	virtual void updateCustomer(std::vector<Customer>& customers, const Customer& updatedCustomer) = 0;
};

#pragma once
#pragma once
