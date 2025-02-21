// Check whether a given graph is connected or not using Depth first Search.

#include <iostream>
using namespace std;

class Stack
{
public:
	int* arr;
	int top, size;

	Stack(int size)
	{
		this->size = size; // Fixed incorrect size initialization
		arr = new int[size];
		top = -1;
	}

	bool empty()
	{
		return top == -1;
	}

	void push(int val)
	{
		top++;
		arr[top] = val;
	}

	int pop()
	{
		int removed = arr[top];
		top--;
		return removed;
	}
};

// DFS function to check connectivity
bool DFS(int startNode, int** graph, int n)
{
	bool* visited = new bool[n];

	// Initially mark all nodes as unvisited
	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	Stack s(n);
	s.push(startNode);
	visited[startNode] = true;

	while (!s.empty())
	{
		int current = s.pop();

		for (int i = n - 1; i >= 0; i--)
		{
			if (graph[current][i] == 1 && !visited[i])
			{
				s.push(i);
				visited[i] = true;
			}
		}
	}

	for (int i = 0; i < n; i++)
	{
		if (!visited[i])
		{
			return false; // Graph is not connected
		}
	}
	return true;
}

int main()
{
	int n;
	cout << "Enter the number of nodes: ";
	cin >> n;

	int** graph = new int* [n];

	for (int i = 0; i < n; i++)
	{
		graph[i] = new int[n];
	}

	// Initialize adjacency matrix to 0
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			graph[i][j] = 0;
		}
	}

	int m;
	cout << "Enter the number of edges: ";
	cin >> m;

	int ch;
	cout << "Enter '0' for Directed, '1' for Undirected: ";
	cin >> ch;

	int src, dst;
	for (int i = 0; i < m; i++)
	{
		cout << "Enter the edges (source & destination): ";
		cin >> src >> dst;

		graph[src][dst] = 1;
		if (ch == 1)
		{
			graph[dst][src] = 1;
		}
	}

	// Check if the graph is connected
	if (DFS(0,graph, n))
	{
		cout << "The graph is Connected.\n";
	}
	else
	{
		cout << "The graph is Not Connected.\n";
	}

	return 0;
}
