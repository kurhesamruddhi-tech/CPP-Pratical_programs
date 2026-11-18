// Experiment 3: Types of Constructors
// Aim: Demonstrate default, parameterized, copy and move constructors.

#include <iostream>
#include <string>
#include <utility>
using namespace std;

class Student
{
public:
    string name;

    // Default constructor
    Student()
    {
        name = "Pooja";
        cout << "Default Constructor" << endl;
    }

    // Parameterized constructor
    Student(string n)
    {
        name = n;
        cout << "Parameterized Constructor" << endl;
    }

    // Copy constructor
    Student(const Student &s)
    {
        name = s.name;
        cout << "Copy Constructor" << endl;
    }

    // Move constructor
    Student(Student &&s) noexcept
    {
        name = move(s.name);
        cout << "Move Constructor" << endl;
    }
};

int main()
{
    Student s1;
    cout << "Name: " << s1.name << endl;

    Student s2("Priya");
    cout << "Name: " << s2.name << endl;

    Student s3(s2);             // Calls copy constructor
    cout << "Name: " << s3.name << endl;

    Student s4(move(s3));       // Calls move constructor
    cout << "Name: " << s4.name << endl;

    return 0;
}
