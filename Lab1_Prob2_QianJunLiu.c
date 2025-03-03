/*  
 * Author: QianJunLiu
 * Number: 041150452  
 * Date: 15-01-2025  
 * Course: CST8234 
 * Project: Lab1_problem2  
 */
#include <stdio.h>
/* define Macros for BMI calcualtion.*/
#define BMIFORMULA(weight, height) ((weight) / ((height) * (height)))
/* define main function.*/
int main(void) 
{
    /* define variables*/
    float weight,height,BMI;
    /* input different variables*/
    printf("Enter weight in kilograms:");
    scanf("%f", &weight);    
    printf("Enter height in meters:");
    scanf("%f", &height);
    /* Calculate the BMI value*/
    BMI=BMIFORMULA(weight, height);
    printf("BMI = %.2f",BMI);
    printf("Category:"); 
    /* Based on the BMI vaule to print out the BMI results */
    if (BMI < 18.5) {
        printf(" Underweight:\n");
    } else if (BMI >= 18.5 && BMI < 25) {
        printf(" Normal weight\n");
    } else if (BMI >= 25 && BMI < 30) {
        printf(" Overweight\n");
    } else if (BMI >= 30) {
        printf(" Obese:\n");
    }

    return 0;
}