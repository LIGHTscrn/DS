#include<stdio.h>

typedef struct node{
    int data;
    struct node* left;
    struct node* right;
}node;

node* root = NULL;

int main(void){
    while(1){
        printf("Enter the element to insert");
        
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
    if(root == NULL){
        printf("Tree is empty");
        return;
    }
    while(current){
        parent = current;
        if(data == (current -> data)){
            break;
        }
        else if(data < (current -> data)){
            current = (current -> left);
        }
        else if(data > (current -> data)){
            current = (current -> right);
        }
    }
    if(current == NULL){
        printf("Element not found");
        return;
    }
    
}