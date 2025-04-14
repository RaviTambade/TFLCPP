#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <string>


#define MAX_PRODUCTS 100

// This is a simple C program that demonstrates a layered architecture for a flower store application.
// The program consists of three main layers: Model, Service, and Controller.
// The Model layer contains the Product class and ProductRepository class.


typedef struct {
    int productId;
    char title[100];
    char description[200];
    char category[100];
    int quantity;
    double price;
} Product;

typedef struct {
    Product* products[MAX_PRODUCTS];
    int productCount;
} ProductRepository;

// Function Prototypes (Model layer)
Product* createProduct(int id, const char* title, const char* desc, const char* category, int qty, double price);
void displayProduct(const Product* p);
double getTotalPrice(const Product* p);
double getDiscountedPrice(const Product* p, double discount);

// Repository functions
void initRepository(ProductRepository* repo);
void addProduct(ProductRepository* repo, Product* p);
Product* getProduct(ProductRepository* repo, int index);
Product* findProductById(ProductRepository* repo, int id);
Product* findProductByTitle(ProductRepository* repo, const char* title);
void removeProduct(ProductRepository* repo, int index);
void updateProduct(ProductRepository* repo, int index, Product* newProduct);
void displayProducts(ProductRepository* repo);

// Service Layer
void applyDiscount(ProductRepository* repo, int productId, double discount);
void calculateTotalPrice(ProductRepository* repo, int productId);
void searchProductByTitle(ProductRepository* repo, const char* title);

// Controller Layer
void addProductController(ProductRepository* repo, int id, const char* title, const char* desc, const char* category, int qty, double price);
void updateProductController(ProductRepository* repo, int index, Product* p);

// --- Implementations ---

Product* createProduct(int id, const char* title, const char* desc, const char* category, int qty, double price) {
    Product* p = (Product*)malloc(sizeof(Product));
    p->productId = id;
    strcpy_s(p->title, title);
    strcpy_s(p->description, desc);
    strcpy_s(p->category, category);
    p->quantity = qty;
    p->price = price;
    return p;
}

void displayProduct(const Product* p) {
    printf("Product ID: %d\n", p->productId);
    printf("Title: %s\n", p->title);
    printf("Description: %s\n", p->description);
    printf("Category: %s\n", p->category);
    printf("Quantity: %d\n", p->quantity);
    printf("Price: $%.2f\n", p->price);
}

double getTotalPrice(const Product* p) {
    return p->price * p->quantity;
}

double getDiscountedPrice(const Product* p, double discount) {
    return p->price - (p->price * discount / 100.0);
}

void initRepository(ProductRepository* repo) {
    repo->productCount = 0;
}

void addProduct(ProductRepository* repo, Product* p) {
    if (repo->productCount < MAX_PRODUCTS) {
        repo->products[repo->productCount++] = p;
    }
    else {
        printf("Product repository is full!\n");
    }
}

Product* getProduct(ProductRepository* repo, int index) {
    if (index >= 0 && index < repo->productCount) {
        return repo->products[index];
    }
    return NULL;
}

Product* findProductById(ProductRepository* repo, int id) {
    for (int i = 0; i < repo->productCount; i++) {
        if (repo->products[i]->productId == id)
            return repo->products[i];
    }
    return NULL;
}

Product* findProductByTitle(ProductRepository* repo, const char* title) {
    for (int i = 0; i < repo->productCount; i++) {
        if (strcmp(repo->products[i]->title, title) == 0)
            return repo->products[i];
    }
    return NULL;
}

void removeProduct(ProductRepository* repo, int index) {
    if (index >= 0 && index < repo->productCount) {
        free(repo->products[index]);
        for (int i = index; i < repo->productCount - 1; i++) {
            repo->products[i] = repo->products[i + 1];
        }
        repo->productCount--;
    }
    else {
        printf("Invalid index!\n");
    }
}

void updateProduct(ProductRepository* repo, int index, Product* newProduct) {
    if (index >= 0 && index < repo->productCount) {
        Product* p = repo->products[index];
        strcpy_s(p->title, newProduct->title);
        strcpy_s(p->description, newProduct->description);
        strcpy_s(p->category, newProduct->category);
        p->quantity = newProduct->quantity;
        p->price = newProduct->price;
        free(newProduct);
    }
    else {
        printf("Invalid index!\n");
    }
}

void displayProducts(ProductRepository* repo) {
    for (int i = 0; i < repo->productCount; i++) {
        displayProduct(repo->products[i]);
        printf("------------------------\n");
    }
}

// Service Layer

void applyDiscount(ProductRepository* repo, int productId, double discount) {
    Product* p = findProductById(repo, productId);
    if (p) {
        p->price = getDiscountedPrice(p, discount);
    }
    else {
        printf("Product not found!\n");
    }
}

void calculateTotalPrice(ProductRepository* repo, int productId) {
    Product* p = findProductById(repo, productId);
    if (p) {
        printf("Total Price for %s: $%.2f\n", p->title, getTotalPrice(p));
    }
    else {
        printf("Product not found!\n");
    }
}

void searchProductByTitle(ProductRepository* repo, const char* title) {
    Product* p = findProductByTitle(repo, title);
    if (p) {
        displayProduct(p);
    }
    else {
        printf("Product not found!\n");
    }
}

// Controller Layer

void addProductController(ProductRepository* repo, int id, const char* title, const char* desc, const char* category, int qty, double price) {
    Product* p = createProduct(id, title, desc, category, qty, price);
    addProduct(repo, p);
}

void updateProductController(ProductRepository* repo, int index, Product* p) {
    updateProduct(repo, index, p);
}

// Main Function
int main() {
    printf("Welcome to Transflower Store!\n");

    ProductRepository repo;
    initRepository(&repo);

    Product* product1 = createProduct(1, "Gerbera", "Wedding Flower", "Flower", 10, 19.99);
    Product* product2 = createProduct(2, "Rose", "Valentine Flower", "Flower", 5, 29.99);
    Product* product3 = createProduct(3, "Jasmine", "Smelling Flower", "Flower", 20, 39.99);
    Product* product4 = createProduct(4, "Mango", "Devgad Alphanso", "Fruit", 15, 49.99);

    addProduct(&repo, product1);
    addProduct(&repo, product2);
    addProduct(&repo, product3);
    addProduct(&repo, product4);

    displayProducts(&repo);

    printf("Apply Discount and Calculate Total Price\n");

    applyDiscount(&repo, 1, 10);  // Apply 10% discount to product with ID 1
    calculateTotalPrice(&repo, 1); // Calculate total price for product with ID 1
    searchProductByTitle(&repo, "Rose"); // Search for product by title

    printf("\nAdding a new product...\n");
    addProductController(&repo, 5, "Tulip", "Spring Flower", "Flower", 8, 15.99);
    displayProducts(&repo);

    printf("Updating product at index 1...\n");
    Product* updated = createProduct(2, "Lily", "Summer Flower", "Flower", 12, 25.99);
    updateProductController(&repo, 1, updated);
    displayProducts(&repo);

    printf("Thank you for visiting Transflower Store!\n");

    // Cleanup
    for (int i = 0; i < repo.productCount; i++) {
        free(repo.products[i]);
    }

    return 0;
}
