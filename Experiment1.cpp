#include <iostream>
using namespace std;

int main()
{
    // Data types and variables
    int age = 20;
    float height = 5.5f;
    char grade = 'A';
    bool is_student = true;

    // Constant
    const int max_marks = 100;

    // Variable for user input
    int stud_age;

    // Arithmetic and relational operators
    int a = 10, b = 3;

    cout << "Age: " << age << endl;
    cout << "Height: " << height << endl;
    cout << "Grade: " << grade << endl;
    cout << "Is student: " << boolalpha << is_student << endl;
    cout << "Max marks: " << max_marks << endl;

    cout << "Sum: " << a + b << endl;
    cout << "Difference: " << a - b << endl;
    cout << "Product: " << a * b << endl;
    cout << "Quotient: " << a / b << endl;
    cout << "Remainder: " << a % b << endl;
    cout << "a > b: " << (a > b) << endl;

    cout << "Enter your age: ";
    cin >> stud_age;
    cout << "You entered: " << stud_age << endl;

    return 0;
}
