//���� ���߱� ����
//������ ������
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int output(int num, int answer, int *low, int *high);
int main()
{
	int answer, num, count = 0, low = 0, high = 100;

	srand((unsigned int)time(NULL));
	answer = rand() % 101;

	while (1)
	{
		num = input();
		count++;
		if (output(num, answer, &low, &high))
		{
			break;
		}
	}
	printf("\n\n\n");
	printf("���~�¾Ҵ�~~��ī��ī~~%d ��° ���� ���߼̽��ϴ�.\n", count);

	return 0;
}

int input()
{
	int num;
	while (1)
	{
		printf("# ���ڸ� �Է��Ͻÿ�(1~100) : ");
		scanf("%d", &num);
		if (getchar() == '\n')
		{
			if ((num > 0) && (num < 101))
			{
				break;
			}

			else
			{
				continue;
			}
		}
		while (1)
		{
			if (getchar() == '\n')
			{
				break;
			}
		}
	}
	
	return num;
}

int output(int num, int answer, int *low, int*high)
{
	if (num > answer)
	{
		*high = num;
		printf("%d���ٴ� ũ�� %d���ٴ� �۽��ϴ�.\n",*low,*high);
	}

	else if (num < answer)
	{
		*low = num;
		printf("%d���ٴ� ũ�� %d���ٴ� �۽��ϴ�.\n", *low, *high);
	}

	else
	{
		return 1;
	}

	return 0;
}