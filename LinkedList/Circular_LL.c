#include<stdio.h>
#include<stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

void LinkedListTraversal(struct Node *head)
{
    struct Node* ptr = head;

    // printf("Element is %d\n", ptr -> data);
    //     ptr = ptr -> next;

    // while (ptr != head)   //Just writing this while loop wont work because ptr is already equal to head at that moment
    // {
    //     printf("Element is %d\n", ptr -> data);
    //     ptr = ptr -> next;
    // } 
    //WE CAN USE THE ABOVE CODE TOO BUT LETS SEE A DIFFERENT APPROACH, Basically for the kickstart

    
     //Just writing this while loop wont work because ptr is already equal to head at that moment
    do{
        printf("Element is %d\n", ptr -> data);  //In dp while loop the conditon will be checked after the loop has performed 1 iteration
        ptr = ptr -> next;
    } while (ptr != head) ;
}

struct Node * insertAtFirst(struct Node* head, int data)
{
    struct Node* ptr = (struct Node*)malloc(sizeof(struct Node));
    struct Node * p= head -> next;
    ptr -> data = data;

    while(p->next != head)
    {
        p = p->next;
    }
    //At this point P is pointing to the last node of the circular LL

    p -> next = ptr;
    ptr -> next = head;
    head = ptr;
    //ptr = head;
    return head;
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
    fourth->next = head; //Created a circular linked list

    printf("Circular Linked list before insertion \n");
    LinkedListTraversal(head);
    head = insertAtFirst(head, 80);
    printf("Circular Linked list after insertion \n");
    LinkedListTraversal(head);


return 0;
}