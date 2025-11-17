AIM:To reverse a given string using stack opererations based on the LIFO principle.
// Online C compiler to run C program online
#include<stdio.h>
#include<stdlib.h>

int TOP = -1, MAX;
char *STACK;

void display()
{
    printf("There are %d elements in stack:\n", TOP + 1);
    for(int i = TOP; i >= 0; i--)   // removed ;  
    {
        if(i == TOP)
            printf("|%c|  -TOP\n", STACK[i]);
        else
            printf("|%c|\n", STACK[i]);
    }
}

void push(char item)
{
    if(TOP == MAX - 1)
    {
        printf("Stack is overflow\n");
    }
    else
    {
        TOP = TOP + 1;
        STACK[TOP] = item;
    }
}

char pop()
{
    char item;
    if(TOP == -1)
    {
        printf("Stack is underflow\n");
        return '\0';
    }
    else
    {
        item = STACK[TOP];
        TOP = TOP - 1;   // fixed TOP = TOP - 1;
        return item;
    }
}

void stringReversal()
{
    char string[MAX];
    printf("Please enter the string of size %d to reverse:", MAX);
    scanf("%s", string);

    for(int c = 0; c < MAX && string[c] != '\0'; c++)
    {
        push(string[c]);
    }

    printf("Reversed string: ");
    while(TOP != -1)
    {
        printf("%c", pop());
    }
    printf("\n");
}

int main()
{
    int operation = 0;
    
    printf("Enter the size of CHAR STACK:");
    scanf("%d", &MAX);

    STACK = (char*) malloc(MAX * sizeof(char));

START:
    printf("\nWhat STACK operations you want to do?\n1.Basic operations\n2.Reverse of string\nGive your choice:");
    scanf("%d", &operation);

    if(operation == 2)
    {
        stringReversal();
        goto START;
    }
    else if(operation == 1)
    {
        while(operation != 4)
        {
            printf("\n1.push\n2.pop\n3.Display\n4.exit\n");
            printf("Please choose stack operations to perform:");
            scanf("%d", &operation);

            switch(operation)
            {
                case 1:
                {
                    char item;
                    printf("Enter the char to push:");
                    scanf(" %c", &item);   // fixed %s → %c
                    push(item);
                    break;
                }

                case 2:
                {
                    char c = pop();
                    if(c != '\0')
                        printf("Element %c is popped out from top\n", c);
                    break;
                }

                case 3:
                    display();
                    break;

                case 4:
                    return 0;

                default:
                    printf("Incorrect operation selected\n");
                    operation = 0;
                    break;
            }
        }
    }
    else
    {
        goto START;
    }

    return 0;
}
OUTPUT:
Enter the size of CHAR STACK:5

What STACK operations you want to do?
1.Basic operations
2.Reverse of string
Give your choice:2
Please enter the string of size 5 to reverse:clean
Reversed string: naelc
