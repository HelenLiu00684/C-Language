#include "student.h"
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

#define BMIFORMULA(weight, height) ((weight) / ((height) * (height)))

void student_construct(student *stu, const char *name)
{
    strcpy(stu->name,name);

}

void stduent_destruct(student *stu){
    free(stu);
}

void student_bmi(student *stu){
    float BMI=BMIFORMULA(stu->weight,stu->height);
    printf("The %s BMI = %.2f,it belongs to:",stu->name, BMI);
    if (BMI < 18.5) {
        printf(" Underweight:\n");
    } else if (BMI >= 18.5 && BMI < 25) {
        printf(" Normal weight\n");
    } else if (BMI >= 25 && BMI < 30) {
        printf(" Overweight\n");
    } else if (BMI >= 30) {
        printf(" Obese:\n");
    }
}
