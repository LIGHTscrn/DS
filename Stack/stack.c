#include <stdio.h> // the header files


int pop();         // function prototypes
int push(int);
int display();
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

int push(int){
    //TODO push function
    
    return 1;
}

int display(){
    //TODO display function
    return 1;
}

void clear(){
    //TODO clear function
}