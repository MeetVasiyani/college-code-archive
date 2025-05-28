/**/

#include <stdio.h>
#define MAX_SIZE 1000

int stack[MAX_SIZE];
int top = -1;

void push(int value){
    if(top == MAX_SIZE - 1){
        printf("Stack Overflow\n");
        return;
    }
    stack[++top] = value;
}

int pop(){
    if(top == -1){
        return -1;
    }
    return stack[top--];
}

int peek() {
    if (top == -1) return -1;
    return stack[top];
}

int main(){
    int n;
    printf("Enter number of elements in A: ");
    scanf("%d", &n);

    int A[MAX_SIZE], B[MAX_SIZE];
    int bIndex = 0;

    printf("Enter elements of array A:\n");
    for(int i = 0; i < n; i++){
        scanf("%d", &A[i]);
    }

    int nextExpected = 1;

    int i = 0;
    while (i < n || top != -1) {
        if (i < n) {
            push(A[i]);
            i++;
        }

        while (top != -1 && (bIndex == 0 || peek() >= B[bIndex - 1])) {
            int temp = pop();
            B[bIndex++] = temp;
        }
    }

    int sorted = 1;
    for (int j = 1; j < bIndex; j++) {
        if (B[j] < B[j - 1]) {
            sorted = 0;
            break;
        }
    }

    if (sorted) {
        printf("YES, it is possible to sort array B in ascending order.\n");
    } else {
        printf("NO, it is not possible to sort array B in ascending order.\n");
    }

    return 0;
}
