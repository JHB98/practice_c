//������ ����ϱ�
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
double input();
void output(double final_fee);
int main()
{
	double use;
	double fee=0;
	double final_fee=0;
	double tax=0;
	use = input();
	fee = 660 + (use * 88.5);
	tax = fee * 0.09;
	final_fee = fee + tax;
	output(final_fee);

	return 0;

}

double input()
{
	double use = 0;
	printf("���� ��뷮�� �Է��ϼ���(kw) : ");
	scanf("%lf", &use);

	return use;
}

void output(double final_fee)
{
	printf("���� ������� %lf �� �Դϴ�\n", final_fee);

	return;
}