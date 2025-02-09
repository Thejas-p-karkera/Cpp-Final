// Check whether a given graph is connected or not using Depth first Search.

#include <iostream>
using namespace std;

void DFS(int** adjMatrix, int n, int strt, bool* visited)
{
	visited[strt] = true;

	for (int i = 0; i < n; i++)
	{
		if (adjMatrix[strt][i] == 1 && !visited[i])
		{
			DFS(adjMatrix, n, i, visited);
		}
	}
}

int main()
{
	int n;
	cout << "Enter the number of vertices: ";
	cin >> n;

	int** adjMatrix = new int* [n];

	for (int i = 0; i < n; i++)
	{
		adjMatrix[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			adjMatrix[i][j] = 0;
		}
	}

	bool* visited = new bool[n];
	for(int i=0; i<n; i++)
	{
		visited[i] = false;
	}

	//bool visited[100] = {false};
	int m;
	cout << "Enter the number of edges: ";
	cin >> m;

	int src,dst;
	cout << "Enter the edges (source & destination):" << endl;
	for (int i = 0; i < m; i++)
	{
		cin >> src >> dst;
		adjMatrix[src][dst] = 1;
		adjMatrix[dst][src] = 1;
	}

	DFS(adjMatrix, n, 0, visited);
	bool isConnected = true;

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			isConnected = false;
			break;
		}
	}

	if (isConnected)
	{
		cout << "The graph is connected." << endl;
	} 
	else 
	{
		cout << "The graph is NOT connected." << endl;
	}
	return 0;
}
