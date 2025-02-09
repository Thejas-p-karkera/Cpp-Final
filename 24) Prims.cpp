// Construct Minimum Spanning Tree using Prim’s algorithm.

#include<iostream>
using namespace std;

void main()
{
	int n;
	cout << "Enter the number of vertices: ";
	cin >> n;

	int** arr = new int* [n];

	for(int i=0; i<n; i++)
	{
		arr[i] = new int[n];
	}

	cout << "Enter the adjascency matrix (Enter 0 for no edge):" << endl;

	for (int i = 0; i < n; i++)						//	0 2 0 6
	{												//	2 0 3 8
		for (int j = 0; j < n; j++)					//	0 3 0 0
		{											//	6 8 0 0
			cin >> arr[i][j];
		}
	}


	bool* visited = new bool[n];			// to keep track of the visited nodes

	for (int i = 0; i < n; i++)				// Visited Array Initialization
	{
		visited[i] = false;
	}

	visited[0] = true;						// start from the first node


	for (int i = 0; i < n - 1; i++)			// Loop to find n-1 edges
	{
		int minWt = 10000;					// Large value to find the minimum weight
		int src = -1, dst = -1;

		for (int j = 0; j < n; j++)			// Loop through all nodes
		{
			if (visited[j] == 1)			// If the node is visited
			{
				for (int k = 0; k < n; k++)		// Loop through all Edges of the node. To check its connections (Edges)
				{
					if (!visited[k] && arr[j][k] != 0 && arr[j][k] < minWt)		//If the edge of the node is unvisited &
					{															//arr[node][edge] # 0  &  arr[node][edge] < 10000
						minWt = arr[j][k];
						src = j;
						dst = k;
					}
				}
			}
		}
		
		cout << src << " -> " << dst << " with weight " << minWt << endl;
		visited[dst] = true;				// Mark the destination node as visited
	}
}
