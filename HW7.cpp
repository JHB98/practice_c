//����Ÿ��� �ü��� �Է¹޾� ����ð��� ����ϱ�
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{	
	double km=0;
	double km_h=0;
	double hour=0;
	double min=0;
	double sec=0;

	printf("�Ÿ��� �Է��Ͻÿ�(km����) : ");
	scanf("%lf", &km);
	printf("�ü��� �Է��Ͻÿ�(km/h����) : ");
	scanf("%lf", &km_h);

	hour = km / km_h;
	min = (hour - (int)hour) * 60;
	sec = (min - (int)min) * 60;
	printf("%.2lfkm => %d�ð� %d�� %.3lf �� �ҿ��.", km, (int)hour, (int)min, sec);

	return 0;

	
}