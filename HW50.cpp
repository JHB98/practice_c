//문자 검색 프로그램(단일 검색)
//수강생 정문수
#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
char inputnum(char *ch, char check);
int strcheck(char *ch, char check);
int main()
{
	char ch[99] = { 0 };
	char check = 0;
	int index;

	check = inputnum(ch, check);
	index = strcheck(ch, check);
	if (index == -1)
	{
		printf("\"%s\" 문자열 안에 '%c' 문자는 존재하지 않습니다.\n", ch, check);
	}

	else
	{
		printf("\"%s\" 문자열 안에 '%c' 문자는 %d번 위치에 존재합니다\n", ch, check, index);
	}

	return 0;
}

char inputnum(char *ch, char check)
{
	printf("# 문자열을 입력하십시오(1~99글자) : ");
	scanf("%s", ch);
	
	printf("# 문자를 입력하시오 : ");
	scanf(" %c", &check);

	return check;
}

int strcheck(char *ch, char check)
{
	int size, i;
	size = strlen(ch);
	
	for (i = 0;i < size;i++)
	{
		if (ch[i] == check)
		{
			return i;
		}
	}

	return -1;
}