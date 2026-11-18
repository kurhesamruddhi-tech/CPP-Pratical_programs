// Experiment 2: Access Specifiers and Friend Function
// Aim: Demonstrate private, protected and public access specifiers.

#include <iostream>
#include <string>
using namespace std;

class Student
{
private:
    string name;       // Accessible only inside Student

protected:
    int DOB;           // Accessible inside Student and derived classes

public:
    int marks;         // Accessible from outside the class

    Student(string n, int dob, int m)
    {
        name = n;
        DOB = dob;
        marks = m;
    }

    void display()
    {
        cout << "Name: " << name << endl;
        cout << "DOB: " << DOB << endl;
    }

    // A friend function can access private and protected members.
    friend void showGrade(Student s);
};

void showGrade(Student s)
{
    s.display();
    cout << "Marks: " << s.marks << endl;
    cout << "DOB (protected access through friend): " << s.DOB << endl;
}

int main()
{
    Student myDetails("Saipradnya", 2007, 83);

    showGrade(myDetails);

    return 0;
}
