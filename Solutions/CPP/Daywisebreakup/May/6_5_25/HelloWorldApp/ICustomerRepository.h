
#ifndef __ICUSTOMERREPOSITORY_H
#define __ICUSTOMERREPOSITORY_H
#include "Customer.h"
#include <iostream>
#include <string>


using namespace std;

class ICustomerRepository {
public:
	virtual ~ICustomerRepository() = default;
	virtual void addCustomer(Customer* customer) = 0;
	virtual Customer* getCustomer(int index) const = 0;
	virtual Customer* findCustomerById(int id) const = 0;
	virtual Customer* findCustomerByTitle(const std::string& title) const = 0;
	virtual void removeCustomer(int index) = 0;
	virtual void updateCustomer(int index, Customer* customer) = 0;
	virtual void displayCustomers() const = 0;
	virtual void saveCustomers() = 0;
};
#endif
