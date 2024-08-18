/*Create a structure book with book title, author, publication, and price. Read data of 3 books and display.*/
#include <stdio.h>

struct book {
    char title[100];
    char author[100];
    char publication[100];
    float price;
};

void main() {
    struct book books[3];

    printf("Enter details of 3 books:\n");
    for (int i = 0; i < 3; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Title: ");
        scanf("%s", books[i].title);
        printf("Author: ");
        scanf("%s", books[i].author);
        printf("Publication: ");
        scanf("%s", books[i].publication);
        printf("Price: ");
        scanf("%f", &books[i].price);
    }

    printf("\nDetails of 3 books:\n");
    
    for (int i = 0; i < 3; i++) {
        printf("\nBook %d:\n", i + 1);
        printf("Title: %s\n", books[i].title);
        printf("Author: %s\n", books[i].author);
        printf("Publication: %s\n", books[i].publication);
        printf("Price: $%.2f\n", books[i].price);
    }

}
