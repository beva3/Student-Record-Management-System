#include "./student.h"
#include <stdio.h>

int main(){
    Student students[MAX_STUDENTS];  // Array to store student records
    int studentCount = 0;   // Number of students
    int choice = 0;             // User's choice for menu options

    printf("Student Management System\n");
    loadRecordFromFile(students, &studentCount, "./dataTest.csv");    // load existing students
    printf("Number of students = %d\n",studentCount);
    
    // tab_students("./dataTest.csv");
    // displayMenu();
    // displayStudents(students,studentCount); // display);
    // addStudent(students,&studentCount);
    // updateStudent(students,studentCount);
    // deletStudent(students,&studentCount,34);
    // searchStudent(tab_students("./dataTest.csv"),"John",&studentCount);
    // saveRecordsToFile(students, studentCount, "./student.csv"); // save to file
    echoTab2d(tab_students("./dataTest.csv"), &studentCount);
    // searchStudent(tab_students("./dataTest.csv"),inputQuery(),&studentCount);
    return 0;
}   