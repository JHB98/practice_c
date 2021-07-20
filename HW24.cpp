//달팽이 우물 탈출 프로그램
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int escape(int depth);
void output(int depth, int day);
int main()
{
	int depth = 0, day = 0;
	depth = input();
	day = escape(depth);
	output(depth, day);

	return 0;

}

int input()
{
	int depth = 0;
	printf("* 우물의 깊이를 입력하시오(cm단위) : ");
	scanf("%d", &depth);
	return depth;
}

int escape(int depth)
{
	int climb = 0;
	int day = 1;
	while (1)
	{
		if (depth == 0)
		{
			day = 0;
		}
		climb += 50;
		if (climb >= depth)
		{
			break;
		}

		else
		{
			climb -= 20;
			day++;
		}
	}
	return day;

}

void output(int depth, int day)
{
	printf("%.2lf미터 깊이의 우물을 탈출하기 위해서는 %d일이 걸립니다.\n", depth / (double)100, day);
	return;
}