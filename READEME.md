# Student Record Management System

The student record management system is a simple application that allows users
    # to manage student records

The student should allow the following functionalities

1- ADD STUDENT RECORD : User can input details for new student:
    - name
    - roll number
    - age
    - grades

2- VEW STUDENT RECORD : User can display details of all students in the system

3- UPDATE STUDENT RECORD : User can modify details of an existing student record based on the roll number or name

4- DELETE STUDENT RECORDS : User can remove a student record from the system

5- SEARCH FOR STUDENT : User can search for student recort by name or roll number

6- SAVE AND LOAD RECORD : The system should allow saving records to a file and loading records from a file, ensuring that data persists between program execution

--------------------------------------------------------------------
# Function Prototypes Overview

void addStudent(Student students[], int *count);
void displayStudents(const Student students[], int count);
void updateStudent(Student students[], int count);
void deleteStudent(Student students[], int *count, int rollNumber);
void searchStudent(const Student students[], int count, const char *name);
void saveRecordsToFile(const Student students[], int count, const char *filename);
void loadRecordsFromFile(Student students[], int *count, const char *filename);

1. void addStudent(Student students[], int *count);
Purpose: This function adds a new student record to the students array.
Parameters:
Student students[]: An array of Student structures where student records are stored.
int *count: A pointer to an integer that keeps track of the current number of students. Using a pointer allows the function to modify the original count in the calling function.
Return Type: void (no value returned).
2. void displayStudents(const Student students[], int count);
Purpose: This function displays all student records currently stored in the students array.
Parameters:
const Student students[]: A constant array of Student structures to ensure that the data is not modified during display.
int count: The current number of students, indicating how many records to display.
Return Type: void (no value returned).
3. void updateStudent(Student students[], int count);
Purpose: This function updates the details of an existing student record based on the roll number provided by the user.
Parameters:
Student students[]: An array of Student structures that contains the records to be updated.
int count: The current number of students, used to loop through the array to find the correct student.
Return Type: void (no value returned).
4. void deleteStudent(Student students[], int *count, int rollNumber);
Purpose: This function deletes a student record from the students array based on the roll number provided.
Parameters:
Student students[]: An array of Student structures from which the student will be deleted.
int *count: A pointer to an integer that keeps track of the current number of students. This is modified to reflect the new total after a deletion.
int rollNumber: The roll number of the student to be deleted.
Return Type: void (no value returned).
5. void searchStudent(const Student students[], int count, const char *name);
Purpose: This function searches for a student record by name and displays it if found.
Parameters:
const Student students[]: A constant array of Student structures to prevent modification.
int count: The current number of students, used to limit the search to valid indices.
const char *name: A string containing the name of the student to search for.
Return Type: void (no value returned).
6. void saveRecordsToFile(const Student students[], int count, const char *filename);
Purpose: This function saves the current student records to a file.
Parameters:
const Student students[]: A constant array of Student structures whose data will be written to the file.
int count: The number of students, indicating how many records to write.
const char *filename: The name of the file where the records will be saved.
Return Type: void (no value returned).
7. void loadRecordsFromFile(Student students[], int *count, const char *filename);
Purpose: This function loads student records from a file into the students array.
Parameters:
Student students[]: An array of Student structures that will be populated with data from the file.
int *count: A pointer to an integer that keeps track of the current number of students and is updated based on the number of records loaded from the file.
const char *filename: The name of the file from which records will be read.
Return Type: void (no value returned).

Summary
Each of these function prototypes defines a specific piece of functionality within the Student Record Management System, enabling you to add, display, update, delete, search, save, and load student records. The use of pointers, especially for the count parameter, allows you to modify variables in the calling scope, which is crucial for maintaining the correct state of the program.
