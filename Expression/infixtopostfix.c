#include <stdio.h>
#include <ctype.h>

char stack[20];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    if (top == -1)
        return -1;
    else
        return stack[top--];
}

int priority(char x) {
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return -1;  // Default case for non-operators
}

int main() {
    char exp[20], x;
    printf("Enter expression: ");
    scanf("%s", exp);

    printf("Postfix expression: ");
    for (int i = 0; exp[i] != '\0'; i++) {
        if (isalnum(exp[i]))
            printf("%c", exp[i]);  // If the character is an operand, print it
        else if (exp[i] == '(')
            push(exp[i]);  // Push '(' to the stack
        else if (exp[i] == ')') {
            // Pop and print until '(' is found
            while ((x = pop()) != '(')
                printf("%c", x);
        } else {
            // Pop from the stack based on operator precedence
            while (top != -1 && priority(stack[top]) >= priority(exp[i]))
                printf("%c", pop());
            push(exp[i]);  // Push the current operator
        }
    }

    // Pop and print the remaining operators in the stack
    while (top != -1)
        printf("%c", pop());

    printf("\n");
    return 0;
}
