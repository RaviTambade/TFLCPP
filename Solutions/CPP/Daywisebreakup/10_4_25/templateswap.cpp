#include <iostream>
using namespace std;

template <typename T>
void swapValues(T& a, T& b) {
    T temp = a;
    a = b;
    b = temp;
}

template <typename T>
T square(T value) {
    return value * value;
}


int main() {
    int x = 5, y = 10;
    swapValues(x, y);
    cout << "x = " << x << ", y = " << y << endl;

    double a = 3.14, b = 2.71;
    swapValues(a, b);
    cout << "a = " << a << ", b = " << b << endl;

    string s1 = "Hello", s2 = "World";
    swapValues(s1, s2);
    cout << "s1 = " << s1 << ", s2 = " << s2 << endl;

    cout << "Square of 5: " << square(5) << endl;
    cout << "Square of 2.5: " << square(2.5) << endl;
    cout << "Square of -3: " << square(-3) << endl;
    
    return 0;
}

