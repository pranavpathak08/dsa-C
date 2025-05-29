#include<stdio.h>
#include<stdlib.h>

struct Node {
    int info;
    struct Node *left;
    struct Node *right;
};

struct Node *create(int item) {
    struct Node *temp = (struct Node *)malloc(sizeof(struct Node));
    temp->info = item;
    temp->left = NULL;
    temp->right = NULL;

    return temp;
}

struct Node *insertNode(struct Node* root, int item) {
    if(root == NULL) {
        return create(item);
    }
    if(item < root->info) {
        root->left = insertNode(root->left, item);
    }
    else if(item > root->info) {
        root->right = insertNode(root->right, item);
    }
    return root;
}

void search(struct Node *root, int item) {
    if(root == NULL) {
        printf("The tree is empty");
        return;
    }
    struct Node *loc = root;
    while(loc != NULL) {
        if(item == loc->info) {
        printf("Element found");
        return;
        }
        if(item < loc->info) {
            loc = loc->left;
        }
        else{
            loc = loc->right;
        }
    }
    printf("Element Not Found \n");
}

struct Node *findMin(struct Node *root) {
    while(root  && root->left != NULL) {
        root = root->left;
    }
    return root;
}

struct Node *deleteNode(struct Node *root, int item) {
    if(root == NULL) {
        printf("Tree is empty");
        return NULL;
    }
    if(item < root->info) {
        root->left = deleteNode(root->left, item);
    }
    else if(item > root->info) {
        root->right = deleteNode(root->right, item);
    }
    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            return NULL;
        }
        else if(root->left == NULL) {
            struct Node *temp = root->right;
            free(root);
            return temp;
        }
        else if(root->right == NULL) {
            struct Node *temp = root->left;
            free(root);
            return temp;
        }

        struct Node *successor = findMin(root->right);
        root->info = successor->info;
        root->right = deleteNode(root->right, successor->info);
    }
    return root;
}


void inorder(struct Node *root) {
    if(root != NULL) {
        inorder(root->left);
        printf("%d ", root->info);
        inorder(root->right);
    }
}

int main() {
    struct Node *root = NULL;
    root = insertNode(root, 20);
    insertNode(root, 50);
    insertNode(root, 60);
    insertNode(root, 55);
    insertNode(root, 70);

    inorder(root);
    deleteNode(root, 60);
    printf("\n");
    inorder(root);
}