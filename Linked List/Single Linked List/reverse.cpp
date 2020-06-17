	#include<iostream>

using namespace std;

int main()
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct node*head,*newnode,*temp;;
	head=0;
	int choice=1;
	while(choice)
	{
		newnode = (struct node*)malloc(sizeof(struct node));
		cout<<"Enter data : ";
		cin>>newnode->data;
		newnode->next=0;

		if (head==0)
		{
			head=temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
		cout<<"Do you want to continue(0,1) : ";
		cin>>choice;
	}
		struct node *prevnode, *currentnode , *nextnode;
		prevnode=0;
		currentnode=nextnode=head;
		while(nextnode!=0)
		{
			nextnode = nextnode->next;
			currentnode->next = prevnode;
			prevnode=currentnode;
			currentnode=nextnode;
		}
		head=prevnode;
		temp=head;
		while(temp!=0)
		{
			cout<<temp->data;
			temp = temp->next;
			cout<<" ";
		}
		cout<<endl;
	return 0;
}