#include "CustomerBinaryIOManager.h"
 
#include "Customer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>

using namespace std;

void CustomerBinaryIOManager::saveCustomers(const std::vector<Customer>& Customers) {
	std::string filename = "Customers.dat";
	std::ofstream ofs(filename, std::ios::binary);


	if (!ofs) {
		std::cerr << "Failed to open file for writing: " << filename << "\n";
		return;
	}

	size_t size = Customers.size();
	ofs.write(reinterpret_cast<const char*>(&size), sizeof(size));

	for (const auto& Customer : Customers) {
		Customer.save(ofs);
	}
	std::cout << "Customers saved to file: " << filename << std::endl;
}


std::vector<Customer> CustomerBinaryIOManager::loadCustomers() {

	std::string filename = "customers.dat";

	std::ifstream ifs(filename, std::ios::binary);

	if (!ifs) {
		std::cerr << "Failed to open file for reading: " << filename << "\n";
		return {};
	}

	size_t size;
	ifs.read(reinterpret_cast<char*>(&size), sizeof(size));

	std::vector<Customer> Customers(size);
	for (auto& Customer : Customers) {
		Customer.load(ifs);
	}
	return Customers;
}


void CustomerBinaryIOManager::displayCustomers(const std::vector<Customer>& Customers) {

	std::cout << "Customer List:" << std::endl;
	for (const auto& Customer : Customers) {
		Customer.display();
	}
}

void CustomerBinaryIOManager::addCustomer(std::vector<Customer>& Customers, const Customer& Customer) {
	Customers.push_back(Customer);
	std::cout << "Customer added: " << Customer.getName() << std::endl;
}

void CustomerBinaryIOManager::removeCustomer(std::vector<Customer>& Customers, int CustomerId) {
	auto it = std::remove_if(Customers.begin(), Customers.end(),
		[CustomerId](const Customer& Customer) { return Customer.getCustomerId() == CustomerId; });
	if (it != Customers.end()) {
		std::cout << "Customer removed: " << it->getName() << std::endl;
		Customers.erase(it, Customers.end());
	}
	else {
		std::cout << "Customer with ID " << CustomerId << " not found." << std::endl;
	}
}

void CustomerBinaryIOManager::updateCustomer(std::vector<Customer>& Customers, const Customer& updatedCustomer) {
	auto it = std::find_if(Customers.begin(), Customers.end(),
		[updatedCustomer](const Customer& Customer) { return Customer.getCustomerId() == updatedCustomer.getCustomerId(); });
	if (it != Customers.end()) {
		*it = updatedCustomer;
		std::cout << "Customer updated: " << updatedCustomer.getName() << std::endl;
	}
	else {
		std::cout << "Customer with ID " << updatedCustomer.getCustomerId() << " not found." << std::endl;
	}
}