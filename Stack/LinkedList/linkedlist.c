#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    int data;
    struct node* next;
}node;

node* top = NULL;

//function prototypes

int scan(char*);
void push(int);
void pop();
void display();
void peek();

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
                    int element = scan("\nEnter the element: ");
                    push(element);
                }
                break;
            
            case 2:
                {
                    pop();
                }
                break;
            
            case 3:
                {
                    display();
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

void pop(){
    if(top == NULL)
    {
        printf("\nStack is empty\n");
        return;
    }

    node* temp = top;
    top = top->next;
    free(temp);
}

void display(){
    if(top == NULL)
    {
        printf("\nStack is empty\n");
        return;
    }

    node* temp = top;
    while(temp != NULL)
    {
        printf("%d\n", temp->data);
        temp = temp->next;
    }
}
void peek()
{
    if(top == NULL)
    {
        printf("\nStack is empty\n");
        return;
    }

    node* temp = top;
    int count=0;
    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
    printf("\nThe top element is %d\n", top->data);
    printf("The number of elements in the stack is %d\n", count);
}

int scan(char* s)
{
    char buffer[100];
    printf("%s",s);

    if(fgets(buffer, sizeof(buffer),stdin) != NULL)
    {
        return atoi(buffer);
    }
}