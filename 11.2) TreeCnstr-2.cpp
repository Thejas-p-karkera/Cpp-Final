// Construct the binary tree for the given inorder traversal and postorder traversal sequences.

//Tree construction from post-order and inorder

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

int search(int inorder[], int strt, int end, int curr)
{
	for(int i=strt; i<=end; i++)
	{
		if(inorder[i] == curr)
		{
			return i;
		}
	}
	return -1;
}

Node* buildTree(int postorder[], int inorder[], int strt, int end)
{
	static int idx = 4;

	if(strt > end)
	{
		return NULL;
	}

	int curr = postorder[idx];
	idx--;

	Node* node = new Node(curr);

	if(strt == end)
	{
		return node;
	}

	int pos = search(inorder, strt, end, curr);
	node-> right = buildTree(postorder, inorder, pos+1, end);
	node-> left = buildTree(postorder, inorder, strt, pos-1);
	return node;
}

void preOrderprint(Node* root)
{
	if(root == NULL)
	{
		return;
	}

	cout << root->data << " ";
	preOrderprint(root->left);
    preOrderprint(root->right);
}

int main()
{
	int inorder[] = {4, 2, 1, 5, 3};
	int postorder[] = {4, 2, 5, 3, 1};

	Node* root = buildTree(postorder, inorder, 0, 4);

	preOrderprint(root);

	return 0;
}
