#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int scores[6][5] = { 0 };
	int sum = 0;
	double aves[5];
	printf("�л������� �Է� �ϼ��� (5���� �л� �ڷ�)\n");
	for (int i = 0;i < 5;i++)
	{
		printf("%d ��(����,����,����) : ", i + 1);
		for (int l = 1;l < 4;l++)
		{
			*scores[i] = i+1;
			scanf("%d", &*(*(scores + i) + l));
			sum += *(*(scores + i) + l);
		}
		*(*(scores + i) + 4) = sum;
		sum = 0;
	}

	**(scores+5) = 0;
	for (int k = 1;k < 5;k++)
	{
		for (int m = 0;m < 5;m++)
		{
			*(*(scores+5)+k) += *(*(scores+m)+k);
		}
	}

	printf("===========================================\n");
	printf("��ȣ   ����   ����   ����   ����\n");
	printf("===========================================\n");
	for (int i = 0;i < 5;i++)
	{
		for (int k = 0;k < 5;k++)
		{
			printf("%d	", *(*(scores+i)+k));
		}
		printf("\n");
	}
	printf("===========================================\n");
	printf("��������   ");
	for (int h = 1;h < 5;h++)
	{
		printf("%d	", *(*(scores+5)+h));
	}
	printf("\n");
	printf("===========================================\n");
	printf("�������   ");
	for (int k = 1;k < 5;k++)
	{
		*(aves+k) = (*(*(scores+5)+k) / 5);
		printf("%.2lf	", *(aves+k));
	}
	printf("\n===========================================\n");


}