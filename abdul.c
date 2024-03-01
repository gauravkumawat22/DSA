#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NAME_LENGTH 50

struct Student {
    char name[MAX_NAME_LENGTH];
    int rollNumber;
    float marks;
};

struct StudentDatabase {
    struct Student students[100]; // Assuming a maximum of 100 students
    int count;
};

void addStudent(struct StudentDatabase *database) {
    struct Student newStudent;
    printf("Enter name: ");
    fgets(newStudent.name, sizeof(newStudent.name), stdin);
    strtok(newStudent.name, "\n");  // Remove newline character
    printf("Enter roll number: ");
    scanf("%d", &newStudent.rollNumber);
    printf("Enter marks: ");
    scanf("%f", &newStudent.marks);
    database->students[database->count++] = newStudent;
    printf("Student added successfully!\n");
}

void displayAllStudents(struct StudentDatabase *database) {
    if (database->count == 0) {
        printf("No students in the database.\n");
    } else {
        printf("List of all students:\n");
        printf("%-20s%-15s%-10s\n", "Name", "Roll Number", "Marks");
        for (int i = 0; i < database->count; ++i) {
            printf("%-20s%-15d%-10.2f\n", database->students[i].name,
                   database->students[i].rollNumber, database->students[i].marks);
        }
    }
}

void deleteStudent(struct StudentDatabase *database, int rollNumber) {
    for (int i = 0; i < database->count; ++i) {
        if (database->students[i].rollNumber == rollNumber) {
            for (int j = i; j < database->count - 1; ++j) {
                database->students[j] = database->students[j + 1];
            }
            database->count--;
            printf("Student with roll number %d deleted successfully!\n", rollNumber);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rollNumber);
}

void updateStudent(struct StudentDatabase *database, int rollNumber) {
    for (int i = 0; i < database->count; ++i) {
        if (database->students[i].rollNumber == rollNumber) {
            printf("Enter new name: ");
            fgets(database->students[i].name, sizeof(database->students[i].name), stdin);
            strtok(database->students[i].name, "\n");  // Remove newline character
            printf("Enter new marks: ");
            scanf("%f", &database->students[i].marks);
            printf("Student with roll number %d updated successfully!\n", rollNumber);
            return;
        }
    }
    printf("Student with roll number %d not found.\n", rollNumber);
}

int main() {
    struct StudentDatabase database;
    database.count = 0;

    int choice, rollNumber;
    do {
        printf("\nStudent Database Management System\n");
        printf("1. Add Student\n");
        printf("2. Display All Students\n");
        printf("3. Delete Student\n");
        printf("4. Update Student\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                getchar(); // Clear newline character from the buffer
                addStudent(&database);
                break;
            case 2:
                displayAllStudents(&database);
                break;
            case 3:
                printf("Enter roll number to delete: ");
                scanf("%d", &rollNumber);
                deleteStudent(&database, rollNumber);
                break;
            case 4:
                printf("Enter roll number to update: ");
                scanf("%d", &rollNumber);
                getchar(); // Clear newline character from the buffer
                updateStudent(&database, rollNumber);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while (choice != 5);

    return 0;
}
