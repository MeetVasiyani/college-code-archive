/*30. WAP to replace lowercase characters by uppercase & vice-versa in a user 
specified string.*/

#include <stdio.h>
#include <string.h>

void main(){
    char str[100];
    printf("Enter a string: ");
    gets(str);

    for(int i = 0; i < strlen(str); i++){
        if(str[i] >= 97){
            str[i] = str[i] - 32;
        }
        else{
            str[i] = str[i] + 32;
        }
    }

    printf("Switched String : ");
    puts(str);
}