#include<stdio.h>
#pragma warning (disable:4996);
void floyd(int n, int **W, int **D, int **P);
void path(int q, int r, int **P);
int main()
{
	int n = 0;
	printf("n을 입력하세요. : ");
	scanf("%d", &n);
	int ** W = new int *[n];
	for (int a = 0;a < n;a++)
	{
		W[a] = new int[n];
	}
	
	int **D = new int *[n];
	for (int a = 0;a < n;a++)
	{
		D[a] = new int[n];
	}

	int ** P = new int *[n];
	for (int a = 0;a < n;a++)
	{
		P[a] = new int[n];
	}
	printf("그래프를 입력하세요(경로가 없는것은 가중치 1234로 입력)\n");
	for (int i = 0;i < n;i++)
	{
		printf("%d행 : ", i + 1);
		for (int j = 0;j < n;j++)
		{
			int num;
			scanf("%d", &num);
			W[i][j] = num;
		}
	}

	floyd(n, W, D, P);

	int start, finish;
	printf("찾고 싶은 최단 경로의 시작점을 입력하세요 : ");
	scanf("%d", &start);
	printf("찾고 싶은 최단 경로의 도착점을 입력하세요 : ");
	scanf("%d", &finish);
	printf("v%d -> ", start);
	path(start, finish, P);
	printf("v%d", finish);

	return 0;
}
void floyd(int n, int **W, int **D, int **P) {
	int i, j, k;
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++)
		{
			P[i][j] = -1;
		}
	}
	D = W;
	for (k = 0; k < n; k++)
	{
		for (i = 0; i < n; i++)
		{
			for (j = 0; j < n; j++)
			{
				if (D[i][k] + D[k][j] < D[i][j])
				{
					P[i][j] = k;
					D[i][j] = D[i][k] + D[k][j];
				}
			}
		}
	}
}

void path(int q, int r,int **P) 
{
	if (P[q][r] != -1) 
	{
		path(q, P[q][r],P);
		printf("v%d -> ",P[q][r]);
		path(P[q][r], r,P);
	}
}