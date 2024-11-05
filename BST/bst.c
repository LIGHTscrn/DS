#include<stdio.h>
#include<stdlib.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;
void Insert(int data);
void delete(int data);
void inorder(node* root);
void preorder(node* root);
void postorder(node* root);
void search(int data);
node* root = NULL;

int main(void){
    while(1){
        printf("\n1. Insert\n2. Delete\n3. Inorder Traversal\n4. Preorder Traversal\n5. Postorder Traversal\n6.Search\n7. Exit\n");
        int choice;
        scanf("%d", &choice);
        switch(choice){
            case 1:
                printf("Enter the data to be inserted: ");
                int data;
                scanf("%d", &data);
                Insert(data);
                break;
            case 2:
                printf("Enter the data to be deleted: ");
                scanf("%d", &data);
                delete(data);
                break;
            case 3:
                inorder(root);
                break;
            case 4:
                preorder(root);
                break;
            case 5:
                postorder(root);
                break;
            case 6:
                printf("Enter the data to be searched: ");
                scanf("%d", &data);
                search(data);
                break;
            case 7:
                return 0;
            default:
                printf("Invalid choice\n");
        }
        
    }
}

void Insert(int data){
    node* newnode = (node*)malloc(sizeof(node)); //creating the node
    newnode -> left = NULL;
    newnode -> right = NULL;
    newnode -> data = data;
    if(root == NULL){
        root = newnode;
        return;
    }

    node* current = root;
    node* parent = NULL;

    while(current){
        parent = current;
        if(data <= (current->data)){
            current = (current -> left);
        }
        else{
            current = (current -> right);
        }
    }
    if(data <= (parent -> data)){
        parent -> left = newnode;
    }
    else{
        parent -> right = newnode;
    }
}

void delete(int data){
    node* current = root;
    node* parent = NULL;
    
    if(root == NULL){ // If tree is empty
        printf("Tree is empty");
        return;
    }
    
    while(current && current -> data != data){
        parent = current;
        if(data < (current -> data))
            current = (current -> left);
        else
            current = (current -> right);
        
    }
    if(current == NULL){
        printf("Element not found");
        return;
    }
    
    if(current -> left == NULL && current -> right == NULL){// If the node to be deleted is a leaf node
        if(parent == NULL){
            root = NULL;
        }
        else if(parent -> left == current){
            parent -> left = NULL;
        }
        else{
            parent -> right = NULL;
        }
        free(current);
    }
    else if(current -> left == NULL || current -> right == NULL){ // If the node to be deleted has only one child
        node* child = current -> left? current -> left : current -> right;
        if(parent == NULL){
            root = child;
        }
        else if(parent -> left == current){
            parent -> left = child;
        }
        else {
            parent -> right = child;
        }
        free(current);
    } 
    else{ // If the node to be deleted has two children
    
    node* successor = current -> left;
    node* successorParent = current;

    while(successor -> right){
        successorParent = successor;
        successor = successor -> right;
    }
    current -> data = successor -> data;
    if(successorParent -> left == successor){
        successorParent -> left = successor -> left;
    }
    else{
        successorParent -> right = successor -> left;
    }
    free(successor);
}
}
void inorder(node* root){
    if(root == NULL){
        return;
    }
    inorder(root -> left);
    printf("%d ", root -> data);
    inorder(root -> right);

}

void preorder(node* root){
    if(root == NULL){
        return;
    }
    printf("%d ", root -> data);
    preorder(root -> left);
    preorder(root -> right);
}
void postorder(node* root){
    if(root == NULL){
        return;
    }
    postorder(root -> left);
    postorder(root -> right);
    printf("%d ", root -> data);
}

void search(int data){
    node* current = root;
    if(root == NULL){
        printf("Tree is empty");
        return;
    }
    while(current && current -> data != data){
        if(data < current -> data){
            current = current -> left;
        }
        else{
            current = current -> right;
        }
    }
    if(current == NULL){
        printf("Element not found");
    }
    else{
        printf("Element found");
    }
}