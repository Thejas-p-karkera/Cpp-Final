// Implement insertion, deletion and search operations on a Binary Search Tree.

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
	if(root==NULL)
	{
		return new Node(val);
	}

	if(val < root->data)
	{
		root->left = insertBST(root->left,val);
	}
	else
	{
		root->right = insertBST(root->right,val);
	}
	return root;
}

void searchBST(Node* root, int key)
{
	if(root == NULL)
	{
		cout<<"\nSearch element is not found in the tree."<<endl;
		return;
	}

	if(key < root->data)
	{
		searchBST(root->left, key);
	}
	else if(key > root->data)
	{
		searchBST(root->right, key);
	}
	else
	{
		cout<<"\nSearch element present in the tree."<<endl;
		return;
	}
}

Node* inorderSucc(Node* root)
{
	Node* curr = root;
	while(curr && curr->left != NULL)
	{
		curr = curr->left;
	}
	return curr;
}

Node* deleteBST(Node* root, int key)
{
	if(root == NULL)
	{
		return root;
	}

	if(key < root->data)
	{
		root->left =  deleteBST(root->left, key);
	}
	else if(key > root->data)
	{
		root->right =  deleteBST(root->right, key);
	}
	else
	{
		if(root->left == NULL)
		{
			Node* temp = root->right;
			delete(root);
			return temp;
		}
		else if(root->right == NULL)
		{
			Node* temp = root->left;
			delete(root);
			return temp;
		}
		else
		{
			Node* temp = inorderSucc(root->right);
			root->data = temp->data;
			root->right = deleteBST(root->right, temp->data);
		}
	}
	return root;
}

void inorder(Node* root)
{
	if(root == NULL)
	{
		return;
	}

	inorder(root->left);
	cout<<root->data<<" ";
	inorder(root->right);
}

int main()
{

	Node* root = NULL;

	int n,ele;
	cout<<"Enter the Number of nodes: ";
	cin>>n;

	cout<<"Enter "<<n<<" elements into the node: ";
	for(int i=0; i<n; i++)
	{
		cin>>ele;
		root = insertBST(root,ele);
	}

	cout<<"The Tree after inserting "<<n<<" nodes: ";
	inorder(root);

	cout<<"\nEnter the element you want to search: ";
	cin>>ele;
	searchBST(root, ele);

	cout<<"\nEnter the element you want to delete: ";
	cin>>ele;
	deleteBST(root,ele);
	cout<<"The Tree after deletion: ";
	inorder(root);

	/*root = insertBST(root,8);
	insertBST(root,11);
	insertBST(root,7);
	insertBST(root,3);
	insertBST(root,5);
	insertBST(root,10);
	insertBST(root,13);
	insertBST(root,12);

	
	searchBST(root, 4);

	deleteBST(root,11);
	inorder(root);*/
}
