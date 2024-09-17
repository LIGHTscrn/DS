#include <stdio.h> // the header files
#include <stdlib.h> //required for implementing the scan function

int pop();         // function prototypes
int push(int);
int display();
                    //quality of life features
int scan(char*);
void clear();

#define MAXSIZE 10
int stackArray[MAXSIZE]; // the stack array of size MAXSIZE

int top = -1; // defining the top pointer to keep track of stack overflow/underflow, 
                        //(not actually a pointer variable)

int main(int argc, char* argv[]){   // main function
    
    return 0;
}

int pop(){
    // checking underflow condition
    if(top == -1)
    {
        printf("stack is empty");
        return 0;
    }
    else
    {
        int item = stackArray[top]; //storing the element to be deleted in an varialbe

        stackArray[top--] = 0; // replacing the value at top index of array to 0 and decrementing top

        printf("DELETED : %d ", item);

        return 0; //returning the deleted element
    }
    return 1;
}

int push(int item){
    if(top == MAXSIZE - 1) // checking overflow condition
    {
        printf("\nThe Stack is Full\n");
        return 0;
    }
    else
    {
        stackArray[++top] = item; // inserting the item  at array index of top after incrementing it
        printf("Inserted: %d", item);
        return 0;
    }
    return 1;
}

int display(){

    if(top == -1)
    {
        printf("Stack is empty");
        return 0;
    }
    else
    {
        for(int i = top; i > -1; i--)
        {
            printf("%d : %d \n", i , stackArray[i]);
        }
        return 0;
    }
    return 1;
}

void clear(){
    system("clear");
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