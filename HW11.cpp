//ascii 코드를 입력 받아 ascii 코드에 해당 문자 출력하기
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int ascii;
	printf("ASCII code 값을 입력하시오 : ");
	scanf("%d", &ascii);
	printf("%d은(는) '%c'의 ASCII code입니다.\n",ascii,ascii);

	return 0;
}