#pragma once
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
#include "Customer.h"



class ICustomerPersistManager
{
public:
	virtual ~ICustomerPersistManager() {}

	virtual std::vector<Customer> loadCustomers() = 0;
	virtual  void saveCustomers(const std::vector<Customer>& customers) = 0;
	virtual void displayCustomers (const std::vector<Customer>& customers) = 0;
	virtual  void addCustomer(std::vector<Customer>& customers, const Customer& customer) = 0;
	virtual void removeCustomer(std::vector<Customer>& customers, int customerId) = 0;
	virtual void updateCustomer(std::vector<Customer>& customers, const Customer& updatedCustomer) = 0;
};

#pragma once
