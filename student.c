#include "./student.h"

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

void addStudent(Student students[], int *count){
    printf("=== Add new Student ===\n");
    (*count)++;
    printf("saving  %d th student \n",*count);
}

void updateStudent(Student students[], int count){
    printf("=== Update  Student ===\n");
}

void deletStudent(Student students[], int *count,int rollNumber){
    printf("=== Delete Student ===\n");
    printf("rollNumber %d\n",rollNumber);
}

void searchStudent(const Student students[], int count, const char *name){
    printf("=== Search Student ===\n");
    printf("Name %s\n",name);
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