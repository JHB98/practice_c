#include<stdio.h>
#pragma warning (disable:4996);
void floyd(int n, int **W, int **D, int **P);
void path(int q, int r, int **P);
int main()
{
	int n = 0;
	printf("n�� �Է��ϼ���. : ");
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
	printf("�׷����� �Է��ϼ���(��ΰ� ���°��� ����ġ 1234�� �Է�)\n");
	for (int i = 0;i < n;i++)
	{
		printf("%d�� : ", i + 1);
		for (int j = 0;j < n;j++)
		{
			int num;
			scanf("%d", &num);
			W[i][j] = num;
		}
	}

	floyd(n, W, D, P);

	int start, finish;
	printf("ã�� ���� �ִ� ����� �������� �Է��ϼ��� : ");
	scanf("%d", &start);
	printf("ã�� ���� �ִ� ����� �������� �Է��ϼ��� : ");
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