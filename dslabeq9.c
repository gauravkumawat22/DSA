#include <stdio.h>
#include <stdlib.h>

struct Node {
    int coefficient;
    int exponent_x;
    int exponent_y;
    int exponent_z;
    struct Node* next;
};
void insertTerm(struct Node** head, int coeff, int exp_x, int exp_y, int exp_z);
void displayPolynomial(struct Node* head);
int evaluatePolynomial(struct Node* head, int x, int y, int z);
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2);
int main() {
    struct Node* polyP = NULL;
    insertTerm(&polyP, 6, 2, 2, 1);
    insertTerm(&polyP, -4, 0, 1, 5);
    insertTerm(&polyP, 3, 3, 1, 1);
    insertTerm(&polyP, 2, 1, 5, 2);
    printf("Polynomial P(x, y, z): ");
    displayPolynomial(polyP);
    struct Node* poly1 = NULL;
    insertTerm(&poly1, 2, 2, 1, 3);
    insertTerm(&poly1, 3, 1, 1, 1);
    insertTerm(&poly1, -5, 1, 2, 1);
    printf("\nPolynomial POLY1(x, y, z): ");
    displayPolynomial(poly1);
    struct Node* poly2 = NULL;
    insertTerm(&poly2, -1, 2, 2, 1);
    insertTerm(&poly2, 4, 0, 1, 5);
    insertTerm(&poly2, 2, 1, 5, 2);
    printf("\nPolynomial POLY2(x, y, z): ");
    displayPolynomial(poly2);
    int result = evaluatePolynomial(polyP, 1, 2, 3);
    printf("\nResult of P(1, 2, 3): %d\n", result);
    struct Node* polySum = addPolynomials(poly1, poly2);
    printf("\nSum of POLY1 and POLY2: ");
    displayPolynomial(polySum);
    free(polyP);
    free(poly1);
    free(poly2);
    free(polySum);
    return 0;
}
void insertTerm(struct Node** head, int coeff, int exp_x, int exp_y, int exp_z) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if (!newNode) {
        printf("Memory allocation failed.\n");
        exit(1);
    }
    newNode->coefficient = coeff;
    newNode->exponent_x = exp_x;
    newNode->exponent_y = exp_y;
    newNode->exponent_z = exp_z;
    newNode->next = *head;
    *head = newNode;
}
void displayPolynomial(struct Node* head) {
    if (!head) {
        printf("Empty polynomial.\n");
        return;
    }
    while (head->next != NULL) {
        printf("%dx^%dy^%dz^%d + ", head->coefficient, head->exponent_x, head->exponent_y, head->exponent_z);
        head = head->next;
    }
    printf("%dx^%dy^%dz^%d\n", head->coefficient, head->exponent_x, head->exponent_y, head->exponent_z);
}
int evaluatePolynomial(struct Node* head, int x, int y, int z) {
    int result = 0;
    while (head != NULL) {
        result += head->coefficient * pow(x, head->exponent_x) * pow(y, head->exponent_y) * pow(z, head->exponent_z);
        head = head->next;
    }
    return result;
}
struct Node* addPolynomials(struct Node* poly1, struct Node* poly2) {
    struct Node* polySum = NULL;
    while (poly1 != NULL || poly2 != NULL) {
        int coeff1 = (poly1 != NULL) ? poly1->coefficient : 0;
        int exp_x1 = (poly1 != NULL) ? poly1->exponent_x : 0;
        int exp_y1 = (poly1 != NULL) ? poly1->exponent_y : 0;
        int exp_z1 = (poly1 != NULL) ? poly1->exponent_z : 0;
        int coeff2 = (poly2 != NULL) ? poly2->coefficient : 0;
        int exp_x2 = (poly2 != NULL) ? poly2->exponent_x : 0;
        int exp_y2 = (poly2 != NULL) ? poly2->exponent_y : 0;
        int exp_z2 = (poly2 != NULL) ? poly2->exponent_z : 0;
        int sumCoeff = coeff1 + coeff2;
        int sumExp_x = (exp_x1 > exp_x2) ? exp_x1 : exp_x2;
        int sumExp_y = (exp_y1 > exp_y2) ? exp_y1 : exp_y2;
        int sumExp_z = (exp_z1 > exp_z2) ? exp_z1 : exp_z2;
        insertTerm(&polySum, sumCoeff, sumExp_x, sumExp_y, sumExp_z);
        if (poly1 != NULL) {
            poly1 = poly1->next;
        }
        if (poly2 != NULL) {
            poly2 = poly2->next;
        }
    }
    return polySum;
}
