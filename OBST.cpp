#include<stdio.h>
#pragma warning (disable:4996);
void optsearchtree(int n, float *p, float& minavg, int **R);
int main()
{
	int n = 0;
	float minavg = 0;
	printf("몇개의 node를 입력하시겠습니까? : ");
	scanf("%d", &n);
	float *p = new float[n+1];
	for (int i = 1;i < n + 1;i++)
	{
		printf("%d 번째 node의 확률을 입력하세요 : ", i);
		scanf("%f", &p[i]);
	}
	int **R = new int *[n + 2];
	for (int h = 1;h < n + 2;h++)
	{
		R[h] = new int[n + 1];
	}

	optsearchtree(n, p, minavg, R);
	printf("\n\nminavg : %f\n\n", minavg);
	printf("R 배열\n");
	for (int i = 1;i < n+2;i++)
	{
		for (int j = 0;j < n+1;j++)
		{
			printf("%d ", R[i][j]);
		}
		printf("\n");
	}

	return 0;
}

void optsearchtree(int n, float *p, float& minavg, int **R)
{
	int i, j, k, diagonal;
	float **A = new float *[n + 2];
	for (int h = 1;h < n + 2;h++)
	{
		A[h] = new float[n + 1];
	}

	for (i = 1; i < n+1; i++) 
	{
		A[i][i - 1] = 0; 
		A[i][i] = p[i]; 
		R[i][i] = i; 
		R[i][i - 1] = 0;
	}
	A[n + 1][n] = 0; R[n + 1][n] = 0;
	
	float minimum = 100;
	for (diagonal = 1; diagonal <= n - 1; diagonal++)
	{
		for (i = 1; i <= n - diagonal; i++) 
		{
			j = i + diagonal;
			for (int k = i;k <= j;k++)
			{
				float sigma_p = 0;
				for (int l = i;l <= j;l++)
				{
					sigma_p += p[l];
				}
				if (minimum > (A[i][k - 1] + A[k + 1][j] + sigma_p))
				{
					minimum = (A[i][k - 1] + A[k + 1][j] + sigma_p);
					R[i][j] = k;
				}
				A[i][j] = minimum;
			}
			minimum = 100;
		}
	}
	minavg = A[1][n];
}