/*23. WAP to sort the N names in an alphabetical order. */
#include <stdio.h>
#include <string.h>

void main(){
    int n;
    printf("Enter number of names:");
    scanf("%d",&n);
    char names[n][10];
    char temp[10];
    
    for (int i = 0; i < n; i++){
        printf("Enter name: ");
        scanf("%s", &names[i]);
    }
    
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(names[i],names[j])>0){
                strcpy(temp,names[i]);
                strcpy(names[i],names[j]);
                strcpy(names[j],temp);
            }
        }
    }

    printf("\nSorted List : ");
    for(int i=0;i<n;i++){
        printf("%s ",names[i]);
    }
}