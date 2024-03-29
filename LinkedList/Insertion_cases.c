// insertion at different cases

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void traversal(struct Node *ptr) //*ptr is a pointer of the same struct Node type so it will point the nodes which is of its own type
{
    int i = 1;
    while (ptr != NULL)
    {
        printf("Element in node %d is : %d \n", i, ptr->data);
        ptr = ptr->next;
        i++;
    }
}

// A function is created that returns a struct node* i.e. a head

// Case 1
struct Node *insertAtFirst(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Case 3
struct Node *insertAtEnd(struct Node *head, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;
    struct Node *p = head; // P pointing head

    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;

    return head;
}

// Case 4
struct Node *insertAfterNode(struct Node *head, struct Node *prevNode, int data)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr; // Ptr is the new Node

    return head;
}

// Case 2
struct Node *insertAtIndex(struct Node *head, int data, int index)
{
    struct Node *ptr = (struct Node *)malloc(sizeof(struct Node));
    struct Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

int main()
{
    struct Node *head;   // We had is a struct Node type of a pointer which will hold the access to an address's value
    struct Node *second; // These are pointers that are pointing to the heap so that memory can be allocated dynamically
    struct Node *third;
    struct Node *fourth;
    struct Node *fifth;

    // We'll insert more nodes later

    // We'll allocate memory to each of the nodes whose pointers we declared earlier

    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(sizeof(struct Node));
    third = (struct Node *)malloc(sizeof(struct Node));
    fourth = (struct Node *)malloc(sizeof(struct Node));
    fifth = (struct Node *)malloc(sizeof(struct Node));

    // The linking begins now
    // We'll link the head to the second first

    head->data = 10;
    head->next = second;

    // Linking of the second node to the third

    second->data = 12;
    second->next = third;

    // Linking the 3rd node to the 4th

    third->data = 345;
    third->next = fourth;

    // the 4th node will be the terminating/last node of the whole list

    fourth->data = 450;
    fourth->next = fifth;

    // inserting the 5th element
    fifth->data = 6969;
    fifth->next = NULL;

    // NOw we will write the code for traversal before the main function and call the function here

    printf("\n linked list before insertion\n");
    traversal(head); // We call the funtion and assign the ptr pointer to the head from where the traversal will begin
    printf("\n");
    // head = insertAtFirst(head, 56);
    // head =insertAtIndex(head, 96, 3);

    //head = insertAtEnd(head, 169 );

    head = insertAfterNode(head, third, 999);
    printf("\n Linked list after insertion\n");
    traversal(head);

    return 0;
}