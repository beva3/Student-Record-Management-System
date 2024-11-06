#include "./student.h"

int main(){
    Student students[100];  // Array to store student records
    int studentCount = 0;   // Number of students
    int choice;             // User's choice for menu options

    printf("Student Management System\n");
    loadRecordFromFile(students, &studentCount, "./student.csv");    // load existing students
    printf("Number of students = %d\n",studentCount);
    // displayMenu();
    displayStudents(students,studentCount); // display);
    return 0;
}   