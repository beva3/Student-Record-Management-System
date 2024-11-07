#include "./student.h"

int main(){
    Student students[MAX_STUDENTS];  // Array to store student records
    int studentCount = 0;   // Number of students
    int choice;             // User's choice for menu options

    printf("Student Management System\n");
    loadRecordFromFile(students, &studentCount, "./dataTest.csv");    // load existing students
    printf("Number of students = %d\n",studentCount);
    // displayMenu();
    displayStudents(students,studentCount); // display);
    // addStudent(students,&studentCount);
    // updateStudent(students,studentCount);
    // deletStudent(students,&studentCount,34);
    searchStudent(students,"John Doe");
    // saveRecordsToFile(students, studentCount, "./student.csv"); // save to file
    return 0;
}   