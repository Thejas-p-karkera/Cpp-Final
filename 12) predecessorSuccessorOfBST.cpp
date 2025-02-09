// Find inorder predecessor and inorder successor in a Binary Search Tree.

#include<iostream>
using namespace std;

class Node
{
	public:
		int data;
		Node* left;
		Node* right;

		Node(int val)
		{
			data = val;
			left = NULL;
			right = NULL;
		}
};

Node* insertBST(Node* root, int val)
{
	if(root == NULL)
	{
		return new Node(val);
	}

	if(val < root->data)
	{
		root->left = insertBST(root->left, val);
	}
	else
	{
		root->right = insertBST(root->right, val);
	}
	return root;
}


void printInorder(Node* root, int& index, int arr[])
{
	if(root == NULL)
	{
		return;
	}

	printInorder(root->left, index, arr);
	cout<<root->data<<" ";

	arr[index] = root->data;
	index++;

	printInorder(root->right, index, arr);
}


int search(int key, int n, int arr[])
{
	for(int i=0; i<=n; i++)
	{
		if(key == arr[i])
		{
			return i;
		}
	}
	return -1;
}


int main()
{
	Node* root = NULL;

	int n, ele;

	cout<<"How many elements you want to store?: ";
	cin>>n;
	cout<<"Enter "<<n<<" elements: ";

	for(int i=0; i<n; i++)
	{
		cin>>ele;
		root = insertBST(root, ele);
	}

	int* arr = new int[n];
	int index=0;

	cout<<"The Inorder traversal of the BST: ";

	printInorder(root, index, arr);

	cout<<"\nEnter the element to get it's predecessor and successor: ";
	cin>>ele;
	if(search(ele, n, arr) == -1)
	{
		cout<<"The element is not present in the BST";
	}
	else
	{
		if(search(ele, n, arr) == 0)
		{
			cout<<"Predecessor : Nill"<<endl;
			cout<<"Successor : "<<arr[search(ele, n, arr)+1]<<endl;
		}
		else if(search(ele, n, arr) == n-1)
		{
			cout<<"Predecessor : "<<arr[search(ele, n, arr)-1]<<endl;
			cout<<"Successor : Nill"<<endl;
		}
		else
		{
			cout<<"Predecessor : "<<arr[search(ele, n, arr)-1]<<endl;
			cout<<"Successor : "<<arr[search(ele, n, arr)+1]<<endl;
		}
	}
}
