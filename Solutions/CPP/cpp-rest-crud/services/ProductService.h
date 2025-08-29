#include <vector>
#include "..\entities\product.h"
#include "IProductService.h"
#include "..\repositories\IProductRepository.h"

using namespace std;

#ifndef PRODUCTSERVICE_H
#define PRODUCTSERVICE_H

class ProductService: public IProductService {
public:
    IProductRepository * repository;
    ProductService(IProductRepository * repository);
    virtual ~ProductService () = default;       

    virtual void addProduct(const Product& product);
    virtual void updateProduct(int id, const Product& product);
    virtual void removeProduct(int id);
    virtual Product getProduct(int id) const;
    virtual vector<Product> getAllProducts() const;
};

#endif // PRODUCTSERVICE_H
