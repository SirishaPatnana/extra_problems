//2.Merge two linked list which are in sorted order
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
} *start = NULL, *start2 = NULL;
struct node* merge(struct node* a, struct node* b)
{
	int i=0;
	struct node *head = NULL, *head1 = a, *head2 = b;
	start = head;
	while (head1 != NULL)
	{
		if (i == 0)
		{
			if (head1->data < head2->data)
			{
				head = head1;
				start = head;
				head1 = head1->next;
			}
			else
			{
				head = head2;
				start = head;
				head2 = head2->next;
			}
		}
		else
		{
			if (head1->data < head2->data)
			{
				head->next = head1;
				if (head1 != NULL)
					head = head1;
				head1 = head1->next;
				
			}
			else
			{
				if(head2 != NULL)
				{
					head->next = head2;
					if (head2 != NULL)
						head = head2;
					head2 = head2->next;
					
				}
				if (head2 == NULL)
					break;
			}
		}i++;
	}
	if (head2 != NULL)
		head->next = head2;
	if (head1 != NULL)
		head->next = head1;
	return start;
}
int main()
{
	struct node *newnode, *curnode;
	int x;
	scanf("%d", &x);
	while (x == 1)
	{
		newnode = (struct node *)malloc(sizeof(struct node));

		scanf("%d", &newnode->data);
		newnode->next = NULL;

		if (start == NULL)
		{
			start = newnode;
			curnode = newnode;
		}
		else
		{
			curnode->next = newnode;
			curnode = newnode;
		}
		scanf("%d", &x);
	}
	scanf("%d", &x);
	while (x == 1)
	{
		newnode = (struct node *)malloc(sizeof(struct node));

		scanf("%d", &newnode->data);
		newnode->next = NULL;

		if (start2 == NULL)
		{
			start2 = newnode;
			curnode = newnode;
		}
		else
		{
			curnode->next = newnode;
			curnode = newnode;
		}
		scanf("%d", &x);
	}
	start = merge(start, start2);
	newnode = start;
	while (newnode != NULL)
	{
		printf("%d->", newnode->data);
		newnode = newnode->next;
	}
	getch();
	return 0;
}