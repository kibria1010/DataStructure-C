#include<stdio.h>
#include<stdlib.h>
struct Student
{
    int id;
    float *mark;
};

int main()
{
    struct Student *A;
    int n, i, j;

    scanf("%d", &n);

    A = (struct Student*)malloc(sizeof(struct Student));
    (*A).mark = (float*)malloc(n*sizeof(float));

    for(i=0; i<n; i++)
    {
        scanf("%f", (*A).mark+i);
        //scanf("%f", A->mark+i);
    }
    for(i=0; i<n; i++)
    {
        printf("%f ", *((*A).mark+i));
        //printf("%f ", *(A->mark+i));
    }

    return 0;
}


