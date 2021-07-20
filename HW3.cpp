//초 수를 시,분,초 단위로 환산하는 프로그램
//수강생 정문수 HW3
#include<stdio.h>
void caltime(int sec1, int time1[],char name1[][30]);
int main()
{
	int sec = 54321;
	int time[20] = {3600,60,1};
	char name[3][30] = { "시간","분","초" };

	caltime(sec, time,name);

}

void caltime(int sec1, int time1[],char name1[][30])
{
	int i;
	printf("%d초는", sec1);
	for (i = 0;i < 3;i++)
	{
		printf("%d %s",sec1 / time1[i],name1[i]);
		sec1 = sec1 - time1[i] * (sec1 / time1[i]);
	}
	printf("입니다.");
	return;
}

