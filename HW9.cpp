//입력된 정수를 8진수와 16진수로 출력하는 프로그램
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int main()
{
	int number;
	number = input();
	printf("입력된 값은 8진수로 %#o 입니다.\n",number);
	printf("입력된 값은 16진수로 %#x 입니다.\n",number);
	return 0;
}

int input()
{
	int number;
	printf("정수값을 입력하세요 : ");
	scanf("%d", &number);

	return number;
}
