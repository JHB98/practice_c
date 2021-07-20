//다섯명의 학생의 키를 입력 받아 그 평균 출력
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int student = 1;
	double height = 0;
	double sum = 0;
	while (student != 6)
	{
		printf("%d 번 학생의 키는? ", student);
		scanf("%lf", &height);
		sum += height;
		student++;
	}
	printf("다섯 명의 평균 키는 %.1lf cm입니다.\n", sum / (double)5);

	return 0;
}