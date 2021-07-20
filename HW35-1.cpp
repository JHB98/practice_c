//총 5개의 정수를 입력받아 그 수의 합 출력하기
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i, sum = 0, num;
	for (i = 1;i <= 5;)
	{
		printf("0보다 큰수를 입력하시오(%d 번째) : ",i);
		scanf("%d", &num);
		if (num <= 0)
		{
			continue;
		}
		sum += num;
		i++;
	}

	printf("입력된 값의 총 합 : %d\n", sum);
	return 0;
}