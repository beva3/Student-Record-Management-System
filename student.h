#ifndef __STUDENTS__
#define __STUDENTS__
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <stdbool.h>
#define MAX_STUDENTS 5000
typedef struct Student{
    char name[50];
    int rollNumber;
    int age;
    float grade; // student's NOTES
}Student;

// tabe of students
char **tab_students(char *filename);
// display menu
void displayMenu();
// function to add a new student record 
void addStudent(const char *fileName, Student newStudent);
void appendStudent(char ***tab_students,Student *newStudent);
// function to display all students records
void displayStudents(const Student students[], int count);
// function to update existing students records
void updateStudent(Student students[], int count);
// function to delete a student record by roll number
void deletStudent(Student students[], int *count,int rollNumber);
// function to search for a student record by roll number
void searchStudent(char **students,const char *str,int *count);
// function to save a student to a file
void saveRecordsToFile(const Student students[], int count, const char *fileName);
// function to load student records from a file
void loadRecordFromFile(Student students[], int *count, const char *fileName);
void echoTab2d(char **tab_students,int *count);
// imput query
char *inputQuery();
// input new student 
Student inputNewStudent();
void printOneStudent(Student *student);
void initialize_2D(char ***tab_2D,int rows, int colums);
#endif // !__STUDENTS__
