/*Create a menu driven program to implement own string.h library. (without using built-in string functions)*/
#include <stdio.h>
#include <stdlib.h>

#define MAX_SIZE 100

int main() {
    int choice;
    char str1[MAX_SIZE], str2[MAX_SIZE];

    while (1) {
        printf("\nOwn String Library Menu:\n");
        printf("1. my_strcpy()\n");
        printf("2. my_strcat()\n");
        printf("3. my_strcmp()\n");
        printf("4. my_strchr()\n");
        printf("5. my_strstr()\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                printf("my_strcpy(\"%s\", \"%s\") = %s\n", str1, str2, my_strcpy(str1, str2));
                break;
            case 2:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                printf("my_strcat(\"%s\", \"%s\") = %s\n", str1, str2, my_strcat(str1, str2));
                break;
            case 3:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                printf("my_strcmp(\"%s\", \"%s\") = %d\n", str1, str2, my_strcmp(str1, str2));
                break;
            case 4:
                printf("Enter the string: ");
                scanf("%s", str1);
                printf("Enter the character: ");
                scanf("%c", &str2[0]);
                printf("my_strchr(\"%s\", '%c') = %s\n", str1, str2[0], my_strchr(str1, str2[0]));
                break;
            case 5:
                printf("Enter the first string: ");
                scanf("%s", str1);
                printf("Enter the second string: ");
                scanf("%s", str2);
                printf("my_strstr(\"%s\", \"%s\") = %s\n", str1, str2, my_strstr(str1, str2));
                break;
            case 6:
                exit(0);
            default:
                printf("Invalid choice!\n");
        }
    }
    return 0;
}

char *my_strcpy(char *dest, const char *src) {
    char *ptr = dest;
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return ptr;
}

char *my_strcat(char *dest, const char *src) {
    char *ptr = dest;
    while (*dest != '\0') {
        dest++;
    }
    while (*src != '\0') {
        *dest++ = *src++;
    }
    *dest = '\0';
    return ptr;
}

int my_strcmp(const char *str1, const char *str2) {
    while (*str1 != '\0' && *str1 == *str2) {
        str1++;
        str2++;
    }
    return *str1 - *str2;
}

char *my_strchr(const char *str, int ch) {
    while (*str != '\0') {
        if (*str == ch) {
            return (char *)str;
        }
        str++;
    }
    return NULL;
}

char *my_strstr(const char *str1, const char *str2) {
    while (*str1 != '\0') {
        const char *p1 = str1;
        const char *p2 = str2;
        while (*p2 != '\0' && *p1 == *p2) {
            p1++;
            p2++;
        }
        if (*p2 == '\0') {
            return (char *)str1;
        }
        str1++;
    }
    return NULL;
}


