#include <iostream>
#include <fstream>
#include <string>
using namespace std;

class Product {
private:
    int id;
    string name;
    float price;

public:
    void input() {
        cout << "Enter product ID: ";
        cin >> id;
        cin.ignore(); // clear newline
        cout << "Enter product name: ";
        getline(cin, name);
        cout << "Enter product price: ";
        cin >> price;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price << endl;
    }

    void saveToFile(const char* filename) {
        ofstream file(filename, ios::binary | ios::app);
        if (!file) {
            cerr << "Error opening file for writing.\n";
            return;
        }

        // Write id
        file.write(reinterpret_cast<char*>(&id), sizeof(id));

        // Write string length and then the string characters
        size_t nameLen = name.length();
        file.write(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
        file.write(name.c_str(), nameLen);

        // Write price
        file.write(reinterpret_cast<char*>(&price), sizeof(price));

        file.close();
    }

    static void readFromFile(const char* filename) {
        ifstream file(filename, ios::binary);
        if (!file) {
            cerr << "Error opening file for reading.\n";
            return;
        }

        while (file.peek() != EOF) {
            Product p;
            size_t nameLen;
            char* tempName;

            // Read id
            file.read(reinterpret_cast<char*>(&p.id), sizeof(p.id));

            // Read name length, then the name itself
            file.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));
            tempName = new char[nameLen + 1];
            file.read(tempName, nameLen);
            tempName[nameLen] = '\0';
            p.name = string(tempName);
            delete[] tempName;

            // Read price
            file.read(reinterpret_cast<char*>(&p.price), sizeof(p.price));

            p.display();
        }

        file.close();
    }
};

int main() {
    Product p;
    p.input();
    p.saveToFile("products.dat");

    cout << "\nProducts from file:\n";
    Product::readFromFile("products.dat");

    return 0;
}
