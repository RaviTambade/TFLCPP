#include <iostream>
#include <string>
using namespace std;

class Complex {
    private: 
            int imag;
            int real;
    public:
            Complex(){
                imag=real=0;
            }

            Complex(int r, int i){
                real=r;
                imag=i;
            }

            //friend function
            //Operator overloading allows us to define new behaviour  of specific Operator in our Class

            friend  istream&  operator>>(istream& is,   Complex& c)
            {
                cout << "Enter Complex Number"<<endl;
                cout<<"real:  ";
                is >> c.real ;
                cout<<endl <<"imag:  ";
                is >> c.imag;
                return is;
            }  
            
            friend  ostream&  operator<<(ostream& os, const Complex& c)
            {
                os<<c.real << " + "<<c.imag <<"i" <<endl;
                return os;
            }

            //member function

            //Method overloading
            //Arithmatic operator overloading
            Complex operator+(const Complex& other) const{
                Complex temp;
                temp.real=this->real+ other.real;
                temp.imag=this->imag+ other.imag;
                return temp;     
            }

           static  Complex operator+ (Complex& c1, Complex c2){
                Complex temp;
                temp.real=c1.real+ c2.real;
                temp.imag=c2.imag+ c2.imag;
                return temp;     
            }
            ~Complex(){

            }
};


int main(){

    Complex c1;
    Complex c2;
    cin>>c1;
    cin>>c2;

    cout<<c1;
    cout<<c2;

    Complex c3= c1 + c2;

    Complex c5=c1.operator+(c2);

    cout<<"Ater Adding two complex numbers : "<<endl;
    cout<<c3;

}