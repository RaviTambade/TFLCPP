#include <iostream>
#include <fstream>
#include <string>

using namespace std;
void writeToScreen(){
    cout<<"Welcome to File IO"<<endl;
    cout<<"Transflower learning experience"<<endl; 
}

void writeToFile(string fileName){
    //OF: output file
    ofstream stream("tfl.txt");
    stream<<"Welcome to File IO"<<endl;
    stream<<"Transflower learning experience"<<endl;
    stream.close();
}

void readFromFile(string fileName){
    string firstMessage;
    //if : input file
    ifstream stream(fileName);
    do{
        stream>>firstMessage;
        cout<<firstMessage<<" ";
    }
    while( !stream.eof());
    stream.close();
}

int main(){
    //writeToScreen();
    writeToFile("tfl.txt"); 
    readFromFile("tfl.txt");
}