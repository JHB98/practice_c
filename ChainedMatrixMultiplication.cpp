#include<stdio.h>
#pragma warning (disable:4996);
void order(int i, int j, int **P);
void minmult(int n, int *d, int **P);
int main()
{
	int n = 0;
	int line = 0;
	int num = 0;
	printf("몇개의 행렬을 곱하실건가요? : ");
	scanf("%d", &n);

	int *d = new int[n+1];
	printf("첫번째 행렬의 행을 입력하세요 : ");
	scanf("%d", &line);
	d[0] = line;
	for (int i = 1;i < n+1;i++)
	{
		printf("각 행렬의 열수를 입력하세요 :");
		scanf("%d", &line);
		d[i] = line;
	}

	int ** P = new int *[n];
	for (int a = 1;a < n;a++)
	{
		P[a] = new int[n+1];
	}

	minmult(n, d, P);
	printf("\n최적의 순서\n");
	order(1, n, P);
	printf("\n");

	return 0;
}

void minmult(int n, int *d, int **P)
{
	int i, j, k, diagonal;
	int **M = new int *[n+1];
	for (int h = 1;h < n+1;h++)
	{
		M[h] = new int[n+1];
	}

	for (i = 1; i < n+1; i++)
	{
		M[i][i] = 0;
	}

	int minimum = 99999999;
	for (diagonal = 1; diagonal <= n - 1; diagonal++)
	{
		for (i = 1; i <= n - diagonal; i++)
		{
			j = i + diagonal;
			for (int k = i;k <= j - 1;k++)
			{
				if (minimum > (M[i][k] + M[k + 1][j] + (d[i - 1] * d[k] * d[j])))
				{
					minimum = (M[i][k] + M[k + 1][j] + (d[i - 1] * d[k] * d[j]));
					P[i][j] = k;
				}
				M[i][j] = minimum;
			}
			minimum = 9999999;
		}
	}

	printf("M 배열\n");
	for (int i = 1;i <= n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			printf("%d ", M[i][j]);
		}
		printf("\n");
	}

	printf("P 배열\n");
	for (int i = 1;i < n;i++)
	{
		for (int j = 1;j <= n;j++)
		{
			printf("%d ", P[i][j]);
		}
		printf("\n");
	}
}
void order(int i, int j,int **P)
{
	int k = 0;
	if (i == j)
	{
		printf("A%d", i);
	}
	else {
		k = P[i][j];
		printf("(");
		order(i,k,P);
		order(k + 1, j,P);
		printf(")");
	}
}

