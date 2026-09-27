#include <stdio.h>
#include <ctype.h>
#include <string.h>

char stack[100];
int top = -1;

void push(char x) {
    stack[++top] = x;
}

char pop() {
    return stack[top--];
}

int priority(char x) {
    if (x == '^')
        return 3;
    if (x == '*' || x == '/')
        return 2;
    if (x == '+' || x == '-')
        return 1;
    return 0;
}

int main() {
    char infix[100], postfix[100];
    int i, j = 0;
    char ch;

    printf("Enter infix expression: ");
    scanf("%s", infix);

    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];

        /* Operand */
        if (isalnum(ch)) {
            postfix[j++] = ch;
        }

        /* Opening bracket */
        else if (ch == '(') {
            push(ch);
        }

        /* Closing bracket */
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(')
                postfix[j++] = pop();

            pop();   // remove '('
        }

        /* Operator */
        else {
            while (top != -1 &&
                   stack[top] != '(' &&
                   priority(stack[top]) >= priority(ch)) {
                postfix[j++] = pop();
            }

            push(ch);
        }
    }

    while (top != -1)
        postfix[j++] = pop();

    postfix[j] = '\0';

    printf("Postfix expression: %s\n", postfix);

    return 0;
}