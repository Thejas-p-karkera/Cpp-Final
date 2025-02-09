// Demonstrate adjacency list representation of a graph.

#include<iostream>
using namespace std;

void main()
{
	int n;
	cout << "Enter the number of nodes: ";
	cin >> n;

	int** arr = new int* [n];

	for (int i = 0; i < n; i++)
	{
		arr[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			arr[i][j] = 0;
		}
	}

	int ch;
	cout << "Enter '0' for Directed, '1' for Undirected: ";
	cin >> ch;

	int m;
	cout << "Enter the number of edges: ";
	cin >> m;

	int src, dst;
	for (int i = 0; i < m; i++)
	{
		cout << "Enter Edges (Source & Destination): ";
		cin >> src >> dst;

		arr[src][dst] = 1;
		if (ch == 1)
		{
			arr[dst][src] = 1;
		}
	}

	for (int i = 0; i < n; i++)
	{
		cout << i << " -> ";
		for (int j = 0; j < n; j++)
		{
			if (arr[i][j] == 1)
			{
				cout << j << " ";
			}
		}
		cout << endl;
	}
}
