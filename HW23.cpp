//�ݺ������� �ΰ��� ������ �Է¹޾� �μ��� ���� ���
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int num1 = 0, num2 = 0, re = 0;
	while (1)
	{
		printf("#�ΰ��� ������ �Է��ϼ��� : ");
		if (re = scanf("%d %d", &num1, &num2) == 2)
		{
			if (num1 < num2)
			{
				printf("%d - %d=%d\n", num2, num1, num2 - num1);
			}

			else
			{
				printf("%d-%d=%d\n", num1, num2, num1 - num2);
			}
		}

		else
		{
			break;
		}
	}
	return 0;
}