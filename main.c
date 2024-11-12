#include "./student.h"
#include <stdio.h>

int main(){
    Student students[MAX_STUDENTS];  // Array to store student records
    char **tab_s = tab_students("./dataTest.csv");
    Student new_s = {"beva",12,2,1.};
    int studentCount = 0;   // Number of students
    int choice = 0;             // User's choice for menu options

    printf("Student Management System\n");
    loadRecordFromFile(students, &studentCount, "./dataTest.csv");    // load existing students
    printf("Number of students = %d\n",studentCount);
    
    // tab_students("./dataTest.csv");
    // displayMenu();
    // displayStudents(students,studentCount); // display);
    // addStudent("./dataTest.csv",(Student){"new Bienvenu",4,12,23.2});
    // addStudent("./dataTest.csv",inputNewStudent());
    // updateStudent(students,studentCount);
    // deletStudent(students,&studentCount,34);
    // searchStudent(tab_students("./dataTest.csv"),"John",&studentCount);
    // saveRecordsToFile(students, studentCount, "./student.csv"); // save to file
    echoTab2d(tab_s, &studentCount);
    appendStudent(&tab_s,&new_s);
    // searchStudent(tab_students("./dataTest.csv"),inputQuery(),&studentCount);
    return 0;
}   