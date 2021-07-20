#include<stdio.h>
#define student 4
#define subject 5
void print_heading(void)
{
	printf("성명 국어 영어 수학 과학 사회 총점 평균 \n");
	printf("\n");
}

int main()
{
	char names[student][20] = { "홍길동","성춘향","진달래","개나리"};
	int score[student][subject + 2] = { {78,90,34,46,80},{98,74,84,76,72},{76,48,34,72,89},{61,91,67,88,83} };
	int i, j, sum = 0, row=4, col=7;

	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col - 2;j++)
		{
			sum += score[i][j];
		}
		score[i][subject] = sum;
		score[i][subject + 1] = sum / 5;
		sum = 0;
	}
	print_heading();
	for (i = 0;i < row;i++)
	{
		printf("%5s, ", names[i]);
		for (j = 0;j < col;j++)
		{
			printf("%3d, ", score[i][j]);
		}
		printf("\n");
	}

	return 0;
}