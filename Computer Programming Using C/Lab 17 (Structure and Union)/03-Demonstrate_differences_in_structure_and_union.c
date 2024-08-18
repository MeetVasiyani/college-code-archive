/*Demonstrate difference between structure and union. */
#include <stdio.h>
#include <string.h>

struct Car {
    char brand[20];
    int year;
    float price;
};

union Info {
    int id;
    float weight;
    char name[20];
};

void main() {

    printf("Structure demonstration:\n");

    struct Car myCar;
    strcpy(myCar.brand, "Toyota");
    myCar.year = 2020;
    myCar.price = 25000.50;

    printf("Brand: %s\n", myCar.brand);
    printf("Year: %d\n", myCar.year);
    printf("Price: $%.2f\n", myCar.price);
    printf("Size of Car structure: %lu bytes\n", sizeof(myCar));

    printf("\nUnion demonstration:\n");

    union Info myInfo;
    myInfo.id = 123;
    printf("ID: %d\n", myInfo.id);

    strcpy(myInfo.name, "John");
    printf("Name: %s\n", myInfo.name);

    myInfo.weight = 68.5;
    printf("Weight: %.2f kg\n", myInfo.weight);
    printf("Size of Info union: %lu bytes\n", sizeof(myInfo));

}
