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
 #define MALLOC(num,type) (type *)malloc((num)*sizeof(type));
 int main(void){
    int numberItem;
    int i,x;
    int *parray;
    int total=0;
    printf("please input the numberItem:\n");
    scanf("%d",&numberItem);
    printf("please input the value of x:\n");
    scanf("%d",&x);

    /*malloc a memory*/
    parray=MALLOC(numberItem+1,int);
    if(parray==NULL){
        perror("The memory allocation is failed.\n");
        exit(1);
    }
    /* input the cofficients of the polynomial*/
    for(i=0;i<numberItem+1;i++){
        printf("Enter the coefficient of X^%d:",numberItem-i);
        scanf("%d",&parray[i]);
    }

    printf("\n");
    for(i=0;i<numberItem+1;i++){
        printf("The saving coefficient number X^%d is:%d\n",i,*(parray+i));
        total = total+*(parray+i)*pow(x,i);
    }

    printf("The formular is:\n");
    for(i=0;i<numberItem+1;i++){    
        printf("%dX^%d ",*(parray+i),i);
        /*total = total+*(parray+i)*pow(x,i);*/
        if(i<numberItem)
            printf("+");
    }
/*gcc -ansi -pedantic -Wextra -Wall -o Lab2New Lab2New.c -lm*/
    printf("The total number is:%d\n",total);
    parray=NULL;/*Must free the pointer after set pointer = free*/
    free (parray);

    
    return 0;

 }