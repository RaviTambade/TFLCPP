### **Problem Statement for Delivery Tracking System in C**

A **Delivery Tracking System** is a software solution designed to help businesses track the status of deliveries, manage the shipment process, and provide customers with real-time updates on their orders. This system will allow users to monitor the progress of deliveries, update shipment statuses, and store relevant delivery information.

In this **Delivery Tracking System in C**, users (such as delivery managers or customers) will be able to:
- Add new delivery details.
- Track and update the status of deliveries.
- Search and view information about specific deliveries.
- Maintain a history of deliveries for reporting purposes.
  
This system can be used by logistics companies, e-commerce platforms, or any business that needs to manage and track deliveries efficiently. It can help improve the accuracy of delivery statuses, enhance customer satisfaction, and streamline the delivery management process.

---

### **Objective:**

The **Delivery Tracking System in C** aims to:
1. Allow users to add and manage delivery information, including delivery ID, customer details, shipping address, and delivery status.
2. Provide the ability to search for deliveries by ID, customer name, or status.
3. Track the status of deliveries (e.g., "Shipped", "In Transit", "Delivered", "Returned").
4. Update the status of deliveries as they progress.
5. Allow users to view and manage delivery history.

---

### **System Features and Functional Requirements:**

1. **Delivery Information Management:**
   - **Add New Delivery:** The system should allow users to add new deliveries with essential information such as delivery ID, customer name, contact details, delivery address, and initial delivery status.
   - **View Deliveries:** The system should allow users to view all deliveries or search for specific deliveries by their ID, customer name, or status.

2. **Delivery Status Management:**
   - **Update Delivery Status:** Users should be able to update the delivery status at different stages (e.g., "Shipped", "In Transit", "Out for Delivery", "Delivered", "Returned").
   - **Track Delivery:** Users should be able to track and view the current status of a specific delivery.

3. **Search and Reporting:**
   - **Search by Delivery ID or Customer Name:** Users should be able to search for specific deliveries using the delivery ID or customer name.
   - **Generate Reports:** Generate reports that display the status of deliveries, and allow the user to filter by specific delivery stages or other criteria (e.g., deliveries that are "In Transit").

4. **Data Validation:**
   - Ensure that all required fields (delivery ID, customer name, delivery address, etc.) are provided and that data such as phone numbers are in the correct format.

5. **User Interface:**
   - The system will provide a simple text-based menu interface for interacting with the system, where users can select options to add deliveries, update statuses, and view or search deliveries.

---

### **Data Structures:**

1. **Delivery Structure:**
   Each delivery will be represented by a structure containing the following attributes:
   - Delivery ID (unique identifier)
   - Customer name
   - Contact number
   - Delivery address
   - Delivery status (e.g., "Shipped", "In Transit", "Delivered")
   - Date of delivery (optional, can be updated)

   ```c
   #define MAX_DELIVERIES 100

   // Structure to store delivery information
   struct Delivery {
       int deliveryID;              // Unique identifier for each delivery
       char customerName[100];      // Customer's name
       char customerPhone[15];      // Customer's phone number
       char deliveryAddress[200];   // Delivery address
       char deliveryStatus[50];     // Status of the delivery (e.g., "Shipped", "In Transit")
       char deliveryDate[20];       // Date of delivery (optional)
   };

   struct Delivery deliveries[MAX_DELIVERIES];
   int totalDeliveries = 0;        // Total number of deliveries
   ```

2. **Status Management:**
   - The delivery status could be one of the following predefined states:
     - **Shipped**
     - **In Transit**
     - **Out for Delivery**
     - **Delivered**
     - **Returned**

---

### **Functional Requirements:**

1. **Add New Delivery:**
   - The system should allow the user to enter the customer’s name, contact information, delivery address, and the initial status of the delivery.

2. **Update Delivery Status:**
   - Users should be able to update the delivery status as the shipment progresses through various stages.

3. **Track Delivery:**
   - Users should be able to track a specific delivery by providing its unique ID or customer name, and the system will return the current status.

4. **View All Deliveries:**
   - The system should allow users to view a list of all deliveries, including their status and customer details.

5. **Search Deliveries:**
   - The system should allow users to search for deliveries by their unique delivery ID or customer name. The system should return all relevant details of the delivery.

6. **Generate Reports:**
   - The system should allow the generation of reports that display a list of deliveries based on their current status or any other filter criteria (e.g., deliveries that are still "In Transit").

---

### **Sample Menu Options:**

```
Delivery Tracking System
=========================
1. Add New Delivery
2. View All Deliveries
3. Search Delivery by ID or Customer Name
4. Update Delivery Status
5. Generate Delivery Report (by Status)
6. Exit
Enter your choice (1-6):
```

---

### **Constraints and Assumptions:**

1. **Fixed Capacity:**
   - The system will store a maximum of `MAX_DELIVERIES` deliveries (e.g., 100). If the system reaches this limit, no more deliveries can be added.

2. **Basic Input Validation:**
   - The system will validate required fields like delivery ID, customer name, and status. It will also ensure that phone numbers are in the correct format.

3. **Temporary Data Storage:**
   - The data will be stored temporarily during the program's execution. Once the program ends, all data will be lost. Future enhancements could include persistent data storage, such as saving the data to files.

4. **Simple Text-Based Interface:**
   - The system will feature a basic text-based interface that allows users to select actions and view data. This can be enhanced in future iterations by integrating with graphical interfaces or web applications.

---

### **Sample Code Outline:**

```c
#include <stdio.h>
#include <string.h>

#define MAX_DELIVERIES 100

struct Delivery {
    int deliveryID;
    char customerName[100];
    char customerPhone[15];
    char deliveryAddress[200];
    char deliveryStatus[50];
    char deliveryDate[20];
};

struct Delivery deliveries[MAX_DELIVERIES];
int totalDeliveries = 0;

void addDelivery() {
    if (totalDeliveries < MAX_DELIVERIES) {
        struct Delivery newDelivery;
        printf("Enter Delivery ID: ");
        scanf("%d", &newDelivery.deliveryID);
        getchar();  // Consume newline character
        
        printf("Enter Customer Name: ");
        fgets(newDelivery.customerName, 100, stdin);
        newDelivery.customerName[strcspn(newDelivery.customerName, "\n")] = '\0';

        printf("Enter Customer Phone: ");
        fgets(newDelivery.customerPhone, 15, stdin);
        newDelivery.customerPhone[strcspn(newDelivery.customerPhone, "\n")] = '\0';

        printf("Enter Delivery Address: ");
        fgets(newDelivery.deliveryAddress, 200, stdin);
        newDelivery.deliveryAddress[strcspn(newDelivery.deliveryAddress, "\n")] = '\0';

        printf("Enter Initial Delivery Status (e.g., Shipped, In Transit): ");
        fgets(newDelivery.deliveryStatus, 50, stdin);
        newDelivery.deliveryStatus[strcspn(newDelivery.deliveryStatus, "\n")] = '\0';

        strcpy(newDelivery.deliveryDate, "N/A");  // Optional: Can be updated later
        deliveries[totalDeliveries++] = newDelivery;
        printf("Delivery added successfully!\n");
    } else {
        printf("Cannot add more deliveries. Maximum capacity reached.\n");
    }
}

void viewDeliveries() {
    for (int i = 0; i < totalDeliveries; i++) {
        printf("\nDelivery ID: %d\n", deliveries[i].deliveryID);
        printf("Customer: %s\n", deliveries[i].customerName);
        printf("Phone: %s\n", deliveries[i].customerPhone);
        printf("Address: %s\n", deliveries[i].deliveryAddress);
        printf("Status: %s\n", deliveries[i].deliveryStatus);
        printf("Delivery Date: %s\n", deliveries[i].deliveryDate);
    }
}

void updateDeliveryStatus() {
    int deliveryID;
    printf("Enter Delivery ID to update status: ");
    scanf("%d", &deliveryID);
    
    for (int i = 0; i < totalDeliveries; i++) {
        if (deliveries[i].deliveryID == deliveryID) {
            printf("Enter new status (e.g., Shipped, In Transit, Delivered): ");
            getchar();  // Consume newline character
            fgets(deliveries[i].deliveryStatus, 50, stdin);
            deliveries[i].deliveryStatus[strcspn(deliveries[i].deliveryStatus, "\n")] = '\0';
            printf("Status updated successfully!\n");
            return;
        }
    }
    printf("Delivery not found.\n");
}

void searchDelivery() {
    char searchTerm[100];
    printf("Enter Customer Name or Delivery ID to search: ");
    getchar();  // Consume newline character
    fgets(searchTerm, 100, stdin);
    searchTerm[strcspn(searchTerm, "\n")] = '\0';  // Remove newline character
    
    for (int i = 0; i < totalDeliveries; i++) {
        if (strstr(deliveries[i].customerName, searchTerm) != NULL || 
            deliveries[i].deliveryID == atoi(searchTerm)) {
            printf("\nDelivery ID: %d\n", deliveries[i].deliveryID);
            printf("Customer: %s\n", deliveries[i].customerName);
            printf("Phone: %s\n", deliveries[i].customerPhone);
            printf("Address: %s\n", deliveries[i].deliveryAddress);
            printf("Status: %s\n", deliveries[i].deliveryStatus);
            printf("Delivery Date: %s\n", deliveries[i].deliveryDate);
            return;
        }
    }
    printf("Delivery not found.\n");
}

int main() {
    int choice;
    while (1) {
        printf("\nDelivery Tracking System\n");
        printf("=========================\n");
        printf("1. Add New Delivery\n");
        printf("2. View All Deliveries\n");
        printf("3. Search Delivery by ID or Customer Name\n");
        printf("4. Update Delivery Status\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: addDelivery(); break;
            case 2: viewDeliveries(); break;
            case 3: search

Delivery(); break;
            case 4: updateDeliveryStatus(); break;
            case 5: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
```

---

### **Conclusion:**

The **Delivery Tracking System in C** helps businesses manage and track deliveries, providing a straightforward solution for adding, updating, and viewing delivery information. The system allows users to track the status of deliveries in real-time, ensuring smooth delivery operations. Future enhancements could include adding persistent storage (e.g., file storage or databases), improving search functionality, and providing more advanced reporting capabilities.