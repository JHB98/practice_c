//�Ҽ� ���
//������ ������
#include<stdio.h>
#include<math.h>
#pragma warning (disable:4996);
int input();
int primeNumber(int number);
int main()
{
	int number, i, check, count = 0;
	number = input();

	printf("\n1~%d ������ �Ҽ� ���� ������ �����ϴ�.\n", number);
	for (i = 2;i <= number;i++)
	{
		check = primeNumber(i);
		if (check == 1)
		{
			printf("%5d", i);
			count++;
			if (count % 5 == 0)
			{
				printf("\n");
			}
		}
	}
	printf("\n1~%d ������ �� �Ҽ��� %d�� �Դϴ�.\n\n", number, count);

	return 0;
}

int input()
{
	int number;
	
	while (1)
	{
		printf("* ������ �ϳ��� �Է��Ͻÿ� : ");
		scanf("%d", &number);
		if (getchar() == '\n')
		{
			break;
		}
		while (1)
		{
			if (getchar() == '\n')
			{
				break;
			}
		}
	}

	return number;
}

int primeNumber(int number)
{
	int j;
	for (j = 2;j <= sqrt((double)number);j++)
	{
		if (number%j == 0)
		{
			return 0;
		}
	}

	return 1;
}