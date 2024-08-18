/*Get a number as a string from user and convert string to integer, string to float as per user’s choice.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void main() {
    char number_str[100];
    char conversion_choice[10];

    printf("Enter a number: ");
    scanf("%s", number_str);

    printf("Enter 'int' to convert to integer or 'float' to convert to float: ");
    scanf("%s", conversion_choice);

    if (strcmp(conversion_choice, "int") == 0) {
        int converted_number = atoi(number_str);
        printf("The number as an integer is: %d\n", converted_number);
    } 
    else if (strcmp(conversion_choice, "float") == 0) {
        float converted_number = atof(number_str);
        printf("The number as a float is: %f\n", converted_number);
    } 
    else {
        printf("Invalid conversion choice. Please enter 'int' or 'float'.\n");
    }
}
