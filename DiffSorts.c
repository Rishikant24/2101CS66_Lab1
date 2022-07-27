#include <stdio.h>
#include <math.h>

void swap(int *x, int *y);
void insertion_sort(int a[], int s);
void selection_sort(int a[], int s);

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