//문자열 첫 문자와 마지막 문자 출력하기
//수강생 정문수
#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
void input(char(*str)[20]);
void sort(char(*str)[20]);
void output(char(*str)[20]);
int main()
{
	char str[5][20] = { 0 };
	input(str);
	sort(str);
	output(str);

	return 0;
}

void input(char(*str)[20])
{
	int i;
	for (i = 0;i < 5;i++)
	{
		printf("%d번 문자열을 입력하시오 : ", i+1);
		scanf("%s", str[i]);
	}
	printf("\n\n");
	return;
}

void sort(char(*str)[20])
{
	int i, j;
	char tmp[20];
	for (i = 0;i < 4;i++)
	{
		for (j = i + 1;j < 5;j++)
		{
			if (strcmp(str[i], str[j]) > 0)
			{
				strcpy(tmp, str[i]);
				strcpy(str[i], str[j]);
				strcpy(str[j], tmp);
			}
		}
	}

	return;
}

void output(char(*str)[20])
{
	int i, len;
	for (i = 0;i < 5;i++)
	{
		len = strlen(str[i]) - 1;
		printf("str[%d] = %s %c %c\n", i, str[i], **(str + i), *(*(str + i) + len));
	}
	printf("\n\n");
	return;
}
