//��Ī�Ǵ� �� ���
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i, j, line;
	
	printf("��� ���μ��� �Է��Ͻÿ� : ");
	scanf("%d", &line);

	if (getchar() != '\n')
	{
		return 0;
	}

	

	for (i = 1;i <= line;i++)
	{
		for (j = 1;j <= i;j++)
		{
			printf("*");
		}
		j--;
		printf("%*s", ((line * 2) + 1) - (2*j),"");

		for (j = 1;j <= i;j++)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}