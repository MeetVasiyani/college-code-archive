/*47. Write a menu driven program to implement following operations on a circular 
queue using an Array 
• Insert 
• Delete 
• Display all elements of the queue*/

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
    printf("Queue elements: ");
    int i = front;
    while(i != rear){
        printf("%d ", queue[i]);
        i = (i + 1) % MAX_LENGTH;
    }
    printf("%d\n", queue[rear]);
}

void enqueue(int value){
    if((rear + 1) % MAX_LENGTH == front){
        printf("Queue is full\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    rear = (rear + 1) % MAX_LENGTH;
    queue[rear] = value;

    display();
}

void dequeue(){
    if(front == -1){
        printf("Queue is empty\n");
        return;
    }
    if(front == rear){
        printf("Element deleted: %d\n", queue[front]);
        front = rear = -1;
    }
    else{
        printf("Element deleted: %d\n", queue[front]);
        front = (front + 1) % MAX_LENGTH;
    }

    display();
}

void main(){
    int choice, value;
    while(1){
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                enqueue(value);
                break;
            case 2:
                dequeue();
                break;
            case 3:
                display();
                break;
            case 4:
                break;
            default:
                printf("Invalid choice\n");
                break;
        }
        if(choice == 4){
            break;
        }
    }
}