#include<stdio.h>
#include<stdlib.h>

int main()
{
    int n, i, *A;

    printf("how much element: ");
    scanf("%d", &n);

    A = (int*)malloc(n*sizeof(int));

    printf("Input:");
    for(i=0; i<n; i++)
    {
        scanf("%d", (A+i)); //(A+i) same to &A[i]
    }

    printf("\nOutput: \n");
    for(i=0; i<n; i++)
    {
        printf("%d ", *(A+i));// *(A+i) same to A[i]
    }

    return 0;
}
