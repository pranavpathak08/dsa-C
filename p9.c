#include<stdio.h>
#include<stdlib.h>
# define N 10

int queue[N];
int front = -1;
int rear = -1;

int isFull(){
    if(front == 0 && rear == N-1){
        return 1;
    }
    else
        return 0;
}
int isEmpty(){
    if(rear == -1 && front == -1){
        return 1;
    }
    return 0;
}
int Dequeue(){
    if(isEmpty()){
        printf("Queue is Empty");
        exit(1);
    }
    else if(front == rear){
        int item = queue[front];
        front = -1;
        rear = -1;
        return item;
    }
    else{
        int item = queue[front];
        front = front + 1;
        return item;
    }
}
void Enqueue(){
    int item;
    if(isFull()){
        printf("Queue is Full");
        exit(1);
    }
    else if(rear == N-1 && front!=0){
        int c = 0;
        for (int i = front; i < rear;i++){
            queue[c] = queue[i];
            c++;
        }
        front = 0;
        rear = c - 1;
    }
    else{
        printf("Enter element to be inserted: ");
        scanf("%d", &item);
        rear = rear + 1;
        queue[rear] = item;
    }
}
void display(){
    if(isEmpty()){
        printf("Queueis empty");
    }
    else{
        printf("Queue Elements\n");
        for (int i = front; i <= rear;i++){
            printf("%d ", queue[i]);
        }
    }
}

int main(){
    int choice;
    while (1) {
        printf("\nQueue Operations:\n");
        printf("1. Enqueue\n");
        printf("2. Dequeue\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: Enqueue(); break;
            case 2: printf("Popped element: %d\n", Dequeue()); break;
            case 3: display(); break;
            case 4: exit(0);
                break;
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}