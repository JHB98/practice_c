//이름을 영문으로 입력받아 출력
//수강생 정문수
#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	char name[21] = { 0 };
	printf("이름을 입력하시오(성과 이름사이를 _로 이어서 입력) : ");
	scanf("%s", name);

	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);

	return 0;
}