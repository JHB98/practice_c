//����� ��� ���α׷�
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
void input(int *age, int *number);
void output(int fee, int sale);
int main()
{	
	int age, fee, number,sale=0;
	input(&age,&number);
	if (age < 7)
	{
		fee = 500 * number;
	}
	else if (age <= 13)
	{
		fee = 700 * number;
	}
	else if (age <= 19)
	{
		fee = 1000 * number;
	}
	else if (age <= 55)
	{
		fee = 1500 * number;
	}
	else
	{
		fee = 500 * number;
	}

	if (number >= 5)
	{
		sale = fee * 0.1;
	}
	output(fee,sale);

	return 0;
}
void input(int *age, int *number)
{
	printf("���尴�� ���̸� �Է��Ͻÿ� : ");
	scanf("%d", age);
	printf("���尴�� ���� �Է��Ͻÿ� : ");
	scanf("%d", number);
	
}
void output(int fee,int sale)
{
	printf("����� => %d��\n", fee);
	printf("���αݾ� => %d��\n", sale);
	printf("�����ݾ� => %d��\n", fee - sale);
	return;
}