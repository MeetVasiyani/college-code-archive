/*Demonstrate structure pointer.*/
#include <stdio.h>

struct student {
    char name[50];
    int age;
    float marks;
};

void main() {
    struct student *ptr;
    struct student s1 = {"John", 20, 85.5};

    ptr = &s1;

    printf("Name: %s\n", ptr->name);
    printf("Age: %d\n", ptr->age);
    printf("Marks: %.2f\n", ptr->marks);

}
