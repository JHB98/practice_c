//1~100������ ������ 3�� ����� * �� 5�� ����� #���� 3��5�� ������� ������ڷ� ���
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i;
	for (i = 1;i <= 100;i++)
	{
		if (((i % 3) != 0) && ((i % 5) != 0))
		{
			printf("%4d", i);
		}
		if ((i % 3) == 0)
		{
			if ((i % 5) == 0)
			{
				printf("%4d", i);
				if (i % 10 == 0)
				{
					printf("\n");
				}
				continue;
			}
			else
			{
				printf("%3s*", "");
			}
		}

		if ((i % 5) == 0)
		{
			printf("%3s#", "");
			if (i % 10 == 0)
			{
				printf("\n");
			}

		}
	}

	return 0;
}