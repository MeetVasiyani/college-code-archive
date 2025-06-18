#include <stdio.h>
#define MAX_LENGTH 5

int queue[MAX_LENGTH];
int front = -1;
int rear = -1;

void display(){
    if(front == -1){
        printf("Queue is empty.\n");
        return;
    }
    printf("Queue elements: ");
    for(int i = front; i <= rear; i++){
        printf("%d ", queue[i]);
    }
    printf("\n");
}

void enqueue(int value) {
    if(rear == MAX_LENGTH - 1){
        printf("Queue is full. Cannot enqueue.\n");
        return;
    }
    if(front == -1){
        front = 0;
    }
    queue[++rear] = value;
    display();
}

void dequeue() {
    if(front == -1){
        printf("Queue is empty. Cannot dequeue.\n");
        return;
    }
    printf("Dequeued element: %d\n", queue[front]);
    front++;
    if(front > rear){
        front = rear = -1;
    }
    display();
}


void main(){
    int choice, value;
    while(1){
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");    
        printf("Enter your choice: ");
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the value to enqueue: ");
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
                printf("Invalid choice. Try again.\n");
        }
        if(choice == 4){
            break;
        }
    }
}