//�Է¹��� �� ���̿��� ¦�� or Ȧ�������� �� ���
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
void scale(int *start, int *end);
char choice(int *start, int *end);
void output(int *start, int *end, char check);
int main()
{
	int start = 0, end = 0;
	char check;
	scale(&start, &end);
	check = choice(&start, &end);
	output(&start, &end, check);

	return 0;
}

void scale(int *start, int *end)
{
	while (1)
	{
		printf("# ���� ���� �Է��Ͻÿ� : ");
		scanf("%d", start);
		if (getchar() == '\n')
		{
			if (*start<0)
			{
				continue;
			}

			else
			{
				break;
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

	while (1)
	{
		printf("# �� ���� �Է��Ͻÿ� : ");
		scanf("%d", end);
		if (getchar() == '\n')
		{
			if (*end <= *start)
			{
				continue;
			}

			else
			{
				break;
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
	return;
}

char choice(int *start, int *end)
{
	char check;
	while (1)
	{
		printf("%d~%d ������ ¦���� ���� ���ұ��? Ȧ���� ���� ���ұ��? (¦�� : e / Ȧ�� : o) : ", *start, *end);
		scanf("%c", &check);
		if (getchar() == '\n')
		{
			if ((check=='e')||(check=='o'))
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
	return check;
}

void output(int *start, int *end, char check)
{
	int sum=0, i;
	if (check == 'e')
	{
		printf("%d~%d ������ ¦��(", *start, *end);
		for (i = *start;i <= *end;i++)
		{
			if (i % 2 == 0)
			{
				printf("%4d", i);
				sum += i;
			}
		}
		printf(") �� ���� %d �Դϴ�.\n", sum);
	}

	if (check == 'o')
	{
		printf("%d~%d ������ Ȧ��(", *start, *end);
		for (i = *start;i <= *end;i++)
		{
			if (i % 2 != 0)
			{
				printf("%4d", i);
				sum += i;
			}
		}
		printf(") �� ���� %d �Դϴ�.\n", sum);
	}

	return;
}