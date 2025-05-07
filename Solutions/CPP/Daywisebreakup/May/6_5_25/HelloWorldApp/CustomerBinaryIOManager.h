#include "Customer.h"
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include "ICustomerPersistManager.h"
#pragma once
class CustomerBinaryIOManager : public ICustomerPersistManager
{
public:
	void saveCustomers(const std::vector<Customer>& customers) override;
	std::vector<Customer> loadCustomers() override;

	void displayCustomers(const std::vector<Customer>& customers) override;

	void addCustomer(std::vector<Customer>& Customers, const Customer& customer) override;
	void removeCustomer(std::vector<Customer>& customers, int customerId) override;
	void updateCustomer(std::vector<Customer>& customers, const Customer& updatedCustomer) override;
};