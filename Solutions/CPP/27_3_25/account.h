//Declaration File


   namespace Banking{
    class Account{
        private:
                int id;
                string name;
                double balance;
        public :
            Account(int i=0, string nm="", double amount=0):id(i), name(nm), balance(amount);
            //setter and getter
            void setId(int i);
            int getId();
            void setName(string nm);
            string getName();
    
           void setBalance(double bal)
            double  getBalance()
            void deposit(double amount);
            void withdraw(double amount);
            friend  istream&  operator>>(istream& is,   Account& prn)
            friend  ostream&  operator<<(ostream& os, const Account& prn);
            void serialize(std::ofstream& outFile) 
            void deserialize(std::ifstream& inFile)
            void display() const;
        };    
   }
   