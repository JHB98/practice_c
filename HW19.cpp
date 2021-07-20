//윤,평년 구하는 프로그램
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int yearCheck(int year);
void output(int year,int check);
int main()
{
	int year;
	int check;
	year = input();
	check = yearCheck(year);
	output(year,check);

	return 0;
}

int input()
{
	int year;
	printf("년도를 입력하시오 : ");
	scanf("%d", &year);

	return year;
}

int yearCheck(int year)
{
	int check=0;
	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				check = 1;
			}

			else
			{
				check = 0;
			}
		}
		
		else
		{
			check = 1;
		}
	}
	else
	{
		check = 0;
	}

	return check;
}

void output(int year,int check)
{
	if (check == 0)
	{
		printf("%d년은 평년입니다.\n", year);
	}

	else
	{
		printf("%d년은 윤년입니다.\n", year);
	}
}

