#include "Customer.h"

void Customer::serialize(const std::string& filename) {
    std::ofstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for writing!" << std::endl;
        return;
    }
    file.write(reinterpret_cast<char*>(this), sizeof(*this));
    file.close();
    std::cout << "Serialization successful." << std::endl;
}


Customer Customer::deserialize(const std::string& filename) {
    std::ifstream file(filename, std::ios::binary);
    if (!file) {
        std::cerr << "Error opening file for reading!" << std::endl;
        // Returning a default-initialized object if deserialization fails
        return Customer("", 0, 0.0);
    }
    Customer customer("", 0, 0.0);
    file.read(reinterpret_cast<char*>(&customer), sizeof(customer));
    file.close();
    std::cout << "Deserialization successful." << std::endl;
    return customer;
}


void Customer::display() const {
    std::cout << "Name: " << name << ", Age: " << age 
              << ", Salary: " << salary << std::endl;
}
