#pragma once
#include <iostream>
#include <string>
using namespace std;

class Customer
{
private:
	int customerId;
	std::string name;
	std::string email;
	std::string phoneNumber;
	std::string address;
public:
	Customer(int id, const std::string& n, const std::string& e, const std::string& p, const std::string& a);
		
	int getCustomerId() const;
	std::string getName() const;
	std::string getEmail() const;
	std::string getPhoneNumber() const;
	std::string getAddress() const;
	void setName(const std::string& n);
	void setEmail(const std::string& e);
	void setPhoneNumber(const std::string& p);
	void setAddress(const std::string& a);
	void display() const;
};

