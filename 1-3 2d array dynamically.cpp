#include<stdio.h>
#include<stdlib.h>

int main()
{
    int **A, row, col, i, j;

    printf("how much row and col: ");
    scanf("%d%d",&row, &col);

    A = (int**)malloc(row*sizeof(int*));

    for (i=0; i<row; i++)
    {
        *(A+i)=(int*)malloc(col*sizeof(int));
    }

    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            scanf("%d", (*(A+i)+j));
        }
    }

    for (i=0; i<row; i++)
    {
        for (j=0; j<col; j++)
        {
            printf("%d ", *(*(A+i)+j));
        }
        printf("\n");
    }

    return 0;
}

