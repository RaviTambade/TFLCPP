#ifndef __PRODUCT_H
#define __PRODUCT_H
#include <iostream>
#include <string>

//#pragma region
//This pragma region is used to group the data members of the class

using namespace std;
class Product {


private:
		

			#pragma region Data Members
			int productId;
			string title;
			string description;
			string category;
			int quantity;
			double price;
		#pragma endregion
public:

		#pragma region Member Functions

			#pragma region Constructors and Destructor
				Product(int id);
				Product(int id, const string& t, const string& d, const string& c, int q, double p);
				
				Product(int id, const string& t, const string& d, double p, int q);
			
			#pragma endregion

			#pragma region Setters and Getters
		int getProductId() const;
		string getTitle() const;
		void setTitle(const string& t);
		string getDescription() const;
		void setDescription(const string& d);
		string  getCategory() const;
		void setCategory(const string& c);
		int getQuantity() const;
		void setQuantity(int q);
		double getPrice() const;
		void setPrice(double p);
		double getTotalPrice() const;
		double getDiscountedPrice(double discount) const;
		void display() const;

		#pragma
	#pragma endregion
};
#endif
