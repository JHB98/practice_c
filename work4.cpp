#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int diameter, price;
	double size, price_per_10cm;
	printf("���� ����(cm)? : ");
	scanf("%d", &diameter);
	printf("���� ����(��)? : ");
	scanf("%d", &price);
	size = (3.14*diameter*diameter) / 4;
	price_per_10cm = (price / ((2 * 3.14*(diameter / 2)) / 10));

	printf("������ ũ�� : %.4lf\n",size);
	printf("10cm�� ���� : %.4lf ��\n", price_per_10cm);

	return 0;
}