// C++ program to find height of tree 
#include <bits/stdc++.h> 
using namespace std; 

struct Node 
{ 
	int data; 
	struct Node* left; 
	struct Node* right; 
  
  	Node(int data)
    {
      this->data = data;
      left = right = NULL;
    }
}; 

int maxDepth(Node* node) 
{ 
	if (node == NULL) 
		return 0; 
	else
	{ 
		/* compute the depth of each subtree */
		int lDepth = maxDepth(node->left); 
		int rDepth = maxDepth(node->right); 
	
		// use larger one
		if (lDepth > rDepth) 
			return(lDepth + 1); 
		else return(rDepth + 1); 
	} 
} 

	
// Driver code	 
int main() 
{ 
	struct Node *root = new Node(1); 

	root->left = new Node(2); 
	root->right = new Node(3); 
	root->left->left = new Node(4); 
	root->left->right = new Node(5); 
	
	cout << "Height of tree is " << maxDepth(root); 
	return 0; 
} 

