/*
    BFS spanning tree

    0 ----- 1
    | \     |
    |  \    |
    |   \   |
    |    \  |
    3 ---- 2
     \    /
      \  /
       4
      / \
     5   7

    # Consider the graph shown
    # We can start with any source node
    # Let's start with 0
    # Try to construct a tree with 0 as the root 
    # Mark all the sideways or duplicate edges (above a node) as dashed
    # This constructed tree is called as BFS Spanning Tree
    # Level order traversal of a BFS spanning tree is a valid BFS traversal of a graph

    BFS Traversal

    -> Consider the graph shown
    -> We can start with any source node
    -> Let's start with 0 and insert it in the queue
    -> Visit all the connected vertices and enqueue them for exploration (in any order)
    -> 0 is now explored! Let's go to the next in queue (1)
    -> Repeat the same for other elements in the queue

Algorithm for BFS :
    * input : A graph G = (V, E) and source node 's' in V
    * Algorithm :
        -> Mark all nodes 'v' in V as unvisited
        -> Mark source node 's' as visited
        -> enq(Q, s) // first-in-first-out queue Q
        -> while (Q is not empty)
           {
                u := deg(Q);
                for each unvisited neighbour v of u
                {
                    mark v as visited;
                    enq(Q,v);
                }
            }
*/
#include<stdio.h>
#include<stdlib.h> 

struct queue
{
    int size;
    int f;
    int r;
    int* arr;
};

int isFull(struct queue * q)
{
    if (q->r == q->size - 1)
    {
        return 1;
    }
    return 0;
}

int isEmpty(struct queue * q)
{
    if (q->r == q->f)
    {
        return 1;
    }
    return 0;
}

void enqueue(struct queue * q, int val)
{
    if (isFull(q))
    {
        printf("This queue is full\n");
    }
    else
    {
        q->r ++;
        q->arr[q->r] = val;
    }
}

int dequeue(struct queue * q)
{
    int a = -1;
    if (isEmpty(q))
    {
        printf("This queue is empty\n");
    }
    else
    {
        q->f ++;
        a = q->arr[q->f];
    }
    return a;
}

void display(struct queue * q)
{
    for (int i = q->f + 1; i <= q->r; i++)
    {
        printf("%d ", q->arr[i]);
    }
    puts("");
}

int main()
{
    // Initializing Queue (Array Implementation)

    struct queue* q;
    q->size = 400;
    q->f = q->r = -1;
    q->arr = (int *)malloc(q->size * sizeof(int));

    // BFS implementation (using adjacancy matrix)

    int node;
    int i = 6;
    int visited[7] = {0};
    int adj_mat[7][7] = {
                            {0, 1, 1, 1, 0, 0, 0},
                            {1, 0, 1, 0, 0, 0, 0},
                            {1, 1, 0, 1, 1, 0, 0},
                            {1, 0, 1, 0, 1, 0, 0},
                            {0, 0, 1, 1, 0, 1, 1},
                            {0, 0, 0, 0, 1, 0, 0},
                            {0, 0, 0, 0, 1, 0, 0}
                        };
    printf("%d ", i);
    visited[i] = 1;
    enqueue(q, i);  // enqueue i for exploration

    while (!isEmpty(q))
    {
        node = dequeue(q);
        for (int j = 0; j < 7; j++)
        {
            if (adj_mat[node][j] == 1 && visited[j] == 0)
            {
                printf("%d ", j);
                visited[j] = 1;
                enqueue(q, j);
            }
        }
    }
    return 0;
}
