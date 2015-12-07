//1.Find median of a given linked list
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
struct node
{
	int data;
	struct node *next;
}*start = NULL;
float median(struct node *head)
{
	int c = 0;
	struct node *pre;
	if (head == NULL)
		return 0;
	while (head != NULL)
	{
		head = head->next;
		c++;
	}
	head = start;
	int d;
	float k;
	d = c/2;
	while (d> 0)
	{
		pre = head;
		head = head->next;
		d--;
	}
	k = head->data;
	//printf("%f", k);
	if (c % 2 == 0&&c!=0)
	{
	k = k + pre->data;
	//printf(" pre  %d", pre->data);
	k = k / 2;
	}
	return k;
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
	newnode = start;
	printf("%f", median(newnode));
	/*newnode = start;
	while (newnode != NULL)
	{
	printf("%d->", newnode->data);
	newnode = newnode->next;
	}*/
	getch();
	return 0;
}