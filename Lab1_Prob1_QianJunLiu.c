/*  
 * Author: QianJunLiu
 * Number: 041150452  
 * Date: 15-01-2025  
 * Course: CST8234 
 * Project: Lab1_problem1  
 */
#include <stdio.h>
/* define Macros for math methods.*/
#define ADD(x, y) ((x) + (y))
#define SUB(x, y) ((x) - (y))
#define MUL(x, y) ((x) * (y))
#define DIV(x, y) ((x) / (y))

/* define main function.*/
int main(void) 
{
    /* define variables*/
    int num1,num2,choice;
    /* input different variables*/
    printf("Enter first number:");
    scanf("%d", &num1);    
    printf("Enter second number:");
    scanf("%d", &num2);
    printf("Select operation (1 for ADD, 2 for SUB, 3 for MUL, 4 for DIV):");
    scanf("%d", &choice);
    /* run different math functions and get different values based on the choice values*/
    switch (choice) 
    {
    case 1:
        printf("Result: %d+%d = %d\n", num1, num2, ADD(num1, num2));
        break;
    case 2:
        printf("Result: %d-%d = %d\n", num1, num2, SUB(num1, num2));
        break;
    case 3:
        printf("Result: %d*%d = %d\n", num1, num2, MUL(num1, num2));
        break;
    case 4:
        if(num2==0){
            /* print out error if Diveision by zero*/
            printf("Error: Division by zero is not allowed!\n");
        }else {
            printf("Result: %d/%d = %d\n", num1, num2, DIV(num1, num2));
        }
        break;
    }

     
    return 0;
}



