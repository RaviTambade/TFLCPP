#include <iostream>
#include <fstream>
#include <string>
#include <vector>
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

    void saveToFile(ofstream &file) const {
        size_t nameLen = name.length();

        file.write(reinterpret_cast<const char*>(&id), sizeof(id));
        file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        file.write(name.c_str(), nameLen);
        file.write(reinterpret_cast<const char*>(&price), sizeof(price));
    }

    static Product readFromFile(ifstream &file) {
        Product p;
        size_t nameLen;
        char* tempName;

        file.read(reinterpret_cast<char*>(&p.id), sizeof(p.id));
        file.read(reinterpret_cast<char*>(&nameLen), sizeof(nameLen));

        tempName = new char[nameLen + 1];
        file.read(tempName, nameLen);
        tempName[nameLen] = '\0';
        p.name = string(tempName);
        delete[] tempName;

        file.read(reinterpret_cast<char*>(&p.price), sizeof(p.price));

        return p;
    }
};

int main() {
    vector<Product> products;
    int n;

    cout << "How many products do you want to enter? ";
    cin >> n;

    for (int i = 0; i < n; ++i) {
        cout << "\nProduct #" << (i + 1) << ":\n";
        Product p;
        p.input();
        products.push_back(p);
    }

    // Save all products to file
    ofstream outFile("products.dat", ios::binary | ios::app);
    for (const auto& p : products) {
        p.saveToFile(outFile);
    }
    outFile.close();

    // Read all products back from file
    cout << "\nProducts from file:\n";
    ifstream inFile("products.dat", ios::binary);
    while (inFile.peek() != EOF) {
        Product p = Product::readFromFile(inFile);
        p.display();
    }
    inFile.close();

    return 0;
}
