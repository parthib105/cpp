#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int src;
    int des;
    int wei;
} edge;

void sort(edge arr[], int n)
{
    for (int i = 1; i < n; i++)
    {
        edge curr = arr[i];
        int pos = i - 1;
        while ( arr[pos].wei > curr.wei && pos >=0)
        {
            arr[pos + 1] = arr[pos];
            pos --;
        }
        arr[pos + 1] = curr;
    }
}

int find(int v, int parent[])
{
    if (parent[v] == v)
    {
        return v;
    }
    return find(parent[v], parent);
}

void kruskals(edge arr[], int v, int e)
{
    // sort the array w.r.t weights
    sort(arr, e);

    // making an output array of size v - 1
    edge* op = (edge *)malloc((v - 1) * sizeof(edge));

    int k = 0;
    int parent[v];
    for (int i = 0; i < v; i++)
    {
        parent[i] = i;
    }

    for (int i = 0; i < e; i++)
    {
        if (k == v - 1)
        {
            break;
        }

        edge currEdge = arr[i];
        int src_parent = find(currEdge.src, parent);
        int des_parent = find(currEdge.des, parent);

        if (src_parent != des_parent)
        {
            op[k] = currEdge;
            k++;
            parent[src_parent] = des_parent;
        }
    }

    for (int i = 0; i < v - 1; i++)
    {
        printf("(%d, %d, %d), ", op[i].src, op[i].des, op[i].wei);
    }
    puts(" ");
}

int main()
{
    // Taking input for no. of edges and vertices
    // int e, v;
    // printf("Enter the no. edges and vertices of the graph : ");
    // scanf("%d %d", &e, &v);

    edge arr[5];

    arr[0].src = 2;
    arr[0].des = 3;
    arr[0].wei = 4;

    arr[1].src = 0;
    arr[1].des = 2;
    arr[1].wei = 6;

    arr[2].src = 0;
    arr[2].des = 1;
    arr[2].wei = 10;

    arr[3].src = 0;
    arr[3].des = 3;
    arr[3].wei = 5;

    arr[4].src = 1;
    arr[4].des = 3;
    arr[4].wei = 15;


    kruskals(arr, 4, 5);
    return 0;
}