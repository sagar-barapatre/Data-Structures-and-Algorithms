#include<iostream>

using namespace std;

int main()
{
	struct node
	{
		int data;
		struct node *next;
		struct node *prev;
	};
	struct node *head,*tail,*temp,*newnode;
	head=0;
	int choice=1;
	while(choice)
{
	newnode = (struct node*)malloc(sizeof(struct node));
	cout<<"Enter the data : ";
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
	cout<<"Do you want to continue (0,1)  :";
	cin>>choice;
}
	struct node*nextnode,*current;

int position,i=1;
	current = head;
	while(current!=0)
{
	nextnode = current->next;
	current->next= current->prev;
	current->prev = nextnode;
	current = nextnode;
}

current = head;
head=tail;
tail=current;

temp = head;
while(temp!=0)
{
	cout<<temp->data;
	temp = temp->next;
	cout<<" ";
}
cout<<endl;
return 0;
}