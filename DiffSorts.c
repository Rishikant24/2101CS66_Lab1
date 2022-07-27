#include <stdio.h>
#include <math.h>



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
    
}
