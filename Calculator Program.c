#include <stdio.h>
#include <math.h>

int main()
{   
    float a, b, ans;
    int n;
    
    //Input 2 numbers
    printf("Enter two numbers on which you want to perform arithmetic operation: \n");
    scanf("%f%f",&a, &b);
    
    // Select operation
    printf("Choose the Operation you want to perform:\n");
    printf("Enter 1 for Addition\n");
    printf("Enter 2 for Subtraction\n");
    printf("Enter 3 for Multiplication\n");
    printf("Enter 4 for Division\n");
    printf("Enter 5 for Modulus Function\n");
    scanf("%d", &n);

    switch(n)
    {
        case 1:     // Addition Operation
        {
            ans = a+b;
            printf("%f + %f = %f", a, b, ans);
            break;
        }
    
    }

}