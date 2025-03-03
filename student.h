#ifndef MY_STUDENT_FILE_H  /*Header Guard */ 
#define MY_STUDENT_FILE_H
#define NUM_COURSES_PER_STUDENT 3 



typedef struct student {
    int sid;                        /*student id*/
    char name[20];                  /*student name*/
    enum {male,female} gender;      /*gender type*/
    float weight;                   /*weight value */
    float height;                   /*height value*/
    /*course (*course)[3]; */            /*SUBJECT pointer ;*/
     /*course *courses; */                /*pointer of course array*/ 
     /*int num_courses; */                /*the number of course*/ 
} student;




/*Here are some methods for declarations*/
void student_construct(student *stu, const char *name);
void stduent_destruct(student *stu);
void student_bmi(student *stu);

#endif