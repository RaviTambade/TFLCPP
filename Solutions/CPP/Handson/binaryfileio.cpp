#include <iostream>
#include <fstream>
using namespace std;

class Product {
private:
    int id;
    char name[50];
    float price;

public:
    void input() {
        cout << "Enter product ID: ";
        cin >> id;
        cin.ignore(); // clear newline
        cout << "Enter product name: ";
        cin.getline(name, 50);
        cout << "Enter product price: ";
        cin >> price;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price << endl;
    }

    // Save the object to a binary file
    void saveToFile(const char* filename) {
        ofstream file(filename, ios::binary | ios::app);
        file.write(reinterpret_cast<char*>(this), sizeof(*this));
        file.close();
    }

    // Read all objects from a binary file
    static void readFromFile(const char* filename) {
        Product p;
        ifstream file(filename, ios::binary);
        while (file.read(reinterpret_cast<char*>(&p), sizeof(p))) {
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
