/*  
 * Author: QianJunLiu
 * Number: 041150452  
 * Date: 17-02-2025  
 * Course: CST8234 
 * Project: Pointers on C P111  
 */
#include <stdio.h>

int main(void){
    int (*parray1)[2],(*parray2)[2];
    int array1[2][2],array2[2][2];
    int i=0,j=0;
    parray1=array1;
    parray2=array2;


    printf("Please input values for the first array1:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",(*(parray1+i)+j));
        }
    }

    printf("Please input values for the second array2:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            scanf("%d",(*(parray2+i)+j));
        }
    }

    printf("Please out all values of array1:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d",*(*(parray1+i)+j));
        }
        printf("\n");
    }

    printf("Please out all values of array2:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d",*(*(parray2+i)+j));
        }
        printf("\n");
    }

    printf("Please out all result of array1 and array2:\n");
    for(i=0;i<2;i++){
        for(j=0;j<2;j++){
            printf("%d ",(*(*(parray1+i)+j)*(*(*(parray2+i)+j))));
        }
        printf("\n");
    }

    return 0;
    }



