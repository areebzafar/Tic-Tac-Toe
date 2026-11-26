#include <iostream>
#include <string>
using namespace std;

#define MAX 100

struct Student {
    int roll;
    string name;
    string grade;
};

Student arr[MAX];
int size = 0;

void traverse() {
    if (size == 0) {
        cout << "\nNo records available.\n";
        return;
    }

    cout << "\n--- Student List ---\n";
    for (int i = 0; i < size; i++) {
        cout << "\nRoll No: " << arr[i].roll;
        cout << "\nName   : " << arr[i].name;
        cout << "\nGrade  : " << arr[i].grade << endl;
    }
}

void insertStudent() {
    if (size == MAX) {
        cout << "\nArray is full! Cannot insert.\n";
        return;
    }

    cout << "\nEnter Roll Number: ";
    cin >> arr[size].roll;

    cin.ignore();
    cout << "Enter Name: ";
    getline(cin, arr[size].name);

    cout << "Enter Grade: ";
    cin >> arr[size].grade;

    size++;
    cout << "\nStudent inserted successfully!\n";
}

int searchStudent(int roll) {
    for (int i = 0; i < size; i++) {
        if (arr[i].roll == roll) {
            return i;
        }
    }
    return -1;
}

void deleteStudent() {
    int roll;
    cout << "\nEnter Roll Number to delete: ";
    cin >> roll;

    int index = searchStudent(roll);

    if (index == -1) {
        cout << "\nStudent not found!\n";
        return;
    }

    for (int i = index; i < size - 1; i++) {
        arr[i] = arr[i + 1];
    }

    size--;
    cout << "\nStudent deleted successfully!\n";
}

void updateStudent() {
    int roll;
    cout << "\nEnter Roll Number to update: ";
    cin >> roll;

    int index = searchStudent(roll);

    if (index == -1) {
        cout << "\nStudent not found!\n";
        return;
    }

    cin.ignore();
    cout << "Enter New Name: ";
    getline(cin, arr[index].name);

    cout << "Enter New Grade: ";
    cin >> arr[index].grade;

    cout << "\nStudent record updated successfully!\n";
}

int main() {
    int choice;

    do {
        cout << "\n====== STUDENT MANAGEMENT SYSTEM (DSA - ARRAY) ======\n";
        cout << "1. Traverse\n";
        cout << "2. Insert\n";
        cout << "3. Delete\n";
        cout << "4. Search\n";
        cout << "5. Update\n";
        cout << "6. Exit\n";
        cout << "Enter choice: ";
        cin >> choice;

        switch (choice) {
            case 1:
                traverse();
                break;

            case 2:
                insertStudent();
                break;

            case 3:
                deleteStudent();
                break;

            case 4: {
                int roll;
                cout << "\nEnter Roll Number to search: ";
                cin >> roll;

                int index = searchStudent(roll);
                if (index == -1) {
                    cout << "\nStudent not found!\n";
                } else {
                    cout << "\nStudent Found:";
                    cout << "\nRoll No: " << arr[index].roll;
                    cout << "\nName   : " << arr[index].name;
                    cout << "\nGrade  : " << arr[index].grade << endl;
                }
                break;
            }

            case 5:
                updateStudent();
                break;

            case 6:
                cout << "\nExiting program...\n";
                break;

            default:
                cout << "\nInvalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}
