#include <iostream>
#include ".\httplib.h"
#include ".\services\IProductService.h"
#include ".\services\ProductService.h"

#include ".\repositories\IProductRepository.h"
#include ".\repositories\ProductRepository.h"
#include <memory>

using namespace std;
using namespace httplib;

int main() {
    Server svr;


 

    svr.Get("/api/products", [](const Request &req, Response &res) {
        
       // IProductRepository * repository = new ProductRepository();
       // IProductService * service = new ProductService(repository);
       // auto products = service->getAllProducts();
    
        // Convert products to JSON and set response
        vector<Product> products = {
        {1, "Gerbera", "Wedding Flower", "Flower", 100},
        {2, "Rose", "Valentine Flower", "Flower", 200},
        {3, "Lily", "Decorative Flower", "Flower", 300}
        };

        // Convert products to JSON and set response
        string json = "[";
        for (const auto& product : products) {
            json += "{\"id\":" + to_string(product.id) + ",\"name\":\"" + product.title + "\",\"price\":" + to_string(product.price) + "},";
        }
        if (!products.empty()) {
            json.pop_back();  // Remove last comma
        }
        json += "]";
        res.set_content(json, "text/json");
    });

    svr.Get("/api/customers", [](const Request &req, Response &res) {
        res.set_content("<h1>Customer List</h1><ul><li>Ravi Tambade</li><li>Shamiksha Choudhari</li></ul>", "text/html");
    });

    // POST /customers
    svr.Post("/api/customers", [](const Request &req,   Response &res) {
        try {
            
            res.status = 201; // Created
            res.set_content("Added Customer", "application/plain");
        } catch (...) {
            res.status = 400;
            res.set_content("Exception: while adding customer", "application/plain");
        }
    });

    // PUT /customers/<id>
    svr.Put(R"(/api/customers/(\d+))", [](const Request &req, Response &res) {
        int id = std::stoi(req.matches[1]);
        try {
            res.status = 201; // Created
            res.set_content(" updated Customer ", "application/plain");
           
        } catch (...) {
            res.status = 400;
            res.set_content("Exception: while updating customer", "application/plain");
        }
    });


   // DELETE /customers/<id>
    svr.Delete(R"(/api/customers/(\d+))", [](const Request &req, Response &res) {
        int id = std::stoi(req.matches[1]);
        res.set_content("Deleted Customer", "application/plain");
    });

 
    svr.listen("localhost", 9000);
    return 0;
}


//g++ main.cpp -o server.exe -D_WIN32_WINNT=0x0A00 -lws2_32 -lwsock32
