#include <string>

#include <vector>
#include "Employee.h"

class FileIOManager {
public:
    void writeToFile(const std::string& filename, const std::vector<Employee>& employees);
    std::vector<Employee> readFromFile(const std::string& filename);
};