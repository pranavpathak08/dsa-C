#include<stdio.h>
#include<stdlib.h>

#define N 10
int top=-1;
int arr[N];

int isFull(){
    if(top == N - 1){
        return 1;
    }
    else
        return 0;
}

int isEmpty(){
    if(top == -1){
        return 1;
    }
    else
        return 0;
}
void push(){
    if(isFull()){
        printf("Stack if Full");
    }
    else{
        int item;
        printf("Enter element to push: ");
        scanf("%d", &item);
        top = top + 1;
        arr[top] = item;
    }

}
int pop(){
    int item;
    if(isEmpty()){
        printf("Stack is Empty");
        exit(1);
    }
    else{
        item = arr[top];
        top = top - 1;
    }
    return item;
}
void display(){
    if(isEmpty()){
        printf("Stack is empty");
    }
    else{
        printf("Stack elements\n");
        for (int i = top; i >= 0;i--){
            printf("%d ", arr[i]);
        }
    }
    
}
int main(){
    int choice;
    while (1) {
        printf("\nStack Operations:\n");
        printf("1. Push\n");
        printf("2. Pop\n");
        printf("3. Display\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1: push(); break;
            case 2: printf("Popped element: %d\n", pop()); break;
            case 3: display(); break;
            case 4: exit(0);
            default: printf("Invalid choice! Try again.\n");
        }
    }
    return 0;
}