#include <fstream>
#include <sstream>
#include "Employee.h"
#include "FileIOManager.h"

void FileIOManager::writeToFile(const std::string& filename, const std::vector<Employee>& employees) {
    std::ofstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for writing");
    }
    for (const auto& emp : employees) {
        file << emp.id << "," << emp.name << "," << emp.salary << "," << emp.experience << "," << emp.age << "\n";
    }
}


std::vector<Employee> FileIOManager::readFromFile(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        throw std::runtime_error("Could not open file for reading");
    }

    std::vector<Employee> employees;
    std::string line;
    while (std::getline(file, line)) {
        std::istringstream iss(line);
        Employee emp;
        std::string token;

        if (std::getline(iss, token, ',')) emp.id = std::stoi(token);
        if (std::getline(iss, token, ',')) emp.name = token;
        if (std::getline(iss, token, ',')) emp.salary = std::stof(token);
        if (std::getline(iss, token, ',')) emp.experience = std::stoi(token);
        if (std::getline(iss, token, ',')) emp.age = std::stoi(token);

        // Only add if all fields were successfully read
        if (!emp.name.empty()) {
            employees.push_back(emp);
        }
    }
    return employees;
}
