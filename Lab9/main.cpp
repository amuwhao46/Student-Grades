//==========================================================
//
// Title:       Structs and Stuff
// Course:      CSC 2111
// Lab Number:  9
// Author:      Oke Amuwha
// Date:        2/16/21
// Description:
//   Using Structs and array's to assign
//   values to different variables
//
//==========================================================
#include <cstdlib> // For several general-purpose functions
#include <fstream> // For file handling
#include <iomanip> // For formatted output
#include <iostream> // For cin, cout, and system
#include <string> // For string data type
#include <cmath> // For math
using namespace std; // So "std::cout" may be abbreviated to "cout"

//==========================================================
// Global Variables
//==========================================================
const int ARRAY_SIZE = 20;
const int COL1 = 10;
const int COL2 = 3;
const int COL3 = 14;
const string FILE_NAME = "studentData.txt";

//==========================================================
// Student Struct
//==========================================================
struct studentType
{
    string studentFName;
    string studentLName;
    int testScore;
    char grade;
};

//==========================================================
// Read Data Function
//==========================================================
int readData(ifstream& inFile, studentType student[])
{
    
    // Reads each line
    int line = 0;
    
    inFile >> student[line].studentFName
    >> student[line].studentLName
    >> student[line].testScore
    >> student[line].grade;
    
    // Loops through each line to assign data
    while (inFile)
    {
        line++;
        inFile >> student[line].studentFName
        >> student[line].studentLName
        >> student[line].testScore
        >> student[line].grade;
    }
    return line;
}

//==========================================================
//  Letter Grade Function
//==========================================================
char letterGrade(int grade)
{
        // Returns letter grade
        if (grade >= 90 && grade <= 100)
        {
            return 'A';
        }
        else if (grade >= 80 && grade < 90)
        {
            return 'B';
        }
        else if (grade >= 70 && grade < 80)
        {
            return 'C';
        }
        else if (grade >= 60 && grade < 70)
        {
            return 'D';
        }
        else
            return 'F';
}

//==========================================================
// Assign Grade Function
//==========================================================
void getGrade (studentType student[])
{
    // Assigns grades to students
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        student[i].grade = letterGrade(student[i].testScore);
    }
}

//==========================================================
// Highest Score Function
//==========================================================
void highestGrade(studentType student[])
{
    // Calculates & display's highest grade
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        if (student[0].testScore < student[i].testScore)
            student[0].testScore = student[i].testScore;
    }
    cout << "The student with the highest test score is: "
    << student[0].studentFName << " "
    << student[0].studentLName << endl;
    cout << endl;
}

//==========================================================
// Print Function
//==========================================================
void print(studentType student[])
{
    // Header
    cout << setw(COL3) << left << "Name"
    << setw(COL1) << left << "Score"
    << setw(COL1) << left << "Grade" << endl;
    
    // Outputs to display
    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        cout << left << student[i].studentLName
        << setw(2) << left << ", "
        << setw(COL1) << left << student[i].studentFName
        << setw(COL1) << student[i].testScore
        << setw(COL2) << student[i].grade << endl;
    }
    cout << endl;
}

//==========================================================
// Main
//==========================================================
int main()
{
    // Declare variables
    studentType student[ARRAY_SIZE];
    ifstream inFile;
    
    // Open file
    inFile.open(FILE_NAME);
    
    // Execute in file
    readData(inFile, student);
    getGrade(student);
    print(student);
    highestGrade(student);
    
    inFile.close();
}
