//지하철 요금 계산하기
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int calfee(int station);
void output(int fee);
int main()
{
	int station;
	int fee;
	station = input();
	fee = calfee(station);
	output(fee);

	return 0;

}

int input()
{	
	int station;
	printf("역수를 입력하시오 : ");
	scanf("%d", &station);

	return station;
}

int calfee(int station)
{
	int fee;
	int st_to_fee;
	if (station <= 5)
	{
		fee = 600;
	}

	else if (station <= 10)
	{
		fee = 800;
	}
	else
	{
			while (1)
			{
				st_to_fee = station - 10;
				if (station % 2 == 0)
				{
					fee=800 + (st_to_fee * 50);
				}
				else
				{
					station + 1;
				}
				break;
			}
			return fee;
	}
}

void output(int fee)
{
	printf("요금 : %d원\n", fee);
}