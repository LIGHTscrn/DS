#include <stdio.h>

typedef struct tuple
{
    char* row;
    char* col;
    char* value;
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
            if(matrix[i][j] != 0)
            {
                count++;
            }
        }
    }  
    // number of 0s should be greater than half the total number of elements in the matrix for it to be sparse

    if( count >= (rows * cols)/2 )
    {
        printf("The given matrix is not a sparse matrix\n ");
        return 0;
    }

    //since the matrix is a sparse matrix the following code will execute  
    tuple sparsematrix[count + 1];

    sparsematrix[0].row = "rows";
    sparsematrix[0].col = "cols";
    sparsematrix[0].value = "Value";

    int k = 1;

    for(int i = 0; i < rows; i++)
    {
        for(int j = 0; j < cols; j++)
        {
            if(matrix[i][j] != 0)
            {
                sparsematrix[k].row = i;
                sparsematrix[k].col = j;
                sparsematrix[k].value = matrix[i][j];
                k++;
            }
        }
    }

    printf("The tuple representation of the sparse matrix is: \n");

    for(int i = 0 ; i < k; i++)
    {
        printf("%d %d %d\n", sparsematrix[i].row, sparsematrix[i].col, sparsematrix[i].value);
    }

    return 0;
}