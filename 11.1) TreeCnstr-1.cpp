// Construct the binary tree for the given inorder traversal and preorder traversal sequences.

//Tree construction from pre-order and inorder

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

int search(int inorder[],int strt, int end, int curr)
{
	for(int i=strt; i<=end; i++)
	{
		if(curr == inorder[i])
		{
			return i;
		}
	}
	return -1;
}

Node* buildTree(int preorder [],int inorder [], int strt, int end)
{
	static int idx = 0;

	if(strt>end)
	{
		return NULL;
	}

	int curr = preorder[idx];
	idx ++;

	Node* node = new Node(curr);

	int pos = search(inorder, strt, end, curr);
	node->left = buildTree(preorder, inorder , strt, pos-1);
	node->right = buildTree(preorder , inorder , pos+1, end);
	return node;
}

void postOrderPrint(Node* root)
{
	if(root==NULL)
	{
		//cout<<"Emptry tree";
		return;
	}

	postOrderPrint(root->left);
	postOrderPrint(root->right);
	cout<<root->data<<" ";
}

int main()
{
	int inorder [] = {4,5,6,3,1,8,7,9,11,10,12};
	int preorder [] = {1,3,5,4,6,7,8,9,10,11,12};

	Node* root = buildTree(preorder ,inorder , 0, 10);

	postOrderPrint(root);
}
