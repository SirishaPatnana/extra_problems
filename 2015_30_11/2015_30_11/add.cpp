//6.Write a program to add two linked list (Each node is represented by a digit ) (Note: Unequal Lengths can also be given )
//Ex: Input 1->2->3->4 and 1->2->3->4
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*head = NULL, *start1 = NULL, *start2 = NULL;
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
int add(struct node *head1, struct node *head2)
{
	int c = 0, sum = 0;
	head1 = reverse(head1);
	head2 = reverse(head2);
	start1 = head1;
	start2 = head2;
	while (head1 != NULL && head2 != NULL)
	{
		int d = c + head1->data + head2->data;
		if (d >= 10)
		{
			c = 1;
			d = d % 10;
		}
		else
			c = 0;
		sum = sum * 10 + d;
		head1 = head1->next;
		head2 = head2->next;
	}
	while (head1 != NULL)
	{
		sum = sum * 10 + c + head1->data;
		c = 0;
		head1 = head1->next;
	}
	while (head2 != NULL)
	{
		sum = sum * 10 + c + head2->data;
		c = 0;
		head2 = head2->next;
	}
	sum = sum * 10 + c;
	int rev = 0;
	while (sum > 0)
	{
		int r = sum % 10;
		rev = (rev * 10) + r;
		sum = sum / 10;
	}
	return rev;
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

		if (start1 == NULL)
		{
			start1 = newnode;
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
	printf("%d", add(start1, start2));
	getch();
	return 0;
}