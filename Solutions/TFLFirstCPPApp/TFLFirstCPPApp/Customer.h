#pragma once
#include <iostream>
#include <fstream>
#include <string>

class Customer
{
    private:
        std::string name;
        int age;
        double salary;

    public:
        Customer(const std::string& name, int age, double salary) :
            name(name), age(age), salary(salary) {}

        void serialize(const std::string& filename);
        static Customer deserialize(const std::string& filename);

        void display() const;
};