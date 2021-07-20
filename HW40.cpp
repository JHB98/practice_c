//대칭되는 별 찍기
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i, j, line;
	
	printf("출력 라인수를 입력하시오 : ");
	scanf("%d", &line);

	if (getchar() != '\n')
	{
		return 0;
	}

	

	for (i = 1;i <= line;i++)
	{
		for (j = 1;j <= i;j++)
		{
			printf("*");
		}
		j--;
		printf("%*s", ((line * 2) + 1) - (2*j),"");

		for (j = 1;j <= i;j++)
		{
			printf("*");
		}

		printf("\n");
	}

	return 0;
}