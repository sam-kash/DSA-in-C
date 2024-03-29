//Including DELETION MAIN
// Linked list creation & Traversal

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};
// Case 1: Deleting first element
struct Node* Deletefirst(struct Node *head) 
{
    struct Node* ptr = head;
    head = head -> next;
    free (ptr);
    return head;
}

//Case 2: Delete at Index
struct Node* deleteAtIndex(struct Node* head, int index)
{
    struct Node* p = head;
    struct Node* q = head ->next;

    for (int i=0; i< index-1; i++)    // Index cant be 0
    {
        p = p -> next;
        q = q -> next;
    }

    p -> next = q->next;
    free(q);
    return head;
}

//Case 3 : Delete last node

struct Node* DeleteLast(struct Node* head)
{
    struct Node* p = head;
    struct Node* q = head->next ;

    while (q-> next != NULL)
    { 
        p = p->next;
        q = q->next;
    }

    p-> next = NULL;
    free(q);
    return head;
}

// Case 4 : Delete with a value
struct Node* DeleteWithValue(struct Node* head, int value)
{
    struct Node* p = head;
    struct Node* q = head ->next;

    while(q -> data != value && q->next!= NULL) // We're  not terminating because we got the value, we're terminating because q reached NULL
    {
        p = p -> next;
        q = q -> next;
    }

    if(q -> data == value) // Because of the last condition we need to see if the last node has our value or not
    {
        p -> next = q -> next;
        free(q);
    }
    return head;
}


void LinkedListTraversal(struct Node *ptr)
{
    while (ptr != NULL)
    {
        printf("Element : %d\n", ptr->data);
        ptr = ptr->next;
    }
}

int main()
{
    struct Node *head;
    struct Node *second;
    struct Node *third;
    struct Node *fourth;

    // Allocated memory of nodes in linked list in the heap
    head = (struct Node *)malloc(sizeof(struct Node));
    second = (struct Node *)malloc(1 * sizeof(struct Node));
    third = (struct Node *)malloc(1 * sizeof(struct Node));
    fourth = (struct Node *)malloc(1 * sizeof(struct Node));

    // Linking head and second node

    head->data = 7;
    head->next = second;

    // Linking second and third node

    second->data = 8;
    second->next = third;

    // Inserting extra node as an element

    third->data = 69;
    third->next = fourth;

    // Terminating linked list after the fourth node

    fourth->data = 9;
    fourth->next = NULL;

    printf("Deletion before deletion : \n");

    LinkedListTraversal(head);

    // head = Deletefirst(head); //Function call for deleting 1st node of the linked list

    //head = deleteAtIndex(head , 2); // Case 2

    //head = DeleteLast(head); //Case 3

    head = DeleteWithValue(head , 69);

    printf("Linked list after deletion : \n");
    LinkedListTraversal(head);  // IT will be changed

    return 0;
}
