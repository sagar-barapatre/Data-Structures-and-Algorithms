#include<bits/stdc++.h>
using namespace std;

class Node {
public :
	int data;
	Node* left;
	Node* right;

	Node(int data)
	{
		this->data = data;
		left = right = NULL;
	}
};

void Inorder(Node* root)
{
	if (root == NULL)
	{
		return;
	}

	Inorder(root->left);
	cout << root->data << " ";
	Inorder(root->right);
}

Node* buildTreeHelper( int inorder[], int preorder[], int InS, int InE, int PreS, int PreE)
{

	if (InS > InE)
	{
		return NULL;
	}

	int rootData = preorder[PreS];

	int lIns = InS;
	int rootIndex = -1;
	for (int i = InS ; i <= InE ; i++)
	{
		if (inorder[i] == rootData)
		{
			rootIndex = i;
			break;
		}
	}
	int lIne = rootIndex - 1;
	int lPres = PreS + 1;
	int lPree = lIne - lIns + lPres;
	int rIns = rootIndex + 1;
	int rIne = InE;
	int rPres = lPree  + 1;
	int rPree = PreE;


	Node* root = new Node(rootData);
	root->left = buildTreeHelper(inorder, preorder, lIns, lIne, lPres, lPree);
	root->right = buildTreeHelper(inorder, preorder, rIns, rIne, rPres, rPree);

	return root;
}

Node* buildTree(int inorder[], int preorder[], int size)
{
	return buildTreeHelper(inorder, preorder, 0, size - 1, 0, size - 1);
}
int main()
{

	int inorder[] = {4, 2, 5, 1, 8, 6, 9, 3, 7};
	int preorder[] = {1, 2, 4, 5, 3, 6, 8, 9, 7};

	Node* root = buildTree(inorder, preorder, 9);
	Inorder(root);
	delete root;
	return 0;
}