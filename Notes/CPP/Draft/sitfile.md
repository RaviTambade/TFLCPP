# Student Information System
To add **file handling** to the **Student Information System** project using **C++ file streams**, we can use the **`fstream`** library to store and retrieve student data to/from a file. This will allow the system to persist student information even after the program is closed and reopened.

### Steps for Adding File Handling:

1. **Saving Student Records to a File**: Whenever a student is added or updated, save the student information to a file.
2. **Reading Student Records from a File**: When the program starts, read the data from the file and populate the system with existing student records.
3. **Deleting Student Records from a File**: If a student record is deleted, the corresponding record in the file should also be removed.

### File Operations to Implement:
- **Saving data to a file** when a new student is added.
- **Reading data from a file** when the system starts.
- **Updating data in a file** after modifying a student record.
- **Deleting data in a file** when a record is removed.

### **File Handling in the Student Information System**

We'll modify the `StudentInfoSystem` class to incorporate file handling for storing and reading student data.

#### 1. **Update the `StudentInfoSystem` Class to Handle File Operations**

Here's the modified version of the system with file handling capabilities:

```cpp
#include <iostream>
#include <vector>
#include <string>
#include <fstream>

using namespace std;

class Student {
public:
    int studentID;
    string name;
    int age;
    string course;
    float marks;
    char grade;

    // Constructor to initialize student information
    Student(int id, string n, int a, string c, float m, char g) {
        studentID = id;
        name = n;
        age = a;
        course = c;
        marks = m;
        grade = g;
    }

    // Default constructor for file reading
    Student() {}

    // Function to display student information
    void displayStudent() {
        cout << "ID: " << studentID << ", Name: " << name << ", Age: " << age 
             << ", Course: " << course << ", Marks: " << marks << ", Grade: " << grade << endl;
    }

    // Function to calculate grade based on marks
    void calculateGrade() {
        if (marks >= 90) grade = 'A';
        else if (marks >= 75) grade = 'B';
        else if (marks >= 50) grade = 'C';
        else grade = 'F';
    }

    // Function to write student to a file
    void writeToFile(ofstream &outFile) {
        outFile << studentID << "\n"
                << name << "\n"
                << age << "\n"
                << course << "\n"
                << marks << "\n"
                << grade << "\n";
    }

    // Function to read student from a file
    void readFromFile(ifstream &inFile) {
        inFile >> studentID;
        inFile.ignore(); // Ignore newline
        getline(inFile, name);
        inFile >> age;
        inFile.ignore(); // Ignore newline
        getline(inFile, course);
        inFile >> marks;
        inFile.ignore(); // Ignore newline
        inFile >> grade;
    }
};

class StudentInfoSystem {
private:
    vector<Student> students;
    const string filename = "students.txt"; // File to store student data

public:
    // Function to add a student
    void addStudent() {
        int id, age;
        string name, course;
        float marks;
        char grade;

        cout << "Enter Student ID: ";
        cin >> id;
        cout << "Enter Student Name: ";
        cin.ignore();  // Ignore leftover newline
        getline(cin, name);
        cout << "Enter Age: ";
        cin >> age;
        cout << "Enter Course: ";
        cin.ignore();  // Ignore leftover newline
        getline(cin, course);
        cout << "Enter Marks: ";
        cin >> marks;

        // Calculate grade based on marks
        Student newStudent(id, name, age, course, marks, grade);
        newStudent.calculateGrade();

        students.push_back(newStudent);

        // Save the new student data to file
        saveToFile();
        cout << "Student added successfully!" << endl;
    }

    // Function to display all students
    void displayStudents() {
        if (students.empty()) {
            cout << "No students in the record." << endl;
            return;
        }
        for (const auto& student : students) {
            student.displayStudent();
        }
    }

    // Function to search for a student by ID
    void searchStudent(int id) {
        bool found = false;
        for (const auto& student : students) {
            if (student.studentID == id) {
                student.displayStudent();
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    // Function to update student information by ID
    void updateStudent(int id) {
        bool found = false;
        for (auto& student : students) {
            if (student.studentID == id) {
                found = true;
                string name, course;
                int age;
                float marks;
                cout << "Enter new Name: ";
                cin.ignore();  // Ignore leftover newline
                getline(cin, name);
                student.name = name;
                cout << "Enter new Age: ";
                cin >> age;
                student.age = age;
                cout << "Enter new Course: ";
                cin.ignore();  // Ignore leftover newline
                getline(cin, course);
                student.course = course;
                cout << "Enter new Marks: ";
                cin >> marks;
                student.marks = marks;
                student.calculateGrade();
                saveToFile(); // Save updated data to file
                cout << "Student information updated successfully!" << endl;
                break;
            }
        }
        if (!found) {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    // Function to delete a student by ID
    void deleteStudent(int id) {
        bool found = false;
        for (auto it = students.begin(); it != students.end(); ++it) {
            if (it->studentID == id) {
                students.erase(it);
                saveToFile(); // Save updated data to file
                cout << "Student with ID " << id << " deleted successfully!" << endl;
                found = true;
                break;
            }
        }
        if (!found) {
            cout << "Student with ID " << id << " not found." << endl;
        }
    }

    // Function to save all students to the file
    void saveToFile() {
        ofstream outFile(filename);
        if (outFile.is_open()) {
            for (const auto& student : students) {
                student.writeToFile(outFile);
            }
            outFile.close();
        } else {
            cout << "Unable to open file for saving!" << endl;
        }
    }

    // Function to load all students from the file
    void loadFromFile() {
        ifstream inFile(filename);
        if (inFile.is_open()) {
            while (!inFile.eof()) {
                Student student;
                student.readFromFile(inFile);
                if (inFile) {
                    students.push_back(student);
                }
            }
            inFile.close();
        } else {
            cout << "Unable to open file for reading!" << endl;
        }
    }
};

int main() {
    StudentInfoSystem sis;
    sis.loadFromFile(); // Load data from file when the program starts
    int choice, id;

    while (true) {
        // Display the menu
        cout << "\nStudent Information System\n";
        cout << "1. Add Student\n";
        cout << "2. Display All Students\n";
        cout << "3. Search Student by ID\n";
        cout << "4. Update Student Information\n";
        cout << "5. Delete Student Record\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                sis.addStudent();
                break;
            case 2:
                sis.displayStudents();
                break;
            case 3:
                cout << "Enter Student ID to search: ";
                cin >> id;
                sis.searchStudent(id);
                break;
            case 4:
                cout << "Enter Student ID to update: ";
                cin >> id;
                sis.updateStudent(id);
                break;
            case 5:
                cout << "Enter Student ID to delete: ";
                cin >> id;
                sis.deleteStudent(id);
                break;
            case 6:
                cout << "Exiting program. Goodbye!" << endl;
                return 0;
            default:
                cout << "Invalid choice! Please try again." << endl;
        }
    }

    return 0;
}
```

### **Key Changes:**

1. **File Operations**:
   - **`saveToFile()`**: Saves all student data to the file.
   - **`loadFromFile()`**: Loads student data from the file at the beginning of the program.
   - **`writeToFile()`**: Writes individual student data to the file.
   - **`readFromFile()`**: Reads individual student data from the file.

2. **Handling New Students**: Whenever a student is added or updated, the system saves the data back to the file using `saveToFile()`.

3. **Loading Data on Startup**: The `loadFromFile()` function is called when the program starts to read any previously saved student data.

### **How the Program Works Now**:
- When you run the program, it will read any existing student data from `students.txt`.
- Any addition, update, or deletion of student records will be reflected both in the program and saved back to the file.
- When you exit and restart the program, the student data will persist.

This enhances the Student Information System with **file handling**, allowing the system to save and load student data between program runs.