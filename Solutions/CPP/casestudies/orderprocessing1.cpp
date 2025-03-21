#include <iostream>
#include <string>
#include <vector>

using namespace std;

class Order {

private:
    int orderID;
    string customerName;
    vector<int> productIDs;
    int quantityOrdered;
    float totalAmount;
    string orderStatus;

public:
    // Constructor
    Order(int id, string name, vector<int> products, int quantity, float amount) 
        : orderID(id), customerName(name), productIDs(products), quantityOrdered(quantity), totalAmount(amount), orderStatus("Pending") {}

    // Getter and Setter for orderID
    int getOrderID() { return orderID; }
    void setOrderID(int id) { orderID = id; }

    // Operation: Create Order
    void createOrder() {
        cout << "Creating order for: " << customerName << endl;




        
        // Implement business logic here
    }

    // Operation: View Order
    void viewOrder() {
        cout << "Order ID: " << orderID << ", Status: " << orderStatus <<endl;
    }

    // Operation: Process Order
    void processOrder() {
        // Implement business logic for processing the order
        orderStatus = "Processed";




        cout << "Order Processed" << endl;
    }
};

int main() {
    vector<int> products = {101, 102, 103};
    Order order1(1, "John Doe", products, 3, 250.75);
    order1.createOrder();
    order1.viewOrder();
    order1.processOrder();
    order1.viewOrder();

    return 0;
}
