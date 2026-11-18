// Experiment 8: STL Containers and Algorithms
// Processes a student marks dataset using vector, map, unordered_map,
// and the sort, find_if, and transform algorithms.

#include <algorithm>
#include <iomanip>
#include <iostream>
#include <map>
#include <string>
#include <unordered_map>
#include <vector>

struct Student {
    int id;
    std::string name;
    double marks;
};

char calculateGrade(double marks) {
    if (marks >= 90.0) {
        return 'A';
    }
    if (marks >= 75.0) {
        return 'B';
    }
    if (marks >= 60.0) {
        return 'C';
    }
    return 'F';
}

int main() {
    std::vector<Student> students = {
        {101, "Justin", 82.0},
        {102, "Emma", 94.5},
        {103, "Jennifer", 58.0},
        {104, "Sunny", 76.0},
        {105, "Victoria", 88.5}
    };

    // Add 2.5 bonus marks, without allowing a score above 100.
    std::transform(students.begin(), students.end(), students.begin(),
                   [](Student student) {
                       student.marks = std::min(100.0, student.marks + 2.5);
                       return student;
                   });

    // Sort students by marks in descending order.
    std::sort(students.begin(), students.end(),
              [](const Student& a, const Student& b) {
                  return a.marks > b.marks;
              });

    std::cout << std::fixed << std::setprecision(1);
    std::cout << "Sorted leaderboard (with bonus marks):\n";

    for (const Student& student : students) {
        std::cout << "ID: " << student.id
                  << " | Name: " << student.name
                  << " | Marks: " << student.marks
                  << " | Grade: " << calculateGrade(student.marks)
                  << '\n';
    }

    // Find the first student whose marks are below 65.
    auto it = std::find_if(
        students.begin(), students.end(),
        [](const Student& student) {
            return student.marks < 65.0;
        });

    if (it != students.end()) {
        std::cout << "\nFirst student needing attention (marks below 65): "
                  << it->name << " (" << it->marks << ")\n";
    } else {
        std::cout << "\nNo student has marks below 65.\n";
    }

    // Store student ID-to-marks information in an unordered_map.
    std::unordered_map<int, double> idToMarks;

    // Store grade-to-student-name information in a map.
    std::map<char, std::vector<std::string>> gradeDistribution;

    for (const Student& student : students) {
        idToMarks[student.id] = student.marks;
        gradeDistribution[calculateGrade(student.marks)].push_back(student.name);
    }

    std::cout << "\nFast lookup - Marks for ID 104: ";
    auto marksIt = idToMarks.find(104);

    if (marksIt != idToMarks.end()) {
        std::cout << marksIt->second << '\n';
    } else {
        std::cout << "Student ID not found.\n";
    }

    std::cout << "\nGrade distribution:\n";
    for (const auto& entry : gradeDistribution) {
        std::cout << "Grade " << entry.first << ": ";

        for (std::size_t i = 0; i < entry.second.size(); ++i) {
            if (i > 0) {
                std::cout << ", ";
            }
            std::cout << entry.second[i];
        }

        std::cout << '\n';
    }

    return 0;
}
