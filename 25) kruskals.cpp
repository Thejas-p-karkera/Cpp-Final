#include<iostream>
using namespace std;

class Edge
{
public:
    int src, dst, wt;
};

// Function to find the root of a node using path compression
int findParent(int node, int* parent)
{
    while (parent[node] != node)
    {
        node = parent[node];
    }
    return node;
}

// Function to perform union operation
void unionSets(int u, int v, int* parent)
{
    int rootU = findParent(u, parent);
    int rootV = findParent(v, parent);
    parent[rootV] = rootU;
}

int main()
{

    int n, e;

    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the number of edges: ";
    cin >> e;

    Edge* edges = new Edge[e];

    cout << "Enter the edges with their weights (src dst weight): " << endl;

    for (int i = 0; i < e; i++) 
    {
        cin >> edges[i].src >> edges[i].dst >> edges[i].wt;
    }

    // Sorting edges based on weight using simple selection sort
    for (int i = 0; i < e - 1; i++)
    {
        for (int j = i + 1; j < e; j++)
        {
            if (edges[j].wt < edges[i].wt)
            {
                Edge temp = edges[i];
                edges[i] = edges[j];
                edges[j] = temp;
            }
        }
    }

    int* parent = new int[n];

    for (int i = 0; i < n; i++)
    {  
        // Initializing parent array for union-find
        parent[i] = i;
    }

    cout << "Minimum Spanning Tree using Kruskal's Algorithm:" << endl;

    int edgeCount = 0;

    for (int i = 0; i < e && edgeCount < n - 1; i++)
    { 
        // Finding n-1 edges
        int u = edges[i].src;
        int v = edges[i].dst;
        int wt = edges[i].wt;

        if (findParent(u, parent) != findParent(v, parent)) 
        { 
            // If no cycle is formed
            cout << u << " -> " << v << " with weight " << wt << endl;
            unionSets(u, v, parent);
            edgeCount++;
        }
    }

}
