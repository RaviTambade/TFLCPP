
class Product {
private:
	int productId;
	string title;
	string description;
	string category;
	int quantity;
	double price;

public:
	
	Product(int id);
	Product(int id, const string& t, const string& d, const string& c, int q, double p) :productId(id), title(t), description(d), category(c), quantity(q), price(p) {}

	int getProductId() const;
	string getTitle() const;
	void setTitle(const string& t);

	string getDescription() const;
	void setDescription(const string& d);

	string  getCategory();
	void setCategory(const string& c);

	int getQuantity() const;
	void setQuantity(int q);

	double getPrice() const;
	void setPrice(double p);

	double getTotalPrice() const;
	double getDiscountedPrice(double discount) const;
	void display() const;
};
