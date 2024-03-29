#include<stdio.h>
#include<stdlib.h>

 int visited[7] = {0,0,0,0,0,0,0}; // The same graph that is drawn in the notebook
 int A [7][7] = {
        {0,1,1,1,0,0,0},
        {1,0,1,0,0,0,0},
        {1,1,0,1,1,0,0},
        {1,0,1,0,1,0,0},
        {0,0,1,1,0,1,1},
        {0,0,0,0,1,0,0}, 
        {0,0,0,0,1,0,0} 
    };

void dfs(int i) // i is the node where I currently am
{
    int j;
    printf("%d", i);

    visited[i]= 1; // 1 means that it is visited
    for (j =0; j<7; j++)
    {
        if(A[i][j]==1 && !visited[j]) // IF i has an edge which is visiting a node and it is not visited
        {
            dfs(j);
        }
    }
}


int main(){
    // DFS IMPLIMENTATION
    dfs(1);
    return 0;
}
