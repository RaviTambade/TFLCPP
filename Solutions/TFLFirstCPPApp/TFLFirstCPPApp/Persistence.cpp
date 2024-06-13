#include "Customer.h"

int main_Persistence() {
    // Creating an Employee object
    Customer cust1("Sham Manohar", 25, 50000.0);

    // Serializing the object
    cust1.serialize("customer.dat");

    // Deserializing the object
    Customer cust2 = Customer::deserialize("employee.dat");

    // Displaying the deserialized object
    cust2.display();
    return 0;
}
