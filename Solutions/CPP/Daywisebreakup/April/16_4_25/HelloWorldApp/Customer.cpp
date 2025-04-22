#include "Customer.h"

#include <iostream>
#include <string>
using namespace std;

Customer::Customer(int id, const std::string& n, const std::string& e, const std::string& p, const std::string& a)
	: customerId(id), name(n), email(e), phoneNumber(p), address(a) {
}
int Customer::getCustomerId() const { return customerId; }
std::string Customer::getName() const { return name; }
std::string Customer::getEmail() const { return email; }
std::string Customer::getPhoneNumber() const { return phoneNumber; }
std::string Customer::getAddress() const { return address; }
void Customer::setName(const std::string& n) { name = n; }
void Customer::setEmail(const std::string & e) { email = e; }
void Customer::setPhoneNumber(const std::string& p) { phoneNumber = p; }
void Customer::setAddress(const std::string& a) { address = a; }
void Customer::display() const {
	std::cout << "Customer ID: " << customerId << "\n"
		<< "Name: " << name << "\n"
		<< "Email: " << email << "\n"
		<< "Phone Number: " << phoneNumber << "\n"
		<< "Address: " << address << "\n";
}