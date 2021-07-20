//삼각 알파벳 출력
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i, j;
	char english;

	printf("*영문자 대문자 입력('A'~'Z') : ");
	scanf("%c", &english);
	
	if ((english >= 'A') && (english <= 'Z'))
	{
		for (i = english;i >= 'A';i--)
		{
			for (j = english;j >= i;j--)
			{
				printf("%c", j);
			}
			printf("\n");
		}
	}

	return 0;
}