#include <stdio.h>
#include <stdlib.h>
#define MAX 5
struct CircularQueue {
    char items[MAX];
    int front, rear;
};
void initializeQueue(struct CircularQueue *cq);
void insertElement(struct CircularQueue *cq, char element);
char deleteElement(struct CircularQueue *cq);
void displayQueue(struct CircularQueue cq);
int isFull(struct CircularQueue cq);
int isEmpty(struct CircularQueue cq);
int main() {
    struct CircularQueue cq;
    initializeQueue(&cq);
    int choice;
    char element;
    do {
        printf("\nCircular Queue Operations:\n");
        printf("1. Insert Element\n");
        printf("2. Delete Element\n");
        printf("3. Demonstrate Overflow and Underflow\n");
        printf("4. Display Queue\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch (choice) {
            case 1:
                printf("Enter the element to be inserted: ");
                scanf(" %c", &element);
                insertElement(&cq, element);
                break;
            case 2:
                element = deleteElement(&cq);
                if (element != '\0') {
                    printf("Deleted element: %c\n", element);
                }
                break;
            case 3:
                if (isFull(cq)) {
                    printf("Queue is Full (Overflow)\n");
                } else if (isEmpty(cq)) {
                    printf("Queue is Empty (Underflow)\n");
                } else {
                    printf("Queue has elements\n");
                }
                break;
            case 4:
                displayQueue(cq);
                break;
            case 5:
                printf("Exiting program.\n");
                break;
            default:
                printf("Invalid choice. Please enter a valid option.\n");
        }
    } while (choice != 5);
    return 0;
}
void initializeQueue(struct CircularQueue *cq) {
    cq->front = cq->rear = -1;
}
void insertElement(struct CircularQueue *cq, char element) {
    if ((cq->front == 0 && cq->rear == MAX - 1) || (cq->rear == (cq->front - 1) % (MAX - 1))) {
        printf("Queue is Full (Overflow)\n");
        return;
    }
    if (cq->front == -1) {
        cq->front = cq->rear = 0;
    } else if (cq->rear == MAX - 1 && cq->front != 0) {
        cq->rear = 0;
    } else {
        cq->rear++;
    }
    cq->items[cq->rear] = element;
    printf("Element %c inserted successfully.\n", element);
}
char deleteElement(struct CircularQueue *cq) {
    if (cq->front == -1) {
        printf("Queue is Empty (Underflow)\n");
        return '\0';
    }
    char deletedElement = cq->items[cq->front];
    if (cq->front == cq->rear) {
        cq->front = cq->rear = -1;
    } else if (cq->front == MAX - 1) {
        cq->front = 0;
    } else {
        cq->front++;
    }
    return deletedElement;
}
void displayQueue(struct CircularQueue cq) {
    if (isEmpty(cq)) {
        printf("Queue is Empty.\n");
        return;
    }
    printf("Circular Queue elements: ");
    int i;
    for (i = cq.front; i != cq.rear; i = (i + 1) % MAX) {
        printf("%c ", cq.items[i]);
    }
    printf("%c\n", cq.items[i]);
}
int isFull(struct CircularQueue cq) {
    return (cq.front == 0 && cq.rear == MAX - 1) || (cq.rear == (cq.front - 1) % (MAX - 1));
}
int isEmpty(struct CircularQueue cq) {
    return cq.front == -1;
}
 