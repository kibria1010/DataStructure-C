#include <stdio.h>
#include <stdlib.h>
#define NULL 0

typedef struct Node{
    int data;
    struct Node* next;
    struct Node* prev;
} Node;
Node* head;
Node* tail;
int length;

void init() {
    head = NULL;
    tail = NULL;
    length = 0;
}

void insert_first(int item) {
    // allocate memory for a newNode using malloc which return void type pointer of
    // Node is casted to Node and stored to a pointer of Node named new_node
    Node* new_node = (Node*)malloc(sizeof(Node));
    /*        0R(new_node
        +---+----+---+
        |   |    |   |
        +---+----+---+
    */
    new_node->data = item;
    /*        0R(new_node)
        +---+----+---+
        |   |item|   |
        +---+----+---+
    */
    new_node->prev = NULL;
    new_node->next = head;
    /*         0R(newNode)
        +----+----+----+       Assumed that, it is the first and last node.
        |null|item|null|
        +----+----+----+
    */
    if(head != NULL) // if there is more than one data in the list
        head->prev = new_node;  //store the address of new_node to prev of head.
    else
        tail = new_node;   // if there is no data in the list
    head = new_node;
    /*  head          0R(newNode)
        +----+  +----+----+----+
        |0R  |  |null|item|null|
        +----+  +----+----+----+
    */
    length++;
}

void insert_last(int item) {
    // allocate memory for a newNode using malloc which return void type pointer of
    // Node is casted to Node and stored to a pointer of Node named new_node
    Node* new_node = (Node*)malloc(sizeof(Node));
    /* head           0R               1R (newNode)
       +----+  +----+----+----+ +----+----+----+
       | 0R |  |null|item|null| |    |    |    |
       +----+  +----+----+----+ +----+----+----+
    */
    // 2. store item as data of corresponding newNode
    new_node->data = item;
    /* head           0R               1R (newNode)
       +----+  +----+----+----+ +----+----+----+
       | 0R |  |null|item|null| |    |item|    |
       +----+  +----+----+----+ +----+----+----+
    */
    new_node->next = NULL;
    new_node->prev = tail;
    /* head           0R              1R (newNode)
       +----+  +----+----+----+ +----+----+----+
       | 0R |  |null|item|null| | 0R |item|null|
       +----+  +----+----+----+ +----+----+----+
    */
    if(tail != NULL)
        tail->next = new_node;
        /* head           0R              1R (newNode)
           +----+  +----+----+----+ +----+----+----+
           | 0R |  |null|item| 1R | | 0R |item|null|
           +----+  +----+----+----+ +----+----+----+
        */
    else
        head = new_node;
    tail = new_node;
    length++;
}

void insert_at(int item, int pos) {
    if(pos<0 || pos>length) {
        return;
    }
    if(pos == 0) {
        insert_first(item);
        return;
    }
    else if(pos == length)
    {
        insert_last(item);
        return;
    }
    else {
        //*********insert at a particular pos*********
        //1. allocate memory for a newNode
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        /* head           0R             2R(newNode)        1R
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
           | 0R |  |null|item| 1R | |    |    |    | | 0R |item|null|
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
        */
        //2. store item in the corresponding data of the newNode.
        newNode->data = item;
        /* head           0R             2R(newNode)        1R
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
           | 0R |  |null|item| 1R | |    |item|    | | 0R |item|null|
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
        */
        //Now find the (N-1)th node.
        struct Node* temp = head;    //temp = 0R
        int i=0;

        while(i < pos-1) { //1. 0 < (1-1) or 0<0(f)  //assume that index is 1 to insert.

            temp = temp->next;
            i++;
        }
        // after loop, temp is stored by the address of (N-1)th node. //temp = 0R

        newNode->next = temp->next;
        /* head           0R             2R(newNode)        1R
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
           | 0R |  |null|item| 1R | |    |item| 1R | | 0R |item|null|
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
        */
        newNode->prev = temp;
        /* head           0R             2R(newNode)        1R
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
           | 0R |  |null|item| 1R | | 0R |item| 1R | | 0R |item|null|
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
        */

        temp->next->prev = newNode;
        /* head           0R             2R(newNode)        1R
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
           | 0R |  |null|item| 1R | | 0R |item| 1R | | 2R |item|null|
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
        */
        temp->next = newNode;
        /* head           0R             2R(newNode)        1R
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
           | 0R |  |null|item| 2R | | 0R |item| 1R | | 2R |item|null|
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
        */

    }
    length++;
}


int search(int key) {
    // Write your code here
    struct Node* temp = head;
    int index=0;
    //(until temp is not equal to null)
    //update temp with the address of next node
    while(temp != NULL) {  // until last node ref is not stored

        if(temp->data == key) // check key with all data sequentially
        {
            break;
        }
        // update temp with the address of next node
        temp = temp->next;
        index++;
    }

    /* last node ref is stored in temp only when key is not found
    as we used break if found.*/
    if(temp == NULL)
    {
        return -1;
    }
    else  // it means the key is found
    {
        return index;
    }

}


void delete_first() {
    // Write your code here
    if(head == NULL) // head is null only when there is no data
    {
        printf("List is empty. there is nothing to delete");
        return;
    }
    else if( head->next == NULL) // if one data exists
    {
        free(head);
        head = NULL;
        tail = NULL;
    }
    else   // there is more than one data
    {
        struct node *temp = head;
        head = head->next;        // head next is storing with the ref of 2nd node which is first node after this.
        /* head           0R             2R                 1R
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
           | 2R |  |null|item| 2R | | 0R |item| 1R | | 2R |item|null|
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
        */
        head->prev = NULL;
        /* head           0R             2R                1R
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
           | 2R |  |null|item| 2R | |null|item| 1R | | 2R |item|null|
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
        */
        free(temp);
        /* head            2R               1R
           +----+   +----+----+----+ +----+----+----+
           | 2R |   |null|item| 1R | | 2R |item|null|
           +----+   +----+----+----+ +----+----+----+
        */
    }
    length--;
}


void delete_last() {
    // Write your code here
    if(head == NULL)
    {
        printf("List is empty. there is nothing to delete");
        return;
    }

    else if(head->next == NULL)  // if there is only one data
    {
        delete_first();
        return;
    }
    else            // if there is more than one data
    {
        struct Node *temp = tail;//temp(1R) tail(1R)

        tail->prev->next = NULL; // store null at the next ref of the previous of last node
        tail = tail->prev;       //tail(2R)
        /* head           0R             2R                 1R
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
           | 2R |  |null|item| 2R | | 0R |item|null| | 2R |item|null|
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
        */
        free(temp);
        /* head           0R               2R
           +----+  +----+----+----+ +----+----+----+
           | 2R |  |null|item| 2R | | 0R |item|null|
           +----+  +----+----+----+ +----+----+----+
        */
        length--;
    }
}


void delete_at(int pos) {
    // Write your code here
     if(pos<0 || pos>length) {
        return;
    }
    if(pos == 0) {           // first node has to deleted
        delete_first();
        return;
    }
    else if(pos == length-1) // last node has to deleted
    {
        delete_last();
        return;
    }
    else        // node between first node and last node
    {
        struct Node* temp = head, *temp1;
        int i=0;
        while(i < pos-1) {    // stop at previous node of the Nth node.

            temp = temp->next;
            i++;
        }
        // after loop, temp is stored by the address of (N-1)th node

        temp1 = temp->next;    //temp(0R)
        temp->next->next->prev = temp;
        /* head           0R             2R                 1R
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
           | 2R |  |null|item| 2R | | 0R |item|1R  | | 0R |item|null|
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
        */
        temp->next = temp->next->next;
        /* head           0R             2R                 1R
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
           | 2R |  |null|item| 1R | | 0R |item|1R  | | 0R |item|null|
           +----+  +----+----+----+ +----+----+----+ +----+----+----+
        */
        free(temp1);
        /* head           0R                 1R
           +----+  +----+----+----+  +----+----+----+
           | 2R |  |null|item| 1R |  | 0R |item|null|
           +----+  +----+----+----+  +----+----+----+
        */
    }
    length--;
}

void delete_item(int item) {
    int index = search(item);
    if(index != -1) //if the item is founded as search function return -1 when not founded
    {
        delete_at(index);
    }
}

void print() {
    Node* temp = head;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

void print_back() {
    Node* temp = tail;
    while(temp!= NULL) {
        printf("%d ", temp->data);
        temp = temp->prev;
    }
    printf("\n");
}

int main() {
    init();

    insert_last(30);
    print();          // 30
    print_back();     // 30

    insert_last(20);
    print();          // 30 20
    print_back();     // 20 30

    insert_last(10);
    print();          // 30 20 10
    print_back();     // 10 20 30

    insert_at(40, 1);
    print();             // 30 40 20 10
    print_back();        // 10 20 40 30

    int pos = search(40);
    printf("40 found at %d\n", pos);  // 40 founded at pos 2

    delete_first();
    print();             // 40 20 10
    print_back();        // 10 20 40

    delete_last();
    print();             // 40 20
    print_back();        // 20 40

    delete_at(1);
    print();             // 40
    print_back();        // 40

    delete_at(0);
    printf("List is empty ...!");
    print();             //
    print_back();        //

    return 0;
}
