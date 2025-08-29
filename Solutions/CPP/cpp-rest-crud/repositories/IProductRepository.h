#include "..\entities\product.h"
#include <vector>

using namespace std;    
#ifndef IPRODUCTREPOSITORY_H
#define IPRODUCTREPOSITORY_H

class IProductRepository {
public:
    virtual ~IProductRepository() = default;

    virtual void add(const Product& product) = 0;
    virtual void update(int id, const Product& product) = 0;
    virtual void remove(int id) = 0;
    virtual Product get(int id) const = 0;
    virtual vector<Product> getAll() const = 0;
};

#endif // IPRODUCTREPOSITORY_H
