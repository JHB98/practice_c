//똬리 배열
//수강생 정문수
#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996);
int** make_ary(int *num);
void input_ary(int **p, int num);
void print_ary(int**p, int num);
void free_ary(int **p, int num);
int main()
{
	int **p;
	int num;
	p = make_ary(&num);
	input_ary(p,num);
	print_ary(p, num);
	free_ary(p, num);

	return 0;
}

int** make_ary(int *num)
{
	int i;
	int **p;
	printf("# ? x ? 행렬 : ");
	scanf("%d", num);
	printf("\n\n");

	p = (int **)malloc(sizeof(int *) * (*num));

	for (i = 0;i < (*num);i++)
	{
		p[i] = (int *)malloc(sizeof(int) * (*num));
	}

	return p;
}

void input_ary(int **p, int num)
{
	int i, j, k, l;
	int count = 1;
	int line = 0, row = num-1;
		
	while (1)
	{
		for (i = line;i < num - line - 1;i++)
		{
			p[line][i] = count;
			count++;
		}

		for (j = line;j < num - line - 1;j++)
		{
			p[j][row] = count;
			count++;
		}

		for (k = num - line - 1;k > num - row - 1;k--)
		{
			p[num - line - 1][k] = count;
			count++;
		}

		for (l = num - line - 1;l > num - row - 1;l--)
		{
			p[l][num - row - 1] = count;
			count++;
		}

		line++;
		row--;

		if (row == (num - 1) / 2)
		{
			break;
		}
	}
	if ((num % 2))
	{
		p[line][row] = count;
	}
	return;
}

void print_ary(int**p, int num)
{
	int i, j;

	for (i = 0;i < num;i++)
	{
		for (j = 0;j < num;j++)
		{
			printf("%3d", p[i][j]);
		}
		printf("\n");
	}
	printf("\n");

	return;
}

void free_ary(int **p, int num)
{
	int i;
	for (i = 0;i < num;i++)
	{
		free(p[i]);
	}
	free(p);

	return;
}

