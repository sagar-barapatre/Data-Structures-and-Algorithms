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
		temp = newnode;
	}
	cout<<"Do u want to continue (0,1) : ";
	cin>>choice;
}
temp = head;
int count=0,position;
	  while(temp != 0)
	  {
	  	count++;
	  	temp=temp->next;
	  }
	  if(count%2==0)
	  {
	  	position = (count/2)+1;
	  }
	  else
	  {
	  	position = (count+1)/2;
	  }
	  int i=1;
	  temp=head;
	  while(i<position)
	  {
	  	temp= temp->next;
	  	i++;
	  }

	  cout<<"The middle element is : "<<temp->data<<endl;

	  return 0;
	}