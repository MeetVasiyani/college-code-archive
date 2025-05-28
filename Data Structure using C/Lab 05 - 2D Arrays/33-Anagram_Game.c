/*33. Design anagram game using array.  
• Allow a user to enter N words and store it in an array.  
• Generate a random number between 0 to N-1.  
• Based on the random number generated display the word stored at that 
index of an array and allow user to enter its anagram.  
• Check whether the word entered by the user is an anagram of displayed 
number or not and display an appropriate message.  
• Given a word A and word B. B is said to be an anagram of A if and only if 
the characters present in B is same as characters present in A, 
irrespective of their sequence. For ex: “LISTEN” == “SILENT”. */

#include<stdio.h>
#include<string.h>
#include <time.h>
#include <stdlib.h>

void main(){
    
    int n;
    printf("How many words do you want to enter? : ");
    scanf("%d",&n);
    
    char words[n][100];

    for(int i = 0; i < n; i++){
        printf("Enter word %d : ",i+1);
        scanf("%s",words[i]);
    }

    srand(time(0));
    int random = rand() % n;

    printf("Word Selected : %s\n",words[random]);

    printf("Enter Anagram for the selected word : ");
    char anagram[100];
    scanf("%s",anagram);

    int c1[26] = {0};
    int c2[26] = {0};

    for(int i = 0; i < strlen(words[random]); i++){
        c1[words[random][i] - 'a']++;
        c2[anagram[i] - 'a']++;
    }

    int flag = 1;
    for(int i = 0; i < 26; i++){
        if(c1[i] != c2[i]){
            flag = 0;
            break;
        }
    }
    
    if(flag){
        printf("Given word is an Anagram\n");
    }
    else{
        printf("Given word is not an Anagram\n");
    }
}