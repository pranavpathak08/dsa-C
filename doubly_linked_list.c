#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node {
    struct Node *prev;
    int data;
    struct Node *next;
};

struct Node* newNode(int value){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->prev = NULL;
    temp->data = value;
    temp->next = NULL;
    return temp;
}

struct Node* insert_at_start(struct Node* head, int value){
    struct Node *new_node = newNode(value);
    new_node->next = head;
    if(head!=NULL){
        head->prev = new_node;
    }
    return new_node;
}

struct Node* insert_at_end(struct Node* head, int value){
    struct Node *new_node = newNode(value);
    struct Node *current = head;
    if(head==NULL){
        return new_node;
    }
    while(current->next!=NULL){
        current = current->next;
    }
    current->next = new_node;
    new_node->prev = current;
    return head;
}

struct Node* insert_after_element(struct Node* head, int target, int value){
    struct Node *new_node = newNode(value);
    struct Node *current = head;
    if(head == NULL){
        printf("Linked List is Empty\n");
        return NULL;
    }
    while(current!=NULL && current->data!=target){
        current = current->next;
    }
    if(current==NULL){
        printf("Element Not Found");
        return head;
    }
    new_node->next = current->next;
    current->next = new_node;
    new_node->prev = current;
    return head;
}

struct Node *insert_before_element(struct Node *head, int target, int value){
    struct Node *current = head;
    struct Node *temp = NULL;
    if(head == NULL){
        printf("Linked List is Empty\n");
        return NULL;
    }
    while(current!=NULL && current->data!=target){
        current = current->next;
    }
    if(current==NULL){
        printf("Element Not Found");
        return head;
    }
    temp = current->prev;
    struct Node *new_node = newNode(value);
    if(current->prev == NULL){
        new_node->next = head;
        head->prev = new_node;
        head = new_node;
        return head;
    }
    temp->next = new_node;
    new_node->prev = temp;
    current->prev = new_node;
    new_node->next = current;

    return head;
}

struct Node* insert_at_specific_pos(struct Node* head, int value, int pos){
    if(head == NULL){
        printf("Linked List is Empty\n");
        return NULL;
    }
    int i = 1;
    struct Node *current = head;
    struct Node *new_node = newNode(value);
    if(pos == 1){
        new_node->next = head;
        head->prev = new_node;
        return new_node;
    }
    while(i < pos && current!=NULL){
        current = current->next;
        i++;
    }
    if(current == NULL || pos == 0){
        printf("Invalid position");
        free(new_node);
        return head;
    }
    current->prev->next = new_node;
    new_node->next = current;
    new_node->prev = current->prev;

    return head;
}

struct Node* delete_at_start(struct Node*head){
    if(head == NULL){
        printf("Linked List is empty!\n");
        return NULL;
    }
    printf("Value deleted is %d", head->data);
    head = head->next;
    return head;
}
struct Node* delete_at_end(struct Node*head){
    if(head == NULL){
        printf("Linked List is Empty\n");
    }
    if(head->next == NULL){
        printf("Value deleted is %d\n", head->data);
        free(head);
        return NULL;
    }
    struct Node *current = head;
    struct Node *temp = NULL;

    while(current->next!=NULL){
        current = current->next;
    }
    printf("Value deleted is %d", current->data);
    temp = current->prev;
    temp->next = NULL;
    free(current);
    return head;
}

struct Node* delete_at_specific_pos(struct Node* head, int pos){
    if(head == NULL){
        printf("Linked List is Empty\n");
        return NULL;
    }
    if(pos == 1){
        head = head->next;
        return head;
    }
    int i = 1;
    struct Node *current = head;

    while(i!=pos && current!=NULL){
        current = current->next;
        i++;
    }
    if(current==NULL || pos == 0){
        printf("Invalid Position\n");
        return NULL;
    }
    printf("Value deleted is %d\n", current->data);
    if(current->next != NULL){
        current->prev->next = current->next;
    }
    else{
        current->prev->next = NULL;
    }
    
    free(current);
    return head;
}

struct Node* delete_after_element(struct Node* head, int target){
    if(head == NULL){
        printf("Linked List is Empty\n");
        return NULL;
    }
    struct Node *current = head;
    struct Node *temp = NULL;
    while(current->next!=NULL && current->data!=target){
        temp = current;
        current = current->next;
    }
    if(current==NULL || current->next == NULL){
        printf("Element Not Found or no node exists after this\n");
        return head;
    }
    printf("Value Deleted is %d\n", current->next->data);
    current->next = current->next->next;
    return head;
}

bool search_linked_list(struct Node* head, int target){
    while(head!=NULL){
        if(head->data == target){
            return true;
        }
        head = head->next;
    }
    return false;
}

void traverse_list(struct Node* head){
    struct Node *current = head;
    while(current!=NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

int main(){
    struct Node *head = NULL;
    int choice, value, target, pos;

    while(1){
        printf("1. Insert Value at the start\n");
        printf("2. Insert Value at end\n");
        printf("3. Insert Value after a specific element\n");
        printf("4. Insert Value before a specific element\n");
        printf("5. Traverse Linked List\n");
        printf("6. Search Element in Linked List\n");
        printf("7. Delete value from the start\n");
        printf("8. Delete value at the end\n");
        printf("9. Delete Value after a specific Element\n");
        printf("10. Delete Value at a specific position\n");
        printf("11. Insert Value at a specific position\n");
        printf("12. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert at the start: ");
                scanf("%d", &value);
                head = insert_at_start(head, value);
                break;
            case 2:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                head = insert_at_end(head, value);
                break;
            case 3:
                printf("After which element you want to insert the value?: ");
                scanf("%d", &target);
                printf("Value you want to insert: ");
                scanf("%d", &value);
                head = insert_after_element(head, target, value);
                break;
            case 4:
                printf("Before which element you want to insert the value?: ");
                scanf("%d", &target);
                printf("Value you want to insert: ");
                scanf("%d", &value);
                head = insert_before_element(head, target, value);
                break;
            case 5:
                traverse_list(head);
                break;
            case 6:
                printf("Enter element you want to search: ");
                scanf("%d", &target);
                if(search_linked_list(head, target)){
                    printf("Element Found\n");
                }
                else{
                    printf("Element Not Found");
                }
                break;
            case 7:
                head = delete_at_start(head);
                break;
            case 8:
                head = delete_at_end(head);
                break;
            case 9:
                printf("After which element you want to delete the value?: ");
                scanf("%d", &target);
                head = delete_after_element(head, target);
                break;
            case 10:
                printf("At which position you want to delete the element?: ");
                scanf("%d", &pos);
                head = delete_at_specific_pos(head, pos);
                break;
            case 11:
                printf("At which position you want to insert the element?: ");
                scanf("%d", &pos);
                printf("What value you want to insert?: ");
                scanf("%d", &value);
                head = insert_at_specific_pos(head, value, pos);
                break;
            case 12:
                printf("Exiting Program");
                exit(0);
                break;
            default:
                printf("Invalid Choice! Enter again: ");
        }
    }
}