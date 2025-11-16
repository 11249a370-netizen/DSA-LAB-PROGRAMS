AIM:
To implement a stack data structure using an array, allowing the user to initialize the stack with elements and perform push and pop
operations interactively.
SOURCE CODE:
  #include <stdio.h>

int TOP = -1, MAX;

void display(int stack[]) {
    if (TOP == -1) {
        printf("Stack is empty.\n");
        return;
    }
    printf("Current stack elements are :");
    for (int i = 0; i <= TOP; i++) {
        printf(">>%d ", stack[i]);
    }
    printf("(TOP)\n");
}

void push(int stack[]) {
    int item;
    if (TOP == MAX - 1) {       // Fixed comparison operator here
        printf("stack is overflow\n");
    } else {
        printf("Enter the item to push:");
        scanf("%d", &item);
        TOP = TOP + 1;
        stack[TOP] = item;
    }
}

void pop(int stack[]) {
    if (TOP == -1) {
        printf("stack is underflow\n");
    } else {
        printf("Top element in the stack:%d\n", stack[TOP]);
        TOP = TOP - 1;
        
    }
}

int main() {
    int operation = 0;
    printf("Enter the size of STACK:");
    scanf("%d", &MAX);
    int stack[MAX];

    // Take initial elements equal to stack size
    printf("Enter %d elements to initialize the stack:\n", MAX);
    for (int i = 0; i < MAX; i++) {
        scanf("%d", &stack[i]);
        TOP++;
    }

    display(stack);  // Show initial stack elements

    while (operation != 3) {
        printf("\nstack operations:\n 1.push \n 2.pop \n 3.Exit \n");
        printf("please choose stack operation to perform:");
        scanf("%d", &operation);
        switch (operation) {
            case 1:
                push(stack);
                display(stack);
                break;
            case 2:
                pop(stack);
                display(stack);
                break;
            case 3:
                return 0;
            default:
                printf("Incorrect option selected");
                break;
        }
    }

    return 0;
}
OUTPUT:
Enter the size of STACK:6
Enter 6 elements to initialize the stack:
95 85 92 89 93 92 
Current stack elements are :>>95 >>85 >>92 >>89 >>93 >>92 (TOP)

stack operations:
 1.push 
 2.pop 
 3.Exit 
please choose stack operation to perform:2
Top element in the stack:92
Current stack elements are :>>95 >>85 >>92 >>89 >>93 (TOP)
