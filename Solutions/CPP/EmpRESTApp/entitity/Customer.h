#ifndef CUSTOMER_H
#define CUSTOMER_H
#include <iostream>
#include <string>

using namespace std;

class Customer
{
private:
	string firstname;
	string lastname;
	string email;
	int customerId;
	int age;
public:
	Customer();
	Customer(string f, string l, string e, int id, int a);

	void setFirstname(const string& f);

	void setLastname(const string& l);

	void setEmail(const string& e);
	void setCustomerId(const int id);
	void setAge(const int a);


	string getFirstname();
	string getLastname();
	string getEmail();
    int getCustomerId() const;

	int getAge();
	void display() const;

	//friend istream& operator>>(istream& is, Customer& cus);
	// ostream& operator<<(ostream& os, const Customer& cus);

	void serialize(ofstream& outFile);
	void deserialize(ifstream& inFile);
};

#endif

#pragma once
