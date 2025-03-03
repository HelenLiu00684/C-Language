/*  
 * Author: QianJunLiu
 * Number: 041150452  
 * Date: 17-02-2025  
 * Course: CST8234 
 * Project: Pointers on C P111  
 */
 #include <stdio.h>
 int main(void){
    int i;
    for(i=0;i<10;i++){
        if(i==5)
            break;
        else
            printf("The current number is:%d\n",i);
    }
    return 0;
 }