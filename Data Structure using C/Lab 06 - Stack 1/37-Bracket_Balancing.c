/*37. Chef has a string which contains only the characters '{', '}', '[', ']', '(' and ')'.  
Now Chef wants to know if the given string is balanced or not.  
If is balanced then print 1, otherwise print 0.  
A balanced parenthesis string is defined as follows: 
• The empty string is balanced 
• If P is balanced then (P), {P}, [P] is also balanced 
• if P and Q are balanced PQ is also balanced 
• "([])", "({})[()]" are balanced parenthesis strings  
• "([{]})", "())" are not balanced. 
 
Input Format:  
The first line of the input contains a single integer T denoting the number of 
test cases. The description of T test cases follows. The first and only line of 
each test case contains a single string 
 
Output Format:  
For each test case, print a single line containing the answer. 

Sample Example: 
 
Output: 
1 
0 
1 
0 

Input:
4 
() 
([)] 
([{}()])[{}] 
[{{}] 
*/

#include <stdio.h>
#include <string.h>
#define MAX_SIZE 100

char stack[MAX_SIZE];
int top = -1;

void push(char value){
    if(top == MAX_SIZE - 1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

char pop(){
    if(top == -1){
        printf("Stack Underflow\n");
        return -1;
    }
    return stack[top--];
}

void main(){
    char str[MAX_SIZE];
    printf("Enter a string of parentheses: ");
    scanf("%s", str);
    top = -1;
    int balanced = 1;
    for(int i = 0; i < strlen(str); i++){
        if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
            push(str[i]);
        } else if(str[i] == ')'){
            if(top == -1 || pop() != '('){
                balanced = 0;
                break;
            }
        } else if(str[i] == ']'){
            if(top == -1 || pop() != '['){
                balanced = 0;
                break;
            }
        } else if(str[i] == '}'){
            if(top == -1 || pop() != '{'){
                balanced = 0;
                break;
            }
        }
    }
    if(top != -1){
        balanced = 0;
    }
    printf("%d\n", balanced);
}





/*
void main(){
    int T;
    scanf("%d", &T);
    while(T--){
        char str[MAX_SIZE];
        scanf("%s", str);
        top = -1;
        int balanced = 1;
        for(int i = 0; i < strlen(str); i++){
            if(str[i] == '(' || str[i] == '[' || str[i] == '{'){
                push(str[i]);
            } else if(str[i] == ')'){
                if(top == -1 || pop() != '('){
                    balanced = 0;
                    break;
                }
            } else if(str[i] == ']'){
                if(top == -1 || pop() != '['){
                    balanced = 0;
                    break;
                }
            } else if(str[i] == '}'){
                if(top == -1 || pop() != '{'){
                    balanced = 0;
                    break;
                }
            }
        }
        if(top != -1){
            balanced = 0;
        }
        printf("%d\n", balanced);
    }
    
}
*/