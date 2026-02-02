## **CPP-REST-CRUD : Building a Simple REST API in C++**

 
This is a **perfect candidate for a Transflower Learning Framework (TLF) case study**, because it connects **core C++**, **system design**, and **modern backend thinking** without hiding behind frameworks.

Below is a **TLF-style learning module**, written the way you would **explain, position, and mentor students** before implementation.

### **Theme:**

> *“C++ is not just for systems — it can speak HTTP too.”*

## 🎯 **Learning Intent (Why this exists in TLF)**

Most students believe:

* REST APIs are **Java / .NET / Node-only**
* C++ is **only for DSA, OS, or competitive programming**

This lab **breaks that mental boundary**.

Through this project, learners understand:

* How **modern application architecture** works
* How **layered design** applies even in C++
* How **HTTP, REST, CRUD, and clean architecture** are language-agnostic concepts

## 🧠 **Core Thinking Before Coding (TLF Rule #1)**

> Frameworks change.
> Languages change.
> **Architecture thinking does not.**

This project is **NOT about httplib.h**
This project **IS about separation of responsibility**

## 🏗️ **System You Are Building**

You are building a **lightweight Product Management REST API** using **pure C++**, capable of:

* Creating products
* Reading products
* Updating products
* Deleting products

The application communicates over **HTTP**, follows **REST conventions**, and uses **layered architecture**.

## 📁 **Project Structure (TLF-Aligned)**

```
cpp-rest-crud/
│── main.cpp            ← HTTP entry point (Controller layer)
│── httplib.h           ← HTTP server (Infrastructure)
│
├── entities/            ← Domain Layer
│   ├── product.h
│   └── customer.h
│
├── repositories/        ← Data Access Layer (DAL)
│   ├── IProductRepository.h
│   ├── ProductRepository.h
│   └── ProductRepository.cpp
│
├── services/            ← Business Logic Layer (BLL)
│   ├── IProductService.h
│   ├── ProductService.h
│   └── ProductService.cpp
│
└── .vscode/
```

📌 **TLF Insight**

> Folder structure tells the *story* of the application.

## 🧩 **Layer-by-Layer Responsibility (TLF Breakdown)**

### 1️⃣ **Domain Layer — Entities**

📂 `entities/`

**Purpose:**
Represents **real-world business objects**, not technical concerns.

Example:

* `Product`
* `Customer`

Rules:

* ❌ No HTTP logic
* ❌ No storage logic
* ✅ Only data + meaning

📌 *Same concept as “Model” in MVC*


### 2️⃣ **Data Access Layer (DAL) — Repositories**

📂 `repositories/`

**Purpose:**
Handles **how data is stored and retrieved**

Key design idea:

* Code depends on **interfaces**, not implementations

Components:

* `IProductRepository` → contract
* `ProductRepository` → actual storage (in-memory / file)

📌 **TLF Rule**

> Business logic must not care *where* data comes from.

### 3️⃣ **Business Logic Layer (BLL) — Services**

📂 `services/`

**Purpose:**
Contains **rules, validations, and decisions**

Responsibilities:

* Validate product data
* Decide when repository should be called
* Prepare output for controller

📌 **Critical TLF Insight**

> Controllers should be thin.
> Services should be smart.

### 4️⃣ **Controller Layer — main.cpp**

📄 `main.cpp`

**Purpose:**
Acts as the **HTTP Controller**

Responsibilities:

* Accept HTTP requests
* Map URLs to service calls
* Convert input/output to JSON
* Send HTTP responses

Example routes:

* `POST /products`
* `GET /products`
* `GET /products/{id}`
* `PUT /products/{id}`
* `DELETE /products/{id}`

📌 **TLF Mapping**

> `main.cpp` = Controller
> `httplib` = HTTP listener
> `ProductService` = Application brain

## 🔄 **Request Flow (TLF Way)**

### Example: `GET /products`

```
Client
  ↓
HTTP Request
  ↓
httplib (Server)
  ↓
Controller (main.cpp)
  ↓
ProductService
  ↓
ProductRepository
  ↓
Data Source
  ↑
Response bubbles back
```

📌 **Important Observation**

* No layer skips another
* No circular dependency
* Clear direction of flow

## 🧠 **Key Concepts Students Must Internalize**

| Concept    | What Student Learns           |
| ---------- | ----------------------------- |
| REST       | Resource-based URLs           |
| CRUD       | Business operations           |
| HTTP       | Language-independent protocol |
| Interfaces | Dependency inversion          |
| Layering   | Clean architecture            |
| C++ OOP    | Real-world usage              |
| JSON       | Cross-platform data           |

## 🧪 **Lab Problem Statement (TLF Style)**

### **Problem Statement**

Design and implement a **C++ RESTful CRUD API** for managing `Product` resources using a **layered architecture**.

The system must:

* Follow REST conventions
* Separate concerns into:

  * Entities
  * Repositories
  * Services
  * Controllers
* Use interfaces for loose coupling
* Be extendable for future storage (file / database)



## ✅ **Expected Learning Outcomes**

After completing this lab, learners should be able to:

- ✔ Explain REST without mentioning frameworks
- ✔ Build APIs in **any language**, not just C++
- ✔ Understand backend architecture deeply
- ✔ Confidently map Java/.NET concepts to C++
- ✔ Stop fearing “enterprise design”

## 🔍 **Industry Mapping**

| Industry Term | This Project         |
| ------------- | -------------------- |
| Microservice  | Lightweight REST API |
| Controller    | main.cpp             |
| Service       | ProductService       |
| Repository    | ProductRepository    |
| DTO / Model   | Product              |
| API Gateway   | HTTP entry point     |


## 🌱 **Mentor Note (Transflower Signature)**

> If you can build a REST API in C++,
> Java becomes easy.
> .NET becomes familiar.
> Node becomes obvious.
>
> Because now you are not learning tools —
> **you are learning systems.**

This project is a **C++ REST API implementing CRUD operations** using the `httplib.h` (a lightweight HTTP server library).

### 🔑 Components Explained

1. **Entities (`entities/`)**

   * `product.h`: Defines the `Product` entity with fields like `id`, `title`, `description`.
   * `customer.h`: Similar structure for `Customer`.

   These act like *models* in MVC.

2. **Repositories (`repositories/`)**

   * `IProductRepository.h`: Interface defining CRUD operations (e.g., `addProduct`, `getProductById`, `deleteProduct`).
   * `ProductRepository.h/.cpp`: Implements data storage for products (likely using an in-memory `std::vector<Product>`).

   → This is your **Data Access Layer (DAL)**.

3. **Services (`services/`)**

   * `IProductService.h`: Interface for product-related business operations.
   * `ProductService.cpp/.h`: Implements logic between repository and controller (e.g., validation, transformations).

   → This is your **Business Logic Layer (BLL)**.

4. **`httplib.h`**

   * A third-party single-header C++ HTTP library used to create REST endpoints without heavy frameworks.

5. **`main.cpp`**

   * The entry point of the program.
   * Creates an HTTP server.
   * Defines REST endpoints:

     * `POST /products` → Create product
     * `GET /products` → List all products
     * `GET /products/{id}` → Fetch product by ID
     * `PUT /products/{id}` → Update product
     * `DELETE /products/{id}` → Delete product
   * Routes delegate requests to `ProductService`, which in turn uses `ProductRepository`.

### ⚙️ Flow of a Request (Example: `GET /products`)

1. Client sends HTTP request → `httplib` receives it.
2. `main.cpp` maps the route → calls `ProductService.getAllProducts()`.
3. `ProductService` calls `ProductRepository.getAllProducts()`.
4. Repository fetches data (from in-memory list or file).
5. Response serialized to JSON (likely using `nlohmann/json.hpp`).
6. Sent back to client as HTTP response.

## main.cpp code Explaination

### 1. **Includes**

```cpp
#include <iostream>
#include ".\httplib.h"
#include ".\services\IProductService.h"
#include ".\services\ProductService.h"
#include ".\repositories\IProductRepository.h"
#include ".\repositories\ProductRepository.h"
#include <memory>
```

* `httplib.h` → lightweight HTTP server library.
* `IProductService` & `ProductService` → **business logic layer** (currently commented out).
* `IProductRepository` & `ProductRepository` → **data access layer** (currently not used, but planned for actual database/repo).
* `memory` → for smart pointers.

### 2. **Setup server**

```cpp
using namespace httplib;

int main() {
    Server svr;
```

* Creates an HTTP server object `svr`.
* Think of it like Express.js in Node.js or Flask in Python, but for C++.

### 3. **GET /api/products**

```cpp
svr.Get("/api/products", [](const Request &req, Response &res) {
    // Repository + Service would normally be used here
    // IProductRepository * repository = new ProductRepository();
    // IProductService * service = new ProductService(repository);
    // auto products = service->getAllProducts();

    vector<Product> products = {
        {1, "Gerbera", "Wedding Flower", "Flower", 100},
        {2, "Rose", "Valentine Flower", "Flower", 200},
        {3, "Lily", "Decorative Flower", "Flower", 300}
    };

    string json = "[";
    for (const auto& product : products) {
        json += "{\"id\":" + to_string(product.id) +
                ",\"name\":\"" + product.title +
                "\",\"price\":" + to_string(product.price) + "},";
    }
    if (!products.empty()) json.pop_back();  // remove last comma
    json += "]";
    res.set_content(json, "text/json");
});
```

👉 What happens:

* Currently hardcodes a **vector of products**.
* Converts vector → JSON string manually (instead of using `nlohmann/json`).
* Sends back JSON response.

📌 Example response:

```json
[
  {"id":1,"name":"Gerbera","price":100},
  {"id":2,"name":"Rose","price":200},
  {"id":3,"name":"Lily","price":300}
]
```

### 4. **GET /api/customers**

```cpp
svr.Get("/api/customers", [](const Request &req, Response &res) {
    res.set_content("<h1>Customer List</h1><ul><li>Ravi Tambade</li><li>Shamiksha Choudhari</li></ul>", "text/html");
});
```

* Returns **HTML response** instead of JSON.
* Example response:

```html
<h1>Customer List</h1>
<ul>
  <li>Ravi Tambade</li>
  <li>Shamiksha Choudhari</li>
</ul>
```

### 5. **POST /api/customers**

```cpp
svr.Post("/api/customers", [](const Request &req, Response &res) {
    try {
        res.status = 201; // Created
        res.set_content("Added Customer", "application/plain");
    } catch (...) {
        res.status = 400;
        res.set_content("Exception: while adding customer", "application/plain");
    }
});
```

* Simulates **adding a new customer**.
* Always returns `"Added Customer"`.
* Uses **status 201 (Created)** to follow REST conventions.


### 6. **PUT /api/customers/{id}**

```cpp
svr.Put(R"(/api/customers/(\d+))", [](const Request &req, Response &res) {
    int id = std::stoi(req.matches[1]); // extract id from URL
    try {
        res.status = 201; 
        res.set_content("updated Customer", "application/plain");
    } catch (...) {
        res.status = 400;
        res.set_content("Exception: while updating customer", "application/plain");
    }
});
```

* Uses **Regex route**: `/api/customers/(\d+)` → matches `/api/customers/5`.
* Extracts ID from URL (`req.matches[1]`).
* Responds `"updated Customer"`.



### 7. **DELETE /api/customers/{id}**

```cpp
svr.Delete(R"(/api/customers/(\d+))", [](const Request &req, Response &res) {
    int id = std::stoi(req.matches[1]);
    res.set_content("Deleted Customer", "application/plain");
});
```

* Deletes customer by ID (again, just a simulated response).
* Example request: `DELETE /api/customers/3`.


### 8. **Start Server**

```cpp
svr.listen("localhost", 9000);
return 0;
```

* Runs the server at: **[http://localhost:9000](http://localhost:9000)**
* You can now test endpoints using **Postman / curl / browser**.

### 9. **Build Command**

```bash
g++ main.cpp -o server.exe -D_WIN32_WINNT=0x0A00 -lws2_32 -lwsock32
```

* Compiles with required Windows networking libraries.

✅ **Summary**

* This is a **mini C++ REST API**.
* `httplib` = HTTP engine.
* Hardcoded data for now, but service/repository pattern is ready to be integrated.
* Implements **CRUD**:

  * `GET /api/products` → Read all products
  * `GET /api/customers` → Read all customers
  * `POST /api/customers` → Create customer
  * `PUT /api/customers/{id}` → Update customer
  * `DELETE /api/customers/{id}` → Delete customer
