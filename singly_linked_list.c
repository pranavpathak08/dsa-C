#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct Node{
    int data;
    struct Node* next;
};
//Function to create a new node
struct Node* newNode(int data){
    struct Node *temp = (struct Node*)malloc(sizeof(struct Node));
    temp->data = data;
    temp->next = NULL;
    return temp; //Returning pointer to the newly created node
}
//Function to traverse and print the elements of the linked list
void traverseLinkedList(struct Node* head){
    struct Node *current = head;

    if(current==NULL){
        printf("Linked List is Empty\n");
    }

    while(current!=NULL){
        printf("%d ", current->data);
        current = current->next;
    }
    printf("\n");
}

bool searchLinkedList(struct Node* head, int target){
    while(head!=NULL){
        if(head->data == target){
            return true;
        }
        head = head->next;
    }
    return false;
}

struct Node* insert_at_beginning(struct Node* head, int value){
    struct Node* new_node = newNode(value);
    new_node->next = head;
    return new_node;
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

struct Node* insert_after_element(struct Node* head, int target, int value){
    struct Node *current = head;

    while(current!=NULL && current->data!=target){
        current = current->next;
    }
    if(current == NULL){
        printf("Element not found\n");
        return head;
    }
    struct Node *new_node = newNode(value);
    new_node->next = current->next;
    current->next = new_node;

    return head;
}
struct Node* insert_before_element(struct Node* head, int target, int value){
    //Case 1:
    if(head == NULL){
        printf("List is Empty\n");
        return head;
    }

    //Case 2: Inserting before the first node
    if(head->data == target){
        struct Node *new_node = newNode(value);
        new_node->next = head;
        return new_node;    
    }

    struct Node *current = head;
    while(current->next!=NULL && current->next->data!=target){
        current = current->next;
    }
    if(current->next == NULL){
        printf("Element not found in the list\n");
    }
    struct Node *new_node = newNode(value);
    new_node->next = current->next;
    current->next = new_node;

    return head;
}

struct Node* delete_at_start(struct Node* head){
    if(head == NULL){
        printf("Linked List is Empty\n");
    }
    struct Node *current = head;
    printf("Value deleted is %d\n", current->data);
    head = head->next;
    free(current);
    return head;
}

struct Node* delete_at_end(struct Node* head){
    if(head == NULL){
        printf("Linked List is Empty\n");
    }
    if(head->next==NULL){
        printf("Value deleted is: %d\n", head->data);
        free(head);
        return NULL;
    }
    struct Node *current = head;
    struct Node *prev = NULL;
    while(current->next!=NULL){
        prev = current;
        current = current->next;
    }
    printf("Value deleted is %d\n", current->data);
    prev->next = NULL;
    free(current);
    return head;
}

struct Node* delete_after_element(struct Node* head, int target){
    if (head == NULL) {
        printf("Linked List is Empty\n");
        return NULL;
    }
    struct Node *current = head;

    while (current != NULL && current->data != target) {
        current = current->next;
    }

    if (current == NULL || current->next == NULL) {
        printf("No Node exists after this element or Element Not Found\n");
        return head;
    }
    struct Node* temp = current->next;
    printf("Value deleted is: %d\n", temp->data);
    current->next = temp->next;
    free(temp);
    return head;

}

struct Node* delete_before_element(struct Node* head, int target){
    if(head == NULL){
        printf("Linked List is Empty\n");
    }
    if(head->next == NULL){
        head = delete_at_start(head);
    }
    if(head->next->next == NULL){
        printf("Value deleted is: %d", head->data);
        head = head->next;
        return head;
    }
    if(target == head->data){
        printf("It is the first element\n");
    }
    struct Node *current = head;
    struct Node *prev = NULL;
    while(current!=NULL && current->next->next->data!=target){
        current = current->next;
    }
    printf("Value deleted is: %d\n", current->next->data);
    prev = current;
    prev->next = current->next->next;
    return head;
}

int main(){
    struct Node *head = NULL;
    int choice, value, target;

    while(1){
        printf("Menu for Linked List Operations\n");
        printf("1. Insert value at start\n");
        printf("2. Insert value at the end\n");
        printf("3. Insert value after a given element\n");
        printf("4. Insert value before a given element\n");
        printf("5. Search value in the linked list\n");
        printf("6. Display the linked list\n");
        printf("7. Delete value at the start\n");
        printf("8. Delete value at the end\n");
        printf("9. Delete after element\n");
        printf("10. Delete before element\n");
        printf("11. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                printf("Enter value to insert at the start: ");
                scanf("%d", &value);
                head = insert_at_beginning(head, value);
                break;
            case 2:
                printf("Enter value to insert at the end: ");
                scanf("%d", &value);
                head = insert_at_end(head, value);
                break;
            case 3:
                printf("After which element you want to insert value?: ");
                scanf("%d", &target);
                printf("Enter value you want to insert: ");
                scanf("%d", &value);
                head = insert_after_element(head, target, value);
                break;
            case 4:
                printf("Before which element you want to insert value?: ");
                scanf("%d", &target);
                printf("Enter value you want to insert: ");
                scanf("%d", &value);
                head = insert_before_element(head, target, value);
                break;
            case 5:
                printf("Enter the value you want to search: ");
                scanf("%d", &target);
                if(searchLinkedList(head, target)){
                    printf("Element Found in the list\n");
                }
                else{
                    printf("Element not found in the list\n");
                }
                break;
            case 6:
                traverseLinkedList(head);
                break;
            case 7:
                head = delete_at_start(head);
                break;
            case 8:
                head = delete_at_end(head);
                break;
            case 9:
                printf("After which element you want to delete the value?");
                scanf("%d", &target);
                head = delete_after_element(head, target);
                break;
            case 10:
                printf("Before which element you want to delete the value?");
                scanf("%d", &target);
                head = delete_before_element(head, target);
                break;
            case 11:
                printf("Exiting Program");
                exit(0);
                break;
            default:
                printf("Invalid Choice! Please Enter again");
        }
    }
    
    return 0;
}

