// Implement depth first traversal of a graph.

#include<iostream>
using namespace std;

class Stack
{
	public:
		int* arr;
		int top, size;

		Stack(int size)
		{
			size = size;
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

void DFS(int startNode, int** graph, int n)
{
	bool* visited = new bool[n];

	for (int i = 0; i < n; i++)
	{
		visited[i] = false;
	}

	Stack s(n);
	s.push(startNode);
	visited[startNode] = true;

	cout << "DFS Traversal: ";
	while (!s.empty())
	{
		int current = s.pop();
		cout << current << " ";

		for(int i = n-1; i >= 0; i--)
		{
			if (graph[current][i] == 1 && !visited[i])
			{
				s.push(i);
				visited[i] = true;
			}
		}
	}

	cout << "\nUnvisited Nodes :";
	for(int i=0; i<n; i++)
	{
		if (!visited[i])
		{
			cout << i << " ";
		}
	}

}

int main()
{
	int n;
	cout << "Enter the nummber of nodes: ";
	cin >> n;

	int** graph = new int* [n];

	for (int i = 0; i < n; i++)
	{
		graph[i] = new int[n];
	}

	for (int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			graph[i][j] = 0;
		}
	}

	int m;
	cout << "Enter the nummber of edges: ";
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

	int startNode;
	cout << "Entter the starting Node: ";
	cin >> startNode;

	DFS(startNode, graph, n);

	return 0;
}
