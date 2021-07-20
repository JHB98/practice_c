//두 정수를 입력 받아 합,차,곱,몫의 값을 출력하는 프로그램
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int num1, num2;
	printf("두 정수를 입력 받아 합,차,곱,몫의 값을 출력\n");
	printf("두 정수를 입력하세요 : ");
	scanf("%d %d", &num1, &num2);
	printf("%d + %d = %d\n", num1, num2, num1 + num2);
	printf("%d - %d = %d\n", num1, num2, num1 - num2);
	printf("%d * %d = %d\n", num1, num2, num1 * num2);
	printf("%d / %d = %.2lf\n", num1, num2, (double)num1 / num2);

	return 0;

}