//2���� ��ȯ ���α׷�
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i, num1, res;
	unsigned int  num2 = 0x80000000;
	printf("* 10���� ������ �Է��Ͻÿ� : ");
	scanf("%d", &num1);

	printf("%d(10) = ", num1);
	for (i = 0;i < 32;i++)
	{
		if (num1 & num2)
		{
			printf("1");
		}

		else
		{
			printf("0");
		}

		num2 = num2 >> 1;
	}
	
	printf("(2)\n");
	return 0;
}