//회문 검사 프로그램
//수강생 정문수
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#pragma warning (disable:4996);
void inputstring(char *ch);
int circular(char *ch);
void output(char *ch, int check);
int main()
{
	char ch[100] = { 0 };
	int check;
	inputstring(ch);
	check = circular(ch);
	output(ch, check);

	return 0;

}
void inputstring(char *ch)
{
	printf("# 문자열을 입력하십시오: ");
	scanf("%s", ch);

	return;
}

int circular(char *ch)
{
	int tmp, i, j, size;
	size = strlen(ch);
	for (j = 0;j < size;j++)
	{
		ch[j] = (char)tolower(ch[j]);
	}
	
	for (i = 0;i < (size / 2);i++)
	{
		if (ch[i] != ch[(size-1)- i])
		{
			return 0;
		}
	
	}

	return 1;
}

void output(char *ch, int check)
{
	if(check==1)
	{
		printf("\"%s\" : 회문입니다! \n", ch);
	}

	else
	{
		printf("\"%s\" : 회문이 아닙니다! \n", ch);
	}

	return;
}