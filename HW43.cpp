//소수 출력
//수강생 정문수
#include<stdio.h>
#include<math.h>
#pragma warning (disable:4996);
int input();
int primeNumber(int number);
int main()
{
	int number, i, check, count = 0;
	number = input();

	printf("\n1~%d 까지의 소수 값은 다음과 같습니다.\n", number);
	for (i = 2;i <= number;i++)
	{
		check = primeNumber(i);
		if (check == 1)
		{
			printf("%5d", i);
			count++;
			if (count % 5 == 0)
			{
				printf("\n");
			}
		}
	}
	printf("\n1~%d 까지의 총 소수는 %d개 입니다.\n\n", number, count);

	return 0;
}

int input()
{
	int number;
	
	while (1)
	{
		printf("* 정수값 하나를 입력하시오 : ");
		scanf("%d", &number);
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

	return number;
}

int primeNumber(int number)
{
	int j;
	for (j = 2;j <= sqrt((double)number);j++)
	{
		if (number%j == 0)
		{
			return 0;
		}
	}

	return 1;
}