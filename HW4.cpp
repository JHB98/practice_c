//1년을 일,시,분,초로 환산하는 프로그램
//수강생 정문수
#include<stdio.h>
int main()
{
	double year = 365.2422;
    double daytohour = (year - (int)year) * 24;
	double hourtomin = (daytohour - (int)daytohour) * 60;
	double mintosec = (hourtomin - (int)hourtomin) * 60;
	printf("%.4lf일은 %d일",year,(int)year);
	printf(" %d시간", (int)daytohour);
	printf(" %d분",(int)hourtomin);
	printf(" %.2lf초입니다.\n",mintosec);



	

	

	return 0;
	
}