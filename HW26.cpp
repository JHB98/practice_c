//���� ���� �� ����
//������ ������
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int output(int num, int answer, int *win, int *draw);
int main()
{
	int answer, num, win = 0, draw = 0;

	srand((unsigned int)time(NULL));

	while (1)
	{
		num = input();
		answer = rand() % 4;
		if (output(num, answer, &win, &draw))
		{
			break;
		}
	}
	printf("\n\n");
	printf("���� ��� : %d �� %d ��\n", win,draw);

	return 0;
}

int input()
{
	int num;
	while (1)
	{
		printf("# ������ 1, ������ 2, ���� 3 �߿��� �����ϼ��� : ");
		scanf("%d", &num);
		if (getchar() == '\n')
		{
			if ((num > 0) && (num < 4))
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

int output(int num, int answer, int *win, int *draw)
{	
	if (answer==1)
	{
		if (num == 1)
		{
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n\n");
			(*draw)++;
		}

		else if (num == 2)
		{
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : ����� �����ϴ�.\n\n");
			return 1;
		}

		else
		{
			printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n\n");
			(*win)++;
		}
	}

	if (answer == 2)
	{
		if (num == 2)
		{
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n\n");
			(*draw)++;
		}

		else if (num == 3)
		{
			printf("����� �� ����, ��ǻ�ʹ� ���� ���� : �����ϴ�.\n\n");
			return 1;
		}

		else
		{
			printf("����� ���� ����, ��ǻ�ʹ� ���� ���� : �̰���ϴ�.\n\n");
			(*win)++;
		}
	}

	if (answer == 3)
	{
		if (num == 3)
		{
			printf("����� �� ����, ��ǻ�ʹ� �� ���� : �����ϴ�.\n\n");
			(*draw)++;
		}

		else if (num == 1)
		{
			printf("����� ���� ����, ��ǻ�ʹ� �� ���� : ����� �����ϴ�.\n\n");
			return 1;
		}

		else
		{
			printf("����� ���� ����, ��ǻ�ʹ� �� ���� : �̰���ϴ�.\n\n");
			(*win)++;
		}
	}

	return 0;
}