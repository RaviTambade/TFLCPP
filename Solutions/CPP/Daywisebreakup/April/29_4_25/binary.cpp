#include <iostream>
#include <fstream>
#include <string>

class Product {
private:
    int id;
    std::string name;
    double price;

public:
    Product() : id(0), price(0.0) {}
    Product(int id, const std::string& name, double price)
        : id(id), name(name), price(price) {}

    void saveToBinary(std::ofstream& outFile) const {
        outFile.write(reinterpret_cast<const char*>(&id), sizeof(id));
        
        size_t nameLength = name.size();
        outFile.write(reinterpret_cast<const char*>(&nameLength), sizeof(nameLength));
        outFile.write(name.c_str(), nameLength);
        
        outFile.write(reinterpret_cast<const char*>(&price), sizeof(price));
    }

    void loadFromBinary(std::ifstream& inFile) {
        inFile.read(reinterpret_cast<char*>(&id), sizeof(id));
        
        size_t nameLength;
        inFile.read(reinterpret_cast<char*>(&nameLength), sizeof(nameLength));
        
        name.resize(nameLength);
        inFile.read(&name[0], nameLength);
        
        inFile.read(reinterpret_cast<char*>(&price), sizeof(price));
    }

    void display() const {
        std::cout << "ID: " << id << "\nName: " << name << "\nPrice: " << price << "\n";
    }
};

int main() {
    Product p1(101, "Laptop", 59999.99);

    // Save to binary file
    {
        std::ofstream outFile("product.bin", std::ios::binary);
        if (!outFile) {
            std::cerr << "Cannot open file for writing.\n";
            return 1;
        }
        p1.saveToBinary(outFile);
    }

    // Load from binary file
    Product p2;
    {
        std::ifstream inFile("product.bin", std::ios::binary);
        if (!inFile) {
            std::cerr << "Cannot open file for reading.\n";
            return 1;
        }
        p2.loadFromBinary(inFile);
    }

    std::cout << "Loaded product:\n";
    p2.display();

    return 0;
}
