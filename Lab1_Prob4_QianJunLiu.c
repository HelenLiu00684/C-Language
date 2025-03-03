/*  
 * Author: QianJunLiu
 * Number: 041150452  
 * Date: 15-01-2025  
 * Course: CST8234 
 * Project: Lab1_problem4  
 */

#include <stdio.h>
/* define main function.*/
int main(void) 
{
    /* define variables*/
    int num,num0,num1,sum,i;
    printf("Enter the value of N: ");
    /* input a Fibonacci number*/
    scanf("%d", &num);
    printf("Fibonacci Sequence up to %d th term:",num);
    num0 = 0;
    num1 = 1; 
    printf("%d ",num0);
    printf("%d ",num1);
    /* print a Fibonacci result*/
    for(i=2; i<=num; i++){
        sum = num0+num1;
        num0=num1;
        num1=sum;
        printf("%d ",sum);
	}
    printf("\n");
    return 0;
}
