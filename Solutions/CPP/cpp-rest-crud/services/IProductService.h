
#include "..\entities\product.h"

#include <vector>

using namespace std;

#ifndef IPRODUCTSERVICE_H
#define IPRODUCTSERVICE_H

class IProductService{
public:

    virtual ~IProductService() = default;

    virtual void addProduct(const Product& product) = 0;
    virtual void updateProduct(int id, const Product& product) = 0;
    virtual void removeProduct(int id) = 0;
    virtual Product getProduct(int id) const = 0;
    virtual vector<Product> getAllProducts() const = 0;
};

#endif // IPRODUCTSERVICE_H
