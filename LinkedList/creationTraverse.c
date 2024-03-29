// Linked list creation & Traversal

#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

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

    LinkedListTraversal(head);

    return 0;
}
