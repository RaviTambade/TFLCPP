#include "ProductRepository.h"
#include <algorithm>

using namespace std;

    void ProductRepository::add(const Product& product)  {
        products.push_back(product);
    }

    void ProductRepository::update(int id, const Product& product)  {
        for (auto& p : products) {
            if (p.id == id) {
                p = product;
                break;
            }
        }
    }

    void ProductRepository::remove(int id)  {
        products.erase(remove_if(products.begin(), products.end(),
            [id](const Product& p) { return p.id == id; }), products.end());
    }

    Product ProductRepository::get(int id) const  {
        for (const auto& p : products) {
            if (p.id == id) {
                return p;
            }
        }
    }

    vector<Product> ProductRepository::getAll() const  {

        vector<Product> products = {
        {1, "Gerbera", "Wedding Flower", "Flower", 100},
        {2, "Rose", "Valentine Flower", "Flower", 200},
        {3, "Lily", "Decorative Flower", "Flower", 300}
        };

        return products;
    }


