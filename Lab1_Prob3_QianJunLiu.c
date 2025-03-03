/*  
 * Author: QianJunLiu
 * Number: 041150452  
 * Date: 15-01-2025  
 * Course: CST8234 
 * Project: Lab1_problem3  
 */
#include <stdio.h>
#include <stdbool.h>
/* define Macros for the Leap years calcualtion.*/
#define LEAPFORMULA(year) (year/4&&(year/100||year/400)) ? true:false
/* define main function.*/
int main(void) 
{
    /* define variables*/
    int year;
    bool flag;
    /* input different variables*/
    printf("Enter year: ");
    scanf("%d", &year);
    /* Calculate the flag value to indicate the year is LEAP or not, and print out the result*/
    flag = LEAPFORMULA(year); 
    switch (flag) 
    {
    case true:
        printf("%d is a Leap Year.\n", year);
        break;
    case false:
        printf("%d is not a Leap Year.\n", year);
        break;
    }
    return 0;
}