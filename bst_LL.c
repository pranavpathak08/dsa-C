#include<stdlib.h>
#include<stdio.h>

struct Node{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node* create_node(int value){
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));
    new_node->left = NULL;
    new_node->right = NULL;
    new_node->data = value;
    return new_node;
}

struct Node* insertNode(struct Node* root, int value){
    
    struct Node *new_node = create_node(value);
    if(root == NULL){
        root = new_node;
        return root;
    }
    if(value > root->data){
        root->right = insertNode(root, value);
    }
    else if(value < root->data){
        root->left = insertNode(root, value);
    }
    return root;
}

struct Node* deleteNode(struct Node* root, int value){
    if(value > root->data){
        root->right = deleteNode(root, value);
    }
    else if(value < root->data){
        root->left = deleteNode(root, value);
    }
    
}


int main(){
    struct Node *root = NULL;

}
