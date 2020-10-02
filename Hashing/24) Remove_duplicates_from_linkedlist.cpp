#include <iostream>
#include <unordered_set>
using namespace std;

// Data Structure to store a linked list node
struct Node
{
	int data;
	Node* next;
};

// Helper function to print given linked list
void printList(Node* head)
{
	Node* ptr = head;
	while (ptr)
	{
		cout << ptr->data << " -> ";
		ptr = ptr->next;
	}

	cout << "null";
}

// Helper function to insert a new node in the beginning of the linked list
void push(Node** headRef, int data)
{
	Node* newNode = new Node();

	newNode->data = data;
	newNode->next = *headRef;
	*headRef = newNode;
}

// Function to remove duplicates from a sorted list
void RemoveDuplicates(Node* head)
{
	Node* previous = nullptr;
	Node* current = head;

	// take an empty set to store linked list nodes for future reference
	unordered_set<int> set;

	// do till linked list is not empty
	while (current != nullptr)
	{
		// if current node is seen before, ignore it
		if (set.find(current->data) != set.end())
		{
			previous->next = current->next;
		}
		else
		{
			// insert current node into the set and proceed to next node
			set.insert(current->data);
			previous = current;
		}
		current = previous->next;
	}
}

// main method to remove remove duplicates from list
int main()
{
	// input keys
	int keys[] = {5, 3, 4, 2, 5, 4, 1, 3};
	int n = sizeof(keys) / sizeof(keys[0]);

	// points to the head node of the linked list
	Node* head = nullptr;

	// construct linked list
	for (int i = n - 1; i >= 0; i--)
		push(&head, keys[i]);

	RemoveDuplicates(head);

	// print linked list
	printList(head);

	return 0;
}