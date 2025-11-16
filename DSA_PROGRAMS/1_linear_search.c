Aim:
To search for a specific element (key) in an integer array using linear search and display its position if found.
SOURCE CODE:
#include<stdio.h>
int main()
{
    int n,venkata,found=0,i;  //here venkata is like key
    //input size of array
    printf("Enter the size of the array :");
    scanf("%d",&n);
    int arr[n];
    //input array elements
    printf("Enter %d elements:",n);
    for(int i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    //input element to search 
    printf("Enter element to search:");
    scanf("%d",&venkata);
    for(i=0;i<n;i++)
    {
        if(arr[i]==venkata)
        {
            printf("Element(venkata) found at position %d\n",i+1);
            found=1;
            break;
        }
    }
    if(!found)
    {
        printf("Element not found\n");
    }
    return 0;
  }
OUTPUT:
Enter the size of the array :5
Enter 5 elements:64 28 11 21 93
Enter element to search:11
Element(venkata) found at position 3
