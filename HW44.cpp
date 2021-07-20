//입력받은 값 사이에서 짝수 or 홀수값들의 합 출력
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
void scale(int *start, int *end);
char choice(int *start, int *end);
void output(int *start, int *end, char check);
int main()
{
	int start = 0, end = 0;
	char check;
	scale(&start, &end);
	check = choice(&start, &end);
	output(&start, &end, check);

	return 0;
}

void scale(int *start, int *end)
{
	while (1)
	{
		printf("# 시작 값을 입력하시오 : ");
		scanf("%d", start);
		if (getchar() == '\n')
		{
			if (*start<0)
			{
				continue;
			}

			else
			{
				break;
			}
	
		}
		while (1)
		{
			if (getchar() == '\n')
			{
				break;
			}
		}
	}

	while (1)
	{
		printf("# 끝 값을 입력하시오 : ");
		scanf("%d", end);
		if (getchar() == '\n')
		{
			if (*end <= *start)
			{
				continue;
			}

			else
			{
				break;
			}

		}
		while (1)
		{
			if (getchar() == '\n')
			{
				break;
			}
		}
	}
	return;
}

char choice(int *start, int *end)
{
	char check;
	while (1)
	{
		printf("%d~%d 까지의 짝수의 합을 구할까요? 홀수의 합을 구할까요? (짝수 : e / 홀수 : o) : ", *start, *end);
		scanf("%c", &check);
		if (getchar() == '\n')
		{
			if ((check=='e')||(check=='o'))
			{
				break;
			}

			else
			{
				continue;
			}
		}
		while (1)
		{
			if (getchar() == '\n')
			{
				break;
			}
		}
	}
	return check;
}

void output(int *start, int *end, char check)
{
	int sum=0, i;
	if (check == 'e')
	{
		printf("%d~%d 까지의 짝수(", *start, *end);
		for (i = *start;i <= *end;i++)
		{
			if (i % 2 == 0)
			{
				printf("%4d", i);
				sum += i;
			}
		}
		printf(") 의 합은 %d 입니다.\n", sum);
	}

	if (check == 'o')
	{
		printf("%d~%d 까지의 홀수(", *start, *end);
		for (i = *start;i <= *end;i++)
		{
			if (i % 2 != 0)
			{
				printf("%4d", i);
				sum += i;
			}
		}
		printf(") 의 합은 %d 입니다.\n", sum);
	}

	return;
}