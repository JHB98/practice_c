#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int scores[6][5] = { 0 };
	int sum = 0;
	double aves[5];
	printf("학생성적을 입력 하세요 (5명의 학생 자료)\n");
	for (int i = 0;i < 5;i++)
	{
		printf("%d 번(국어,영어,수학) : ", i + 1);
		for (int l = 1;l < 4;l++)
		{
			*scores[i] = i+1;
			scanf("%d", &*(*(scores + i) + l));
			sum += *(*(scores + i) + l);
		}
		*(*(scores + i) + 4) = sum;
		sum = 0;
	}

	**(scores+5) = 0;
	for (int k = 1;k < 5;k++)
	{
		for (int m = 0;m < 5;m++)
		{
			*(*(scores+5)+k) += *(*(scores+m)+k);
		}
	}

	printf("===========================================\n");
	printf("번호   국어   영어   수학   총점\n");
	printf("===========================================\n");
	for (int i = 0;i < 5;i++)
	{
		for (int k = 0;k < 5;k++)
		{
			printf("%d	", *(*(scores+i)+k));
		}
		printf("\n");
	}
	printf("===========================================\n");
	printf("과목총점   ");
	for (int h = 1;h < 5;h++)
	{
		printf("%d	", *(*(scores+5)+h));
	}
	printf("\n");
	printf("===========================================\n");
	printf("과목평균   ");
	for (int k = 1;k < 5;k++)
	{
		*(aves+k) = (*(*(scores+5)+k) / 5);
		printf("%.2lf	", *(aves+k));
	}
	printf("\n===========================================\n");


}