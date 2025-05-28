/*55. WAP to define a C structure named Student (roll_no, name, branch and 
batch_no) and also to access the structure members using Pointer.*/

#include<stdio.h>

struct Student{
    int roll_no;
    char name[20];
    char branch[20];
    int batch_no;
};

void main(){
    struct Student s1;
    struct Student *ptr;
    ptr = &s1;

    printf("Enter roll number: ");
    scanf("%d", &ptr->roll_no);
    printf("Enter name: ");
    scanf("%s", &ptr->name);
    printf("Enter branch: ");
    scanf("%s", &ptr->branch);
    printf("Enter batch number: ");
    scanf("%d", &ptr->batch_no);

    printf("\nStudent Details :");
    printf("Roll number: %d\n", ptr->roll_no);
    printf("Name: %s\n", ptr->name);
    printf("Branch: %s\n", ptr->branch);
    printf("Batch number: %d\n", ptr->batch_no);
}