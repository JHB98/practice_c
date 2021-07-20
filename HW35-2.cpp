//1~100가지의 숫자중 3의 배수는 * 로 5의 배수는 #으로 3과5의 공배수는 정상숫자로 출력
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i;
	for (i = 1;i <= 100;i++)
	{
		if (((i % 3) != 0) && ((i % 5) != 0))
		{
			printf("%4d", i);
		}
		if ((i % 3) == 0)
		{
			if ((i % 5) == 0)
			{
				printf("%4d", i);
				if (i % 10 == 0)
				{
					printf("\n");
				}
				continue;
			}
			else
			{
				printf("%3s*", "");
			}
		}

		if ((i % 5) == 0)
		{
			printf("%3s#", "");
			if (i % 10 == 0)
			{
				printf("\n");
			}

		}
	}

	return 0;
}