//세 과목 점수 입력받아 총점,평균 출력하기
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int history;
	int literature;
	int art;
	int total;
	double average;
	printf("역사 문학 예능 세과목의 점수를 입력하시면 총점과 평균을 알려드립니다.\n");
	printf("역사, 문학, 예능 점수를 입력하세요 :");
	scanf("%d %d %d", &history, &literature, &art);
	total = history + literature + art;
	average = (double)total / 3;
	printf("총점은 %d 이고 평균은 %.2lf 입니다.\n", total, average);

	return 0;

}