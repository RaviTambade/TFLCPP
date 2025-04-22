#include <iostream>
#include <string>
using namespace std;

// Base class Printer
class Printer {
protected:
    string printerName;

public:
    // Constructor
    Printer(string name) : printerName(name) {}

    // Virtual function to print the type of printer
    virtual void print() {
        cout << "Printing from Printer: " << printerName << endl;
    }

    // Friend function declaration
    friend void showPrinterDetails(Printer& printer);
};

// Derived class InkjetPrinter
class InkjetPrinter : public Printer {
protected:
    int inkLevel;

public:
    // Constructor
    InkjetPrinter(string name, int ink) : Printer(name), inkLevel(ink) {}

    // Override the print function
    void print() override {
        cout << "Printing from Inkjet Printer: " << printerName << " with ink level " << inkLevel << "%" << endl;
    }

    // Friend function declaration
    friend void showInkjetDetails(InkjetPrinter& inkjet);
};

// Derived class LaserPrinter
class LaserPrinter : public Printer {
protected:
    int tonerLevel;

public:
    // Constructor
    LaserPrinter(string name, int toner) : Printer(name), tonerLevel(toner) {}

    // Override the print function
    void print() override {
        cout << "Printing from Laser Printer: " << printerName << " with toner level " << tonerLevel << "%" << endl;
    }

    // Friend function declaration
    friend void showLaserDetails(LaserPrinter& laser);
};

// Friend function to display Printer details
void showPrinterDetails(Printer& printer) {
    cout << "Printer Name: " << printer.printerName << endl;
}

// Friend function to display Inkjet Printer details
void showInkjetDetails(InkjetPrinter& inkjet) {
    showPrinterDetails(inkjet);  // Calling the friend function of base class
    cout << "Ink Level: " << inkjet.inkLevel << "%" << endl;
}

// Friend function to display Laser Printer details
void showLaserDetails(LaserPrinter& laser) {
    showPrinterDetails(laser);  // Calling the friend function of base class
    cout << "Toner Level: " << laser.tonerLevel << "%" << endl;
}

int main() {
    // Create instances of printers
    InkjetPrinter inkjet("HP Inkjet", 75);
    LaserPrinter laser("Canon Laser", 50);

    // Demonstrate the print functions
    inkjet.print();
    laser.print();

    // Use friend functions to show printer details
    showInkjetDetails(inkjet);
    showLaserDetails(laser);

    return 0;
}
