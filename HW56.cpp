//배열의 부분합 구하기(2차원)
//수강생 정문수
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#pragma warning (disable:4996);
void random_ary(int(*num)[5]);
void cal_ary(int(*num)[5], int *sum1, int*sum2, int *sum3);
void show_ary(int(*num)[5], int *sum1, int*sum2, int *sum3);
int main()
{
	int num[5][5] = { 0 };
	int sum1 = 0, sum2 = 0, sum3 = 0;
	srand((unsigned int)time(NULL));
	random_ary(num);
	cal_ary(num, &sum1, &sum2, &sum3);
	show_ary(num, &sum1, &sum2, &sum3);

	return 0;
}

void random_ary(int(*num)[5])
{
	int i, j, res;
	for (i = 0;i < 5;i++)
	{
		for (j = 0;j < 5;j++)
		{
			res = (rand()% 20)+1;
			num[i][j] = res;
		}
	}

	return;
}

void cal_ary(int(*num)[5], int *sum1, int*sum2, int *sum3)
{
	int i, j, k, l, n;
	for (i = 0;i < 5;i++)
	{
		*sum1 += num[i][i];
		
	}
	for (j = 1;j < 5;j++)
	{
		for (k = 0;k < j;k++)
		{
			*sum2 += num[j][k];
		}
	}
	
	for (l = 0;l < 5;l++)
	{
		for (n = l+1;n < 5;n++)
		{
			*sum3 += num[l][n];
		}
	}

	return;
}

void show_ary(int(*num)[5], int *sum1, int*sum2, int *sum3)
{
	int i, j;
	for (i = 0;i < 5;i++)
	{
		printf("%d번 행     :", i);

		for (j = 0;j < 5;j++)
		{
			printf("%3d", num[i][j]);
		}
		printf("\n");
	}
	printf("\nsum1 = %d\nsum2 = %d\nsum3 = %d\n",*sum1,*sum2,*sum3);

	return;
}