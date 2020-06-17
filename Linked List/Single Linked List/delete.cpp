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
  int position,i=1;
	struct node *nextnode;
	newnode = (struct node*) malloc(sizeof(struct node)); 
	cout<<"enter the position after which node is to be inserted : ";
	cin>>position;
	temp = head;
	while (i<position-1)
	{
		temp = temp->next;
		i++;
	}

	nextnode = temp->next;
	 temp->next = nextnode->next;
	free(nextnode);

temp = head;
	while (temp!=0)
	{
		cout<<temp->data;
		temp = temp->next;
		cout<<" "<<endl;
	}
	return 0;
}