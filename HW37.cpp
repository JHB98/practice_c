//Ȳ�ݵ���
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int sum = 0, i = 1, j, day, coin = 1, k = 0;
	printf("* ����� �ٹ��ϼ��� �Է��Ͻÿ� : ");
	scanf("%d",&day);

	while(1)
	{
		for (j = 0;j < i;j++)
		{
			k++;
			sum += coin;
			if (k == day)
			{
				break;
			}
		}
		if (k == day)
		{
			break;
		}
		i++;
		coin++;
	}

	printf("�ٹ��� : %d �� / �� ��ȭ ���� : %d ��\n", day, sum);

	return 0;
}