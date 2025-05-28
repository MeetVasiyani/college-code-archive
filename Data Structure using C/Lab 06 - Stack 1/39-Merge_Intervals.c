/*
39. Given a set of time intervals in any order, our task is to merge all overlapping 
intervals into one and output the result which should have only mutually 
exclusive intervals. 
 
Sample Example-1: 
Input: Intervals = {{1,3},{2,4},{6,8},{9,10}} 
Output: {{1, 4}, {6, 8}, {9, 10}} 
Explanation: Given intervals: [1,3],[2,4],[6,8],[9,10], we have only two overlapping 
intervals here,[1,3] and [2,4]. Therefore we will merge these two and return [1,4],[6,8], 
[9,10] 
 
Sample Example-2: 
Input: Intervals = {{6,8},{1,9},{2,4},{4,7}} 
Output: {{1, 9}}
*/

#include <stdio.h>

int stack[100][2];
int top = -1;

void mergeOrPush(int start, int end){
    if(top == -1 || stack[top][1] < start){
        top++;
        stack[top][0] = start;
        stack[top][1] = end;
    }
    else{
        if(stack[top][1] < end){
            stack[top][1] = end;
        }
    }
}


void main(){

    int n;
    printf("Enter number of intervals: ");
    scanf("%d", &n);

    int arr[n][2];
    for (int i = 0; i < n; i++) {
        printf("Enter start of interval %d: ", i + 1);
        scanf("%d", &arr[i][0]);
        printf("Enter end of interval %d: ", i + 1);
        scanf("%d", &arr[i][1]);
    }

    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i][0] > arr[j][0]) {
                int temp1 = arr[i][0], temp2 = arr[i][1];
                arr[i][0] = arr[j][0];
                arr[i][1] = arr[j][1];
                arr[j][0] = temp1;
                arr[j][1] = temp2;
            }
        }
    }

    for (int i = 0; i < n; i++) {
        mergeOrPush(arr[i][0], arr[i][1]);
    }

    printf("Merged Intervals: ");
    for (int i = 0; i <= top; i++) {
        printf("[%d, %d] ", stack[i][0], stack[i][1]);
    }

}