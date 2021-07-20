//정해진 금액으로 물건 구입
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int price, c_p, s_p, co_p;

	printf("현재 당신의 소유 금액 입력 : ");
	scanf("%d", &price);

	if (getchar() != '\n')
	{
		return 0;
	}

	for (c_p = 500;c_p < price;c_p += 500)
	{
		for (s_p = 700;s_p < price;s_p += 700)
		{
			for (co_p = 400;co_p <= price;co_p += 400)
			{
				if (c_p + s_p + co_p == price)
				{
					printf("크림빵(%d 개), 새우깡(%d 봉지), 콜라(%d 병)\n", c_p / 500, s_p / 700, co_p / 400);
				}
				else
				{
					continue;
				}
			}
		}
		
	}

	return 0;
	
}