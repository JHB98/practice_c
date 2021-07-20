//3차원 배열 동적메모리 할당
//수강생 정문수
#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996);
int*** make_ary(int *page, int *line, int *row);
void input_ary(int ***p, int * page, int *line, int *row);
void print_ary(int ***p, int *page, int *line, int *row);
void free_ary(int ***p, int *page, int *line, int *row);
int main()
{
	int ***p;
	int page, line, row;

	p = make_ary(&page, &line, &row);
	input_ary(p, &page, &line, &row);
	print_ary(p, &page, &line, &row);
	free_ary(p, &page, &line, &row);

	return 0;
}
int*** make_ary(int *page, int *line, int *row)
{
	int ***p;
	int i,j;

	printf("page : ");
	scanf("%d", page);

	printf("line : ");
	scanf("%d", line);

	printf("row : ");
	scanf("%d", row);

	p = (int ***)malloc(sizeof(int **) * (*page));

	for (i = 0;i < *line;i++)
	{
		p[i] = (int **)malloc(sizeof(int *) * (*line));
	}

	for (i = 0;i < *page;i++)
	{
		for (j = 0;j < *line;j++)
		{
			p[i][j] = (int *)malloc(sizeof(int) * (*row));
		}
	}

	return p;
}
void input_ary(int ***p, int * page, int *line, int *row )
{
	int k, l, n, input = 1;
	for (k = 0;k < *page;k++)
	{
		for (l = 0;l < *line;l++)
		{
			for (n = 0;n < *row;n++)
			{
				p[k][l][n] = input;
				input++;
			}
		}
	}

	return;
}
void print_ary(int ***p, int *page, int *line, int *row)
{
	int k, l, n;
	for (k = 0;k < *page;k++)
	{
		for (l = 0;l < *line;l++)
		{
			for (n = 0;n < *row;n++)
			{
				printf("%3d", p[k][l][n]);
			}
			printf("\n");
		}
		printf("\n\n");
	}

	return;
}
void free_ary(int ***p, int *page, int *line, int *row)
{
	int i, j, k;

	for (i = 0;i < *page;i++)
	{
		for (j = 0;j < *line;j++)
		{
			free(p[i][j]);
		}
	}

	for (k = 0;k < *page;k++)
	{
		free(p[k]);
	}

	//free(p); //이부분만 실행하면 런타임 에러가 뜨는데 왜 그런지 모르겠어요 ㅠㅠ...

	return;
}