AIM:To implement a QUEUE data structure using an array, allowing the user to initialize the QUEUE with elements 
and perform ENQUEUE and DEQUEUE operations interactively.
SOURCE CODE:
#include <stdio.h>
#define SIZE 5

int queue[SIZE];
int front = -1, rear = -1;

// Add element to queue
void enqueue(int value) {
    if (rear == SIZE - 1) {
        printf("Queue Overflow! Cannot add %d\n", value);
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = value;
        printf("Added %d to queue\n", value);
    }
}

// Remove element from queue
void dequeue() {
    if (front == -1 || front > rear) {
        printf("Queue is empty! Nothing to remove\n");
    } else {
        printf("Removed %d from queue\n", queue[front]);
        front++;
        
        if (front > rear) {
            front = rear = -1;
        }
    }
}

// Display all elements in queue
void display() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Queue elements: ");
        for (int i = front; i <= rear; i++) {
            printf("%d ", queue[i]);
        }
        printf("\n");
    }
}

// Get front element without removing it
void peek() {
    if (front == -1 || front > rear) {
        printf("Queue is empty!\n");
    } else {
        printf("Front element: %d\n", queue[front]);
    }
}

int main() {
    int choice, value, n, i;
    
    printf("=== Queue Operations ===\n");
    
    // First, user enters some elements
    printf("How many elements do you want to add initially? (Max %d): ", SIZE);
    scanf("%d", &n);
    
    if (n > SIZE) {
        printf("Cannot add more than %d elements!\n", SIZE);
        n = SIZE;
    }
    
    printf("Enter %d elements:\n", n);
    for (i = 0; i < n; i++) {
        printf("Element %d: ", i + 1);
        scanf("%d", &value);
        enqueue(value);
    }
    
    printf("\nInitial queue created successfully!\n");
    display();
    
    // Now user can perform operations
    while(1) {
        printf("\n--- Queue Operations Menu ---\n");
        printf("1. Enqueue (Add element)\n");
        printf("2. Dequeue (Remove element)\n");
        printf("3. Display queue\n");
        printf("4. Peek (Front element)\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter value to add: ");
                scanf("%d", &value);
                enqueue(value);
                break;
                
            case 2:
                dequeue();
                break;
                
            case 3:
                display();
                break;
                
            case 4:
                peek();
                break;
                
            case 5:
                printf("Final queue: ");
                display();
                printf("Exiting program. Thank you!\n");
                return 0;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    }
    
    return 0;
}
OUTPUT:
=== Queue Operations ===
How many elements do you want to add initially? (Max 5): 4
Enter 4 elements:
Element 1: 103
Added 103 to queue
Element 2: 892
Added 892 to queue
Element 3: 873
Added 873 to queue
Element 4: 971
Added 971 to queue

Initial queue created successfully!
Queue elements: 103 892 873 971 

--- Queue Operations Menu ---
1. Enqueue (Add element)
2. Dequeue (Remove element)
3. Display queue
4. Peek (Front element)
5. Exit
Enter your choice: 1
Enter value to add: 
99

Added 99 to queue

--- Queue Operations Menu ---
1. Enqueue (Add element)
2. Dequeue (Remove element)
3. Display queue
4. Peek (Front element)
5. Exit
Enter your choice: 2
Removed 103 from queue

