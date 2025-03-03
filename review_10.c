/*  
 * Author: QianJunLiu
 * Number: 041150452  
 * Date: 17-02-2025  
 * Course: CST8234 
 * Project: Pointers on C P111  
 */
#include <stdio.h>
void function_position(int *p1, int *p2);
void function_position(int *p1, int *p2){
    int temp=0;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}

int main(void){
    
    int number1,number2;
    int *p1=&number1,*p2=&number2;
    printf("Please input the first number1:");
    scanf("%d",p1);
    printf("Please input the second number2:");
    scanf("%d",p2);
    printf("print out two numbers number1:%d number2:%d:\n",*p1,*p2);

    function_position(p1,p2);
    printf("print out the final two numbers number1:%d number2:%d",*p1,*p2);
    return 0;
}