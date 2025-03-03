/*  
 * Author: QianJunLiu
 * Number: 041150452  
 * Date: 17-02-2025  
 * Course: CST8234 
 * Project: Pointers on C P111  
 */
 #include <stdio.h>

 int main(void){
    int arrayList[2][2];
    int i=0,j=0;
    printf("Please input the items in the array:\n");

    for(i=0;i<2;i++){
        for(j=0;j<2;j++)
        scanf("%d",&arrayList[i][j]);
    }

    for(i=0;i<2;i++){
        for(j=0;j<2;j++)
        printf("The result is: %d\n",arrayList[i][j]);
    }
    printf("The final result is %d\n",(arrayList[0][0]*arrayList[1][1]-arrayList[0][1]*arrayList[1][0]));

    return 0;
 }