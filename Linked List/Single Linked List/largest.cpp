#include<iostream>

using namespace std;

int main()
{
	struct node
	{
		int data;
		struct node *next;
	};
	struct node *head,*newnode,*temp,*answer;
	head=0;
	int choice=1;
	while(choice)
		{
			newnode = (struct node*)malloc(sizeof(struct node));
			cout<<"Enter Element : ";
			cin>>newnode->data;
			newnode->next=0;

			if(head==0)
			{
				head= temp =newnode;
			}
			else
			{
				temp->next = newnode;
				temp= newnode;

			}
	cout<<"Do you want to continue (0,1) : ";
	cin>>choice;
		}
		temp=head;
		while(temp->next!=0)
		{
			if((temp->data)>(temp->next->data))
			{
				answer = temp;
			}
			else
			{
				answer = temp->next;
			}
			temp = temp->next;
		}
		cout<<"The largest element is : ";
		cout<<answer->data<<endl;

		return 0;
}