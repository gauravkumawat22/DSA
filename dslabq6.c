#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Student {
    char usn[20];
    char name[30];
    float avg_marks;
    struct Student* next;};
struct Student* createStudent() {
    struct Student* newStudent = (struct Student*)malloc(sizeof(struct Student));
    if (newStudent == NULL) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    printf("Enter USN: ");
    scanf("%s", newStudent->usn);
    printf("Enter Name: ");
    scanf("%s", newStudent->name);
    printf("Enter Average Marks: ");
    scanf("%f", &newStudent->avg_marks);
    newStudent->next = NULL;
    return newStudent;
}
void insertAtEnd(struct Student** head) {
    struct Student* newStudent = createStudent();
    if (*head == NULL) {
        *head = newStudent;
    } else {
        struct Student* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newStudent;
    }
    printf("Student data inserted at the end successfully.\n");
}
void insertAtFront(struct Student** head) {
    struct Student* newStudent = createStudent();
    newStudent->next = *head;
    *head = newStudent;
    printf("Student data inserted at the front successfully.\n");
}
void deleteAtFront(struct Student** head) {
    if (*head == NULL) {
        printf("Stack is empty. Unable to pop.\n");
        return;
    }
    struct Student* temp = *head;
    *head = (*head)->next;
    free(temp);
    printf("Student data deleted from the front successfully.\n");
}
void displayList(struct Student* head) {
    printf("\nStudent List:\n");
    while (head != NULL) {
        printf("USN: %s, Name: %s, Avg Marks: %.2f\n", head->usn, head->name, head->avg_marks);
        head = head->next;    }
    printf("\n");}
void demonstrateStack(struct Student** head) {
    printf("Demonstrating Stack using SLL:\n");
    insertAtFront(head);
    insertAtFront(head);
    insertAtFront(head);
    displayList(*head);
    deleteAtFront(head);
    displayList(*head);}
void demonstrateQueue(struct Student** head) {
    printf("Demonstrating Queue using SLL:\n");
    insertAtEnd(head);
    insertAtEnd(head);
    insertAtEnd(head);
    displayList(*head);
    deleteAtFront(head);
    displayList(*head);}
int main() {
    struct Student* head = NULL;
    int choice;
    do {
        printf("\nMenu:\n");
        printf("1. Insert at the end\n");
        printf("2. Insert at the front\n");
        printf("3. Delete at the front (Stack pop)\n");
        printf("4. Display status\n");
        printf("5. Demonstrate Stack\n");
        printf("6. Demonstrate Queue\n");
        printf("7. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                insertAtEnd(&head);
                break;
            case 2:
                insertAtFront(&head);
                break;
            case 3:
                deleteAtFront(&head);
                break;
            case 4:
                displayList(head);
                break;
            case 5:
                demonstrateStack(&head);
                break;
            case 6:
                demonstrateQueue(&head);
                break;
            case 7:
                printf("Exiting the program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 7);
    return 0;
}
