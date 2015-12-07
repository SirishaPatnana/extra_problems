//3.Add a node to the circular linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start=NULL;
struct node* cll(struct node *head, int pos)
{
	struct node *pre,*newnode;
	newnode = (struct node *)malloc(sizeof(struct node));
	scanf("%d", &newnode->data);
	head = start;
	if (head == NULL)
	{
		start = newnode;
		newnode->next = start;
		return start;
	}
	if (pos == 0)
	{
		newnode->next = head;
		head = head->next;
		while (head->next != start)
		{
			head = head->next;
		}
		head->next = newnode;
		start = newnode;
		
	}
	else
	{
		while (pos > 0)
		{
			pre = head;
			head = head->next;
			if (head == start)
			{
				break;
			}
			pos--;
		}
		pre->next = newnode;
		newnode->next = head;
	}
	return start;
}
int main()
{
	struct node *newnode, *curnode;
	int x,pos;
	scanf("%d", &x);
	while (x == 1)
	{
		newnode = (struct node *)malloc(sizeof(struct node));
		scanf("%d", &newnode->data);
		if (start == NULL)
		{
			start = newnode;
			curnode = newnode;
			curnode->next = start;
		}
		else
		{
			curnode->next = newnode;
			curnode = newnode;
			curnode->next = start;
		}
		scanf("%d", &x);
	}
	scanf("%d", &pos);
	newnode = cll(start, pos);
	newnode = start;
	printf("%d->", newnode->data);
	newnode = newnode->next;
	while (newnode != start)
	{
		printf("%d->", newnode->data);
		newnode = newnode->next;
	}
	getch();
	return 0;
}