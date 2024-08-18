/*Create a function that converts amount into words. (i.e. 9241: Nine Thousand Two Hundred Forty One)*/
#include <stdio.h>

void convert_to_words(int num);

char *ones[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine"};
char *tens[] = {"", "Ten", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
char *special[] = {"", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};

int main() {
    int amount;
    printf("Enter the amount: ");
    scanf("%d", &amount);
    convert_to_words(amount);
    return 0;
}

void convert_to_words(int num) {
    if (num == 0) {
        printf("Zero\n");
        return;
    }
    int thousands = num / 1000;
    int hundreds = (num / 100) % 10;
    int tens_digit = (num / 10) % 10;
    int ones_digit = num % 10;

    if (thousands > 0) {
        printf("%s Thousand ", ones[thousands]);
    }
    if (hundreds > 0) {
        printf("%s Hundred ", ones[hundreds]);
    }
    if (tens_digit == 1) {
        printf("%s ", special[ones_digit]);
    } 
    else {
        if (tens_digit > 0) {
            printf("%s ", tens[tens_digit]);
        }
        if (ones_digit > 0) {
            printf("%s ", ones[ones_digit]);
        }
    }
    printf("\n");
}
