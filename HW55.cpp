//3행 4열 짜리 배열의 행,열의 합 구하기
//수강생 정문수
#include<stdio.h>
#include<time.h>
#include<stdlib.h>
#pragma warning (disable:4996);
void random_ary(int(*num)[4]);
void show_cal_ary(int(*num)[4]);
int main()
{
	int num[3][4] = { 0 };
	srand((unsigned int)time(NULL));
	random_ary(num);
	show_cal_ary(num);

	return 0;
}

void random_ary(int (*num)[4])
{
	int i, j, res;
	for (i = 0;i < 3;i++)
	{
		for (j = 0;j < 4;j++)
		{
			res = rand() % 10;
			num[i][j] = res;
		}
	}

	return;
}

void show_cal_ary(int(*num)[4])
{
	int i, j, sum = 0;
	for (i = 0;i < 3;i++)
	{
		printf("%d행     :", i);

		for (j = 0;j < 4;j++)
		{
			printf("%3d", num[i][j]);
			sum += num[i][j];
		}
		printf("%5d행의 합 : %d", i, sum);
		printf("\n");
		sum = 0;
	}

	printf("%열의 합 :");
	for (i = 0;i < 4;i++)
	{
		for (j = 0;j < 3;j++)
		{
			sum += num[j][i];
		}
		printf("%3d", sum);

		sum = 0;
	}
	printf("\n");
	return;
}