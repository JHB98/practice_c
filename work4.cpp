#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int diameter, price;
	double size, price_per_10cm;
	printf("피자 직경(cm)? : ");
	scanf("%d", &diameter);
	printf("피자 가격(원)? : ");
	scanf("%d", &price);
	size = (3.14*diameter*diameter) / 4;
	price_per_10cm = (price / ((2 * 3.14*(diameter / 2)) / 10));

	printf("피자의 크기 : %.4lf\n",size);
	printf("10cm당 가격 : %.4lf 원\n", price_per_10cm);

	return 0;
}