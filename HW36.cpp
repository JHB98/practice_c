//�Ǻ���ġ ����
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
void fibonacci(int num);
int main()
{
	int num;
	printf("�Ǻ���ġ ������ �׼��� �Է��Ͻÿ� : ");
	scanf("%d", &num);
	fibonacci(num);

	return 0;
}

void fibonacci(int num)
{
	int i, n1 = 0, n2 = 1, n3 = 0, sum = 0;
	printf("1");
	for (i = 1;i < num;i++)
	{	
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		sum += n3;
		printf("+%d", n3);
	}
	printf("=%d\n", sum + 1);

	return;
}