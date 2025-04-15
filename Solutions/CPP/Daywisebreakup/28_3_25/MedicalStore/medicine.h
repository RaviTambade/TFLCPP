//Declaration File

//Macros: don't defined it this header file is already defined
#ifndef __MEDICINE_H
#define __MEDICINE_H

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

namespace WellnessForever{
    class Medicine{
        private:
                int medID;
                string name;
                string category;
                float price;
                int quantity;
        public :
            Medicine(int i=0, string nm="", string  cat="",float amount=0,int qty=0);

            void setMedicineId(int i);
            int getMedicineId();

            void setName(string nm);
            string getName();

            void setCategory(string nm);
            string getCategory();

            void setPrice(float amount);
            float  getPrice();

            void setQuantity(int amount);
            int  getQuantity();
            
            void display() const;
            
            void serialize(std::ofstream& outFile) ;
            void deserialize(std::ifstream& inFile);
           
            friend  istream&  operator>>(istream& is,   Medicine& md);
            friend  ostream&  operator<<(ostream& os, const Medicine& md);      
    };    
}
   
#endif