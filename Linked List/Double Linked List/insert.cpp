#include<iostream>

using namespace std;

int main()
{
	struct node
	{
		int data;
		struct node * next;
		struct node *prev;
	};
	struct node * head, *newnode, *temp;
	head =0;
	int choice=1,position,i=1;
	while(choice)
{
	newnode = (struct node*) malloc(sizeof(struct node));
	cout<<"enter the data : ";
	cin>>newnode->data;
	newnode -> next=0;

	if (head==0)
	{
		head = temp = newnode;
	}
	else
	{
		temp -> next = newnode;
		temp = newnode;
	}
	cout<<"do you want to continue : ";
	cin>>choice;

}
	
	newnode = (struct node*) malloc(sizeof(struct node)); 
	cout<<"enter the position after which node is to be inserted : ";
	cin>>position;
	temp = head;
	while (i<position)
	{
		temp = temp->next;
		i++;
	}
	cout<<"enter the data to be stored : ";
	cin>>newnode->data;

	newnode->prev = temp;
	newnode->next= temp->next;
	temp->next = newnode;
	newnode->next->prev = newnode;

	temp = head;
	while (temp!=0)
	{
		cout<<temp->data;
		temp = temp->next;
		cout<<" "<<endl;
	}
	return 0;
}