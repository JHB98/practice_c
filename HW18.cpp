//입장료 계산 프로그램
//수강생 정문수
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
	printf("입장객의 나이를 입력하시오 : ");
	scanf("%d", age);
	printf("입장객의 수를 입력하시오 : ");
	scanf("%d", number);
	
}
void output(int fee,int sale)
{
	printf("입장료 => %d원\n", fee);
	printf("할인금액 => %d원\n", sale);
	printf("결제금액 => %d원\n", fee - sale);
	return;
}