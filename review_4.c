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
    int *ap;
    int array[10];
    i=0;
    ap=array;
    for(ap=array;ap<(array+10);ap++){
        *(ap)=i++;
        
    }
    i=0;
    for(ap=array;ap<(array+10);ap++)
        printf("The item of this array position is %d, and the value is %d.\n",i++,*(ap));
    return 0;

}