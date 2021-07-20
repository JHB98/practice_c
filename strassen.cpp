#include<stdio.h>
#pragma warning (disable:4996);
void strassen(int n, int **A, int **B, int **C);
void matrix_mul(int n, int **A, int **B, int **C);
void matrix_plus(int n, int **A, int **B, int **C);
void matrix_sub(int n, int **A, int **B, int **C);
int main()
{
	int n = 0;
	printf("배열 사이즈를 입력하세요(2의 배수) : ");
	scanf("%d", &n);
	int ** ary1 = new int *[n];
	for (int a = 0;a < n;a++)
	{
		ary1[a] = new int[n];
	}

	int ** ary2 = new int *[n];
	for (int b = 0;b < n;b++)
	{
		ary2[b] = new int[n];
	}

	int ** result = new int *[n];
	for (int  c= 0;c < n;c++)
	{
		result[c] = new int[n];
	}

	printf("첫번째 배열안에 넣을 숫자를 입력하세요 \n");
	for (int d = 0;d < n;d++)
	{
		for (int e = 0;e < n;e++)
		{
			int num1 = 0;
			scanf("%d", &num1);
			ary1[d][e] = num1;
		}
	}

	printf("두번째 배열안에 넣을 숫자를 입력하세요 \n");
	for (int f = 0;f < n;f++)
	{
		for (int g = 0;g < n;g++)
		{
			int num1 = 0;
			scanf("%d", &num1);
			ary2[f][g] = num1;
		}
	}
	
	strassen(n, ary1, ary2, result);

	printf("\n----------------------------------------------\n");
	for (int h = 0;h < n;h++)
	{
		for (int i = 0;i < n;i++)
		{
			printf("%d ", result[h][i]);
		}
		printf("\n");
	}

	return 0;
}

void strassen(int n, int **A,int **B, int **C)
{
	if (n <= 2)
	{
		matrix_mul(n, A, B, C);
		return;
	}

	else
	{
		int ** M1 = new int *[n];
		for (int j = 0;j < n;j++)
		{
			M1[j] = new int[n];
		}

		int ** M2 = new int *[n];
		for (int k = 0;k < n;k++)
		{
			M2[k] = new int[n];
		}

		int ** M3 = new int *[n];
		for (int l = 0;l < n;l++)
		{
			M3[l] = new int[n];
		}

		int ** M4 = new int *[n];
		for (int m = 0;m < n;m++)
		{
			M4[m] = new int[n];
		}

		int ** M5 = new int *[n];
		for (int o = 0;o < n;o++)
		{
			M5[o] = new int[n];
		}

		int ** M6 = new int *[n];
		for (int p = 0;p < n;p++)
		{
			M6[p] = new int[n];
		}

		int ** M7 = new int *[n];
		for (int q = 0;q < n;q++)
		{
			M7[q] = new int[n];
		}

		int ** tmp1 = new int *[n/2];
		for (int r = 0;r < (n / 2);r++)
		{
			tmp1[r] = new int[n / 2];
		}
		
		int ** tmp2 = new int *[n/2];
		for (int s = 0;s < (n / 2);s++)
		{
			tmp2[s] = new int[n / 2];
		}

		int ** tmp3 = new int *[n / 2];
		for (int t = 0;t < (n / 2);t++)
		{
			tmp3[t] = new int[n / 2];
		}

		int ** tmp4 = new int *[n / 2];
		for (int u = 0;u < (n / 2);u++)
		{
			tmp4[u] = new int[n / 2];
		}

		for (int v = 0;v < (n / 2);v++)
		{
			for (int w = 0;w < (n / 2);w++)
			{
				tmp1[v][w] = A[v][w];
			}
		}

		for (int i = (n / 2);i < n;i++)
		{
			for (int j = (n / 2);j < n;j++)
			{
				tmp2[i - (n / 2)][j - (n / 2)] = A[i][j];
			}
		}
		
		matrix_plus(n / 2, tmp1, tmp2, tmp1);
		
		for (int i = 0;i < (n / 2);i++)
		{
			for (int j = 0;j < (n / 2);j++)
			{
				tmp3[i][j] = B[i][j];
			}
		}
		
		for (int i = (n / 2);i < n;i++)
		{
			for (int j = (n / 2);j < n;j++)
			{
				tmp4[i - (n / 2)][j - (n / 2)] = B[i][j];
			}
		}
		
		matrix_plus(n / 2, tmp3, tmp4, tmp3);
		strassen(n / 2, tmp1, tmp3, M1);
	
		for (int i = (n/2);i < n;i++)
		{
			for (int j = 0;j < (n / 2);j++)
			{
				tmp1[i - (n / 2)][j] = A[i][j];
			}
		}

		for (int i = (n / 2);i < n;i++)
		{
			for (int j = (n / 2);j < n;j++)
			{
				tmp2[i - (n / 2)][j - (n / 2)] = A[i][j];
			}
		}

		matrix_plus(n / 2, tmp1, tmp2, tmp1);

		for (int i = 0;i < (n / 2);i++)
		{
			for (int j = 0;j < (n / 2);j++)
			{
				tmp3[i][j] = B[i][j];
			}
		}
		strassen(n / 2, tmp1, tmp3, M2);
	

		for (int i = 0;i < (n / 2);i++)
		{
			for (int j = 0;j < (n / 2);j++)
			{
				tmp1[i][j] = A[i][j];
			}
		}

		for (int i = 0;i < (n/2);i++)
		{
			for (int j = (n/2);j < n;j++)
			{
				tmp3[i][j - (n / 2)] = B[i][j];
			}
		}

		for (int i = (n / 2);i < n;i++)
		{
			for (int j = (n / 2);j < n;j++)
			{
				tmp4[i - (n / 2)][j - (n / 2)] = B[i][j];
			}
		}

		matrix_sub(n / 2, tmp3, tmp4, tmp3);
		strassen(n / 2, tmp1, tmp3, M3);
	

		for (int i = (n/2);i < n;i++)
		{
			for (int j = (n/2);j < n;j++)
			{
				tmp1[i - (n / 2)][j - (n / 2)] = A[i][j];
			}
		}

		for (int i = (n/2);i < n;i++)
		{
			for (int j = 0;j < (n/2);j++)
			{
				tmp3[i - (n / 2)][j] = B[i][j];
			}
		}

		for (int i = 0;i < (n/2);i++)
		{
			for (int j = 0;j < (n/2);j++)
			{
				tmp4[i][j] = B[i][j];
			}
		}

		matrix_sub(n / 2, tmp3, tmp4, tmp3);
		strassen(n / 2, tmp1, tmp3, M4);
	

		for (int i = 0;i < (n / 2);i++)
		{
			for (int j = 0;j < (n / 2);j++)
			{
				tmp1[i][j] = A[i][j];
			}
		}

		for (int i = 0;i < (n/2);i++)
		{
			for (int j = (n/2);j < n;j++)
			{
				tmp2[i][j - (n / 2)] = A[i][j];
			}
		}

		matrix_plus(n / 2, tmp1, tmp2, tmp1);

		for (int i = (n/2);i < n;i++)
		{
			for (int j = (n/2);j < n;j++)
			{
				tmp3[i - (n / 2)][j - (n / 2)] = B[i][j];
			}
		}

		strassen(n / 2, tmp1, tmp3, M5);
	

		for (int i = (n/2);i < n;i++)
		{
			for (int j = 0;j < (n / 2);j++)
			{
				tmp1[i - (n / 2)][j] = A[i][j];
			}
		}

		for (int i = 0;i < (n/2);i++)
		{
			for (int j = 0;j < (n/2);j++)
			{
				tmp2[i][j] = A[i][j];
			}
		}

		matrix_sub(n / 2, tmp1, tmp2, tmp1);

		for (int i = 0;i < (n / 2);i++)
		{
			for (int j = 0;j < (n / 2);j++)
			{
				tmp3[i][j] = B[i][j];
			}
		}

		for (int i = 0;i < (n/2);i++)
		{
			for (int j = (n / 2);j < n;j++)
			{
				tmp4[i][j - (n / 2)] = B[i][j];
			}
		}

		matrix_plus(n / 2, tmp3, tmp4, tmp3);
		strassen(n / 2, tmp1, tmp3, M6);
	

		for (int i = 0;i < (n / 2);i++)
		{
			for (int j = (n/2);j < n;j++)
			{
				tmp1[i][j - (n / 2)] = A[i][j];
			}
		}

		for (int i = (n / 2);i < n;i++)
		{
			for (int j = (n / 2);j < n;j++)
			{
				tmp2[i - (n / 2)][j - (n / 2)] = A[i][j];
			}
		}

		matrix_sub(n / 2, tmp1, tmp2, tmp1);

		for (int i = (n/2);i < n;i++)
		{
			for (int j = 0;j < (n / 2);j++)
			{
				tmp3[i - (n / 2)][j] = B[i][j];
			}
		}

		for (int i = (n / 2);i < n;i++)
		{
			for (int j = (n / 2);j < n;j++)
			{
				tmp4[i - (n / 2)][j - (n / 2)] = B[i][j];
			}
		}

		matrix_plus(n / 2, tmp3, tmp4, tmp3);
		strassen(n / 2, tmp1, tmp3, M7);
		
		matrix_plus(n / 2, M1, M4, tmp1);
		matrix_sub(n / 2, tmp1, M5, tmp1);
		matrix_plus(n / 2, tmp1, M7, tmp1); // c11

		matrix_plus(n / 2, M3, M5, tmp2);//c12

		matrix_plus(n / 2, M2, M4, tmp3);//c21

		matrix_plus(n / 2, M1, M3, tmp4);
		matrix_sub(n / 2, tmp4, M2, tmp4);
		matrix_plus(n / 2, tmp4, M6, tmp4);//c22

		for (int i = 0;i < n;i++)
		{
			for (int j = 0;j < n;j++)
			{
				if ((i < (n / 2)) && (j < (n / 2)))
				{
					C[i][j] = tmp1[i][j];
				}

				if ((i < (n / 2)) && (j >= (n / 2)))
				{
					C[i][j] = tmp2[i][j - (n / 2)];
				}

				if ((i >= (n / 2)) && (j < (n / 2)))
				{
					C[i][j] = tmp3[i - (n / 2)][j];
				}

				if ((i >= (n / 2)) && (j >= (n / 2)))
				{
					C[i][j] = tmp4[i - (n / 2)][j - (n / 2)];
				}
			}
		}
	}
}

void matrix_mul(int n,int **A, int **B, int **C)
{
	for (int l = 0;l < n;l++)
	{
		for (int h = 0;h < n;h++)
		{
			C[l][h] = 0;
			for (int j = 0;j < n;j++)
			{
				C[l][h] += A[l][j] * B[j][h];
			}
		}
	}
}

void matrix_plus(int n, int **A, int **B, int **C)
{
	for (int h = 0;h < n;h++)
	{
		for (int j = 0;j < n;j++)
		{
			C[h][j] = A[h][j] + B[h][j];
		}
	}
}

void matrix_sub(int n, int **A, int **B, int **C)
{
	for (int h = 0;h < n;h++)
	{
		for (int j = 0;j < n;j++)
		{
			C[h][j] = A[h][j] - B[h][j];
		}
	}
}