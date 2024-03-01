#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <math.h>

#define MAX_SIZE 100

typedef struct {
    int top;
    int stack[MAX_SIZE];
} Stack;

void initialize(Stack *s) {
    s->top = -1;
}

void push(Stack *s, int value) {
    s->stack[++s->top] = value;
}

int pop(Stack *s) {
    return s->stack[s->top--];
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '%' || ch == '^');
}

int evaluatePostfix(char postfix[]) {
    Stack stack;
    initialize(&stack);

    for (int i = 0; postfix[i] != '\0'; i++) {
        if (isdigit(postfix[i])) {
            push(&stack, postfix[i] - '0');
        } else if (isOperator(postfix[i])) {
            int operand2 = pop(&stack);
            int operand1 = pop(&stack);
            int result;

            switch (postfix[i]) {
                case '+': result = operand1 + operand2; break;
                case '-': result = operand1 - operand2; break;
                case '*': result = operand1 * operand2; break;
                case '/': result = operand1 / operand2; break;
                case '%': result = operand1 % operand2; break;
                case '^': result = (int)pow(operand1, operand2); break;
            }

            push(&stack, result);
        }
    }

    return pop(&stack);
}

int main() {
    char postfix[MAX_SIZE];

    printf("Enter postfix expression: ");
    scanf("%s", postfix);

    int result = evaluatePostfix(postfix);
    printf("Result: %d\n", result);

    return 0;
}
