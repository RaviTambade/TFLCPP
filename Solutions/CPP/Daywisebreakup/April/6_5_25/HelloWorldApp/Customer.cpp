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


#include <fstream> // Add this include directive to resolve the incomplete type error

void Customer::load(std::ifstream& ifs) {
   ifs.read(reinterpret_cast<char*>(&customerId), sizeof(customerId));

   size_t nameLength;
   ifs.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
   name.resize(nameLength);
   ifs.read(&name[0], nameLength);

   size_t emailLength;
   ifs.read(reinterpret_cast<char*>(&emailLength), sizeof(emailLength));
   email.resize(emailLength);
   ifs.read(&email[0], emailLength);

   size_t phoneNumberLength;
   ifs.read(reinterpret_cast<char*>(&phoneNumberLength), sizeof(phoneNumberLength));
   phoneNumber.resize(phoneNumberLength);
   ifs.read(&phoneNumber[0], phoneNumberLength);

   size_t addressLength;
   ifs.read(reinterpret_cast<char*>(&addressLength), sizeof(addressLength));
   address.resize(addressLength);
   ifs.read(&address[0], addressLength);
}

  
void Customer::save(std::ofstream& ofs) const {
	ofs.write(reinterpret_cast<const char*>(&customerId), sizeof(customerId));
	size_t nameLength = name.size();
	ofs.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
	ofs.write(name.c_str(), nameLength);
	size_t emailLength = email.size();
	ofs.write(reinterpret_cast<const char*>(&emailLength), sizeof(emailLength));
	ofs.write(email.c_str(), emailLength);
	size_t phoneNumberLength = phoneNumber.size();
	ofs.write(reinterpret_cast<const char*>(&phoneNumberLength), sizeof(phoneNumberLength));
	ofs.write(phoneNumber.c_str(), phoneNumberLength);
	size_t addressLength = address.size();
	ofs.write(reinterpret_cast<const char*>(&addressLength), sizeof(addressLength));
	ofs.write(address.c_str(), addressLength);
}
 

void Customer::display() const {
	std::cout << "Customer ID: " << customerId << "\n"
		<< "Name: " << name << "\n"
		<< "Email: " << email << "\n"
		<< "Phone Number: " << phoneNumber << "\n"
		<< "Address: " << address << "\n";
}