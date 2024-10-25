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

int insert_first(int item) {    //#3
    // write your code here

    if(!(is_full()))   // isFull returns 0 if not full for what we reverse the returned value to insert.
    {
        int i=0;
        for(i = length-1; i>=0;i--)
        {
            arr[i+1] = arr[i];      // right shift all data from last to first.
        }
        arr[i+1] = item;    // now we are able to insert at first as the first is already right shifted.
        length++;

        printf("Returns 1\n");
        printf("ArrayList: \n");
        print();
        return 1;
    }
    printf("Returns 0\n");
    printf("ArrayList: \n");
    print();
    return 0;;
}

int insert_last(int item) {
    // write your code here

    if(!(is_full()))
    {
        arr[length] = item;
        length++;

        printf("Returns 1\n");
        printf("ArrayList: \n");
        print();
        return 1;
    }

    printf("Returns 0\n");
    printf("ArrayList: \n");
    print();
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

int search(int item) {
    // write your code here
    int i=0;
    for(i=0; i<length; i++)
    {
        if(item == arr[i])    // item will be checked with all data
        {
            return i;   // returning founded index of item.
        }
    }
    return -1;
}

int remove_first() {
    // write your code here
    if(!(is_empty()))     // returned 0 if the arr is empty for what we reversed it to delete.
    {
        int i=0;
        for(i=0; i<length; i++)
        {
            arr[i] = arr[i+1];    // left shift all data from index 0 to length
        }
        length--; // decrease the length by 1

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

int remove_last() {
    // write your code here
    if(!(is_empty()))
    {
        arr[length-1] = 0;
        length--;     // last index is automatically removed by this line.

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

int remove_item_first(int item) {
    // write your code here
    int check = remove_at(0);   // first index removing as the item is first item
}

int remove_item_last(int item) {
    // write your code here
    remove_at(length-1); // last index removing as the item is last item
}

int remove_item_all(int item) {
    // write your code here
    int pos = search(item);    // find pos of the item
    if(pos != -1)
    {
        remove_at(pos);    // if the item is found, deleting the pos of that item.
    }
    else
    {
        printf("Data not found\n");
    }
}

int replace(int old_item, int new_item) {
    // write your code here
    int i, flag=0;

    for(i=0; i<length; i++)
    {
        if(old_item == arr[i])   // check for those data in arr which is matched with old item
        {
            arr[i] = new_item;   // replace founded all old_data by new_item
            flag = 1;
        }
    }

    if(flag == 1)
    {
            printf("Return 1\n");
            printf("ArrayList:\n");
            print();
            return 1;
    }
    else
    {

            printf("Return 0\n");
            printf("ArrayList:\n");
            print();
            return 0;
    }
}

void clear() {
    // write your code here
    int i;
    for(i=0; i<length; i++)
    {
        remove_last();
        i--;
    }
    printf("--------------------------\n");
    print();
    printf("This print function will not print anything. Because, The array is empty\n");
}

int main() {
    init(); // initializes the arraylist first
    // test your functions here

    insert_first(10);        // output: 10

    printf("\n\n");
    insert_first(20);        // output: 20 10
    printf("\n\n");
/*
    insert_last(30);         // output: 20 10 30
    printf("\n\n");
    insert_last(40);         // output: 20 10 30 40
    printf("\n\n");


    insert_at(50, 0);        // output: 50 20 10 30 40
    printf("\n\n");
    insert_at(60, length); // output: 50 20 10 30 40 60
    printf("\n\n");
    insert_at(70, 1);        // output: 50 70 20 10 30 40 60
    printf("\n\n");


    int pos = search(20);
    printf("%d is at index %d", 20, pos);
    printf("\n\n");


    remove_first();         // output: 70 20 10 30 40 60
    printf("\n\n");

    remove_last();          // output: 70 20 10 30 40
    printf("\n\n");

    remove_at(0);           // output: 20 10 30 40
    printf("\n\n");
    remove_at(length-1);    // output: 20 10 30
    printf("\n\n");
    remove_at(1);           // output: 20 30
    printf("\n\n");

    insert_last(20);        // output: 20 30 20
    printf("\n\n");

    replace(20, 10);        // output: 10 30 10
    printf("\n\n");
*/
    clear();


    return 0;
}




