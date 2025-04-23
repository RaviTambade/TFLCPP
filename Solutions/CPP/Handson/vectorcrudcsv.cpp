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
        cin.ignore();
        cout << "Enter product name: ";
        getline(cin, name);
        cout << "Enter product price: ";
        cin >> price;
    }

    void display() const {
        cout << "ID: " << id << ", Name: " << name << ", Price: " << price << endl;
    }

    int getId() const {
        return id;
    }
 
    string getName() const { return name; }
    float getPrice() const { return price; }

    void saveToFile(ofstream& file) const {
        size_t nameLen = name.length();
        file.write(reinterpret_cast<const char*>(&id), sizeof(id));
        file.write(reinterpret_cast<const char*>(&nameLen), sizeof(nameLen));
        file.write(name.c_str(), nameLen);
        file.write(reinterpret_cast<const char*>(&price), sizeof(price));
    }

    static Product readFromFile(ifstream& file) {
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

void writeAllToFile(const vector<Product>& products, const char* filename) {
    ofstream file(filename, ios::binary | ios::trunc);
    for (const auto& p : products) {
        p.saveToFile(file);
    }
    file.close();
}

vector<Product> readAllFromFile(const char* filename) {
    vector<Product> products;
    ifstream file(filename, ios::binary);
    while (file.peek() != EOF) {
        products.push_back(Product::readFromFile(file));
    }
    file.close();
    return products;
}

void editProduct(const char* filename, int targetId) {
    vector<Product> products = readAllFromFile(filename);
    bool found = false;

    for (auto& p : products) {
        if (p.getId() == targetId) {
            cout << "Editing product ID " << targetId << ":\n";
            p.input();
            found = true;
            break;
        }
    }

    if (found) {
        writeAllToFile(products, filename);
        cout << "Product updated successfully.\n";
    } else {
        cout << "Product with ID " << targetId << " not found.\n";
    }
}

void deleteProduct(const char* filename, int targetId) {
    vector<Product> products = readAllFromFile(filename);
    size_t originalSize = products.size();

    products.erase(
        remove_if(products.begin(), products.end(),
                  [targetId](const Product& p) { return p.getId() == targetId; }),
        products.end()
    );

    if (products.size() < originalSize) {
        writeAllToFile(products, filename);
        cout << "Product deleted successfully.\n";
    } else {
        cout << "Product with ID " << targetId << " not found.\n";
    }
}

void displayAllProducts(const char* filename) {
    vector<Product> products = readAllFromFile(filename);
    for (const auto& p : products) {
        p.display();
    }
}


void exportToCSV(const char* binaryFilename, const char* csvFilename) {
    vector<Product> products = readAllFromFile(binaryFilename);
    ofstream csv(csvFilename);

    if (!csv) {
        cerr << "Failed to open CSV file.\n";
        return;
    }

    csv << "ID,Name,Price\n"; // header
    for (const auto& p : products) {
        csv << p.getId() << "," << '"' << p.getName() << '"' << "," << fixed << p.getPrice() << "\n";
    }

    csv.close();
    cout << "Exported to " << csvFilename << " successfully.\n";
}


int main() {
    const char* filename = "products.dat";
    int choice;

    do {
        cout << "\n----- Product Manager -----\n";
        cout << "1. Add Product(s)\n";
        cout << "2. Display All Products\n";
        cout << "3. Edit Product\n";
        cout << "4. Delete Product\n";
        cout << "5. Exit\n";
        cout << "6. Export Products to CSV\n";
        cout << "Choose an option: ";
        cin >> choice;

        switch (choice) {
            case 1: {
                int n;
                cout << "How many products to add? ";
                cin >> n;
                vector<Product> newProducts;
                for (int i = 0; i < n; ++i) {
                    Product p;
                    cout << "\nProduct #" << i + 1 << ":\n";
                    p.input();
                    newProducts.push_back(p);
                }
                ofstream file(filename, ios::binary | ios::app);
                for (const auto& p : newProducts) {
                    p.saveToFile(file);
                }
                file.close();
                break;
            }
            case 2:
                displayAllProducts(filename);
                break;
            case 3: {
                int editId;
                cout << "Enter Product ID to edit: ";
                cin >> editId;
                editProduct(filename, editId);
                break;
            }
            case 4: {
                int delId;
                cout << "Enter Product ID to delete: ";
                cin >> delId;
                deleteProduct(filename, delId);
                break;
            }
            case 5:
                cout << "Exiting...\n";
                break;
            
            case 6:
                exportToCSV(filename, "products.csv");
                break;
            
            default:
                cout << "Invalid option!\n";
        }

    } while (choice != 5);

    return 0;
}
