#include <stdio.h>

int main(void)
{

    return 0;
}

void linearsearch(int arr[], int n, int key)// function to implement linearsearch taking arguments (array[], array length, element to serach)
{
    for(int i = 0; i < n; i++)
    {
        if(arr[i] == key)
        {
            printf("Element found at index %d\n", i);
            return;
        }
    }
    printf("Element not found\n");
}