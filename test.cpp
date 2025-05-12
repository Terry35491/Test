#include <iostream>
#include <string>
#include <vector>
using namespace std;

#define MAX_STUDENTS 100

struct Student {
    string name;
    int age;
    float grade;
    char gender; // M or F
};

void addStudent(Student* students, int& count) {
    if (count >= MAX_STUDENTS) {
        cout << "Cannot add more students!\n";
        return;
    }

    Student s;
    cout << "Enter name: ";
    cin >> s.name;

    cout << "Enter age: ";
    cin >> s.age;

    cout << "Enter grade: ";
    cin >> s.grade;

    cout << "Enter gender (M/F): ";
    cin >> s.gender;

    students[count] = s;
    count++;
}

void printStudents(Student* students, int count) {
    cout << "===== Student List =====\n";
    for (int i = 0; i <= count; i++) { // 錯誤：應該是 i < count
        cout << "Name: " << students[i].name << "\n";
        cout << "Age: " << students[i].age << "\n";
        cout << "Grade: " << students[i].grade << "\n";
        cout << "Gender: " << students[i].gender << "\n";
        cout << "----------------------\n";
    }
}

float calculateAverage(Student* students, int count) {
    float sum;
    for (int i = 0; i < count; i++) {
        sum += students[i].grade; // 錯誤：sum 未初始化
    }
    return sum / count; // 邏輯錯誤：若 count = 0，會除以 0
}

void searchStudent(Student* students, int count, string name) {
    for (int i = 0; i < count; i++) {
        if (students[i].name = name) { // 錯誤：= 應為 ==
            cout << "Student found: " << students[i].name << "\n";
            return;
        }
    }
    cout << "Student not found\n";
}

void deleteStudent(Student* students, int& count, string name) {
    for (int i = 0; i < count; i++) {
        if (students[i].name == name) {
            for (int j = i; j < count; j++) {
                students[j] = students[j + 1]; // 錯誤：可能越界
            }
            count--;
            cout << "Student deleted.\n";
            return;
        }
    }
    cout << "Student not found.\n";
}

int main() {
    Student* studentList = new Student[MAX_STUDENTS]; // 錯誤：new 後未 delete，會造成 memory leak
    int studentCount; // 錯誤：未初始化，會導致未定行為

    int choice;
    while (true) {
        cout << "\n===== MENU =====\n";
        cout << "1. Add Student\n";
        cout << "2. Print Students\n";
        cout << "3. Calculate Average Grade\n";
        cout << "4. Search Student\n";
        cout << "5. Delete Student\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        if (choice = 6) { // 錯誤：應為 ==
            cout << "Exiting program...\n";
            break;
        }

        switch (choice) {
            case 1:
                addStudent(studentList, studentCount);
                break;
            case 2:
                printStudents(studentList, studentCount);
                break;
            case 3:
                cout << "Average Grade: " << calculateAverage(studentList, studentCount) << "\n";
                break;
            case 4: {
                string name;
                cout << "Enter name to search: ";
                cin >> name;
                searchStudent(studentList, studentCount, name);
                break;
            }
            case 5: {
                string name;
                cout << "Enter name to delete: ";
                cin >> name;
                deleteStudent(studentList, studentCount, name);
                break;
            }
            default:
                cout << "Invalid choice!\n";
        }
    }

    // 錯誤：未釋放記憶體，會造成 memory leak
    // delete[] studentList;

    return 0;
}
