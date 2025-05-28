/*3. WAP to determine whether the entered character is vowel or not.*/

#include <stdio.h>
#include <ctype.h>

void main(){
    char ch,temp;
    printf("Enter a single character : ");
    scanf("%c",&ch);

    temp = ch;
    ch = tolower(ch);

    if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u'){
        printf("Entered charachter %c is a Vowel.",temp);
    }
    else{
        printf("Entered charachter %c is a Consonant.",temp);
    }
    
}