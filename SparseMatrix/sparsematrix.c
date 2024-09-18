#include <stdio.h>

typedef struct tuple
{
    int row;
    int col;
    int value;
}tuple;

int main(void)
{
    int rows , cols, count = 0;

    printf("Enter the number of rows of the matrix: ");
    scanf("%d", &rows);

    printf("Enter the number of columns of the matrix: ");
    scanf("%d", &cols);

    int matrix[rows][cols];

    printf("Enter the matrix elements: \n");

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            printf("Matrix[i][j]: ");
            scanf("%d", &matrix[i][j]);
            if(matrix[i][j] == 0)
            {
                count++;
            }
        }
    }  

    if( count <= (rows * cols)/2 )
    {
        printf("The given matrix is not a sparse matrix\n ");
        return 0;
    }

    //since the matrix is a sparse matrix the following code will execute  

}