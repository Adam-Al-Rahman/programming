#include <iostream>
#include <string>
#include <vector>

// Student class to represent a student object
class Student {
 private:
  std::string name;
  int age;
  int studentID;

 public:
  // Constructor
  Student(const std::string& n, int a, int id) : name(n), age(a), studentID(id) {}

  // Getters
  std::string getName() const { return name; }
  int getAge() const { return age; }
  int getStudentID() const { return studentID; }

  // Display student information
  void displayInfo() const {
    std::cout << "Name: " << name << std::endl;
    std::cout << "Age: " << age << std::endl;
    std::cout << "Student ID: " << studentID << std::endl;
    std::cout << "---------------------------" << std::endl;
  }
};

// ObjectDatabase class to manage student objects
class ObjectDatabase {
 private:
  std::vector<Student> students;

 public:
  // Singleton pattern to ensure only one instance of ObjectDatabase
  static ObjectDatabase& getInstance() {
    static ObjectDatabase instance;
    return instance;
  }

  // Add a student to the database
  void addStudent(const std::string& name, int age, int studentID) {
    Student newStudent(name, age, studentID);
    students.push_back(newStudent);
  }

  // Display all students in the database
  void displayAllStudents() const {
    for (const auto& student : students) {
      student.displayInfo();
    }
  }

 private:
  // Private constructor to enforce Singleton pattern
  ObjectDatabase() = default;
  ~ObjectDatabase() = default;

  // Disable copy and assignment to enforce Singleton pattern
  ObjectDatabase(const ObjectDatabase&) = delete;
  ObjectDatabase& operator=(const ObjectDatabase&) = delete;
};

int main() {
  // Get the singleton instance of ObjectDatabase
  ObjectDatabase& database = ObjectDatabase::getInstance();

  // Adding students to the database
  database.addStudent("Alice", 20, 1001);
  database.addStudent("Bob", 22, 1002);
  database.addStudent("Charlie", 21, 1003);

  // Displaying all students in the database
  database.displayAllStudents();

  return 0;
}
