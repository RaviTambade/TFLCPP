#include <iostream>
#include <fstream>       
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

    std::ifstream file("people.csv");
    if (!file.is_open()) {
        std::cerr << "Failed to open file!" << std::endl;
        return 1;
    }

    std::vector<Person> people;
    std::string line;

    while (std::getline(file, line)) {
        if (line.empty()) continue; // skip empty lines

        std::istringstream iss(line);
        int age;
        std::string name;
        float gpa;

        //use operator>> to read from the stream
        // Note: This assumes the CSV format is correct and does not handle commas in names or other complexities.
        iss >> age >> name >> gpa;
        people.emplace_back(age, name, gpa); // directly create and add Person
    }

    file.close(); // always good to close files

    for (const auto& person : people) {
        person.display();
    }
    return 0;
}
