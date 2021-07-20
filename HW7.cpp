//주행거리와 시속을 입력받아 주행시간을 계산하기
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{	
	double km=0;
	double km_h=0;
	double hour=0;
	double min=0;
	double sec=0;

	printf("거리를 입력하시오(km단위) : ");
	scanf("%lf", &km);
	printf("시속을 입력하시오(km/h단위) : ");
	scanf("%lf", &km_h);

	hour = km / km_h;
	min = (hour - (int)hour) * 60;
	sec = (min - (int)min) * 60;
	printf("%.2lfkm => %d시간 %d분 %.3lf 초 소요됨.", km, (int)hour, (int)min, sec);

	return 0;

	
}