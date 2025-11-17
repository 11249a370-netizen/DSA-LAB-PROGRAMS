AIM:To evaluate the given  infix expression to postfix expression.
SOURCE CODE:
#include <stdio.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAX 100

char stack[MAX];
int top = -1;

void push(char item) {
    if (top >= MAX - 1) {
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = item;
}

char pop() {
    if (top < 0) {
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

int precedence(char operator) {
    switch (operator) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '^':
            return 3;
        default:
            return 0;
    }
}

int isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

void infixToPostfix(char* infix, char* postfix) {
    int i = 0, j = 0;
    char token, x;
    
    // Step 4: Scan the infix expression from left to right
    while ((token = infix[i++]) != '\0') {
        // Step 4.I: If operand, add to postfix
        if (isalnum(token)) {
            postfix[j++] = token;
        }
        // Step 4.III: If '(', push to stack
        else if (token == '(') {
            push(token);
        }
        // Step 4.IV: If ')', pop until '('
        else if (token == ')') {
            while ((x = pop()) != '(') {
                postfix[j++] = x;
            }
        }
        // Step 4.II: If operator
        else if (isOperator(token)) {
            // Step 4.II.B: Pop operators with higher or equal precedence
            while (top != -1 && precedence(stack[top]) >= precedence(token)) {
                postfix[j++] = pop();
            }
            // Step 4.II.A: Push current operator
            push(token);
        }
    }
    
    // Step 6: Pop any remaining operators
    while (top != -1) {
        postfix[j++] = pop();
    }
    
    postfix[j] = '\0'; 
}

int main() {
    char infix[MAX], postfix[MAX];
    
    printf("Enter infix expression: ");
    scanf("%s", infix);
    
    infixToPostfix(infix, postfix);
    
    printf("Infix expression: %s\n", infix);
    printf("Postfix expression: %s\n", postfix);
    
    return 0;
}
OUTPUT:
Enter infix expression: A+B*(C-D)
Infix expression: A+B*(C-D)
Postfix expression: ABCD-*+


