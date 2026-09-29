/*An expression-processing application receives an arithmetic expression in infix form. Write a C program using a stack to convert 
it to postfix form while correctly handling parentheses and operator precedence for +, -, *, / and ^. Test the program using an 
expression containing multiple operators and parentheses. */
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 100
char stack[MAX];
int top = -1;
// Push an operator into stack
void push(char ch) {
    stack[++top] = ch;
}
// Pop an operator from stack
char pop() {
    return stack[top--];
}
// Return precedence of operator
int precedence(char ch) {
    if (ch == '^')
        return 3;
    else if (ch == '*' || ch == '/')
        return 2;
    else if (ch == '+' || ch == '-')
        return 1;
    else
        return 0;
}
// Check right associativity
int isRightAssociative(char ch) {
    return ch == '^';
}
// Convert infix to postfix
void infixToPostfix(char infix[]) {
    char postfix[MAX];
    int i, k = 0;
    char ch;
    for (i = 0; infix[i] != '\0'; i++) {
        ch = infix[i];
        // Ignore spaces
        if (ch == ' ')
            continue;
        // If operand, add to postfix
        if (isalnum(ch)) {
            postfix[k++] = ch;
        }
        // If opening parenthesis
        else if (ch == '(') {
            push(ch);
        }
        // If closing parenthesis
        else if (ch == ')') {
            while (top != -1 && stack[top] != '(') {
                postfix[k++] = pop();
            }
            if (top != -1 && stack[top] == '(')
                pop();
        }
        // If operator
        else {
            while (top != -1 &&
                   stack[top] != '(' &&
                   (precedence(stack[top]) > precedence(ch) ||
                   (precedence(stack[top]) == precedence(ch) &&
                    !isRightAssociative(ch)))) {
                postfix[k++] = pop();
            }
            push(ch);
        }
    }
    // Pop remaining operators
    while (top != -1) {
        postfix[k++] = pop();
    }
    postfix[k] = '\0';
    printf("Postfix expression: %s\n", postfix);
}
int main() {
    char infix[MAX];
    printf("Enter infix expression: ");
    fgets(infix, MAX, stdin);
    infix[strcspn(infix, "\n")] = '\0';
    infixToPostfix(infix);
    return 0;
}