//이름의 글자 수 출력하기
//수강생 정문수
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{
	unsigned int len1, len2;
	char name[2][20];
	printf("#성을 입력하시오 : ");
	scanf("%s", name[0]);
	printf("#이름을 입력하시오 :");
	scanf("%s", name[1]);
	len1 = strlen(name[0]);
	len2 = strlen(name[1]);
	
	printf("%s %s\n", name[0], name[1]);
	printf("%*d %*d\n", len1, len1, len2, len2);

	return 0;

}