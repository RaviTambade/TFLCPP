class ProductController {

private:
	//state
	ProductRepository& repo;
	ProductService& service;

public:
	//behavior

	ProductController(ProductRepository& r, ProductService& s);

	void addProduct(int id, const string& title, const string& description, const string& category, int quantity, double price);
	void removeProduct(int index);
	void updateProduct(int index, Product* product);

	void displayProducts() const;
	void applyDiscount(int productId, double discount);

	void calculateTotalPrice(int productId);


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

