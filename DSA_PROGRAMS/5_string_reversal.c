AIM:To reverse a given string using stack opererations based on the LIFO principle.
#include <stdio.h>
#include<stdlib.h>
int TOP=-1,MAX;
char *STACK;
void display()
{
    printf("There are %d elements in stack:",TOP+1);
    for(int i=TOP;i>=0;i--);
    {
        if(i==TOP)
            printf("|%c|,-TOP\n",STACK[i]);
        else
            printf("|%c|\n",STACK[i]);
    }
    void push(char item)
    {
        if(TOP==MAX-1)
        {
            printf("Stack is overflow ");
        }
        else
        {
            TOP=TOP+1;
            STACK[TOP]=item;
        }
    }
    char pop()
    {
        char item;
        if(TOP==-1)
        {
            printf("stack is underflow\n");
            return'\0';
        }
        else
        {
            item=STACK[TOP];
            TOP=TOP=-1;
            return item;
        }
    }
    void stringReversal()
    {
        char string[MAX];
        printf("please enter the string of size %d to reverse:",MAX);
        scanf("%s",string);
