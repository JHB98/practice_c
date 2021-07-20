//반복적으로 두개의 정수를 입력받아 두수의 차를 출력
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int num1 = 0, num2 = 0, re = 0;
	while (1)
	{
		printf("#두개의 정수를 입력하세요 : ");
		if (re = scanf("%d %d", &num1, &num2) == 2)
		{
			if (num1 < num2)
			{
				printf("%d - %d=%d\n", num2, num1, num2 - num1);
			}

			else
			{
				printf("%d-%d=%d\n", num1, num2, num1 - num2);
			}
		}

		else
		{
			break;
		}
	}
	return 0;
}