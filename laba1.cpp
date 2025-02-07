#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Student {
private:
    string fullName;
    vector<int> grades;

public:
    Student(string name, vector<int> marks) : fullName(name), grades(marks) {}

    void printInfo() const {
        cout << "ФИО: " << fullName << "\nОценки: ";
        for (int grade : grades) {
            cout << grade << " ";
        }
        cout << "\n";
    }

    bool scholarship() const {
        for (int grade : grades) {
            if (grade < 4) {
                return false;
            }
        }
        return true;
    }

    string getName() const {
        return fullName;
    }
};

int main() {
	setlocale(LC_ALL, "Russian");   
    vector<Student> students = {
        Student("Иванов Иван Иванович", {5, 4, 5, 5}),
        Student("Петров Петр Петрович", {3, 4, 5, 5}),
        Student("Сидоров Сидор Сидорович", {4, 4, 4, 5}),
        Student("Кузнецов Алексей Сергеевич", {5, 5, 5, 5})
    };

    cout << "Студенты, получающие стипендию:\n";
    for (const Student& student : students) {
        if (student.scholarship()) {
            student.printInfo();
        }
    }

    return 0;
}
