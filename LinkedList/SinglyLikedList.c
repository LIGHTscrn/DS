#include<stdio.h>
#include<stdlib.h>

typedef struct Node {
    int data;
    struct node *next;
} Node;

Node *head = NULL;

int main(int argc , char * argv[])
{
    printf("Linked List\n");
    int data;
    while(1){
        printf("Insert \n");
        printf("1.At the Beginning \t 2.At the End \t 3.At specific location\n");
        printf("Delete \n");
        printf("4.At the Beginning \t 5.At the End \t 6.At specific location\n");
        printf("7.Display \t 8.Exit\n");
        int choice;       
        printf("Enter your choice : ");
        scanf("%d",&choice);
        switch(choice){
            case 1:
                printf("Enter the data : ");
                scnaf("%d",&data);
                insertAtBeginning(data);
        }
         }
   return 0;
}

void insertAtBeginning(int data){
    Node *newnode = (Node *)malloc(sizeof(Node));
    if(newnode == NULL){
        printf("Memory not allocated\n");
        return;
    }
    newnode -> data = data;
    newnode -> next = head;
    head = newnode;
}