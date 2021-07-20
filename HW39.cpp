//0부터 99까지의 정수를 한줄에 10개씩 수직으로 출력
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i, j;

	for (i = 0;i < 10;i++)
	{
		for (j = i;j < 100;j += 10)
		{
			printf("%5d", j);
		}
		printf("\n");
	}

	return 0;
}