#include <stdio.h>

int arr[100];
int size = 100;
int length;

void init() {
    length = 0;
}

void print() {
    for(int i=0; i<length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int is_full() {
    // write your code here
    if(length == size-1)    //#1 -> array is full if the length is 99(size-1)
    {
        return 1;
    }

    return 0;
}

int is_empty() {
    // write your code here
    if(length == 0) //#2 -> array is empty if the length is 0
    {
        return 1;
    }
    return 0;
}

int insert_at(int item, int pos) {
    // write your code here
    if(!(is_full()))
    {
        if(pos>-1 && pos<size)    // check pos between 0 and 99
        {
            int i=0;
            for(i = length-1; i>=pos;i--)
            {
                arr[i+1] = arr[i];  // right shift all from last to pos
            }
            arr[i+1] = item;
            length++;

            printf("Returns 1\n");
            printf("ArrayList: \n");
            print();
            printf("Returns 1\n");
            return 1;
        }
        else
        {
                printf("pos is not valid.\n");
        }
    }

    printf("Returns 0\n");
    printf("ArrayList: \n");
    print();
    return 0;
}

int remove_at(int pos) {
    // write your code here
    if(!(is_empty()))
    {
        int i=0;
        for(i=pos; i<length; i++)
        {
            arr[i] = arr[i+1];
        }
        length--;

        printf("Return 1\n");
        printf("ArrayList:\n");
        print();
        return 1;
    }
    printf("Return 0\n");
    printf("ArrayList:\n");
    print();
    return 0;
}

void enqueue(int item)
{
    insert_at(item, length);
}

void dequeue()
{
    remove_at(0);
}

int main() {
    init(); // initializes the arraylist first
    // test your functions here

    enqueue(10);    // output: 10             <=10
    printf("\n\n");
    enqueue(20);    // output: 10 20          <=20
    printf("\n\n");
    enqueue(30);    // output: 10 20 30       <=30
    printf("\n\n");


    //---------------------------------------------
    dequeue();       // output: 20 30           =>10
    printf("\n\n");

    dequeue();       // output: 30              =>20
    printf("\n\n");

        dequeue();   // output:                 =>30
    printf("\n\n");

    return 0;
}




