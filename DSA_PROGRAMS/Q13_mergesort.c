AIM:To write a C program to sort an array of elements using 
the Merge Sort algorithm, which follows the divide-and-conquer technique.
  
 SOURCE CODE:
#include <stdio.h>

// Merge two sorted subarrays
void merge(int arr[], int left, int mid, int right)
{
    int i = left;
    int j = mid + 1;
    int k = 0;

    int temp[right - left + 1];

    // Merge sort  logic 
    while (i <= mid && j <= right)
    {
        if (arr[i] < arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    // Copying left-out elements
    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    // Copying temp back to original
    for (i = left, k = 0; i <= right; i++, k++)
        arr[i] = temp[k];
}

//Here  merge Sort function
void mergeSort(int arr[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        mergeSort(arr, left, mid);      // Left part
        mergeSort(arr, mid + 1, right); // Right part
        merge(arr, left, mid, right);   // Merge halves
    }
}

int main()
{
    int n;
    printf("Enter number of elements: ");
    scanf("%d", &n);

    int arr[n];
    printf("Enter %d elements:\n", n);
    for (int i = 0; i < n; i++)
        scanf("%d", &arr[i]);

    mergeSort(arr, 0, n - 1);

    printf("Sorted array (Merge Sort): ");
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);

    return 0;
}
OUTPUT:
Enter number of elements: 6
Enter 6 elements:
34 67 42 9 6 732
Sorted array (Merge Sort): 6 9 34 42 67 732 
