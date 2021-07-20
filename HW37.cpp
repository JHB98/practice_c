//황금동전
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int sum = 0, i = 1, j, day, coin = 1, k = 0;
	printf("* 기사의 근무일수를 입력하시오 : ");
	scanf("%d",&day);

	while(1)
	{
		for (j = 0;j < i;j++)
		{
			k++;
			sum += coin;
			if (k == day)
			{
				break;
			}
		}
		if (k == day)
		{
			break;
		}
		i++;
		coin++;
	}

	printf("근무일 : %d 일 / 총 금화 개수 : %d 개\n", day, sum);

	return 0;
}