//달걀 포장 프로그램
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int main()
{
	int num = 0, count = 0;
	while (count!=10)
	{
		num = input();

		if ((num >= 150) && (num <= 500))
		{
			count++;
			printf("*현재 달걀의 수 : %d\n\n", count);
		}

		else if (num < 150)
		{
			printf("메추리알 가지고 장난하지 마시오~^^\n\n");
		}

		else
		{
			printf("타조알 가지고 장난하지 마시오~^^\n\n");
		}
		
	}
	
	printf("*** 달걀 포장이 끝났습니다.\n\n");


	return 0;

}
int input()
{
	int num;
	while (1)
	{
		printf("# 계란의 무게를 입력하세요(단위 g) : ");
		scanf("%d", &num);
		if (getchar() == '\n')
		{
			break;
		}
		while (1)
		{
			if (getchar() == '\n')
			{
				break;
			}
		}
	}

	return num;
}