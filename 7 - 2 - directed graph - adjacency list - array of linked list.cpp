#include<stdio.h>
#include<stdlib.h>

struct G* createG(struct G *g, int numOfVartex);
void addEdge(struct G *g, int sV, int dV);
void printfG(struct G *g);

struct ALN
{
    int dV;
    struct ALN *next;
};

struct AL
{
    struct ALN *head;
};

struct G
{
    int numOfV;
    struct AL *adjA;
};

int main()
{
    struct G *g;
    int choice, numOfV, sV, dV;

    while(1)
    {
        printf("###########################################");
        printf("\n1. Create G\n2. Add Edge\n3. Read G\n4. Delete Edge\n5. Exit.\n");
        printf("\nEnter a choice: ");
        scanf("%d", &choice);

        switch(choice)
        {
            case 1:
                printf("Enter numer of vetices: ");
                scanf("%d", &numOfV);
                g = createG(g, numOfV);
                break;
            case 2:
                printf("Enter source and destination: ");
                scanf("%d", &sV);
                scanf("%d", &dV);
                addEdge(g, sV, dV);
                break;
            case 3:
                printfG(g);
                break;
            case 4:
                //deleteEdge();
                break;
            case 5:
                exit(1);
                break;
            default:
                printf("Enter the right choice..!");
        }
    }
    return 0;
}

struct G* createG(struct G *g, int numOfV)
{
    g = (struct G*)malloc(sizeof(struct G));
    g->numOfV = numOfV;

    g->adjA = (struct AL*)malloc(numOfV*sizeof(struct AL));

    for(int i=0; i<g->numOfV; i++)
    {
        g->adjA[i].head = NULL;
    }

    printf("A G has been created with a AL for %d vertices.\n", numOfV);
    return g;
}


void addEdge(struct G *g, int sV, int dV)
{
    struct ALN *node1;
    node1 = (struct ALN*)malloc(sizeof(struct ALN));

    //adjA[sV] -> node for dV
    node1->dV = dV;
    node1->next = g->adjA[sV].head;
    g->adjA[sV].head = node1;

}

void printfG(struct G *g)
{
    for(int i=0; i<g->numOfV; i++)
    {
        struct ALN *temp = g->adjA[i].head;

        if(temp){ printf("\nAdjacency List of Vertex %d:\n", i); }
        while(temp != NULL)
        {
            printf("%d - %d ",i, temp->dV);
            temp = temp->next;
        }
    }
    printf("\n");
}

















