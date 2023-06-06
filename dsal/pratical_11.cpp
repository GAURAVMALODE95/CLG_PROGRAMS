#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// Structure to hold student information
struct Student {
    int rollNumber;
    string name;
    string division;
    string address;
};

// Function to add a new student record
void addStudent() {
    Student student;
    
    cout << "Enter Roll Number: ";
    cin >> student.rollNumber;
    
    cout << "Enter Name: ";
    cin.ignore();
    getline(cin, student.name);
    
    cout << "Enter Division: ";
    getline(cin, student.division);
    
    cout << "Enter Address: ";
    getline(cin, student.address);
    
    ofstream outFile("students.txt", ios::app);
    outFile << student.rollNumber << "," << student.name << "," << student.division << "," << student.address << endl;
    outFile.close();
    
    cout << "Student record added successfully." << endl;
}

// Function to delete a student record
void deleteStudent() {
    int rollNumber;
    cout << "Enter Roll Number of student to delete: ";
    cin >> rollNumber;
    
    ifstream inFile("students.txt");
    ofstream outFile("temp.txt");
    
    Student student;
    bool found = false;
    
    while (inFile >> student.rollNumber) {
        inFile.ignore();
        getline(inFile, student.name, ',');
        getline(inFile, student.division, ',');
        getline(inFile, student.address);
        
        if (student.rollNumber != rollNumber) {
            outFile << student.rollNumber << "," << student.name << "," << student.division << "," << student.address << endl;
        } else {
            found = true;
        }
    }
    
    inFile.close();
    outFile.close();
    
    if (found) {
        remove("students.txt");
        rename("temp.txt", "students.txt");
        cout << "Student record deleted successfully." << endl;
    } else {
        remove("temp.txt");
        cout << "Student record not found." << endl;
    }
}

// Function to display information of a particular student
void displayStudent() {
    int rollNumber;
    cout << "Enter Roll Number of student to display: ";
    cin >> rollNumber;
    
    ifstream inFile("students.txt");
    
    Student student;
    bool found = false;
    
    while (inFile >> student.rollNumber) {
        inFile.ignore();
        getline(inFile, student.name, ',');
        getline(inFile, student.division, ',');
        getline(inFile, student.address);
        
        if (student.rollNumber == rollNumber) {
            cout << "Roll Number: " << student.rollNumber << endl;
            cout << "Name: " << student.name << endl;
            cout << "Division: " << student.division << endl;
            cout << "Address: " << student.address << endl;
            found = true;
            break;
        }
    }
    
    inFile.close();
    
    if (!found) {
        cout << "Student record not found." << endl;
    }
}

int main() {
    int choice;
    
    do {
        cout << "***** Student Information System *****" << endl;
        cout << "1. Add Student" << endl;
        cout << "2. Delete Student" << endl;
        cout << "3. Display Student" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter your choice: ";
        cin >> choice;
        
        switch (choice) {
            case 1:
                addStudent();
                break;
            case 2:
                deleteStudent();
                break;
            case 3:
                displayStudent();
                break;
            case 4:
                cout << "Exiting program..." << endl;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
        
        cout << endl;
    } while (choice != 4);
    
    return 0;
}
