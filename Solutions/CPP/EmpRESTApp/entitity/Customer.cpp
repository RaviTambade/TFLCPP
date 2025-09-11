#include "Customer.h"
#include <iostream>
#include<fstream>
#include <string>
#include"CustomerBinaryIOManger.h"


using namespace std;

Customer::Customer() {}

Customer::Customer(string f, string l, string e, int id, int a) {
	firstname = f;
	lastname = l;
	email = e;
	customerId = id;
	age = a;
}



void Customer::setFirstname( const string& f) {
	firstname = f;
}
void Customer::setLastname(const string& l) {
	lastname = l;
}
void Customer::setEmail(const string& e) {
	email = e;
}
void Customer::setCustomerId(const int id) {
	customerId = id;
}
void Customer::setAge(const int a) {
	age = a;
}
string Customer::getFirstname() {
	return firstname;
}
string  Customer::getLastname() {
	return lastname;
}
string Customer::getEmail() {
	return email;
}

int Customer::getCustomerId()  const{
	return customerId;
}

int Customer::getAge() {
	return age;
}

void Customer::serialize(ofstream& ofs) {

	size_t  firstnameLength = firstname.size();
	ofs.write(reinterpret_cast<char*>(&firstnameLength), sizeof(firstnameLength));
	ofs.write(firstname.c_str(), firstnameLength);

	size_t  lastnameLength = lastname.size();
	ofs.write(reinterpret_cast<char*>(&lastnameLength), sizeof(lastnameLength));
	ofs.write(lastname.c_str(), lastnameLength);

	size_t  emailLength = email.size();
	ofs.write(reinterpret_cast<char*>(&emailLength), sizeof(emailLength));
	ofs.write(email.c_str(), emailLength);
	ofs.write(reinterpret_cast<char*>(&customerId), sizeof(customerId));
	ofs.write(reinterpret_cast<char*>(&age), sizeof(age));

}
void Customer::deserialize(ifstream& ifs) {
	int id;
	int ag;
	size_t firstNameLength;
	size_t lastNameLength;
	size_t emailLength;
	string first;
	string last;
	string email;


	ifs.read(reinterpret_cast<char*>(&firstNameLength), sizeof(firstNameLength));
	first.resize(firstNameLength);
	ifs.read(&first[0], firstNameLength);

	ifs.read(reinterpret_cast<char*>(&lastNameLength), sizeof(lastNameLength));
	last.resize(lastNameLength);
	ifs.read(&last[0], lastNameLength);

	ifs.read(reinterpret_cast<char*>(&emailLength), sizeof(emailLength));
	email.resize(emailLength);
	ifs.read(&email[0], emailLength);

	ifs.read(reinterpret_cast<char*>(&id), sizeof(id));
	ifs.read(reinterpret_cast<char*>(&ag), sizeof(ag));


	firstname = first;
	lastname = last;
	this->email = email;
	customerId = id;
	age = ag;

}
void Customer::display()  const {
	cout << "Customer ID=" << customerId << endl;
	cout << "First Name= " << firstname << endl;
	cout << "Last Name=" << lastname << endl;
	cout << "Email=: " << email << endl;
	cout << "Age= " << age << endl;
}


