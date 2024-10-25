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
    int n, nm, i, j;

    scanf("%d%d", &n, &nm);

    A = (struct Student*)malloc(n*sizeof(struct Student));

    for(i=0; i<n; i++)
    {
        (*(A+i)).mark = (float*)malloc(nm*sizeof(float));
        for(j=0; j<nm; j++)
        {
            scanf("%f", ((*(A+i)).mark)+j);
        }
    }

    for(i=0; i<n; i++)
    {
        for(j=0; j<nm; j++)
        {
            printf("%f ", (*(((*(A+i)).mark)+j)));
        }
    }
    return 0;
}


