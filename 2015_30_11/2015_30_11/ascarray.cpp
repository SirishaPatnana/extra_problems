//8.Given a linked list which is in pattern like combination of ascending and descending. Sort it.(First all ascending numbers occur ,next all descending nums )
//Note: min of descending part is greater than max of ascending
//Ex : Input 1->2->7->20->15->10
//	 Output 1->2->7->10->15->20
#include<stdio.h>
#include<stdlib.h>
#include<conio.h>
struct node
{
	int data;
	struct node *next;
}*start = NULL;
struct node* reverse(struct node *head)
{
	struct node *current, *pre = NULL, *post;
	current = head;
	while (current != NULL)
	{
		post = current->next;
		current->next = pre;
		pre = current;
		current = post;
	}
	head = pre;
	return head;
}
struct node* largesum(struct node* start)
{
	struct node *head, *rev, *head1, *head2, *pre1, *pre2, *post1, *post2;
	head = start;
	while (head != NULL)
	{
		pre1 = head;
		head = head->next;
		if (pre1->data >= head->data)
		{
			post1 = head;
			head1 = pre1;
			break;
		}
	}
	head = start;
	head = reverse(head);
	start = head;
	while (head != NULL)
	{
		pre1 = head;
		head = head->next;
		if (pre1->data <= head->data)
		{
			head2 = pre1;
			pre2 = head;
			break;
		}
	}
	head = start;
	start = reverse(head);
	head = start;
	if (head == head1)
		pre1 = NULL;
	else
	{
		while (head != NULL)
		{
			pre1 = head;
			head = head->next;
			if (head == head1)
				break;

		}
	}
	head = start;
	if (head2->next == NULL)
		post2 = NULL;
	else
		post2 = head2->next;
	if (pre1 == NULL)
		start = head2;
	else
		pre1->next = head2;
	if (head2 != post1)
	{		
		head2->next = post1;
		pre2->next = head1;
	}
	else
		head2->next = head1;
	
	head1->next = post2;
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
	newnode = largesum(start);
	while (newnode != NULL)
	{
		printf("%d->", newnode->data);
		newnode = newnode->next;
	}
	getch();
	return 0;
}