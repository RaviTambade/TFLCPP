#include  "..\entities\product.h"
#include "..\services\ProductService.h"
#include "..\repositories\IProductRepository.h"
#include <memory>

using namespace std;


ProductService::ProductService(IProductRepository * repository){

    this->repository = repository;
}

void ProductService::addProduct(const Product& product) {
    repository->add(product);
}

void ProductService::updateProduct(int id, const Product& product) {
    repository->update(id, product);
}

void ProductService::removeProduct(int id) {
    repository->remove(id);
}

Product ProductService::getProduct(int id) const {
    return repository->get(id);
}

vector<Product> ProductService::getAllProducts() const {
    return repository->getAll();
}

