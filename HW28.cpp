//문자 종류별 카운트 프로그램
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	char ch;
	int alphabet = 0, num = 0, space = 0, etc = 0;
	printf("# 영문 문장을 입력하시오 : ");
	while (1)
	{
		ch = getchar();
		
		if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
		{
			alphabet++;
		}

		else if ((ch >= '0') && (ch <= '9'))
		{
			num++;
		}

		else if ((ch == 9) || (ch == '\n') || (ch == 32))
		{
			space++;
		}
		else if (ch == EOF)
		{
			break;
		}

		else
		{
			etc++;
		}
		
	}

	printf("* 영문자 대소문자 개수 : %d개\n", alphabet);
	printf("* 숫자문자 개수 : %d개\n", num);
	printf("* 여백문자(space,tab,enter) 개수 : %d개\n", space);
	printf("* 그 외 기타문자 개수 : %d개\n", etc);

	return 0;
}