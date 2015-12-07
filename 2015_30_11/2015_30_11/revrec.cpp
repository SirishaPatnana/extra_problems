//4.Reverse an Linked list , using recursion
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
}*start = NULL;
struct node* rev(struct node* head)
{
	struct node* post;
	if (head == NULL)
		return NULL; 
	if (head->next == NULL)
		return head;
	post= rev(head->next);
	head->next->next = head; 
	head->next = NULL;
	return post; 
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
	newnode = rev(start);
	while (newnode != NULL)
	{
		printf("%d->", newnode->data);
		newnode = newnode->next;
	}
	getch();
	return 0;
}