//0���� 99������ ������ ���ٿ� 10���� �������� ���
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i, j;

	for (i = 0;i < 10;i++)
	{
		for (j = i;j < 100;j += 10)
		{
			printf("%5d", j);
		}
		printf("\n");
	}

	return 0;
}