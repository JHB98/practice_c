//구구단 출력
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i, j, k;
	printf("<2중 for문을 이용한 출력>\n");
	for (i = 1;i < 10;i++)
	{
		for (j = 2;j < 6;j++)
		{
			printf("%5d * %d = %3d", j, i, j*i);
		}

		printf("\n");
	}

	printf("\n");

	for (i = 1;i < 10;i++)
	{
		for (j = 6;j < 10;j++)
		{
			printf("%5d * %d = %3d", j, i, j*i);
		}

		printf("\n");
	}

	printf("-----------------------------------------------------------------\n\n");
	
	printf("<3중 for문을 이용한 출력>\n");

	for (i = 2;i <= 6;i+=4)
	{
		for (j = 1;j < 10;j++)
		{
			for (k = i;k < i+4;k++)
			{
				printf("%5d * %d = %3d", k, j, k*j);
			}
			printf("\n");
		}
		printf("\n");
	}
	return 0;
}