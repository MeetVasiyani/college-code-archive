/*48. Write a menu driven program to implement following operations on the 
Doubled Ended Queue using an Array 
• Insert at front end, Insert at rear end 
• Delete from front end, Delete from rear end 
• Display all elements of the queue */

#include<stdio.h>
#define MAX_LENGTH 5

int queue[MAX_LENGTH];
int front = -1;
int rear = -1;

void display(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void enqueueRear(int value){
    if(rear == MAX_LENGTH - 1){
        printf("Queue is full\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear++;
    queue[rear] = value;
    display();
}

void enqueueFront(int value){
    if(front == 0){
        printf("Queue is full\n");
        return;
    }
    if(front == -1){
        front = 0;
        rear = 0;
    }
    else{
        for(int i = rear; i >= front; i--){
            queue[i+1] = queue[i];
        }
        rear++;
    }
    queue[front] = value;
    display();
}

void dequeueFront(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    if(front == rear){
        printf("Dequeued element: %d\n", queue[front]);
        front = -1;
        rear = -1;
    }
    else{
        printf("Dequeued element: %d\n", queue[front]);
        front++;
    }
    display();
}

void dequeueRear(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    if(front == rear){
        printf("Dequeued element: %d\n", queue[rear]);
        front = -1;
        rear = -1;
        return;
    }
    printf("Dequeued element: %d\n", queue[rear]);
    rear--;
    display();
}

void main(){
    int choice, value;
    while(1){
        printf("1. Insert at front end\n");
        printf("2. Insert at rear end\n");
        printf("3. Delete from front end\n");
        printf("4. Delete from rear end\n");
        printf("5. Display all elements of the queue\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueueFront(value);
                break;
            case 2:
                printf("Enter the value to be inserted: ");
                scanf("%d", &value);
                enqueueRear(value);
                break;
            case 3:
                dequeueFront();
                break;
            case 4:
                dequeueRear();
                break;
            case 5:
                display();
                break;
            case 6:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        if(choice == 6){
            break;
        }
    }
}