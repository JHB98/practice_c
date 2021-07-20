//전기요금 계산하기
//수강생 정문수
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
	printf("전기 사용량을 입력하세요(kw) : ");
	scanf("%lf", &use);

	return use;
}

void output(double final_fee)
{
	printf("전기 사용요금은 %lf 원 입니다\n", final_fee);

	return;
}