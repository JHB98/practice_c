//�� 5���� ������ �Է¹޾� �� ���� �� ����ϱ�
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i, sum = 0, num;
	for (i = 1;i <= 5;)
	{
		printf("0���� ū���� �Է��Ͻÿ�(%d ��°) : ",i);
		scanf("%d", &num);
		if (num <= 0)
		{
			continue;
		}
		sum += num;
		i++;
	}

	printf("�Էµ� ���� �� �� : %d\n", sum);
	return 0;
}