// ���ٿ� * 5���� ���
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int main()
{
	int number,i=1;
	number = input();
	while (i <= number)
	{
		printf("*");
		if (i % 5 == 0)
		{
			printf("\n");
		}
		i++;
	}
	printf("\n");
	return 0;

}

int input()
{
	int number;
	printf("#�������� �Է��ϼ��� : ");
	scanf("%d", &number);

	return number;
}