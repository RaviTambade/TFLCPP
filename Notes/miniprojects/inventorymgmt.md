### **Problem Definition for Inventory Management System Using C**

An **Inventory Management System** is a software application designed to help businesses or organizations track and manage their products, goods, and materials in real-time. The system keeps records of items, including quantities, prices, and categories, and helps with various operations like adding new items, updating inventory levels, and generating reports.

This problem definition will focus on creating a simple **Inventory Management System using C** that can handle the addition, deletion, and updating of inventory items, as well as provide a way to display current inventory information.

---

### **Problem Objective:**

To design and implement a simple Inventory Management System using C that allows users to:
1. **Add new products/items** to the inventory.
2. **View current inventory** and display item details (ID, name, quantity, and price).
3. **Update the quantity or price** of existing items in the inventory.
4. **Delete products/items** from the inventory.
5. **Exit the system** when finished.

---

### **System Features and Requirements:**

1. **Product Information:**
   - Each product in the inventory will have the following information:
     - **Product ID**: A unique identifier for each product.
     - **Name**: The name of the product (e.g., "Laptop", "Monitor").
     - **Quantity**: The number of items available in stock.
     - **Price**: The price of a single unit of the product.
   
2. **User Input:**
   - The system should accept user input to add, update, delete, or view products.
   - Input should be validated, ensuring correct types (e.g., integers for quantity and price, strings for name).

3. **Inventory Operations:**
   - **Add Item**: The user can add a new item to the inventory with a product ID, name, quantity, and price.
   - **View Inventory**: The user can view all current items in the inventory along with their details (ID, name, quantity, and price).
   - **Update Item**: The user can update the quantity or price of an existing item based on the product ID.
   - **Delete Item**: The user can remove an item from the inventory based on the product ID.
   - **Exit**: The user can choose to exit the system.

4. **Inventory Storage:**
   - The inventory will be stored in an array of structures. Each structure will hold the details of one product.
   - The system will support a **fixed number of products** (e.g., `MAX_ITEMS = 100`).

5. **Data Persistence:**
   - For simplicity, the system will **not** store data permanently. The inventory will be reset when the program ends (i.e., no file persistence).

---

### **Data Structures:**

The core data structure will be a `struct` to represent a product.

```c
#define MAX_ITEMS 100  // Maximum number of products in the inventory

// Structure to represent an item in the inventory
struct Product {
    int productID;           // Unique identifier for the product
    char name[100];          // Name of the product
    int quantity;            // Quantity available
    float price;             // Price per unit
};

// Array to hold all inventory items
struct Product inventory[MAX_ITEMS];
int currentItemCount = 0;  // Tracks the number of items in the inventory
```

---

### **Functional Requirements:**

1. **Add a New Item:**
   - The user will input the product ID, name, quantity, and price.
   - If the inventory is not full, the item is added to the inventory array.
   - If the inventory is full, the system should notify the user and prevent adding a new item.

2. **View Current Inventory:**
   - The user can see a list of all products in the inventory, including:
     - Product ID
     - Product Name
     - Quantity
     - Price per unit

3. **Update Item:**
   - The user can choose an item by its product ID to update either its **quantity** or **price**.
   - If the product ID does not exist, the system should display an error.

4. **Delete Item:**
   - The user can delete a product by specifying its product ID.
   - Once deleted, the remaining products in the array should be shifted to fill the gap.

5. **Exit the System:**
   - The program should exit gracefully when the user chooses to quit the application.

---

### **Constraints and Assumptions:**

1. **Fixed Capacity:**
   - The system can store a maximum of `MAX_ITEMS` products in memory. This is predefined at the start of the program.
   - If more items need to be added beyond this capacity, the system should notify the user and not allow any further additions.

2. **No Persistent Data Storage:**
   - The system does not use file storage to persist data. Once the program terminates, all data is lost.
   - This could be extended to support file operations (e.g., using text files or databases) in future enhancements.

3. **Basic Input Validation:**
   - The program should handle user input errors (e.g., entering a string for quantity or price) by prompting the user again.
   - Product IDs must be unique.

4. **Simple User Interface:**
   - The system will be operated through a **command-line interface** (CLI) with a simple text menu.

---

### **Sample Menu Options:**

```
Inventory Management System
===========================
1. Add New Product
2. View Inventory
3. Update Product
4. Delete Product
5. Exit
Enter your choice (1-5): 
```

---

### **Sample Code Outline:**

Here’s an outline of how the code for the inventory management system might look:

```c
#include <stdio.h>
#include <string.h>

#define MAX_ITEMS 100

struct Product {
    int productID;
    char name[100];
    int quantity;
    float price;
};

struct Product inventory[MAX_ITEMS];
int currentItemCount = 0;

void addProduct() {
    if (currentItemCount < MAX_ITEMS) {
        struct Product newProduct;
        printf("Enter Product ID: ");
        scanf("%d", &newProduct.productID);
        getchar();  // Consume the newline character
        printf("Enter Product Name: ");
        fgets(newProduct.name, 100, stdin);
        newProduct.name[strcspn(newProduct.name, "\n")] = '\0';  // Remove trailing newline
        printf("Enter Quantity: ");
        scanf("%d", &newProduct.quantity);
        printf("Enter Price: ");
        scanf("%f", &newProduct.price);

        inventory[currentItemCount] = newProduct;
        currentItemCount++;
        printf("Product added successfully!\n");
    } else {
        printf("Inventory is full!\n");
    }
}

void viewInventory() {
    if (currentItemCount == 0) {
        printf("No items in inventory.\n");
    } else {
        printf("Inventory List:\n");
        for (int i = 0; i < currentItemCount; i++) {
            printf("ID: %d, Name: %s, Quantity: %d, Price: %.2f\n",
                   inventory[i].productID, inventory[i].name,
                   inventory[i].quantity, inventory[i].price);
        }
    }
}

void updateProduct() {
    int id, found = 0;
    printf("Enter Product ID to update: ");
    scanf("%d", &id);
    for (int i = 0; i < currentItemCount; i++) {
        if (inventory[i].productID == id) {
            found = 1;
            printf("Enter new quantity: ");
            scanf("%d", &inventory[i].quantity);
            printf("Enter new price: ");
            scanf("%f", &inventory[i].price);
            printf("Product updated successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product ID not found.\n");
    }
}

void deleteProduct() {
    int id, found = 0;
    printf("Enter Product ID to delete: ");
    scanf("%d", &id);
    for (int i = 0; i < currentItemCount; i++) {
        if (inventory[i].productID == id) {
            found = 1;
            for (int j = i; j < currentItemCount - 1; j++) {
                inventory[j] = inventory[j + 1];  // Shift products
            }
            currentItemCount--;
            printf("Product deleted successfully!\n");
            break;
        }
    }
    if (!found) {
        printf("Product ID not found.\n");
    }
}

int main() {
    int choice;
    while (1) {
        printf("\nInventory Management System\n");
        printf("===========================\n");
        printf("1. Add New Product\n");
        printf("2. View Inventory\n");
        printf("3. Update Product\n");
        printf("4. Delete Product\n");
        printf("5. Exit\n");
        printf("Enter your choice (1-5): ");
        scanf("%d", &choice);
        getchar();  // Consume newline

        switch (choice) {
            case 1: addProduct(); break;
            case 2: viewInventory(); break;
            case 3: updateProduct(); break;
            case 4: deleteProduct(); break;
            case 5: return 0;
            default: printf("Invalid choice. Try again.\n");
        }
    }
}
```

---

### **Conclusion:**

This **Inventory Management System** built using C allows users to manage products in an inventory by adding new items, updating existing ones, deleting items, and viewing the current stock. It provides an efficient way to track and manipulate inventory data, though it lacks permanent data storage. The program can be extended in the future to include file handling, advanced searching, or even data persistence.