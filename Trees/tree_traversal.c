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


void preOrder(struct node * root)
{
    if (root != NULL)
    {
        printf("%d ", root -> data);
        preOrder(root -> left);
        preOrder(root ->right);
    }
}

void postOrder(struct node * root)
{
    if (root != NULL)
    {
        postOrder(root -> left);
        postOrder(root -> right);
        printf("%d ", root -> data);
    }
}

void inOrder(struct node* root)
{
    if(root != NULL)
    {
    inOrder(root -> left);
    printf("%d ",root -> data);
    inOrder(root -> right);
    }
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
    struct node* p = createNode(4); //This nigga our root
    struct node* p1 = createNode(1);
    struct node* p2 = createNode(6);
    struct node* p3 = createNode(5) ;
    struct node* p4 = createNode(2);
    
    //This is the tree

    //      4
    //    /  \  
    //   1    6
    //  / \ 
    // 5   2 
 
    //Linking root node with 2nd and 3rd as left child and right child
    p -> left = p1;
    p -> right = p2;
    
    //Linking the childs of the root with its own children
    p1 -> left = p3;
    p1 -> right = p4;

    //Calling that gey ass finction preorder 
    preOrder(p);
    printf("\n");
    postOrder(p);
    printf("\n");
    inOrder(p);

return 0;
}