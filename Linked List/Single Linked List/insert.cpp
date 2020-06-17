#include<iostream>

using namespace std;

int main()
{
	struct node
	{
		int data;
		struct node * next;
	};
	struct node * head, *newnode, *temp;
	head =0;
	int choice=1;
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

int position;
cout<<"Enter the position after which node is to be inserted : ";
cin>>position;
temp=head;
int i=1;
	newnode = (struct node*) malloc(sizeof(struct node));
	cout<<"Enter the data to be stored : ";
	cin>>newnode->data;
	newnode->next=0;

while(i<position)
{
	temp=temp->next;
	i++;
}
newnode->next=temp->next->next;
temp->next=newnode;

temp=head;
while (temp!=0)
	{
		cout<<temp->data;
		temp = temp->next;
		cout<<" ";
	}
	return 0;
}