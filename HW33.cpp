//환풍구 관리 프로그램
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int menu();
char openFan(char fan);
char offFan(char fan);
char reverseFan(char fan);
void  displayFan(char fan);
int main()
{
	char fan = 0x00;
	int check;
	while (1)
	{
		check = menu();
		switch (check)
		{
		case 1: fan = openFan(fan);
				displayFan(fan);
				break;
		case 2: fan = offFan(fan);
				displayFan(fan);
				break;
		case 3: fan = reverseFan(fan);
				displayFan(fan);
				break;
		case 4: return 0;

		}
	}
	
}

int menu()
{
	int check;
	while (1)
	{
		printf("\n\n1. 환풍구 열기 / 2. 환풍구 닫기 / 3. 환풍구 전체 전환 / 4. 종료 : ");
		scanf("%d", &check);
		if (getchar() == '\n')
		{
			if ((check > 0) && (check < 5))
			{
				break;
			}
			else
			{
				continue;
			}
		}
		while (1)
		{
			if (getchar() == '\n')
			{
				break;
			}
		}
	}
	return check;
}

char openFan(char fan)
{
	int num, i;
	unsigned char fan_check = 0x80;
	printf("--------------------------------------------------------\n");
	printf("\t\tFan 열기 작업 실행 화면\n");
	printf("--------------------------------------------------------\n");
	
	while (1)
	{
		printf("* OPEN 할 FAN 번호를 입력하시오(1-8) : ");
		scanf("%d", &num);
		if (getchar() == '\n')
		{
			if ((num > 0) && (num < 9))
			{
				break;
			}
			else
			{
				continue;
			}
		}
		while (1)
		{
			if (getchar() == '\n')
			{
				break;
			}
		}
	}

	for (i = 0;i < (8 - num);i++)
	{
		fan_check = fan_check >> 1;
	}

	fan = fan | fan_check;

	return fan;
}

char offFan(char fan)
{
	int num, i;
	unsigned char fan_check = 0x80;
	printf("--------------------------------------------------------\n");
	printf("\t\tFan 닫기 작업 실행 화면\n");
	printf("--------------------------------------------------------\n");

	while (1)
	{
		printf("* CLOSE 할 FAN 번호를 입력하시오(1-8) : ");
		scanf("%d", &num);
		if (getchar() == '\n')
		{
			if ((num > 0) && (num < 9))
			{
				break;
			}
			else
			{
				continue;
			}
		}
		while (1)
		{
			if (getchar() == '\n')
			{
				break;
			}
		}
	}

	for (i = 0;i < (8 - num);i++)
	{
		fan_check = fan_check >> 1;
	}

	fan = fan ^ fan_check;

	return fan;
}

char reverseFan(char fan)
{
	int num, i;
	printf("--------------------------------------------------------\n");
	printf("\t\tFan 전체 전환 작업 실행 화면\n");
	printf("--------------------------------------------------------\n");
	printf("전체 FAN의 상태가 전환 되었습니다.(ON,OFF 상태 뒤바뀜)\n");
		
	
	fan = ~fan;
	
	return fan;
}

void  displayFan(char fan)
{
	unsigned char fan_check=0x80;
	int i, j;
	printf("--------------------------------------------------------\n");
	for (j = 8;j > 0;j--)
	{
		printf("%d번 FAN\t",j);
	}

	printf("\n");
	for (i = 0;i < 8;i++)
	{
		if (fan & fan_check)
		{
			printf("  ON\t");
		}

		else
		{
			printf("  OFF\t");
		}

		fan_check = fan_check >> 1;
	}
	printf("\n\n");
	printf("--------------------------------------------------------\n");

	return;
}