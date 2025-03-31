#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *next;
};

struct Node *newNode(int data){
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp;
}

struct Node* traverse_list(struct Node* head){
    struct Node *current = head;
    if(current == NULL){
        printf("Linked List is Empty");
    }
    while(current!=NULL){
        printf("%d ", current->data);
        current = current->next;
    }
}

struct Node* insert_at_end(struct Node* head, int value){
    struct Node *new_node = newNode(value);
    struct Node *current = head;
    if(head == NULL){
        return new_node;
    }
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = new_node;
    return head;
}

struct Node* swap_pair_wise(struct Node* head){
    struct Node *current = head;
    while (current != NULL && current->next != NULL) {
        int temp = current->data;
        current->data = current->next->data;
        current->next->data = temp;
        
        current = current->next->next;
    }
    return head;
}

int list_length(struct Node* head){
    struct Node *current = head;
    int ctr = 0;
    while(current!=NULL){
        ctr++;
        current = current->next;
    }
    return ctr;
}

int main(){
    struct Node *head = NULL;

    for (int i = 1; i < 10;i++){
        head = insert_at_end(head, i);
    }
    traverse_list(head);
    int length = list_length(head);
    head = swap_pair_wise(head);
    printf("\n");
    traverse_list(head);
    return 0;
}