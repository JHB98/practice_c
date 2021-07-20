//성명, 키,성별을 입력 받아 출력
//수강생 정문수
#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
int main()
{
	char name[21] = { 0 };
	double height = 0;
	char gender = 0;
	

	printf("# 성명 입력 : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';

	printf("# 키 입력(cm단위) : ");
	scanf("%lf", &height);

	getchar();

	printf("# 성별입력(M/F) : ");
	scanf("%c", &gender);

	if (gender == 'M' || gender == 'm')
	{
		printf("%s씨의 키는 %.2lfcm 이고 남성입니다.\n", name, height);
	}

	if (gender == 'F' || gender == 'f')
	{
		printf("%s씨의 키는 %.2lfcm이고 여성입니다.\n", name, height);
	}

	return 0;
}