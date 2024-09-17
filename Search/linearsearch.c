#include <stdio.h>

void linearsearch(int arr[], int n, int key);
void Recursive_linearsearch(int arr[], int n, int key);
void Recursive_linearsearch_helper(int arr[], int n, int key, int i);

int main(void)
{
    printf("Linear Search\n");

    printf("Enter the array size: ");// get the size of teh array from user
    int length;
    scanf("%d", &length);

    int LinearSearchArray[length];// declare the array of size length

    printf("Enter the elemnts in the array \n");// initialize the array
    
    for(int i = 0; i< length; i++)
    {
        printf("Index %d : ", i);
        scanf("%d", &LinearSearchArray[i]); // get the elements from the user
    }

    printf("Enter the element to search for : "); // get the element to search for from the user 
    
    int element;
    scanf("%d", &element);
    linearsearch(LinearSearchArray, length, element); // call the linearsearch function
    Recursive_linearsearch(LinearSearchArray, length, element); // call the recursive linearsearch function
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

void Recursive_linearsearch(int arr[], int n, int key)//function to implement linearsearch
{
    Recursive_linearsearch_helper(arr, n, key, 0); // call the helper function
}
void Recursive_linearsearch_helper(int arr[], int n, int key, int i)
{
    if(i == n)
    {
        printf("Element not found\n");
        i=0;
        return;
    }
    if(arr[i] == key)
    {
        printf("Element found at index %d\n", i);
        i=0;
        return;
    }
    i++;
    Recursive_linearsearch_helper(arr,n,key,i);
}