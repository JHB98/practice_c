//2진수 변환 프로그램
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i, num1, res;
	unsigned int  num2 = 0x80000000;
	printf("* 10진수 정수를 입력하시오 : ");
	scanf("%d", &num1);

	printf("%d(10) = ", num1);
	for (i = 0;i < 32;i++)
	{
		if (num1 & num2)
		{
			printf("1");
		}

		else
		{
			printf("0");
		}

		num2 = num2 >> 1;
	}
	
	printf("(2)\n");
	return 0;
}