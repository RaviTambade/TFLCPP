#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Person {
    public:
        int age;
        std::string name;
        float gpa;

    Person(int a, const std::string& n, float g) : age(a), name(n), gpa(g) {}

    void display() const {
        std::cout << "Age: " << age << "\nName: " << name << "\nGPA: " << gpa << std::endl;
    }
};
 
int main() {
    
    std::string line = "45 Nikita 44.5,56 Ravi 44.5,98 Kajal 44.5,36 Sarthak 88.5";
    std::istringstream iss(line);

    vector<Person> people;
    Person thePerson(0, "", 0.0f); // Default constructor

    //extract data from the string stream
    //Using getline to read until a comma
    //and then using istringstream to parse the individual fields
    

    while(iss) {
        std::string temp;
        std::getline(iss, temp, ',');
        if (temp.empty()) break; // Skip empty entries

        std::istringstream tempStream(temp);
        tempStream >> thePerson.age >> thePerson.name >> thePerson.gpa;
        people.push_back(thePerson); // Store the person in the vector
    }
 
    for (const auto& person : people) {
        person.display(); // Display each person's details
    }

    return 0;
} // end of main
