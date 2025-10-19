/*
    Critical and Pseudo-Critical Edges

    You are given a weighted undirected connected graph with ‘n’ vertices numbered from 0 to (n - 1), and array 'EDGES' where 
    EDGES[i] = [ ai, bi, WEIGHT ] represents a bidirectional and weighted edge between nodes ai and bi. A minimum spanning 
    tree (MST) is a subset of the graph's edges that connects all vertices without cycles and with the minimum possible total 
    edge weight.

    Your task is to find all the critical and pseudo-critical edges in the given graph's minimum spanning tree (MST). An MST 
    edge whose deletion from the graph would cause the MST weight to increase is called a critical edge. On the other hand, 
    a pseudo-critical edge is that which can appear in some MSTs but not all.

    Note:

    1) A weighted graph refers to one where weights are assigned to each edge, undirected graphs are those where edges are 
       bi-directional and have no arrows.

    2) If no edge exists return -1.

    3) Return the edges in the sorted order of their indices.
    
    For example:

    N = 4, M = 4
    [[0, 1, 1],
    [0, 2, 1],
    [0, 3, 2],
    [2, 3, 2]]

    The critical connections are the 0th connection and the 1st connection because removing the causes the MST weight to 
    increase. The 2nd and 3rd connections are pseudo-critical because any one of the edges can be taken to make MST.

    Sample Input 1 :
    2
    4 4
    0 1 1
    0 2 1
    0 3 2
    2 3 2
    3 3
    0 1 2
    2 0 1
    1 2 1
    Sample Output 1:
    0 1 
    2 3 
    1 2 
    -1
    Explanation Of Sample Input 1:
    For the first test case:

    The critical connections are the 0th connection and the 1st connection because removing the causes the MST weight to 
    increase. The 2nd and 3rd connections are pseudo critical because any one of the edges can be taken to make MST.

    For the second Test case : 

    Edge 1 and 2 are critical for the formation of a minimum spanning tree.
    There is no other edge that is required for the formation of MST, hence there is no pseudo-critical connection, therefore 
    we returned -1.
    
    Sample Input 2 :
    2
    4 4
    0 1 1
    1 2 1
    2 3 1
    0 3 1
    5 7
    0 1 1
    1 2 1
    2 3 2
    0 3 2
    0 4 3
    3 4 3
    1 4 6
    Sample Output 2 :
    -1 
    0 1 2 3 
    0 1 
    2 3 4 5
*/

#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>> &edges)
{
	// Write your code here.
}

int main()
{
    
    return 0;
}