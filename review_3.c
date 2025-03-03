/*  
 * Author: QianJunLiu
 * Number: 041150452  
 * Date: 17-02-2025  
 * Course: CST8234 
 * Project: Pointers on C P111  
 */
 #include<stdio.h>
 int main(void){
    int i;
    printf("Please input a number\n");
    scanf("%d",&i);

    if(i>0)
        printf("This is a positive number.\n");
    else if(i==0)
        printf("This is equal 0.\n");
    else
        printf("This is a negtive number.\n");

    return 0;
        
 }