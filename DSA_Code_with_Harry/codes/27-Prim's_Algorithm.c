#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define V 6

int minWeight(int weight[], bool visited[])
{
    int min = INT_MAX;
    int min_index = -1;

    for (int v = 0; v < V; v++)
    {
        if (visited[v] == false && weight[v] < min)
        {
            min = weight[v];
            min_index = v;
        }
    }
    return min_index;
}

void printMST(int parent[], int graph[V][V])
{
    printf("Edge\tWeight\n");
    for (int i = 1; i < V; i++)
    {
        printf("%d - %d\t%d\n", parent[i], i, graph[i][parent[i]]);
    }
}

void primMST(int graph[V][V])
{
    int parent[V];
    int weight[V];
    bool visited[V];

    for (int i = 0; i < V; i++)
    {
        weight[i] = INT_MAX;
        visited[i] = false;
        parent[i] = -1;
    }

    weight[0] = 0;
    for (int i = 0; i < V - 1; i++)
    {
        int u = minWeight(weight, visited);
        visited[u] = true;
        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] != 0 && visited[v] == false && graph[u][v] < weight[v])
            {
                parent[v] = u;
                weight[v] = graph[u][v];
            }
        }
    }

    printMST(parent, graph);
}

int main()
{
    int graph[V][V] = { {0, 2, 0, 4, 0, 0},
                        {2, 0, 3, 1, 0, 0},
                        {0, 3, 0, 0, 0, 4},
                        {4, 1, 0, 0, 2, 0},
                        {0, 0, 0, 2, 0, 1},
                        {0, 0, 4, 0, 1, 0}};
    
    primMST(graph);
    return 0;
}