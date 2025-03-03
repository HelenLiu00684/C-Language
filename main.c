#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "student.h"

int main(){
    int num=-1,ret=0;
    student *parraystudent;
    char gender_str[10];
    register int i=-1;
    printf("Enter the number of students: ");
    scanf("%d", &num);
    /* Allocate memory *before* calling Add students*/
    parraystudent = (student *)malloc(num * sizeof(student *));
    if (parraystudent == NULL) {
        perror("parraystudent Memory allocation failed");
            exit(1); /* Exit with error*/
        }

    for(i=0;i<num;i++){
        ret=0;
        while (ret != 1) {
        printf("Enter the %d student id: ",i+1);
        ret=scanf("%d", &parraystudent[i].sid);
        if (ret != 1) {
            printf("Error: Please enter a valid integer for the student id \n");
            while (getchar() != '\n');
                }
            }

        ret=0;
        while (ret != 1) {
        printf("Enter the %d student name: ",i+1);
        ret=scanf("%20s", parraystudent[i].name); /*&parraystudent[i].name is wrong..... here is char[n]*/
        if (ret != 1) {
            printf("Error: Please enter a valid string for the student name \n");
            while (getchar() != '\n');
                }
            }    
        

        ret=0;
        while (ret != 1) {
        printf("Enter the %d student gender(male or female): ",i+1);
        scanf("%20s", gender_str);             /*enum need strcmp to get result.....*/
        if (strcmp(gender_str,"male")==0){
            parraystudent[i].gender=male;
            ret=1;
        }else if(strcmp(gender_str,"female")==0){
            parraystudent[i].gender=female;
            ret=1;   
        }else{
            printf("invalid gender！\n");
            ret=0; /*invalid gender*/ 
        }
        if (ret != 1) {
            printf("Error: Please enter a valid string for the student gender \n");
            while (getchar() != '\n');
                }
            }    
        

        ret=0;
        while (ret != 1) {
        printf("Enter the %d student weight kilogram: ",i+1);
        ret=scanf("%f", &parraystudent[i].weight);
        if (ret != 1) {
            printf("Error: Please enter a valid float for the student weight \n");
            while (getchar() != '\n');
                }
            }    
        

        ret=0;
        while (ret != 1) {
        printf("Enter the %d student height meter: ",i+1);
        ret=scanf("%f", &parraystudent[i].height);
        if (ret != 1) {
            printf("Error: Please enter a valid float for the student height \n");
            while (getchar() != '\n');
                }
            }  
            


        }                        
   

    for(i=0;i<num;i++){
        student_bmi(&parraystudent[i]);
    }


     
    free(parraystudent); /*release stduent array memory*/ 
    return 0;
}