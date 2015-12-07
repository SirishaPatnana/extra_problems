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
struct node* subarr(struct node *b)
{
	struct node *a = b, *c = NULL, *e, *f = b;
	int i, k = 0, l, d;
	c = a;
	for (i = 0; a != NULL; i++)
	{

		if (a->data>(a->next)->data)
		{
			k = i;
			break;
		}
		d = a->data;
		a = a->next;
	}
	a = b;
	while (a != NULL)
	{
		if (a->data == d)
			k--;
		a = a->next;
	}
	k += 1;
	a = reverse(f);
	while (a != NULL)
	{
		if (a->data<(a->next)->data)
		{
			l = i;
			break;
		}
		a = a->next;
	}
	d = a->data;
	a->next = NULL;
	a = reverse(a);
	while (a != NULL)
	if (a->data == d)
		l++;
	a = b;
	i = 1;
	while (a != NULL)
	{
		if (i == k)
		{
			c = a;
		}
		if (i == l)
		{
			a->next = NULL;
		}
		a = a->next;
		i++;
	}
	c = reverse(c);
	a = b;
	e = b;
	i = 1;
	while (e != NULL)
	{
		if (i == k - 1)
			a->next = c;
		else if (i == l)
			a->next = e;
		else if (i < k - 1)
			a = a->next;
		e = e->next;
		i++;
	}
	return a;
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
	newnode = subarr(start);
	while (newnode != NULL)
	{
		printf("%d->", newnode->data);
		newnode = newnode->next;
	}
	getch();
	return 0;
}