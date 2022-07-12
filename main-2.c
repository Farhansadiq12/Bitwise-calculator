/*
Bitwise Calculator
*/

#include <stdio.h>

#define BITS 8

void ConvertDecimalToBinary (int a, char arr1[BITS + 1]);

void ConvertDecimalToBinary (int a, char arr1[BITS + 1])
{
    int i, j, s = BITS - 1, k = BITS - 1;
    int arr[BITS + 1];
    
    for(j = 0; j < BITS; j++)
    {
        if(a & 1)
        {
           arr[k] = 1; 
        }
        else
        {
            arr[k] = 0;
        }
        
        a = a >> 1;
        k--;
    }
    
    for(i = BITS - 1; i >= 0; i--)
    {
        if(arr[s] == 0)
        {
            arr1[i] = 48;
        }
        else
        {
            arr1[i] = 49;
        }
        s--;
    }
}

 

int main()
{
    int a, c, i, result;
    char b[3] = { 0 };
    char arr[BITS + 1] = { 0 };
    char arr1[BITS + 1] = { 0 };
    char arr2[BITS + 1] = { 0 };
    printf("Bitwise Calculator\n\n");
    printf("Enter two base 10 values with a bitwise operator to see the decimal result \nand the binary result.  The format is\n\n");
    printf("FirstNumber BitwiseOperator SecondNumber\n\n");
    printf("For example, enter the expression\n\n");
    printf("2 & 3\n\n");
    printf("This calculator can used with &, |, ^, << and >>\n\n");
    printf("Please note that the spaces between numbers and operator is essential\nand the two entered values must be between 0 and 255\n\n");
    printf("Enter expression ");
    scanf("%d %s %d", &a, b, &c);
    printf("\n");

    while ((a < 0) || (a > 255) || (c < 0) || (c > 255))
    {
       printf("\nThe entered expression contains out of range values.\nPlease reenter the expression using values between 0 and 255.\n\n");
       scanf("%d %s %d", &a, b, &c); 
    }
    
    if(b[0] == '&')
    {
        result = a & c;
        printf("In base 10...\n\n");
        printf("%d & %d = %d", a, c, result);
    }
    else if (b[0] == '|')
    {
        result = a | c;
        printf("In base 10...\n\n");
        printf("%d | %d = %d", a, c, result);
    }
    else if (b[0] == '^')
    {
        result = a ^ c;
        printf("In base 10...\n\n");
        printf("%d ^ %d = %d", a, c, result);
    }
    else if (b[0] == '>')
    {
        result = a >> c;
        printf("In base 10...\n\n");
        printf("%d >> %d = %d", a, c, result);
    }
    else if (b[0] == '<')
    {
        result = a << c;
        printf("In base 10...\n\n");
        printf("%d << %d = %d", a, c, result);
    }
    else
    {
        printf("Operator %s is not supported by this calculator.", b);
    }

    
    if((b[0] == '&') || (b[0] == '|') || (b[0] == '^'))
    {
        printf("\n\nIn %d-bit base 2...\n", BITS);
        ConvertDecimalToBinary(a, arr);
        printf("\n  %s", arr);
        printf("\n%c", b[0]);
        ConvertDecimalToBinary(c, arr1);
        printf("\n  %s", arr1);
        printf("\n  ========");
        ConvertDecimalToBinary(result, arr2);
        printf("\n  %s", arr2);
    }
    else if (b[0] == '>')
    {
        printf("\n\nIn %d-bit base 2...\n", BITS);
        ConvertDecimalToBinary(a, arr);
        printf("\n%s", arr);
        printf("\t>> %d",c);
        ConvertDecimalToBinary(result, arr2);
        printf("\n\n%s", arr2);
    }
    else if (b[0] == '<')
    {
        printf("\n\nIn %d-bit base 2...\n", BITS);
        ConvertDecimalToBinary(a, arr);
        printf("\n%s", arr);
        printf("\t<< %d",c);
        ConvertDecimalToBinary(result, arr2);
        printf("\n\n%s", arr2);
    }
    
    return 0;
}







