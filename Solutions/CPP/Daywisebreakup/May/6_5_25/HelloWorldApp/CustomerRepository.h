#ifndef __CUSTOMERREPOSITORY_H  
#define __CUSTOMERREPOSITORY_H  

#include "Customer.h"  
#include "ICustomerRepository.h"  

#include <iostream>  
#include <string>  

using namespace std;  

class CustomerRepository : public ICustomerRepository {  
private:  
  Customer* customers[100];  
  int customerCount;  

public:  
  CustomerRepository();  
  ~CustomerRepository();  
  void addCustomer(Customer* customer) override;  
  Customer* getCustomer(int index) const override;  
  Customer* findCustomerById(int id) const override;  
  Customer* findCustomerByTitle(const std::string& title) const override;  
  void removeCustomer(int index) override;  
  void updateCustomer(int index, Customer* customer) override;  
  void displayCustomers() const override;  
  void saveCustomers() override;  
};  

#endif
