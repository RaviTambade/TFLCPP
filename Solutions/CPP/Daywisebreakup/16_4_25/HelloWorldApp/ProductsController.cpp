class ProductController {

private:
	//state
	ProductRepository& repo;
	ProductService& service;

public:
	//behavior

	ProductController(ProductRepository& r, ProductService& s) : repo(r), service(s) {}

	void addProduct(int id, const string& title, const string& description, const string& category, int quantity, double price) {
		Product* product = new Product(id, title, description, category, quantity, price);
		repo.addProduct(product);
	}
	void removeProduct(int index) {
		repo.removeProduct(index);
	}
	void updateProduct(int index, Product* product) {
		repo.updateProduct(index, product);
	}
	void displayProducts() const {
		repo.displayProducts();
	}
	void applyDiscount(int productId, double discount) {
		service.applyDiscount(productId, discount);
	}

	void calculateTotalPrice(int productId) {
		service.calculateTotalPrice(productId);
	}


	void searchProductByTitle(const string& title) {
		service.searchProductByTitle(title);
	}

	void getProductId(int& productId) {
		std::cout << "Enter Product ID: ";
		std::cin >> productId;
	}

	void getProductIndex(int& index) {
		std::cout << "Enter Product Index: ";
		std::cin >> index;
	}

	void getProductTitle(string& title) {
		std::cout << "Enter Product Title: ";
		std::cin.ignore();
		std::getline(std::cin, title);
	}
};

