//5.Given three numbers n1,n2,and r. Merge the table of n1 and n2 and find the r th number. In merging it should eliminate duplicate values (tables consists the multiples of those numbers ,ie 3 contains 3,6,9,12..)
//Ex, n1 = 3, n2 = 5 and r = 5, The merged table is 3, 5, 9, 10, 12, 15(One more 15 is removed as its duplicate) 18, 20, 21, 24, 25........so on .
//The rth num ie 5th number is 12, so OP is 12
#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int kth(int n1, int n2, int k)
{
	int i = 1, j = 1, count, l = 0, *a;
	a = (int *)malloc(sizeof(int)* 100);
	while (n1*i != n1*n2)
		i++;
	while (n2*j != n1*n2)
		j++;
	count = i + j - 1;
	int p = 1, q = 1;
	for (l = 0; l < count; l++)
	{
		if (p*n1 < q*n2)
		{
			a[l] = 1;
			p++;		
		}
		else
		{
			a[l] = 2;
			q++;
		}
	}
	p = k % 7;
	q = 0;
	p = a[p];
	if (p == 2)
	{
		i = j;
		n1 = n2;
	}
	for (l = 0; l <= k % count; l++)
	{
		if (a[l] == p)
			q++;
	}
	q = q + (i)*(k / count);
	return n1*q;
}
int main()
{
	int n1, n2, max, k;
	scanf("%d %d %d", &n1, &n2, &k);
	printf("%d", kth(n1, n2, k));
	getch();
	return 0;
}