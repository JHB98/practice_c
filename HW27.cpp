//�ް� ���� ���α׷�
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int main()
{
	int num = 0, count = 0;
	while (count!=10)
	{
		num = input();

		if ((num >= 150) && (num <= 500))
		{
			count++;
			printf("*���� �ް��� �� : %d\n\n", count);
		}

		else if (num < 150)
		{
			printf("���߸��� ������ �峭���� ���ÿ�~^^\n\n");
		}

		else
		{
			printf("Ÿ���� ������ �峭���� ���ÿ�~^^\n\n");
		}
		
	}
	
	printf("*** �ް� ������ �������ϴ�.\n\n");


	return 0;

}
int input()
{
	int num;
	while (1)
	{
		printf("# ����� ���Ը� �Է��ϼ���(���� g) : ");
		scanf("%d", &num);
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

	return num;
}