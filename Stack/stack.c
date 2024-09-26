#include <stdio.h> // the header files
#include <stdlib.h> //required for implementing the scan function

int pop();         // function prototypes
int push(int item);
int display();
void peek();
                    //quality of life features
int scan(char*);

#define MAXSIZE 10
int stackArray[MAXSIZE]; // the stack array of size MAXSIZE

int top = -1; // defining the top pointer to keep track of stack overflow/underflow, 
                        //(not actually a pointer variable)

int main(int argc, char* argv[])
{   // main function
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
                    
                    int x = push(element);
                    
                    if(x == 1)
                    {
                    
                        printf("\nStack Overflow\n");
                    }
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
}

int pop(){
    // checking underflow condition
    if(top == -1)
    {
        return 1;
    }
    else
    {
        int item = stackArray[top]; //storing the element to be deleted in an varialbe

        stackArray[top--] = 0; // replacing the value at top index of array to 0 and decrementing top

        printf("DELETED : %d \n", item);

        return 0; //returning the deleted element
    }
}

int push(int item){
    if(top == MAXSIZE - 1) // checking overflow condition
    {
        return 1;
    } else {
        stackArray[++top] = item; // inserting the item  at array index of top after incrementing it
        printf("Inserted: %d\n", item);
        return 0;
    }
    return 1;
}

int display(){

    if(top == -1)
    {
        return 1;
    }
    else
    {
        printf("Stack Contents\n");
        for(int i = top; i > -1; i--)
        {
            printf("%d : %d \n", i + 1, stackArray[i]);
        }
        return 0;

    }
}
int scan(char* s)
{ 
    char buffer[100];

    printf("%s :", s);

    if(fgets(buffer, sizeof(buffer), stdin) != NULL)
    {
        return atoi(buffer);
    }
   
    return -1;
}

void peek()
{
    if(top != -1)
    {
        printf("%d\n", stackArray[top]);
    }
    else
    {
        printf("Stack is empty top = %d\n", top);
    }
}