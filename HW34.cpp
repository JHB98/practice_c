//수도요금 계산 프로그램
//수강생 정문수
#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
int input();
double input2();
double calfee(int fee,double ton);
void output(int code, double ton, double sumfee);

int main()
{
	int code, fee;
	double sumfee = 0, ton;
	code = input();
	getchar();
	ton = input2();
	switch(code)
	{
	case 1: fee = 50;
			sumfee = calfee(fee, ton);
			break;
	case 2: fee = 45;
			sumfee = calfee(fee,ton);
			break;
	case 3: fee = 30; 
			sumfee = calfee(fee,ton);
			break;

	default: printf("잘못 입력하셨습니다.");
	}
	output(code, ton, sumfee);

	return 0;
}

int input()
{
	int code=0;
	printf("* 사용자 코드를 입력하시오(1:가정용 / 2 : 상업용 / 3 : 공업용) : ");
	scanf("%d", &code);

	return code;
}

double input2()
{
	double ton;
	printf("* 사용량을 입력하시오(ton단위) : ");
	scanf("%lf", &ton);
	return ton;
}
double calfee(int fee,double ton)
{
	double sumfee = 0;//총 수도요금
	double sum = 0;//수도사용요금
	
	sum = ton * fee;
	sumfee = sum + (sum*0.05);
	return sumfee;
}

void output(int code, double ton, double sumfee)
{
	char codename[20] = { 0 };
	if (code == 1)
	{
		strcpy(codename, "가정용");
	}
	if (code == 2)
	{
		strcpy(codename, "상업용");
	}
	if (code == 3)
	{
		strcpy(codename, "공업용");
	}

	printf("#사용자 코드 : %d(%s)\n", code, codename);
	printf("#사용량 : %lfton\n", ton);
	printf("#총수도요금 : %.2lf원\n", sumfee);
	
	return;
}