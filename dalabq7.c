#include <stdio.h>
#include <stdlib.h>
#include <string.h>
struct Employee {
    char ssn[12];
    char name[50];
    char department[50];
    struct Employee* next;
    struct Employee* prev;
};
struct Employee* createEmployeeNode(char ssn[], char name[], char department[]) {
    struct Employee* newNode = (struct Employee*)malloc(sizeof(struct Employee));
    if (newNode == NULL) {
        printf("Memory allocation failed\n");
        exit(1);
    }
    strcpy(newNode->ssn, ssn);
    strcpy(newNode->name, name);
    strcpy(newNode->department, department);
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}
void acceptEmployeeData(char ssn[], char name[], char department[]) {
    printf("Enter SSN of employee: ");
    scanf("%s", ssn);
    printf("Enter Name of employee: ");
    scanf("%s", name);
    printf("Enter Department of employee: ");
    scanf("%s", department);
}
void insertEmployeeAtBeginning(struct Employee** head, char ssn[], char name[], char department[]) {
    struct Employee* newNode = createEmployeeNode(ssn, name, department);
    if (*head == NULL) {
        *head = newNode;
    } else {
        newNode->next = *head;
        (*head)->prev = newNode;
        *head = newNode;
    }
}
void insertEmployeeAfterKey(struct Employee** head, char ssn[], char name[], char department[], char keySSN[]) {
    struct Employee* newNode = createEmployeeNode(ssn, name, department);
    struct Employee* temp = *head;
    while (temp != NULL && strcmp(temp->ssn, keySSN) != 0) {
        temp = temp->next;
    }
    if (temp == NULL) {
        printf("Key value not found. Cannot insert.\n");
        free(newNode);
        return;
    }
    newNode->next = temp->next;
    newNode->prev = temp;
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    temp->next = newNode;
    printf("Employee inserted to the right of key value %s.\n", keySSN);
}
void insertEmployeeAtEnd(struct Employee** head, char ssn[], char name[], char department[]) {
    struct Employee* newNode = createEmployeeNode(ssn, name, department);
    if (*head == NULL) {
        *head = newNode;
    } else {
        struct Employee* temp = *head;
        while (temp->next != NULL) {
            temp = temp->next;
        }
        temp->next = newNode;
        newNode->prev = temp;
    }
}
void displayEmployeeList(struct Employee* head) {
    int count = 0;
    printf("Employee List:\n");
    while (head != NULL) {
        printf("SSN: %s, Name: %s, Department: %s\n", head->ssn, head->name, head->department);
        head = head->next;
        count++;
    }
    printf("Number of nodes: %d\n", count);
}
void deleteEmployeeAtEnd(struct Employee** head) {
    if (*head == NULL) {
        printf("List is empty. Cannot delete.\n");
        return;
    }

    struct Employee* temp = *head;

    while (temp->next != NULL) {
        temp = temp->next;
    }

    if (temp->prev != NULL) {
        temp->prev->next = NULL;
    } else {
        *head = NULL;
    }

    free(temp);
    printf("Employee deleted from the end.\n");
}
void freeEmployeeList(struct Employee* head) {
    struct Employee* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
}
int main() {
    struct Employee* head = NULL;
    int choice;
    char ssn[12], name[50], department[50], keySSN[12];
    do {
        printf("\n----- MENU -----\n");
        printf("1. Create a Node of N Employees Data by inserting in front\n");
        printf("2. Insert a new node to the right of key value\n");
        printf("3. Perform Insertion at End of DLL\n");
        printf("4. Display the status of DLL and count the number of nodes\n");
        printf("5. Delete Employee at End\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                acceptEmployeeData(ssn, name, department);
                insertEmployeeAtBeginning(&head, ssn, name, department);
                break;
            case 2:
                printf("Enter SSN of employee to the right of which new node should be inserted: ");
                scanf("%s", keySSN);
                acceptEmployeeData(ssn, name, department);
                insertEmployeeAfterKey(&head, ssn, name, department, keySSN);
                break;
            case 3:
                acceptEmployeeData(ssn, name, department);
                insertEmployeeAtEnd(&head, ssn, name, department);
                break;
            case 4:
                displayEmployeeList(head);
                break;
            case 5:
                deleteEmployeeAtEnd(&head);
                break;
            case 6:
                freeEmployeeList(head);
                printf("Memory freed. Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);
    return 0;
}
