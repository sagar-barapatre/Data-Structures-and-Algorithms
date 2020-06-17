#include<iostream>

using namespace std;

int main()
{
	struct node
	{
		int data;
		struct node * next;
		struct node * prev;
	};

	struct node * head, *newnode, *temp;
	head = 0;
	int choice=1;
	while(choice)
{
	newnode = (struct node*) malloc(sizeof(struct node));
	cout<<"Enter the value : ";
	cin>>newnode->data;
	newnode -> next = 0;

	if (head == 0)
	{
		head = temp = newnode;
	}
	else
	{
		temp -> next = newnode;
		newnode->prev = temp;
		temp = newnode;
	}
	cout<<"Do u want to continue (0,1) : ";
	cin>>choice;
}
	  temp = head;
	  while(temp != 0)
	  {
	  	cout<<temp -> data;
	  	temp = temp -> next;
	  	cout<<" "<<endl;
	  }
	return 0;
}