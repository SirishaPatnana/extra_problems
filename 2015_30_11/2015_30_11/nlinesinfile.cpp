//10. Print the last n lines of a file
#include<stdio.h>
#include<conio.h>
int main()
{
	int c = 0, k;
	char d, e, ch;
	FILE *f, *f2;
	f2 = fopen("t2.txt", "w");
	f = fopen("t1.txt", "r");
	while ((d = fgetc(f)) != EOF)
	{
		if (d == '\n')
			c++;
	}
	printf("%d", c + 1);
	scanf("%d", &k);
	rewind(f);
	while ((c - k) >= 0)
	{
		ch = getc(f);
		if (ch == '\n')
			c--;
	}
	while ((d = fgetc(f)) != EOF)
	{
		fputc(d, f2);
		printf("%c", d);
	}
	fclose(f);
	fclose(f2);
	getch();
	return 0;
}

