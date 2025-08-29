#include "..\entities\product.h"
#include <vector>

using namespace std;    

#ifndef PRODUCTREPOSITORY_H
#define PRODUCTREPOSITORY_H

class ProductRepository: public IProductRepository {
public:
    vector<Product> products;

    virtual ~ProductRepository() = default;
    virtual void add(const Product& product) ;
    void update(int id, const Product& product) ;
    void remove(int id) ;
    Product get(int id) const ;
    vector<Product> getAll() const;
};

#endif // PRODUCTREPOSITORY_H
