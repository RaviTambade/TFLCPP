#pragma once
class ProductService {

private:
	ProductRepository& repo; // Reference to the ProductRepository

public:
	ProductService(ProductRepository& r) : repo(r) {}

	void applyDiscount(int productId, double discount) {
		Product* product = repo.findProductById(productId);
		if (product) {
			double discountedPrice = product->getDiscountedPrice(discount);
			product->setPrice(discountedPrice);
		}
		else {
			std::cout << "Product not found!" << std::endl;
		}
	}


	void calculateTotalPrice(int productId) {
		Product* product = repo.findProductById(productId);
		if (product) {
			double totalPrice = product->getTotalPrice();
			std::cout << "Total Price for " << product->getTitle() << ": $" << totalPrice << std::endl;
		}
		else {
			std::cout << "Product not found!" << std::endl;
		}
	}

	void searchProductByTitle(const std::string& title) {
		Product* product = repo.findProductByTitle(title);
		if (product) {
			product->display();
		}
		else {
			std::cout << "Product not found!" << std::endl;
		}
	}
};

