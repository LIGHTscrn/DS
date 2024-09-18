#include<stdio.h>

void bubblesort(int array[], int length);

int main(void)
{
    int x[] = {100, 21, 30, 4, 67};

    bubblesort(x , 5);

    for(int i = 0; i < 5; i++)
    {
        printf("%d ", x[i]);
    }

    return 0;
}

void bubblesort(int array[], int length)
{
    int temp;
    for(int i = 0; i < length; i++)
    {
        for(int j = 0; j < length - i; j++)
        {
            if(array[j] > array[j+1])
            {
                temp = array[j+1];
                array[j+1] = array[j];
                array[j] = temp;
            }
        }
    }
}