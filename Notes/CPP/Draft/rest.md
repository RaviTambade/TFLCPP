# **step-by-step guide** to building a **simplified C++ REST API CRUD application**

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
