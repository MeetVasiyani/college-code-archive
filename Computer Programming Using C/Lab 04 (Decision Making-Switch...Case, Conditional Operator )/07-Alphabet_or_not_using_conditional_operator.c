//Check whether character is an alphabet or not using conditional operator.
#include <stdio.h>
void main(){
    char c;
    printf("Enter a charachter :");
    scanf("%c",&c);
    (c>='A' && c<='Z' || c>='a' && c<='z')?printf("Entered symbol is a charachter"):printf("Entered symbol is not a charachter");
}