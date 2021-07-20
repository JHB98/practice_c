#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996);
int getMonthDay(int month);
void getDays(double* days, int dayNum);
int getHiday(double* days, int dayNum);
int getLowDay(double* days, int dayNum);
double getAve(double* days, int dayNum);
void display(double* days, int start, int count);

int main()
{
	int month;
	int dayNum;
	int hiDay;
	int lowDay;
	double ave;
	int start;
	int count;
	printf("월을 입력하세요 : ");
	scanf("%d", &month);
	dayNum = getMonthDay(month);
	double* days = (double*)calloc(dayNum+1,sizeof(double));
	getDays(days, dayNum);
	hiDay = getHiday(days, dayNum);
	lowDay = getLowDay(days, dayNum);
	ave = getAve(days, dayNum);
	printf("그래프 출력을 원하는 기간(시작일,기간) : ");
	scanf("%d", &start);
	scanf("%d", &count);

	printf("%d월 기온 보고서\n", month);
	printf("======================================================\n");
	printf("가장 더운날 : %d일\n", hiDay);
	printf("가장 추운날 : %d일\n", lowDay);
	printf("평균 기온 : %.2lf도\n", ave);
	printf("======================================================\n");
	display(days, start, count);
	return 0;
}

int getMonthDay(int month)
{
	int dayNum;
	if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
	{
		dayNum = 30;
	}

	else if (month == 2)
	{
		dayNum = 28;
	}

	else
	{
		dayNum = 31;
	}
	return dayNum;
}

void getDays(double* days, int dayNum)
{
	printf("온도를 입력하세요(1~%d일) : ", dayNum);
	for (int i = 1;i <= dayNum;i++)
	{
		scanf("%lf", &days[i]);
	}
}

int getHiday(double* days, int dayNum)
{
	double high = -10;
	int hiDay = 1;
	for (int i = 1;i <= dayNum;i++)
	{
		if (days[i] > high)
		{
			high = days[i];
			hiDay = i;
		}
	}
	return hiDay;
}

int getLowDay(double* days, int dayNum)
{
	double low = 40;
	int lowDay = 1;
	for (int i = 1;i <= dayNum;i++)
	{
		if (days[i] < low)
		{
			low = days[i];
			lowDay = i;
		}
	}
	return lowDay;
}

double getAve(double* days, int dayNum)
{
	double sum = 0;
	double ave = 0;
	for (int i = 1;i <= dayNum;i++)
	{
		sum += days[i];
	}

	ave = sum / dayNum;

	return ave;
}

void display(double* days, int start, int count)
{
	char** display = (char**)calloc(count, sizeof(char*));
	for (int i = 0;i < count;i++)
	{
		display[i] = (char*)calloc(51, sizeof(char));
	}
	int j = start;

	for (int i = 0;i < count;i++)
	{
		display[i][10] = '|';
		int tmp = (int)days[j];
		display[i][tmp + 10] = '*';
		j++;
	}
	printf("\n\nday : ==========0========================================\n");
	for (int i = 0;i < count;i++)
	{
		printf("%d : ", i + start);

		for (int l = 0;l < 51;l++)
		{
			printf("%c", display[i][l]);
		}
		printf("\n");
	}
	printf("    : ==========0========================================\n");
}