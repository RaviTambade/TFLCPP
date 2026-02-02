# **Building a **simplified C++ REST API**


## Lab Problem: Building a Simplified C++ REST API using Modern Tooling


Modern backend systems are often taught using **high-level frameworks** such as ASP.NET Core, Spring Boot, or Node.js.
However, these frameworks **hide the fundamentals** of how a REST API actually works.

This lab is designed to **pull the curtain back**.

Learners will build a **real REST API in C++**, using:

* A low-level systems language
* A REST SDK instead of a full-stack framework
* Manual build tooling
* Containerization for real-world deployment

This mirrors how **high-performance services**, **embedded systems**, and **infrastructure-level APIs** are built in the industry.

## 🎯 Learning Objectives

By completing this lab, learners will be able to:

* Understand REST APIs beyond frameworks
* Build a CRUD-based REST API using **C++**
* Use **C++ REST SDK (Casablanca)** for HTTP handling
* Manage application builds using **CMake**
* Containerize backend services using **Docker**
* Implement REST endpoints with **in-memory data storage**
* Compare low-level backend design with modern frameworks

## 🧩 Problem Statement

Design and implement a **simplified RESTful API in C++** that manages **Student records**.

The API must support standard **CRUD operations** using HTTP methods and should be deployable as a **Docker container**.

The application should run as a standalone service and respond to HTTP requests from tools such as **Postman** or **cURL**.

## 🏗️ System Architecture (TLF View)

```
Client (Browser / Postman / cURL)
              |
              v
        HTTP Request
              |
              v
+--------------------------------+
|   C++ REST API Server          |
|--------------------------------|
| HTTP Listener (Casablanca)     |
| Route Handling (GET/POST/etc.) |
| Controller Logic               |
| In-memory Data Store           |
| JSON Serialization             |
+--------------------------------+
              |
              v
        HTTP Response
```

 

## ⚙️ Technical Constraints

* Programming Language: **C++ (C++17 or later)**
* REST Framework: **C++ REST SDK (Casablanca)**
* Build Tool: **CMake**
* Container Platform: **Docker**
* Data Storage: **In-memory (e.g., std::map)**
* Port: **8080**

## 🔌 Required REST Endpoints

| HTTP Method | Endpoint         | Description                |
| ----------- | ---------------- | -------------------------- |
| GET         | `/students`      | Retrieve all students      |
| POST        | `/students`      | Add a new student          |
| PUT         | `/students`      | Update an existing student |
| DELETE      | `/students/{id}` | Delete a student by ID     |

## 📄 Data Model (Logical)

Each student record should include at least:

* `id` (integer)
* `name` (string)

Data should be exchanged using **JSON format**.

## 🧪 Expected Behaviour

* The server must start and listen on port `8080`
* Requests must be processed based on HTTP method
* Correct HTTP status codes must be returned:

  * `200 OK`
  * `201 Created`
  * `404 Not Found`
* API must handle multiple requests during runtime
* The application must run inside a Docker container

## 📦 Deliverables

1. C++ source code for REST API
2. `CMakeLists.txt` for build configuration
3. `Dockerfile` for containerization
4. Successful API testing screenshots or logs
5. README explaining:

   * Build steps
   * Run instructions
   * API usage

 
## 🧠 Concept Mapping (TLF Insight)

| Industry Concept | Lab Mapping            |
| ---------------- | ---------------------- |
| REST Controller  | HTTP handler functions |
| Web Server       | C++ HTTP listener      |
| Framework        | C++ REST SDK           |
| ORM              | In-memory data map     |
| Cloud Service    | Docker container       |
| CI/CD Build      | CMake                  |

## 📊 Evaluation Criteria

| Criteria                 | Weight |
| ------------------------ | ------ |
| REST API correctness     | 25%    |
| HTTP method handling     | 20%    |
| JSON request/response    | 15%    |
| Build & Docker setup     | 20%    |
| Code clarity & structure | 20%    |

## 🚀 Extension Tasks (Next TLF Level)

* Replace in-memory storage with **file-based persistence**
* Integrate **SQLite / MySQL**
* Add request validation & error handling
* Introduce logging middleware
* Compare with **ASP.NET Core Web API pipeline**
* Deploy container to cloud VM

> “Frameworks teach you *how to use*.
> Fundamentals teach you *how it works*.”

This lab ensures learners **don’t just consume APIs — they understand them**.

## 🌐 HTTP Pipeline – Conceptual Flow (TLF View)

```
 Client (Browser / Postman / cURL)
               |
               | 1. HTTP Request
               |    (GET /students)
               v
+------------------------------------------------+
|            TCP / Network Layer                 |
|------------------------------------------------|
|  • Socket Accept                               |
|  • Connection Handling                         |
+------------------------------------------------+
               |
               v
+------------------------------------------------+
|          HTTP Listener (Web Server)            |
|------------------------------------------------|
|  • Reads raw HTTP bytes                        |
|  • Parses Request Line                         |
|    GET /students HTTP/1.1                      |
+------------------------------------------------+
               |
               v
+------------------------------------------------+
|        HTTP Request Parser                     |
|------------------------------------------------|
|  • Extract Method (GET / POST / PUT / DELETE)  |
|  • Extract URI (/students, /students/1)        |
|  • Read Headers & Body                         |
+------------------------------------------------+
               |
               v
+------------------------------------------------+
|           Routing Layer                        |
|------------------------------------------------|
|  if (method == GET && path == "/students")     |
|      → handle_get()                            |
|  if (method == POST && path == "/students")    |
|      → handle_post()                           |
+------------------------------------------------+
               |
               v
+------------------------------------------------+
|        Controller / Business Logic             |
|------------------------------------------------|
|  • Validate Input                              |
|  • CRUD Operations                             |
|  • In-memory / DB Access                       |
+------------------------------------------------+
               |
               v
+------------------------------------------------+
|        Response Builder                        |
|------------------------------------------------|
|  • Create JSON Response                        |
|  • Set Status Code (200, 201, 404)              |
|  • Set Headers                                 |
+------------------------------------------------+
               |
               v
+------------------------------------------------+
|           HTTP Response Writer                 |
|------------------------------------------------|
|  HTTP/1.1 200 OK                               |
|  Content-Type: application/json                |
|                                                |
|  { "id": 1, "name": "Ravi" }                   |
+------------------------------------------------+
               |
               v
 Client Receives HTTP Response
```

 

## 🧠 TLF Mapping: Framework vs Fundamentals

```
ASP.NET / Spring / Express
----------------------------------
Middleware
   ↓
Filters
   ↓
Controllers
   ↓
Services
   ↓
Repositories
```

⬇️ **Under the hood (What you built in C++)**

```
Socket → HTTP Listener → Parser → Router → Logic → Response
```

> “Every web framework is just a **beautifully organized HTTP pipeline**.”

Once students see this diagram:

* REST stops being magic ✨
* Frameworks stop being scary 😌
* System-level thinking begins 🧠

 




* **C++ REST SDK (Casablanca)** for the REST API.
* **CMake** as the build tool.
* **Docker** for containerization.
* **In-memory data (e.g., `std::map`)** for simplicity.


## 🧱 Step 1: Set Up Your C++ Project

**Directory Structure:**

```
CppRestApiCrud/
├── CMakeLists.txt
├── main.cpp
└── Dockerfile
```


## 📄 Step 2: Write Your C++ REST API (main.cpp)

```cpp
#include <cpprest/http_listener.h>
#include <cpprest/json.h>
#include <map>
#include <string>
#include <iostream>

using namespace web;
using namespace web::http;
using namespace web::http::experimental::listener;

std::map<int, json::value> students;

void handle_get(http_request request) {
    json::value result = json::value::array();
    int index = 0;
    for (const auto& [id, student] : students) {
        result[index++] = student;
    }
    request.reply(status_codes::OK, result);
}

void handle_post(http_request request) {
    request.extract_json().then([=](json::value body) {
        int id = body[U("id")].as_integer();
        students[id] = body;
        request.reply(status_codes::Created, body);
    });
}

void handle_put(http_request request) {
    request.extract_json().then([=](json::value body) {
        int id = body[U("id")].as_integer();
        if (students.find(id) != students.end()) {
            students[id] = body;
            request.reply(status_codes::OK, body);
        } else {
            request.reply(status_codes::NotFound, U("Student not found"));
        }
    });
}

void handle_delete(http_request request) {
    auto id = std::stoi(request.relative_uri().path().substr(1));
    if (students.erase(id)) {
        request.reply(status_codes::OK, U("Deleted"));
    } else {
        request.reply(status_codes::NotFound, U("Not Found"));
    }
}

int main() {
    http_listener listener(U("http://0.0.0.0:8080/students"));

    listener.support(methods::GET, handle_get);
    listener.support(methods::POST, handle_post);
    listener.support(methods::PUT, handle_put);
    listener.support(methods::DEL, handle_delete);

    try {
        listener
            .open()
            .then([&listener]() {
                std::wcout << U("Listening at ") << listener.uri().to_string() << std::endl;
            })
            .wait();

        std::string line;
        std::getline(std::cin, line); // Keep app running
    }
    catch (std::exception& ex) {
        std::cerr << "Exception: " << ex.what() << std::endl;
    }
}
```

## ⚙️ Step 3: CMake Configuration (CMakeLists.txt)

```cmake
cmake_minimum_required(VERSION 3.10)
project(CppRestApiCrud)

set(CMAKE_CXX_STANDARD 17)

find_package(cpprestsdk REQUIRED)

add_executable(server main.cpp)
target_link_libraries(server PRIVATE cpprestsdk::cpprest)
```

## 🐳 Step 4: Dockerfile

```dockerfile
FROM mcr.microsoft.com/devcontainers/cpp:0-ubuntu-22.04

RUN apt update && apt install -y libcpprest-dev cmake g++

WORKDIR /app
COPY . .

RUN cmake . && make

EXPOSE 8080

CMD ["./server"]
```

## 🚀 Step 5: Build and Run with Docker

### ✅ Build the image

```bash
docker build -t cpp-rest-api .
```

### ▶️ Run the container

```bash
docker run -p 8080:8080 cpp-rest-api
```

## 🧪 Step 6: Test the API using cURL or Postman

* **POST**

```bash
curl -X POST http://localhost:8080/students -H "Content-Type: application/json" -d '{"id":1,"name":"Ravi"}'
```

* **GET**

```bash
curl http://localhost:8080/students
```

* **PUT**

```bash
curl -X PUT http://localhost:8080/students -H "Content-Type: application/json" -d '{"id":1,"name":"Ravi Updated"}'
```

* **DELETE**

```bash
curl -X DELETE http://localhost:8080/students/1
```


Nexe version could be using file-based storage or connected to SQLite/MySQL instead of in-memory data.
