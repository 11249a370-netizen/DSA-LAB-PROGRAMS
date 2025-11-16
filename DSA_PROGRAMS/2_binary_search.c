AIM:
To implement the binary search algorithm to efficiently search for a given element (pavan).
SOURCE CODE: 
  #include<stdio.h>
int main()
{
    int n,pavan,start,end,mid,i;
    printf("Enter the size of the array:");
    scanf("%d",&n);
    int arr[n];
    printf("Enter the sorted elements of array:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter the the element to search :");
    scanf("%d",&pavan);
    start=0;
    end=n-1;
    while(start<=end)
    {
        mid=(start+end)/2;
        if(arr[mid]==pavan)
        {
            printf("pavan(element) found at position %d\n",mid);
            return 0;
        }
        if(arr[mid]<pavan){
            start=mid+1;
        }  
        else
        {
            end=mid-1;
        }
    }    
 printf("sorry pavan not found \n");
 return 0;
 }
 OUTPUT:
 Enter the size of the array:6
 Enter the sorted elements of array:
 16 32 64 70 78 99
 Enter the the element to search :78
 pavan(element) found at position 4


  
