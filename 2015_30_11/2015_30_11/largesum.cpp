//9 . Largest Contiguous Sum Array .
//Ex: 1, 2, 3, 5, -10, 20, 40 O / P : 20, 40 Sum : 60
#include<stdio.h>
#include<conio.h>

#include<stdlib.h>
int arr(int *a, int n)
{
	int i = 0,j = 0,sum=0,*p;
	p = (int*)malloc(sizeof(int)*n);
	for (i = 0; i < n; i++)
	{
		sum = 0;
		for (j = i; j < n; j++)
		{
			if (sum > sum + a[j])
				break;
			sum = sum + a[j];
		}
		p[i] = sum;
	}
	j = 0;
	sum = p[0];
	for (i = 0; i < n; i++)
	{
		if (p[i]>sum)
		{
			sum = p[i];
			j = i;
		}
	}
	return j;
}
int main()
{
	int *p, i,k,sum,n;
	scanf("%d", &n);
	p = (int*)malloc(sizeof(int)*n);
	for (i = 0; i<n; i++)
	{
		scanf("%d", &p[i]);
	}
	k=arr(p, n);
	sum = 0;
	for (i = k; i<n; i++)
	{
		if (sum < sum + p[i])
			printf("%d  ", p[i]);
		else
			break;
		sum = sum + p[i];
	}
	printf("%d", sum);
	getch();
	return 0;
}