#ifndef __STUDENTS__
#define __STUDENTS__
#include <stdio.h>
#include <string.h>
#define MAX_STUDENTS 5000
typedef struct Student{
    char name[50];
    int rollNumber;
    int age;
    float grade; // student's NOTES
}Student;
// display menu
void displayMenu();
// function to add a new student record 
void addStudent(Student students[], int *count);
// function to display all students records
void displayStudents(const Student students[], int count);
// function to update existing students records
void updateStudent(Student students[], int count);
// function to delete a student record by roll number
void deletStudent(Student students[], int *count,int rollNumber);
// function to search for a student record by roll number
void searchStudent(const Student students[],const char *str);
// function to save a student to a file
void saveRecordsToFile(const Student students[], int count, const char *fileName);
// function to load student records from a file
void loadRecordFromFile(Student students[], int *count, const char *fileName);
#endif // !__STUDENTS__
