/*40. Utkarsh has recently started taking English-language classes to improve his 
reading and writing skills. However, he is still struggling to learn English. His 
teacher gave him the following problem to improve his vowel-identification 
skills:  
 
There is a string S of length N consisting of lowercase English letters only.  
Utkarsh has to start from the first letter of the string. 
Each time he encounters a vowel; he has to reverse the entire substring that 
came before the vowel. 
Utkarsh needs help verifying his answer. Can you print the final string after 
performing all the operations for him? 
 
Input Format: 
• First line will contain T, number of test cases. Then T test cases follow. 
• The first line of each test case contains N, the length of the string. 
• The second line contains S, the string itself. 
 
Output Format: 
For each test case, output in a single line the final string after traversing S from 
left to right and performing the necessary reversals.
*/


#include <stdio.h>
#include <string.h>

#define MAX 1000


void reverse(char stack[], int start, int end) {
    while (start < end) {
        char temp = stack[start];
        stack[start] = stack[end];
        stack[end] = temp;
        start++;
        end--;
    }
}

void main() {
    char str[MAX];
    printf("Enter a string: ");
    scanf("%s", str);

    char stack[MAX];
    int top = -1;

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];
        if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
            reverse(stack, 0, top);
        }
        top++;
        stack[top] = str[i];
    }

    stack[top + 1] = '\0';

    printf("%s\n", stack);

}
