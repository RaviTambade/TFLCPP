class ProductRepository {

private:

	// Array of pointers to Product objects
	Product* products[100];
	int productCount;

public:

	// Constructor and Destructor
	ProductRepository() : productCount(0) {}

	~ProductRepository() {
		for (int i = 0; i < productCount; i++) {
			delete products[i];
		}
	}

	void addProduct(Product* product) {
		if (productCount < 100) {
			cout << "product count" << productCount << endl;
			products[productCount++] = product;
		}
		else {
			cout << "Product repository is full!" << std::endl;
		}
	}

	Product* getProduct(int index) const {
		if (index >= 0 && index < productCount) {
			return products[index];
		}
		return nullptr;
	}

	Product* findProductById(int id) const {
		for (int i = 0; i < productCount; i++) {
			if (products[i]->getProductId() == id) {
				return products[i];
			}
		}
		return nullptr;
	}
	Product* findProductByTitle(const std::string& title) const {
		for (int i = 0; i < productCount; i++) {
			if (products[i]->getTitle() == title) {
				return products[i];
			}
		}
		return nullptr;
	}

	void removeProduct(int index) {
		if (index >= 0 && index < productCount) {
			delete products[index];
			for (int i = index; i < productCount - 1; i++) {
				products[i] = products[i + 1];
			}
			productCount--;
		}
		else {
			std::cout << "Invalid index!" << std::endl;
		}
	}

	void updateProduct(int index, Product* product) {
		if (index >= 0 && index < productCount) {
			products[index]->setTitle(product->getTitle());
			products[index]->setDescription(product->getDescription());
			products[index]->setCategory(product->getCategory());
			products[index]->setQuantity(product->getQuantity());
			products[index]->setPrice(product->getPrice());
		}
		else {
			std::cout << "Invalid index!" << std::endl;
		}
	}

	void displayProducts() const {
		for (int i = 0; i < productCount; i++) {
			products[i]->display();
			std::cout << "------------------------" << std::endl;
		}
	}

};
