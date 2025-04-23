#include<iostream>
#include<string.h>
#include<vector>
#include <fstream>
#include <sstream>
using namespace std;
class Person {
    public:
        int age;
        string name;
        float gpa;
 
       
        Person(int a, const std::string& n, float g) : age(a), name(n), gpa(g) {}
        void display() const {
            cout << "Age: " << age << "\nName: " << name << "\nGPA: " << gpa << std::endl;
        }
 
};
 
int main() {
    // vector<Person> people = {
    //     {45, "Nikita", 44.5f},
    //     {56, "Ravi", 44.5f},
    //     {98, "Kajal", 44.5f},
    //     {36, "Sarthak", 88.5f}
    // };
   
    vector<Person> people;
    // read csv file
    ifstream file("data.csv");
    string line;
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }
 
    while (getline(file, line)) {
        istringstream iss(line);
        if (line.empty()) continue;
        string ageStr, name, gpaStr;
       
        // Split by comma
        getline(iss, ageStr, ',');
        getline(iss, name, ',');
        getline(iss, gpaStr, ',');
 
        int age = stoi(ageStr);
        float gpa = stof(gpaStr);
 
        people.emplace_back(age, name, gpa);
        // people.push_back(Person(age, name, gpa));
    }
    file.close();
   
 
    // fetch data from vector people and write into csv file
    ofstream csvOutputFile("data.csv");
    for (const auto& person : people) {
        csvOutputFile << person.age << "," << person.name << "," << person.gpa << "\n";
        person.display();
    }
    csvOutputFile.close();
}