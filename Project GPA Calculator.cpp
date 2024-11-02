#include <iostream>
#include <vector>
using namespace std;

struct Course {
    string name;
    int credits;
    char grade;
};

double gradePoint(char grade) {
    switch (grade) {
        case 'A': return 4.0;
        case 'B': return 3.0;
        case 'C': return 2.0;
        case 'D': return 1.0;
        case 'F': return 0.0;
        default: return 0.0;
    }
}

double calculateGPA(const vector<Course>& courses) {
    double totalPoints = 0.0;
    int totalCredits = 0;

    for (const auto& course : courses) {
        double points = gradePoint(course.grade) * course.credits;
        totalPoints += points;
        totalCredits += course.credits;
    }

    return totalCredits > 0 ? totalPoints / totalCredits : 0.0;
}

int main() {
    int n;
    cout << "Enter the number of courses: ";
    cin >> n;

    vector<Course> courses(n);
    for (int i = 0; i < n; ++i) {
        cout << "Enter course name: ";
        cin >> courses[i].name;
        cout << "Enter credits for " << courses[i].name << ": ";
        cin >> courses[i].credits;
        cout << "Enter grade (A, B, C, D, F) for " << courses[i].name << ": ";
        cin >> courses[i].grade;
    }

    double gpa = calculateGPA(courses);
    cout << "Your GPA is: " << gpa << endl;

    return 0;
}

