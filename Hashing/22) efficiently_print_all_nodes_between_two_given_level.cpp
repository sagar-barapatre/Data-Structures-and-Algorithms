#include <iostream>
#include <list>
using namespace std;

// Data structure to store a Binary Tree node
struct Node
{
	int key;
	Node *left, *right;

	Node(int key)
	{
		this->key = key;
		this->left = this->right = nullptr;
	}
};

// Iterative function to print all nodes between two given
// levels in a binary tree
void printNodes(Node *root, int start, int end)
{
	if (root == nullptr)
		return;

	// create an empty queue and enqueue root node
	list<Node*> queue;
	queue.push_back(root);

	// pointer to store current node
	Node* curr = nullptr;

	// maintains level of current node
	int level = 0;

	// run till queue is not empty
	while (!queue.empty())
	{
		// increment level by 1
		level++;

		// calculate number of nodes in current level
		int size = queue.size();

		// process every node of current level and enqueue their
		// non-empty left and right child to queue
		while (size--)
		{
			curr = queue.front();
			queue.pop_front();

			// print the node if its level is between given levels
			if (level >= start && level <= end)
				cout << curr->key << " ";

			if (curr->left)
				queue.push_back(curr->left);

			if (curr->right)
				queue.push_back(curr->right);
		}

		if (level >= start && level <= end)
			cout << endl;
	}
}

int main()
{
	Node* root = nullptr;

	root = new Node(15);
	root->left = new Node(10);
	root->right = new Node(20);
	root->left->left = new Node(8);
	root->left->right = new Node(12);
	root->right->left = new Node(16);
	root->right->right = new Node(25);
	root->right->right->right = new Node(30);

	int start = 2, end = 3;
	printNodes(root, start, end);

	return 0;
}