AIM:to implement the singly linked list and perform various operations.
SOURCE CODE:
#include <stdio.h>
#include <stdlib.h>

// Structure for a doubly linked list node
struct Node {
    int data;
    struct Node* prev;
    struct Node* next;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->prev = NULL;
    newNode->next = NULL;
    return newNode;
}

// Function to insert at beginning
void insertAtBeginning(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        printf("Node with data %d inserted at beginning.\n", data);
        return;
    }
    
    newNode->next = *head;
    (*head)->prev = newNode;
    *head = newNode;
    printf("Node with data %d inserted at beginning.\n", data);
}

// Function to insert at end
void insertAtEnd(struct Node** head, int data) {
    struct Node* newNode = createNode(data);
    
    if (*head == NULL) {
        *head = newNode;
        printf("Node with data %d inserted at end.\n", data);
        return;
    }
    
    struct Node* temp = *head;
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->next = newNode;
    newNode->prev = temp;
    printf("Node with data %d inserted at end.\n", data);
}

// Function to insert at specific position
void insertAtPosition(struct Node** head, int data, int position) {
    if (position < 1) {
        printf("Invalid position! Position should be >= 1.\n");
        return;
    }
    
    if (position == 1) {
        insertAtBeginning(head, data);
        return;
    }
    
    struct Node* newNode = createNode(data);
    struct Node* temp = *head;
    
    // Traverse to the position-1 node
    for (int i = 1; i < position - 1 && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position %d is out of bounds! List has fewer nodes.\n", position);
        free(newNode);
        return;
    }
    
    // Insert the new node
    newNode->next = temp->next;
    newNode->prev = temp;
    
    if (temp->next != NULL) {
        temp->next->prev = newNode;
    }
    
    temp->next = newNode;
    printf("Node with data %d inserted at position %d.\n", data, position);
}

// Function to delete from beginning
void deleteFromBeginning(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    struct Node* temp = *head;
    *head = (*head)->next;
    
    if (*head != NULL) {
        (*head)->prev = NULL;
    }
    
    printf("Node with data %d deleted from beginning.\n", temp->data);
    free(temp);
}

// Function to delete from end
void deleteFromEnd(struct Node** head) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    struct Node* temp = *head;
    
    // If there's only one node
    if (temp->next == NULL) {
        printf("Node with data %d deleted from end.\n", temp->data);
        free(temp);
        *head = NULL;
        return;
    }
    
    // Traverse to the last node
    while (temp->next != NULL) {
        temp = temp->next;
    }
    
    temp->prev->next = NULL;
    printf("Node with data %d deleted from end.\n", temp->data);
    free(temp);
}

// Function to delete from specific position
void deleteFromPosition(struct Node** head, int position) {
    if (*head == NULL) {
        printf("List is empty! Nothing to delete.\n");
        return;
    }
    
    if (position < 1) {
        printf("Invalid position! Position should be >= 1.\n");
        return;
    }
    
    struct Node* temp = *head;
    
    // If deleting the first node
    if (position == 1) {
        deleteFromBeginning(head);
        return;
    }
    
    // Traverse to the position node
    for (int i = 1; i < position && temp != NULL; i++) {
        temp = temp->next;
    }
    
    if (temp == NULL) {
        printf("Position %d is out of bounds! List has fewer nodes.\n", position);
        return;
    }
    
    // Update links
    if (temp->prev != NULL) {
        temp->prev->next = temp->next;
    }
    
    if (temp->next != NULL) {
        temp->next->prev = temp->prev;
    }
    
    printf("Node with data %d deleted from position %d.\n", temp->data, position);
    free(temp);
}

// Function to search for an element
void searchElement(struct Node* head, int data) {
    if (head == NULL) {
        printf("List is empty! Cannot search.\n");
        return;
    }
    
    struct Node* temp = head;
    int position = 1;
    int found = 0;
    
    while (temp != NULL) {
        if (temp->data == data) {
            printf("Element %d found at position %d.\n", data, position);
            found = 1;
        }
        temp = temp->next;
        position++;
    }
    
    if (!found) {
        printf("Element %d not found in the list.\n", data);
    }
}

// Function to display the list forward
void displayForward(struct Node* head) {
    if (head == NULL) {
        printf("List is empty!\n");
        return;
    }
    
    struct Node* temp = head;
    printf("List (Forward): ");
    while (temp != NULL) {
        printf("%d", temp->data);
        if (temp->next != NULL) {
            printf(" <-> ");
        }
        temp = temp->next;
    }
    printf("\n");
}

// Main function with switch case menu
int main() {
    struct Node* head = NULL;
    int choice, data, position;
    
    printf("=== Doubly Linked List Operations ===\n");
    
    do {
        printf("\n--- Menu ---\n");
        printf("1. Insert at Beginning\n");
        printf("2. Insert at End\n");
        printf("3. Insert at Position\n");
        printf("4. Delete from Beginning\n");
        printf("5. Delete from End\n");
        printf("6. Delete from Position\n");
        printf("7. Search Element\n");
        printf("8. Display List (Forward)\n");
        printf("9. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1:
                printf("Enter data to insert at beginning: ");
                scanf("%d", &data);
                insertAtBeginning(&head, data);
                break;
                
            case 2:
                printf("Enter data to insert at end: ");
                scanf("%d", &data);
                insertAtEnd(&head, data);
                break;
                
            case 3:
                printf("Enter data to insert: ");
                scanf("%d", &data);
                printf("Enter position: ");
                scanf("%d", &position);
                insertAtPosition(&head, data, position);
                break;
                
            case 4:
                deleteFromBeginning(&head);
                break;
                
            case 5:
                deleteFromEnd(&head);
                break;
                
            case 6:
                printf("Enter position to delete: ");
                scanf("%d", &position);
                deleteFromPosition(&head, position);
                break;
                
            case 7:
                printf("Enter element to search: ");
                scanf("%d", &data);
                searchElement(head, data);
                break;
                
            case 8:
                displayForward(head);
                break;
            case 9:
                printf("Exiting program...\n");
                break;
                
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while(choice != 11);
    
    // Free remaining memory before exiting
    struct Node* temp;
    while (head != NULL) {
        temp = head;
        head = head->next;
        free(temp);
    }
    
    return 0;
}

OUTPUT:
=== Doubly Linked List Operations ===

--- Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Search Element
8. Display List (Forward)
9. Exit
Enter your choice: 1
Enter data to insert at beginning: 93
Node with data 93 inserted at beginning.

--- Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Search Element
8. Display List (Forward)
9. Exit
Enter your choice: 2
Enter data to insert at end: 98
Node with data 98 inserted at end.

--- Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Search Element
8. Display List (Forward)
9. Exit
Enter your choice: 3
Enter data to insert: 44
Enter position: 2
Node with data 44 inserted at position 2.

--- Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Search Element
8. Display List (Forward)
9. Exit
Enter your choice: 4
Node with data 93 deleted from beginning.

--- Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Search Element
8. Display List (Forward)
9. Exit
Enter your choice: 5
Node with data 98 deleted from end.

--- Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Search Element
8. Display List (Forward)
9. Exit
Enter your choice: 6
Enter position to delete: 1
Node with data 44 deleted from beginning.

--- Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Search Element
8. Display List (Forward)
9. Exit
Enter your choice: 8
List is empty!

--- Menu ---
1. Insert at Beginning
2. Insert at End
3. Insert at Position
4. Delete from Beginning
5. Delete from End
6. Delete from Position
7. Search Element
8. Display List (Forward)
9. Exit
Enter your choice: 
