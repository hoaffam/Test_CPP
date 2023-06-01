#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <string>
using namespace std;

struct Student {
    string name;
    string gender;
    int age;
    float math, physics, chemistry, average;
};

// Function to input student data
void inputStudents(vector<Student>& students, int N) {
    for (int i = 0; i < N; i++) {
        Student s;
        cout << "Enter student " << i + 1 << " details:" << endl;
        cout << "Name: ";
        cin.ignore();
        getline(cin, s.name);
        cout << "Gender: ";
        cin >> s.gender;
        cout << "Age: ";
        cin >> s.age;
        cout << "Math score: ";
        cin >> s.math;
        cout << "Physics score: ";
        cin >> s.physics;
        cout << "Chemistry score: ";
        cin >> s.chemistry;
        s.average = (s.math + s.physics + s.chemistry) / 3;
        students.push_back(s);
    }
}

// Function to display student data
void displayStudents(const vector<Student>& students) {
    for (const Student& s : students) {
        cout << "Name: " << s.name << ", Gender: " << s.gender << ", Age: " << s.age
             << ", Math: " << s.math << ", Physics: " << s.physics << ", Chemistry: " << s.chemistry
             << ", Average: " << s.average << endl;
    }
}

// Function to sort students by average score, name, and age
bool compareStudents(const Student& a, const Student& b) {
    if (a.average != b.average) {
        return a.average < b.average;
    }
    if (a.name != b.name) {
        return a.name < b.name;
    }
    return a.age < b.age;
}

// Function to sort students
void sortStudents(vector<Student>& students) {
    sort(students.begin(), students.end(), compareStudents);
}

// Function to classify students
void classifyStudents(vector<Student>& students) {
    for (Student& s : students) {
        if (s.average >= 9) {
            cout << s.name << " is classified as Excellent" << endl;
        } else if (s.average >= 7) {
            cout << s.name << " is classified as Good" << endl;
        } else if (s.average >= 5) {
            cout << s.name << " is classified as Average" << endl;
        } else {
            cout << s.name << " is classified as Weak" << endl;
        }
    }
}

// Function to save students to a file
void saveStudentsToFile(const vector<Student>& students, const string& filename) {
    ofstream file(filename);
    if (file.is_open()) {
        for (const Student& s : students) {
            file << "Name: " << s.name << ", Gender: " << s.gender << ", Age: " << s.age
                 << ", Math: " << s.math << ", Physics: " << s.physics << ", Chemistry: " << s.chemistry
                 << ", Average: " << s.average << endl;
        }
        file.close();
    } else {
        cout << "Unable to open file" << endl;
    }
}

int main() {
    vector<Student> students;
    int N;
    cout << "Enter the number of students: ";
    cin >> N;
    inputStudents(students, N);

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Display students" << endl;
        cout << "2. Sort students" << endl;
        cout << "3. Classify students" << endl;
        cout << "4. Save students to file" << endl;
        cout << "5. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                displayStudents(students);
                break;
            case 2:
                sortStudents(students);
                break;
            case 3:
                classifyStudents(students);
                break;
            case 4:
                saveStudentsToFile(students, "students.txt");
                break;
            case 5:
                cout << "Exiting..." << endl;
                break;
            default:
                cout << "Invalid choice" << endl;
        }
    } while (choice != 5);

    return 0;
}
