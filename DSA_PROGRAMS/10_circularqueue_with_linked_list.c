AIM:To implement circular queue using linked list.
SOURCE CODE:
#include <stdio.h>
#include <stdlib.h>

// Structure for queue node
struct Node {
    int data;
    struct Node* next;
};

// Global pointers for front and rear
struct Node* front = NULL;
struct Node* rear = NULL;

// Check if queue is empty
int isEmpty() {
    return front == NULL;
}

// Enqueue operation - Add element at rear
void enqueue(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    if(newNode == NULL) {
        printf("Memory allocation failed!\n");
        return;
    }
    newNode->data = data;
    newNode->next = NULL;
    
    if(isEmpty()) {
        // First node in queue
        front = rear = newNode;
        rear->next = front; // Circular link
    } else {
        rear->next = newNode;
        rear = newNode;
        rear->next = front; // Maintain circular link
    }
    printf("Enqueued %d\n", data);
}

// Dequeue operation - Remove element from front
int dequeue() {
    if(isEmpty()) {
        printf("Queue Underflow! Cannot dequeue from empty queue.\n");
        return -1;
    }
    
    int dequeuedValue = front->data;
    struct Node* temp = front;
    
    if(front == rear) {
        // Only one node in queue
        front = rear = NULL;
    } else {
        front = front->next;
        rear->next = front; // Maintain circular link
    }
    
    free(temp);
    printf("Dequeued %d\n", dequeuedValue);
    return dequeuedValue;
}

// Peek operation - View front element without removing
int peek() {
    if(isEmpty()) {
        printf("Queue is empty! No front element.\n");
        return -1;
    }
    return front->data;
}

// Display queue from front to rear
void display() {
    if(isEmpty()) {
        printf("Queue is empty!\n");
        return;
    }
    
    struct Node* temp = front;
    printf("Queue (Front to Rear): ");
    
    do {
        printf("%d ", temp->data);
        temp = temp->next;
    } while(temp != front);
    
    printf("\n");
}

// Free all nodes in the queue
void freeQueue() {
    if(isEmpty()) {
        return;
    }
    
    struct Node* temp = front;
    struct Node* nextNode;
    
    do {
        nextNode = temp->next;
        free(temp);
        temp = nextNode;
    } while(temp != front);
    
    front = rear = NULL;
}

// Main method with menu-driven interface
int main() {
    int choice, data;
    
    printf("=== CIRCULAR QUEUE OPERATIONS USING LINKED LIST ===\n");
    
    do {
        printf("\n--- Circular Queue Menu ---\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Peek\n");
        printf("4. Display Queue\n");
        printf("5. Check if Empty\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter data to enqueue: ");
                scanf("%d", &data);
                enqueue(data);
                break;
                
            case 2:
                dequeue();
                break;
                
            case 3:
                data = peek();
                if(data != -1) {
                    printf("Front element is: %d\n", data);
                }
                break;
                
            case 4:
                display();
                break;
                
            case 5:
                if(isEmpty()) {
                    printf("Queue is empty\n");
                } else {
                    printf("Queue is not empty\n");
                }
                break;
                
            case 6:
                freeQueue();
                printf("Program exited. Memory freed.\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 6);
    
    return 0;
}
OUTPUT:
=== CIRCULAR QUEUE OPERATIONS USING LINKED LIST ===

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display Queue
5. Check if Empty
6. Exit
Enter your choice: 1
Enter data to enqueue: 93
Enqueued 93

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display Queue
5. Check if Empty
6. Exit
Enter your choice: 1
Enter data to enqueue: 98
Enqueued 98

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display Queue
5. Check if Empty
6. Exit
Enter your choice: 1
Enter data to enqueue: 44
Enqueued 44

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display Queue
5. Check if Empty
6. Exit
Enter your choice: 2
Dequeued 93

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display Queue
5. Check if Empty
6. Exit
Enter your choice: 3
Front element is: 98

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display Queue
5. Check if Empty
6. Exit
Enter your choice: 4
Queue (Front to Rear): 98 44 

--- Circular Queue Menu ---
1. Enqueue
2. Dequeue
3. Peek
4. Display Queue
5. Check if Empty
6. Exit
Enter your choice: 6
Program exited. Memory freed.
