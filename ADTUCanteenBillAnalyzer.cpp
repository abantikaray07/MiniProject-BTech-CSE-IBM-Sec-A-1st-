**Problem Title: ADTU Canteen Bill Analyzer
Story:

At Assam Down Town University (ADTU), the hostel canteen records the daily food expenses of each student.
Each row in a 2D array represents a student, and each column represents a day of the day week (from Monday to Friday).
The value bill[i][j] is the amount in ₹ spent by student i on day j.
You, as the Canteen Manager of ADTU, have been asked to analyze the weekly canteen records.

🧠 Your Tasks:

Given the 2D array bill, write a program to:

Print the total amount spent by each student in the week.

Find the day with the highest total collection.

Identify the student (or students) who spent the most overall.

Input Format:

The first line contains two integers:
n → number of students
m → number of days

The next n lines each contain m integers — the daily bill amounts.

📤 Output Format:

Print each student’s total weekly spending.

Print which day had the highest total collection.

Print which student(s) spent the most overall.
Input :
4 5
30 40 50 60 20
10 20 30 10 40
50 60 40 30 20
20 10 10 20 30

Output:

Student 1 total: ₹200  
Student 2 total: ₹110  
Student 3 total: ₹200  
Student 4 total: ₹90  

Highest collection on Day 2  
Highest spender: Student 1 and Student 3




#include <iostream>
#include <string>
using namespace std;

int main() {
    int n, m;

    cout << "Enter number of students: ";
    cin >> n;
    cout << "Enter number of days: ";
    cin >> m;

    int bill[n][m];

    cout << "Enter bill amounts for each student (rows) for each day (columns):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cin >> bill[i][j];
        }
    }

 
    cout << "\nBill Matrix (each row is a student, each column is a day):" << endl;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            cout << bill[i][j] << "\t";
        }
        cout << endl;
    }
    cout << endl;

    int studentTotals[n] = {0};
    int dayTotals[m] = {0};

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            studentTotals[i] += bill[i][j];
            dayTotals[j] += bill[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        cout << "Student " << i + 1 << " total: Rs." << studentTotals[i] << "  " << endl;
    }

    int maxDayIndex = 0;
    for (int j = 1; j < m; ++j) {
        if (dayTotals[j] > dayTotals[maxDayIndex]) {
            maxDayIndex = j;
        }
    }
    cout << "Highest collection on Day " << maxDayIndex + 1 << "  " << endl;

    int maxSpent = studentTotals[0];
    for (int i = 1; i < n; ++i) {
        if (studentTotals[i] > maxSpent) {
            maxSpent = studentTotals[i];
        }
    }

    cout << "Highest spender:";
    bool first = true;
    for (int i = 0; i < n; ++i) {
        if (studentTotals[i] == maxSpent) {
            if (!first) {
                cout << " and";
            }
            cout << " Student " << i + 1;
            first = false;
        }
    }
    cout << endl;

    return 0;
}