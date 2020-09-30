#include <iostream>
#include <queue>
using namespace std;

// Data structure to store a Binary Tree node
class Node
{
public :
	int data;
	Node *left, *right;

	Node(int data)
	{
		this->data = data;
		this->left = this->right = nullptr;
	}
};

void printNodes(Node* root)
{
	if (root == nullptr)
		return ;
	cout << root->data << " ";

	queue<Node*> q1, q2;
	q1.push(root->left);
	q2.push(root->right);

	while (!q1.empty())
	{
		int n = q1.size();
		while (n--)
		{
			Node* temp = q1.front();
			q1.pop();

			cout << temp->data << " ";
			if (temp->left)
				q1.push(temp->left);
			if (temp->right)
				q1.push(temp->right);


			Node* ans = q2.front();
			q2.pop();
			cout << ans->data << " ";
			if (ans->left)
				q2.push(ans->left);
			if (ans->right)
				q2.push(ans->right);
		}
	}
}

int main()
{
	Node* root = nullptr;

	root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(4);
	root->left->right = new Node(5);
	root->right->left = new Node(6);
	root->right->right = new Node(7);
	root->left->left->left = new Node(8);
	root->left->left->right = new Node(9);
	root->left->right->left = new Node(10);
	root->left->right->right = new Node(11);
	root->right->left->left = new Node(12);
	root->right->left->right = new Node(13);
	root->right->right->left = new Node(14);
	root->right->right->right = new Node(15);

	printNodes(root);

	return 0;
}