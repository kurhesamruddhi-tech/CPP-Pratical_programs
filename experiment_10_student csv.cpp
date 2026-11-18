#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
using namespace std;

int main() {
    fstream file;
    int n, rollNo;
    string name;
    float marks;

    // Write student records into a CSV file
    file.open("students.csv", ios::out | ios::trunc);

    if (!file) {
        cout << "Unable to open file!";
        return 1;
    }

    cout << "Enter number of students: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        cout << "\nEnter roll number: ";
        cin >> rollNo;

        cout << "Enter name: ";
        cin >> ws;
        getline(cin, name);

        cout << "Enter marks: ";
        cin >> marks;

        file << rollNo << "," << name << "," << marks << "\n";
    }

    // Display the current write position
    cout << "\nFile pointer after writing: " << file.tellp() << endl;
    file.close();

    // Read student records from the CSV file
    file.open("students.csv", ios::in);

    if (!file) {
        cout << "Unable to read file!";
        return 1;
    }

    // Move the read pointer to the beginning of the file
    file.seekg(0, ios::beg);

    cout << "\nStudent Records:\n";
    cout << "Roll No\tName\tMarks\n";

    string line;
    while (getline(file, line)) {
        stringstream ss(line);
        string roll, studentName, mark;

        getline(ss, roll, ',');
        getline(ss, studentName, ',');
        getline(ss, mark, ',');

        cout << roll << "\t" << studentName << "\t" << mark << endl;
    }

    cout << "\nFile pointer after reading: " << file.tellg() << endl;

    file.close();
    return 0;
}
