#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int money, rank;
	int under50 = 0, up50_under100 = 0, up100 = 0;
	int tax_under50 = 0, tax_up50_under100 = 0, tax_up100 = 0;
	printf("�� ���Ծ� : ");
	scanf("%d", &money);
	if (money <= 500000)
	{
		under50 = money;
	}
	if ((money > 500000) && (money <= 1000000))
	{
		under50 = 500000;
		up50_under100 = money - 500000;
	}
	if (money > 1000000)
	{
		under50 = 500000;
		up50_under100 = 500000;
		up100 = money - 1000000;
	}
	printf("���(1. ��Ȱ ��ȣ �����, 2. ���� ������, 3. �Ϲ�) : ");
	scanf("%d", &rank);
	switch (rank)
	{
	case 1:
		printf("****************************************\n");
		printf("�� ���Ծ� : %d             ��� : %d\n", money, rank);
		printf("****************************************\n");
		printf("�ݾ�              ����              ����\n");
		printf("----------------------------------------\n");
		if (up50_under100 == 0)
		{
			tax_under50 = under50 * (2 / 100);
			printf("%d           %%2           %d\n", under50, tax_under50);
		}
		if ((up50_under100 != 0) && (up100 == 0))
		{
			tax_under50 = under50 * (2 / 100);
			tax_up50_under100 = up50_under100 * (2 / 100);
			printf("%d           %%2           %d\n", under50, tax_under50);
			printf("%d           %%2           %d\n", up50_under100, tax_up50_under100);
		}
		if (up100 != 0)
		{
			tax_under50 = under50 * 2 / 100;
			tax_up50_under100 = up50_under100 * 2 / 100;
			tax_up100 = up100 * 5 / 100;
			printf("%d           %%2           %d\n", under50, tax_under50);
			printf("%d           %%2           %d\n", up50_under100, tax_up50_under100);
			printf("%d           %%5           %d\n", up100, tax_up100);
		}
		printf("----------------------------------------\n");
		printf("�� ���� :                    %d\n", tax_under50 + tax_up50_under100 + tax_up100);
		printf("========================================\n");
		break;

	case 2:
			printf("****************************************\n");
			printf("�� ���Ծ� : %d             ��� : %d\n", money, rank);
			printf("****************************************\n");
			printf("�ݾ�              ����              ����\n");
			printf("----------------------------------------\n");
			if (up50_under100 == 0)
			{
				tax_under50 = under50 * (2 / 100);
				printf("%d           %%2           %d\n", under50, tax_under50);
			}
			if ((up50_under100 != 0) && (up100 == 0))
			{
				tax_under50 = under50 * (2 / 100);
				tax_up50_under100 = up50_under100 * (2 / 100);
				printf("%d           %%2           %d\n", under50, tax_under50);
				printf("%d           %%2           %d\n", up50_under100, tax_up50_under100);
			}
			if (up100 != 0)
			{
				tax_under50 = under50 * 2 / 100;
				tax_up50_under100 = up50_under100 * 2 / 100;
				tax_up100 = up100 * 5 / 100;
				printf("%d           %%2           %d\n", under50, tax_under50);
				printf("%d           %%2           %d\n", up50_under100, tax_up50_under100);
				printf("%d           %%5           %d\n", up100, tax_up100);
			}
			printf("----------------------------------------\n");
			printf("�� ���� :                    %d\n", tax_under50 + tax_up50_under100 + tax_up100);
			printf("========================================\n");
			break;

	case 3 : 
		printf("****************************************\n");
		printf("�� ���Ծ� : %d             ��� : %d\n", money, rank);
		printf("****************************************\n");
		printf("�ݾ�              ����              ����\n");
		printf("----------------------------------------\n");
		if (up50_under100 == 0)
		{
			tax_under50 = under50 * (2 / 100);
			printf("%d           %%2           %d\n", under50, tax_under50);
		}
		if ((up50_under100 != 0) && (up100 == 0))
		{
			tax_under50 = under50 * (2 / 100);
			tax_up50_under100 = up50_under100 * (5 / 100);
			printf("%d           %%2           %d\n", under50, tax_under50);
			printf("%d           %%5           %d\n", up50_under100, tax_up50_under100);
		}
		if (up100 != 0)
		{
			tax_under50 = under50 * 2 / 100;
			tax_up50_under100 = up50_under100 * 5 / 100;
			tax_up100 = up100 * 7 / 100;
			printf("%d           %%2           %d\n", under50, tax_under50);
			printf("%d           %%5           %d\n", up50_under100, tax_up50_under100);
			printf("%d           %%7           %d\n", up100, tax_up100);
		}
		printf("----------------------------------------\n");
		printf("�� ���� :                    %d\n", tax_under50 + tax_up50_under100 + tax_up100);
		printf("========================================\n");
		break;
	}
	return 0;
}