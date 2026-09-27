/*
  C++ Programming - Week 4 Assignment & Mini Project
  Topics: File Streams (Read/Write), Vectors, Sets, Maps (STL), Exception Handling
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <algorithm>
#include <string>
using namespace std;

// ==========================================
// 1. Write data into a file and read it back
// ==========================================
void fileHandlingDemo() {
    cout << "\n--- 1. File Streams (Read/Write) ---" << endl;
    
    // Writing to file
    ofstream outFile("sample.txt");
    if (outFile.is_open()) {
        outFile << "Hello, C++ File Handling!" << endl;
        outFile << "Storing week 4 assignment data." << endl;
        outFile.close();
        cout << "Data written to 'sample.txt' successfully." << endl;
    } else {
        cout << "Error opening file for writing!" << endl;
    }

    // Reading from file
    ifstream inFile("sample.txt");
    string line;
    cout << "\nReading contents from 'sample.txt':" << endl;
    if (inFile.is_open()) {
        while (getline(inFile, line)) {
            cout << line << endl;
        }
        inFile.close();
    } else {
        cout << "Error opening file for reading!" << endl;
    }
}

// ==========================================
// 2. Use vector to store N elements and sort them
// ==========================================
void vectorSortingDemo() {
    cout << "\n--- 2. Vector Sorting ---" << endl;
    int n, val;
    vector<int> numbers;

    cout << "Enter number of elements (N): ";
    cin >> n;

    cout << "Enter " << n << " integers: ";
    for (int i = 0; i < n; i++) {
        cin >> val;
        numbers.push_back(val);
    }

    // Sorting vector using STL sort
    sort(numbers.begin(), numbers.end());

    cout << "Sorted Vector: ";
    for (int num : numbers) {
        cout << num << " ";
    }
    cout << endl;
}

// ==========================================
// 3. Use map to store student roll & name
// ==========================================
void mapStudentDemo() {
    cout << "\n--- 3. Student Roll & Name using Map ---" << endl;
    map<int, string> studentMap;

    studentMap[101] = "Ankur";
    studentMap[102] = "Rahul";
    studentMap[103] = "Priya";

    cout << "Student Records in Map (Key = Roll No, Value = Name):" << endl;
    for (const auto &pair : studentMap) {
        cout << "Roll No: " << pair.first << " | Name: " << pair.second << endl;
    }
}

// ==========================================
// 4. Handle exception for division by zero
// ==========================================
void exceptionHandlingDemo() {
    cout << "\n--- 4. Exception Handling (Division by Zero) ---" << endl;
    double numerator, denominator;

    cout << "Enter numerator: ";
    cin >> numerator;
    cout << "Enter denominator: ";
    cin >> denominator;

    try {
        if (denominator == 0) {
            throw "Error: Division by Zero is not allowed!";
        }
        double result = numerator / denominator;
        cout << "Result: " << result << endl;
    } catch (const char* msg) {
        cerr << msg << endl;
    }
}

// ==========================================
// Mini Project: Employee Record Saver using File Handling + STL
// ==========================================
struct Employee {
    int id;
    string name;
    double salary;
};

void employeeRecordSaverProject() {
    cout << "\n=== MINI PROJECT: Employee Record Saver ===" << endl;
    vector<Employee> employeeList;
    int numEmp;

    cout << "Enter number of employees to add: ";
    cin >> numEmp;

    for (int i = 0; i < numEmp; i++) {
        Employee emp;
        cout << "\nEnter Employee " << i + 1 << " ID: ";
        cin >> emp.id;
        cout << "Enter Name: ";
        cin.ignore();
        getline(cin, emp.name);
        cout << "Enter Salary: ";
        cin >> emp.salary;
        employeeList.push_back(emp);
    }

    // Saving STL vector data to File
    ofstream empFile("employee_records.txt");
    if (empFile.is_open()) {
        for (const auto &emp : employeeList) {
            empFile << emp.id << "," << emp.name << "," << emp.salary << endl;
        }
        empFile.close();
        cout << "\nEmployee records saved to 'employee_records.txt' successfully!" << endl;
    }

    // Reading and displaying records from File
    ifstream readEmpFile("employee_records.txt");
    string line;
    cout << "\n--- Saved Records From File ---" << endl;
    if (readEmpFile.is_open()) {
        while (getline(readEmpFile, line)) {
            cout << line << endl;
        }
        readEmpFile.close();
    }
}

// ==========================================
// Main Function
// ==========================================
int main() {
    cout << "==========================================" << endl;
    cout << "C++ Week 4 Assignments & Mini Project" << endl;
    cout << "==========================================" << endl;

    fileHandlingDemo();
    vectorSortingDemo();
    mapStudentDemo();
    exceptionHandlingDemo();
    employeeRecordSaverProject();

    return 0;
}
