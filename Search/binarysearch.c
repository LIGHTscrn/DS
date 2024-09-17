#include<stdio.h>

void sortArray(int array[], int n);
void binarysearch(int array[], int n, int key);
void Recursive_binary_search(int array[], int n, int key, int low, int high);


int main(void)
{
                                        // copy of the initial code from linearsearch.c
    printf("BinarySearch\n");

    printf("Enter the array size: ");// get the size of teh array from user
    int length;
    scanf("%d", &length);

    int BinarySearchArray[length];// declare the array of size length

    printf("Enter the elemnts in the array \n");// initialize the array
    
    for(int i = 0; i< length; i++)
    {
        printf("Index %d : ", i);
        scanf("%d", &BinarySearchArray[i]); // get the elements from the user
    }

    printf("Enter the element to search for : "); // get the element to search for from the user 
    
    int element;
    scanf("%d", &element);
    sortArray(BinarySearchArray,length);
    binarysearch(BinarySearchArray, length, element);
    Recursive_binary_search(BinarySearchArray, length, element, 0, length - 1);
    return 0;
}

void binarysearch(int array[], int n, int key)
{
    int low = 0;
    int high = n -1;
    
    if(low > high)
    {
        printf("Element not found\n");
        return;
    }
    while(low <= high)
    {
        int mid = (low+high)/2;
        if(array[mid] == key)
        {
            printf("Element found at index %d\n", mid);
            return;
        }
        else if(array[mid] < key)
        {
            low = mid + 1;
        }
        else
        {
            high = mid - 1;
        }
    }
}

void Recursive_binary_search(int array[], int n, int key, int low, int high)
{
    if(low > high)
    {
        printf("Element not found\n");
        return;
    }
    int mid = (low + high)/2;

    if(array[mid] == key)
    {
        printf("Element found at index %d\n", mid);
        return;
    }
    else if(array[mid] < key)
    {
        Recursive_binary_search(array, n, key, mid+1, high);
    }
    else
    {
        Recursive_binary_search(array, n, key, low, mid-1);
    }
}

void sortArray(int array[], int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if(array[j] > array[j+1])
            {
                int temp = array[j];
                array[j] = array[j+1];
                array[j+1] = temp;
            }
        }
    }
    
}
