#include "./student.h"
#include <stdio.h>

void displayMenu() {
    printf("=== Student Record Management System ===\n");
    printf("1. Add Student\n");
    printf("2. Display All Students\n");
    printf("3. Update Student\n");
    printf("4. Delete Student\n");
    printf("5. Search Student\n");
    printf("6. Save to File\n");
    printf("7. Load from File\n");
    printf("8. Quit\n");
}

void loadRecordFromFile(Student students[], int *count, const char *fileName){
    printf("Loading Student Record ...\n");
    FILE *f = fopen(fileName, "r"); // Open the file for reading
    if(f == NULL){
        printf("Error opening file: %s\n", fileName);
        return;
    }
    *count = 0; // Reset the count to 0, as we'll reppopulated the students array from file
    char line[256]; // Buffer to hold each line read from the file

    // skeep the first line (header) if the file include it
    fgets(line, sizeof(line),f);

    // Read each line of the file unitil EOF is reached (start -> end)
    while(fgets(line, sizeof(line),f)){
        // Parse the line and extract th student data using sscanf
        sscanf(line, "%[^,],%d,%d,%f",
            students[*count].name,
            &students[*count].rollNumber,
            &students[*count].age,
            &students[*count].grade
        );
        (*count)++;
    }
    fclose(f);  // close the file after reading all records
    printf("Loading successful students from file %s\n",fileName);
}

void displayStudents(const Student students[], int count){
    printf("=== Student Records ===\n\n");
    printf("Name\tRoll Number\tAge\tGrade\n");
    for(int i = 0; i < count; i++){
        printf("%s\t%d\t%d\t%.2f\n",
            students[i].name,
            students[i].rollNumber,
            students[i].age,
            students[i].grade
        );
    }
}

Student inputNewStudent(){
    Student newS;

    printf("== Input new student ==\n");
    printf("name  "),strcpy(newS.name , inputQuery());
    printf("rull number "),newS.rollNumber = atoi(inputQuery());
    printf("age students "),newS.age = atoi(inputQuery());
    printf("grade students "),newS.grade = atof(inputQuery());    

    return newS;
}

void printOneStudent(Student *student){
    printf("Name        : %s\n", student->name);
    printf("Roll Number : %d\n", student->rollNumber);
    printf("Age         : %d\n", student->age);
    printf("Grade       : %.2f\n", student->grade);
}
void addStudent(const char *fileName, Student newStudent){
    FILE *f = fopen(fileName, "a"); // Open the file for adding
    if(f == NULL){
        printf("Error opening file: %s\n", fileName);
        exit(1);
    }

    printf("=== Add new Student ===\n");
    printOneStudent(&newStudent);
    
    // Write the student's data in CSV format: name,rollNumber,age,grade
    fprintf(f, "%s,%d,%d,%.2f\n", 
        newStudent.name, 
        newStudent.rollNumber, 
        newStudent.age, 
        newStudent.grade
    );

    printf("Student added successfully!\n");
    fclose(f);

    // befor to print a tab we need to update our data
}

void updateStudent(Student students[], int count){
    printf("=== Update  Student ===\n");
}

void deletStudent(Student students[], int *count,int rollNumber){
    printf("=== Delete Student ===\n");
    printf("rollNumber %d\n",rollNumber);
}

char *inputQuery(){
    char *input = (char *)malloc(sizeof(char) * 256);
    printf("input query : ");
    fgets(input, 256, stdin);
    input[strcspn(input, "\n")] = '\0'; // Remove newline character from input
    return input;
}

void searchStudent(char **students,const char *str,int *count){
    printf("=== Search Student ===\n");

    bool found = false;
    
    for(int index = 0; index < *count; index++) {
        // printf("%s \n",students[index]);
        if(strstr(students[index], str) != NULL) {
            printf(">> string  %s : %s",
                str,
                students[index]
            );
            found = true;
        }
        // found = false; no need
    }
    if(!found){
        printf("Student not found !!!\n");
    }
}

void saveRecordsToFile(const Student students[], int count, const char *fileName){
    printf("Saving Student Record ...\n");
    // FILE *f = fopen(fileName, "w"); // Open the file for writing
    // if(f == NULL){
    //     printf("Error opening file: %s\n", fileName);
    //     return;
    // }

    // // Write the header line
    // fprintf(f, "Name,Roll Number,Age,Grade\n");

    // // Write each student record to the file
    // for(int i = 0; i < count; i++){
    //     fprintf(f, "%s,%d,%d,%.2f\n",
    //         students[i].name,
    //         students[i].rollNumber,
    //         students[i].age,
    //         students[i].grade
    //     );
    // }
    // fclose(f);  // close the file after writing all records
    printf("Saving successful students to file %s\n",fileName);
}

char **tab_students(char *filename){
    // Implementation of tab_students function goes here
    printf("== Tab of students %s ==\n",filename);
    
    char **tmp = (char **) malloc(MAX_STUDENTS * sizeof(char*));
    if(tmp == NULL){
        printf("Error allocating memory\n");
        exit(1);
    }
    for (int i = 0; i < MAX_STUDENTS; i++){
        tmp[i] = (char *) malloc(256 * sizeof(char));
        if(tmp[i] == NULL){
            printf("Error allocating memory\n");
            for(int j=0; j<i; j++){
                free(tmp[j]);
            }
            free(tmp);
            exit(1);
        }
    }
    int index = 0; // index of tab 2D student
    FILE *f = fopen(filename, "r"); // Open the file for reading
    if(f == NULL){
        printf("Error opening file: %s\n", filename);
        exit(1);
    }

    char line[256]; // Buffer to hold each line read from the file
    fgets(line, sizeof(line), f);   // skeep the first line
    while (fgets(line, sizeof(line), f)){
        strcpy(tmp[index], line);
        // printf("line: %s", *tmp);
        // (*tmp)++; // no use index of tab
        index++;
    }
    fclose(f);  // close the file after reading all records
    return tmp;
}

void echoTab2d(char **tab_students,int *count){
    printf("=== Tab of students ===\n\n");
    // printf("Name\tRoll Number\tAge\tGrade\n");
    for(int i = 0; i < *count; i++){
        printf("%04d - %s",i+1,tab_students[i]);
    }
    free((void *)tab_students); // free the memory allocated for tab_students
}