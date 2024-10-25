#include<stdio.h>
#include<stdlib.h>

struct Student
{
    int id;
    float mark[3];
};

int main()
{
    struct Student *A;
    int n, i;

    scanf("%d", &n);

    A = (struct Student*)malloc(n*sizeof(struct Student));

    for(i=0; i<n; i++)
    {
        scanf("%d", &(*(A+i)).id);// &(*(A+i)).id as like as &(A+i)->id
    }

    for(i=0; i<n; i++)
    {
        printf("%d ", (*(A+i)).id);// (*(A+i)).id as like as (A+i)->id
    }

    return 0;
}
