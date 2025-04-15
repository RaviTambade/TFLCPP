#include <iostream>
#include <fstream>
using namespace std;

int main() {
    ofstream outFile;

    // Enable exceptions on the stream
    outFile.exceptions(ofstream::failbit | ofstream::badbit);

    try {
        // Try opening a file (could fail if path is invalid)
        outFile.open("tfl.txt");

        // Write to the file
        outFile << "Welcome to Transflower Learning." << endl;

        // Close the file
        outFile.close();
    } 
    catch (const ofstream::failure& e) {
        // Catch stream exceptions
        cerr << "Exception during file writing: " << e.what() << endl;
    }

    cout << "Program finished." << endl;
    return 0;
}


/*

ofstream::failbit: Set if the stream fails to open the file or write to it.
ofstream::badbit: Set if a serious error occurs (e.g., loss of integrity in the stream).
exceptions(...): This function enables exception throwing on those error conditions.
e.what(): Prints the reason for the exception.
*/