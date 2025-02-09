// Demonstrate adjacency matrix representation of a graph.

#include<iostream>
using namespace std;

void printMatrix(int** arr, int n)
{
	cout<<"The matrix is: "<<endl;

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			cout<<arr[i][j]<<" ";
		}
		cout<<endl;
	}
}

void main()
{
	int n;
	cout<<"Enter the number of Nodes(Vertices): ";
	cin>>n;


	int** arr = new int*[n];
	for(int i=0; i<n; i++)
	{
		arr[i] = new int[n];
	}

	for(int i=0; i<n; i++)
	{
		for(int j=0; j<n; j++)
		{
			arr[i][j] = 0;
		}
	}

	int m;
	cout<<"Enter the number of edges: ";
	cin>>m;

	int src, dst;

	int ch;
    cout << "Enter '0' for Directed graph or '1' for Undirected graph: ";
    cin >> ch;

	for(int i=0; i<m; i++)
	{
		cout<<"Enter the edges (source & destination): "<<endl;
		cin>>src>>dst;
		arr[src][dst] = 1;

		if(ch == 1)
		{
			arr[dst][src] = 1;
		}
		
	}
	
	//arr[src][dst] = 1;
	//arr[dst][src] = 1;
	printMatrix(arr,n);
}
