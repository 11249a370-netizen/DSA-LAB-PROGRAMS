AIM:To immplement stack operations using linked list
SOURCE CODE:
#include <stdio.h>
#include <stdlib.h>

// Structure for stack node
struct Node {
    int data;
    struct Node* next;
};

// Create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        exit(1);
    }
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Check if stack is empty
int isEmpty(struct Node* top) {
    return top == NULL;
}

// Push operation - Add element at top
void push(struct Node** top, int data) {
    struct Node* newNode = createNode(data);
    newNode->next = *top;
    *top = newNode;
    printf("Pushed %d onto stack\n", data);
}

// Pop operation - Remove element from top
int pop(struct Node** top) {
    if(isEmpty(*top)) {
        printf("Stack Underflow! Cannot pop from empty stack.\n");
        return -1;
    }
    
    struct Node* temp = *top;
    int poppedValue = temp->data;
    *top = (*top)->next;
    free(temp);
    printf("Popped %d from stack\n", poppedValue);
    return poppedValue;
}

// Peek operation - View top element without removing
int peek(struct Node* top) {
    if(isEmpty(top)) {
        printf("Stack is empty! No top element.\n");
        return -1;
    }
    return top->data;
}

// Display stack from top to bottom
void display(struct Node* top) {
    if(isEmpty(top)) {
        printf("Stack is empty!\n");
        return;
    }
    
    struct Node* temp = top;
    printf("Stack (Top to Bottom): ");
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

// Free all nodes in the stack
void freeStack(struct Node** top) {
    struct Node* temp;
    while(*top != NULL) {
        temp = *top;
        *top = (*top)->next;
        free(temp);
    }
}

// Main method with menu-driven interface
int main() {
    struct Node* top = NULL;
    int choice, data;
    
    printf("=== STACK OPERATIONS USING LINKED LIST ===\n");
    
    do {
        printf("\n--- Stack Menu ---\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Peek\n");
        printf("4. Display Stack\n");
        printf("5. Check if Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter data to push: ");
                scanf("%d", &data);
                push(&top, data);
                break;
                
            case 2:
                pop(&top);
                break;
                
            case 3:
                data = peek(top);
                if(data != -1) {
                    printf("Top element is: %d\n", data);
                }
                break;
                
            case 4:
                display(top);
                break;
                
            case 5:
                if(isEmpty(top)) {
                    printf("Stack is empty\n");
                } else {
                    printf("Stack is not empty\n");
                }
                break;
                
            case 6:
                freeStack(&top);
                printf("Program exited. Memory freed.\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}
OUTPUT:
=== STACK OPERATIONS USING LINKED LIST ===

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display Stack
5. Check if Empty
6. Exit
Enter your choice: 1
Enter data to push: 93
Pushed 93 onto stack

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display Stack
5. Check if Empty
6. Exit
Enter your choice: 1
Enter data to push: 98
Pushed 98 onto stack

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display Stack
5. Check if Empty
6. Exit
Enter your choice: 1
Enter data to push: 44
Pushed 44 onto stack

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display Stack
5. Check if Empty
6. Exit
Enter your choice: 2
Popped 44 from stack

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display Stack
5. Check if Empty
6. Exit
Enter your choice: 3
Top element is: 98

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display Stack
5. Check if Empty
6. Exit
Enter your choice: 4
Stack (Top to Bottom): 98 93 

--- Stack Menu ---
1. Push
2. Pop
3. Peek
4. Display Stack
5. Check if Empty
6. Exit
Enter your choice: 5
Stack is not empty  
