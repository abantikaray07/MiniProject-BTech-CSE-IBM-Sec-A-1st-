HOSTEL ATTENDANCE TRACKER 
Assam Down Town University maintains a strict hostel monitoring system to ensure student safety.
Every hostel student must mark attendance daily.
The warden keeps attendance for 7 days (Monday to Sunday) for 10 students.

The attendance is stored in a 2D array A[10][7], where:
A[i][j] = 1 → Student i was Present on Day j

A[i][j] = 0 → Student i was Absent on Day j

Here:

i = Student number (1 to 10)

j = Day number (1 to 7)

The warden wants a weekly summary of attendance.

Your Task: Write the algorithm or C program to do the following:
(a) Calculate and print the total number of days each student was present.

Total present days = sum of each row.

(b) Identify the student who has the highest attendance in the week.

If two students have the same highest attendance, print the one with the lower student number.

Find the day (1–7) on which overall hostel attendance was the lowest.

Total attendance on a day = sum of each column.
Input :
1 1 0 1 1 0 1
1 0 1 1 1 1 1
0 1 1 0 1 1 0
1 1 1 1 0 1 1
1 0 1 0 1 0 1
0 0 1 1 1 1 1
1 1 0 0 0 1 1
1 1 1 1 1 0 0
0 1 1 1 1 1 1
1 0 0 1 1 1 1

Output:
Weekly Attendance Summary
-------------------------

Total Present Days:
Student 1: 5
Student 2: 6
Student 3: 4
Student 4: 6
Student 5: 4
Student 6: 5
Student 7: 5
Student 8: 5
Student 9: 6
Student 10: 5

Student with Highest Attendance: Student 2 (6 Days)

Day with Lowest Overall Attendance: Day 2


#include <iostream>
using namespace std ;
int main(){
    int days = 7;
    int student = 10;
    int present =0;
    int absent =0;
    int atten[7][10];
    int totalPresent[10] = {0}; 
    int totalDay[7] = {0};    
    for(int i =0 ; i<student;i++){
        cout<<"Student "<<i+1<<" : ";
        for(int j=0;j<days;j++ ){
            cin>>atten[i][j];
            if(atten[i][j]==1){
               present++;
            }
            else if(atten[i][j]==0){
                absent++;
            }
            else if(atten[i][j]){
                cout<<"INVALID INPUT"<<endl;
                break;
            }
        }
    }
    
    cout<<endl;
cout<<"Present = "<<present<<endl;
cout<<"Absent = "<<absent<<endl;

cout << "Weekly Attendance Summary" << endl;
    cout << "-------------------------" << endl << endl;
    cout << "Total Present Days:" << endl;
    for (int i = 0; i < student; i++) {
        cout << "Student " << i + 1 << ": " << totalPresent[i] << endl;
    }
    cout << endl;
int maxPresent = totalPresent[0];
    int highestStudent = 0;
    for (int i = 1; i < student; i++) {
        if (totalPresent[i] > maxPresent ||
            (totalPresent[i] == maxPresent && i < highestStudent)) {
            maxPresent = totalPresent[i];
            highestStudent = i;
        }
    }

    cout << "Student with Highest Attendance: Student " << highestStudent + 1 << " (";


    int minDay = totalDay[0];
    int lowestDayIdx = 0;
    for (int j = 1; j < days; j++) {
        if (totalDay[j] < minDay) {
            minDay = totalDay[j];
            lowestDayIdx = j;
        }
    }
    cout << "Day with Lowest Overall Attendance: Day " << lowestDayIdx + 1 << endl;

    return 0;

}