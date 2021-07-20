#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int data[5][4] = { 0 };
	char worker[5][10] = { "Kim","Lee","Park","Song","Choi" };
	int sum[7] = { 0 };
	int quarterSum[4] = { 0 };
	float quarterAvg[4] = { 0 };
	float yearAvg = 0;
	char graph[10][4] = { " " };
	int starNum[4] = { 0 };
	for (int i = 0;i < 5;i++)
	{
		printf("%s �� �Ǹ� ������ �Է��ϼ���(1/4,2/4,3/4,4/4) : ", worker[i]);
		for (int l = 0;l < 4;l++)
		{
			scanf("%d", &data[i][l]);
			sum[i] += data[i][l];
		}
	}

	for (int i = 0;i < 4;i++)
	{
		for (int k = 0;k < 5;k++)
		{
			quarterSum[i] += data[k][i];
		}
		sum[5] += quarterSum[i];
	}

	for (int j = 0;j < 4;j++)
	{
		quarterAvg[j] = quarterSum[j] / 5;
		sum[6] += quarterAvg[j];
	}

	printf("================================================================\n");
	printf("�ǸŻ��   1/4�б�   2/4�б�   3/4�б�   4/4�б�   ����\n");
	printf("================================================================\n");
	for (int i = 0;i < 5;i++)
	{
		printf("%s		", worker[i]);
		for (int j = 0;j < 4;j++)
		{
			printf("%d	", data[i][j]);
		}

		printf("%d\n", sum[i]);
	}
	printf("�б�����	");
	for (int j = 0;j < 4;j++)
	{
		printf("%d	", quarterSum[j]);
	}
	printf("%d\n", sum[5]);
	printf("================================================================\n");
	printf("�б����	");
	for (int k = 0;k < 4;k++)
	{
		printf("%.2f   ", quarterAvg[k]);
	}
	printf("%d\n", sum[6]);
	printf("================================================================\n");

	yearAvg = sum[5] / 5;
	for (int k = 0;k < 4;k++)
	{
		starNum[k] = ((quarterAvg[k] * 100) / yearAvg) / 10;
	}
	for (int m = 0;m < 4;m++)
	{
		for (int h = 9;h >= 0;h--)
		{
			if (starNum[m] != 0)
			{
				graph[h][m] = '*';
				starNum[m] -= 1;
			}
		}
	}
	printf("�б⺰ �Ǹ� ���� �׷���\n");
	printf("\n===========================================\n");
	for (int n = 0;n < 10;n++)
	{
		printf("|");
		for (int m = 0;m < 4;m++)
		{
			printf("%c	", graph[n][m]);
		}
		printf("\n");
	}
	printf("\n============================================\n");
	printf("1/4   2/4   3/4   4/4\n");


	return 0;
}