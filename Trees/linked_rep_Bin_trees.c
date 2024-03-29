#include<stdio.h>
#include<stdlib.h>

struct node
{
    int data;
    struct node* left;
    struct node* right;
};

struct node* createNode(int data)
{
    struct node* n; // Creating a node pointer
    n = (struct node*)malloc(sizeof(struct node)); //Memory allocation
    n -> data = data; // Setting data
    n -> left = NULL; // Setting left and right to NULL
    n -> right = NULL;

    return n;  //Returning the created node
}

int main()
{
    /*

    // Creating Nodes and appointing the pointers to NULL

    //Craeting the root node
    struct node* p;
    p = (struct node*)malloc(sizeof(struct node));
    p -> data =2;
    p -> left = NULL;
    p -> right = NULL;

    //Making 2nd node
    struct node* p1;
    p1 -> data =1;
    p1 = (struct node*)malloc(sizeof(struct node));
    p1 -> left = NULL;
    p1 -> right = NULL;

    //making 3rd node
    struct node* p2;
    p -> data =4;
    p2 = (struct node*)malloc(sizeof(struct node));
    p2 -> left = NULL;
    p2 -> right = NULL;

    //Linking root node with 2nd and 3rd as left child and right child
    p -> left = p1;
    p -> right = p2;

    */

   //Craeting the root node Using function
    struct node* p = createNode(2);
    struct node* p1 = createNode(1);
    struct node* p2 = createNode(4); 
    
    //Linking root node with 2nd and 3rd as left child and right child
    p -> left = p1;
    p -> right = p2;



return 0;
}