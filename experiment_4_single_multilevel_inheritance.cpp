// Experiment 4: Single and Multilevel Inheritance
// Aim: Demonstrate inheritance in a university management scenario.

#include <iostream>
#include <string>
using namespace std;

// Base class
class Person
{
public:
    string name = "Alice";

    void showPerson()
    {
        cout << "Name: " << name << endl;
    }
};

// Student inherits from Person (single inheritance)
class Student : public Person
{
public:
    int studentId = 101;

    void showStudent()
    {
        showPerson();
        cout << "ID: " << studentId << endl;
    }
};

// GraduateStudent inherits from Student
// Person -> Student -> GraduateStudent (multilevel inheritance)
class GraduateStudent : public Student
{
public:
    string topic = "AI Research";

    void showGraduate()
    {
        showStudent();
        cout << "Research: " << topic << endl;
    }
};

int main()
{
    cout << "Single Inheritance" << endl;
    Student s;
    s.showStudent();

    cout << endl << "Multilevel Inheritance" << endl;
    GraduateStudent g;
    g.showGraduate();

    return 0;
}
