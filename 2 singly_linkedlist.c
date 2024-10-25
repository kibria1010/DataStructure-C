#include <stdio.h>
#include <stdlib.h>
#define NULL 0

struct Node {
    int data;
    struct Node* next;
};

struct Node* head;
int length;

void init() {
    head = NULL;
    length = 0;
}

void insert_first(int item) {

    /*1. allocate memory using malloc for a node at runtime => malloc(sizeof(struct Node));
     which return a void pointer which is casted by the type of node in order
     to store the address in a variable of node named newNode*/
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    //2. store item in the data of the newNode
    newNode->data = item;

    //3. store reference in the *next of the newNode.
    newNode->next = head;

    //4. change head
    head = newNode;

    // increment length by 1 after inserting a node.
    length++;
}

void insert_last(int item) {

    if(head == NULL) { //if the list is emty
        insert_first(item);
        return;
    }
    //----------------------insertLast
    // 1.  allocate memory and store the ref in newNode.
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

    // 2. store item in the data of corresponding newNode
    newNode->data = item;

    // 3. store reference in the next of corresponding newNode.
    newNode->next = NULL;


    // 4. store the address of newNode (2R) to the reference of last node of the list.
    /*
     head         1R            0R            2R newNode
                  data next      data next     data next
    +---+         +---+---+     +---+---+     +----+----+
    | 1R|         | # | 0R|     | # |null     | #  | null
    +---+         +---+---+     +---+---+     +----+----+
    */

    //initialize the address of first node (head) to temp
    struct Node* temp = head;       // temp = 1R

    //(until temp is stored by the address of last node)
    //update temp with the address of next node
    while(temp->next != NULL) { //1. 1R->next != NULL => 0R != NULL (true)
                                //2. 0R->next != NULL => NULL != NULL (FALSE)
        // update temp with the address of next node
        temp = temp->next;      //1. temp = 1R->next => temp = 0R
    }
    //--------------------------temp = 0R
    temp->next = newNode;   //0R->next = newNode => 0R->next = 2R
        /*
     head         1R            0R            2R newNode
                  data next      data next     data next
    +---+         +---+---+     +---+---+     +----+----+
    | 1R|         | # | 0R|     | # | 2R|     | #  | null
    +---+         +---+---+     +---+---+     +----+----+
    */
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
        //------------------insert at a particular pos
        //1. allocate memory for a newNode
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));

        //2. store item in the corresponding data of the newNode.
        newNode->data = item;

        //4. store the address of newNode to the ref of Nth node.
        /*//3. store the address of Nth node to the ref of newNode.
         head         1R            0R            2R
                      data next      data next     data next
        +---+         +---+---+     +---+---+     +----+----+
        | 1R|         | # | 0R|     | # | 2R|     | #  | null
        +---+         +---+---+     +---+---+     +----+----+
        */
        struct Node* temp = head;    //temp = 1R
        int i=0;

        while(i < pos-1) {      //1. 0 < (2-1) or 0<1

            temp = temp->next;  // temp = 1R->next or temp = 0R
            i++;                //i=1
        }
        // after loop, temp is stored by the address of (N-1)th node
        newNode->next = temp->next;  // newNode->next = (0R->next )(2R)
        temp->next = newNode;        // temp->next = newNode or 0R->next =
        /*head         1R            0R            3R newNode   2R
                      data next      data next     data next    data next
        +---+         +---+---+     +---+---+     +---+---+    +----+----+
        | 1R|         | # | 0R|     | # | 3R|     | # | 2R|    | #  | null
        +---+         +---+---+     +---+---+     +---+---+    +----+----+
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
    else   // there is at least one data
    {
        struct node *temp = head;
        head = head->next;        // head is storing with the ref of 2nd node which is first node after this.
        free(temp);
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
    else
    {
        struct Node* temp = head, *temp1;

        while(temp->next->next != NULL) { //stop at the previous node of last node
            temp = temp->next;
        }

        temp1 = temp->next;
        temp->next = NULL; // store null at the ref of the previous of last node
        free(temp1);
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
        while(i < pos-1) {    // stop at previous node of the node of pos

            temp = temp->next;
            i++;
        }
        // after loop, temp is stored by the address of (N-1)th node
        temp1 = temp->next;
        temp->next = temp->next->next;
        free(temp1);
        /*head         1R            0R            3R newNode   2R
                      data next      data next     data next    data next
        +---+         +---+---+     +---+---+     +---+---+    +----+----+
        | 1R|         | # | 0R|     | # | 3R|     | # | 2R|    | #  | null
        +---+         +---+---+     +---+---+     +---+---+    +----+----+
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

void insert_before(int oldItem, int newItem) {
    // Write your code here
    int index = search(oldItem);
    if(index != -1)//if the item is founded by oldItem as search function return -1 when not founded
    {
        insert_at(newItem, index);
    }
}

void insert_after(int oldItem, int newItem) {
    // Write your code here
    int index = search(oldItem);
    if(index != -1) //if the item is founded as search function return -1 when not founded
    {
        insert_at(newItem, index+1);
    }
}

void print() {
    struct Node* temp = head;
    while(temp != NULL) {
        printf("%d ", temp->data);
        temp = temp->next;
    }
    printf("\n");
}

int main() {
    init();

    insert_first(10);
    printf("List: ");
    print();             // 10

    insert_last(20);
    printf("List: ");
    print();             // 10 20

    insert_first(30);
    printf("List: ");
    print();             // 30 10 20

    insert_at(40, 2);
    printf("List: ");
    print();             // 30 10 40 20

    int pos = search(40);
    printf("40 found at %d\n", pos);  // 40 founded at pos 2

    delete_first();
    printf("List: ");
    print();             // 10 40 20

    delete_last();
    printf("List: ");
    print();             // 10 40

    delete_at(1);
    printf("List: ");
    print();             // 10

    insert_before(10, 20);
    printf("List: ");
    print();             // 20 10

    insert_after(10, 30);
    printf("List: ");
    print();             // 20 10 30

    delete_item(10);
    printf("List: ");
    print();             // 20 30

    return 0;
}


