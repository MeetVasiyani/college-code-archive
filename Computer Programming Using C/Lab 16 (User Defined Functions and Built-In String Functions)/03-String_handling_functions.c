/*Use string handling functions strlen(), strcmp(), strcpy(), strcat(), strrev(), strlwr() and strupr()*/
#include <stdio.h>
#include <string.h>

int main() {
    char str1[100], str2[100];
    
    printf("Enter the first string: ");
    fgets(str1, 100, stdin);
    str1[strcspn(str1, "\n")] = 0;

    printf("Enter the second string: ");
    fgets(str2, 100, stdin);
    str2[strcspn(str2, "\n")] = 0;

    int len1 = strlen(str1);

    int cmp = strcmp(str1, str2);

    strcpy(str2, str1);

    strcat(str1, str2);

    strrev(str1);

    strlwr(str1);

    strupr(str2);

    printf("\nLength of the first string: %d\n", len1);
    printf("Comparison result: %d (0 for equal, positive for str1 > str2, negative for str1 < str2)\n", cmp);
    printf("Copied string: %s\n", str2);
    printf("Concatenated string: %s\n", str1);
    printf("Reversed string: %s\n", str1);
    printf("Lowercase string: %s\n", str1);
    printf("Uppercase string: %s\n", str2);

    return 0;
}

