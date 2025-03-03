/*  
 * Author: QianJunLiu
 * Number: 041150452  
 * Date: 17-02-2025  
 * Course: CST8234 
 * Project: Pointers on C P111  
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <stdbool.h>

/*decleration functions */
bool functionPrimer(int num);

bool functionPrimer(int num){
    int i=4;
    for (;i*i<num;i++){
        if(num/i==0)
            return true;
        else
            continue;
    }
    return false;
}

int main(void){
    int number=-1;
    bool result;
    printf("Please input a number\n");
    scanf("%d",&number);

    if(number<3 && number >1)
        printf("The number is primer.\n");
    else if(number <0)
        printf("This is invalid input.\n");
    else{
        result = functionPrimer(number);
        switch (result){
            case true:
                printf("%d is not a primer.\n",number);
                break;
            case false:
                printf("%d is a primer.\n",number);
                break;

        }
    }
    return 0;
}