//온도 변환하기
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
double input();
void output(double c);
int main()
{	
	double f;
	double c;
	f = input();
	c = (double)5 / (double)9 * (f - 32);
	output(c);
	return 0;
}

double input()
{
	double f;
	printf("화씨온도를 입력하세요 : ");
	scanf("%lf", &f);

	return f;
}

void output(double c)
{
	printf("섭씨 온도는 %.1lf도입니다.\n", c);

	return;
}