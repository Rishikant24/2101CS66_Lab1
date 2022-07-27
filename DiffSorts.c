#include <stdio.h>
#include <math.h>

void swap(int *x, int *y);
void insertion_sort(int a[], int s);
void selection_sort(int a[], int s);
void bubble_sort(int a[], int s);
void printArray(int A[], int size);
void merge(int a[], int l, int m, int r);
void merge_sort(int a[], int l, int s);
int partition (int arr[], int low, int high);
void quick_sort(int arr[], int low, int high);

int main()
{
    int n,i,j,q;
    printf("Enter the number of elements of the array:\n");
    scanf("%d", &n);

    int a[n];
    printf("Enter the array elements that need to be sorted in ascending order:\n");
    for(i=0;i<n;i++)
    {
        scanf("%d", &a[i]);
    }

    printf("Choose your sorting algorithm:\n");
    printf("Enter 1 for 'INSERTION SORT'\n");
    printf("Enter 2 for 'SELECTION SORT'\n");
    printf("Enter 3 for 'BUBBLE SORT'\n");
    printf("Enter 4 for 'MERGE SORT'\n");
    printf("Enter 5 for 'QUICK SORT'\n");

    scanf("%d", &q);

    switch(q)
    {
        case 1: 
        {
            insertion_sort(a, n);
            break;
        }

         case 2: 
        {
            selection_sort(a, n);
            break;
        }

        case 3: 
        {
            bubble_sort(a, n);
            break;
        }

        case 4: 
        {
            merge_sort(a, 0, n-1);
            printArray(a, n);
            break;
        }

        case 5: 
        {
            quick_sort(a,0,n-1);
            printArray(a, n);
            break;
        }
    }

    
    
}

void swap(int *x, int *y)
{
    int temp;
    temp=*y;
    *y=*x;
    *x=temp;
}

void insertion_sort(int a[], int n)
{
    int i,j;
    for(i=1;i<n;i++)
    {
        j=i;
        while(j>0 && a[j]<a[j-1])
        {   
            int *x = &a[j];
            int *y = &a[j-1];
            swap(x,y);
            j--;
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
}

void selection_sort(int a[], int n)
{
    int i, j, imin;
    for(i=0;i<n-1;i++)
    {

        imin=i;
        for(j=i+1;j<n;j++)
        {
            if(a[j]<a[imin])
            {
                imin=j;
            }
        }
        if(imin!=i)
        {   
            int *x = &a[i];
            int *y = &a[imin];
            swap(x,y);
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
}

void bubble_sort(int a[], int n)
{
    int i,j;
    for(i=0;i<n;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j]>a[j+1])
            {   
                int *x = &a[j];
                int *y = &a[j+1];
                swap(x,y);
            }
        }
    }

    for(i=0;i<n;i++)
    {
        printf("%d ", a[i]);
    }
}

void printArray(int A[], int size)
{
    int i;
    for (i = 0; i < size; i++)
        printf("%d ", A[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int r) //function that  merges the two array 
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;
 
    /* create temp arrays */
    int L[n1], R[n2];
 
    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];
 
    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        }
        else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }
 
    /* Copy the remaining elements of L[], if there
    are any */
    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }
 
    /* Copy the remaining elements of R[], if there
    are any */
    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }
}
void merge_sort(int arr[], int l, int r) // function that uses recursion to implement merge sort 
{
    if (l < r) {
        int m = l + (r - l) / 2;
        // Sort first and second halves
        merge_sort(arr, l, m);
        merge_sort(arr, m + 1, r);
        merge(arr, l, m, r);
    }
}

int partition (int arr[], int low, int high)  // partition function for quick sort 
{ 
    int pivot = arr[high]; // pivot 
    int i = (low - 1); // Index of smaller element and indicates the right position of pivot found so far
  
    for (int j = low; j <= high - 1; j++) 
    { 
        // If current element is smaller than the pivot 
        if (arr[j] < pivot) 
        { 
            i++; // increment index of smaller element 
            swap(&arr[i], &arr[j]); 
        } 
    } 
    swap(&arr[i + 1], &arr[high]); 
    return (i + 1); 
} 


void quick_sort(int arr[], int low, int high) // function which implements quick sort 
{ 
    if (low < high) 
    { 
        /* pi is partitioning index, arr[p] is now 
        at right place */
        int pi = partition(arr, low, high); 
  
        // Separately sort elements before 
        // partition and after partition 
        quick_sort(arr, low, pi - 1); 
        quick_sort(arr, pi + 1, high); 
    } 
} 