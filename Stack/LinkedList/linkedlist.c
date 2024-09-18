#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* top = NULL;

int main() {

    // copy paste from stack.c

    printf("Stack\n");


    while(1)
    {
        printf("\n1: Push \t2: Pop \t3: Display \t4: Peek \t5:Exit\n");// menu driven function for user interaction
        int choiceA = scan("\nEnter your choice");

        switch(choiceA)
        {
            case 1:
                {
                    int element = scan("\nEnter the element");
                    push(element);
                }
                break;
            
            case 2:
                {
                    int x = pop();
                    if(x == 1)
                    {
                        printf("\nStack Underflow\n");
                    }
                }
                break;
            
            case 3:
                {
                    int x = display();
                    if(x == 1)
                    {
                        printf("\nStack underflow\n");
                    }
                }
                break;
            
            case 4:
                {
                    peek();
                }
                break;

            case 5:
                {
                    printf("\nExiting . . . . .  done \n");
                    return 0;
                }

            default:
                {
                    printf("\nInvalid choice\n");
                }
                break;
        }   
    }
    return 0;
    // pasted till here ^
}

void push( int x ){

    node* newnode = (node*)malloc(sizeof(node));
    if(!newnode)
    {
        printf("Memory allocation failed\n");
        return;
    }

    newnode->data = x;
    newnode->next = top;
    top = newnode;
}