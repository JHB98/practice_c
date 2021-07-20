#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	char animal[15][20] = { "자(쥐)", "축(소)", "인(호랑이)", "묘(토끼)", "진(용)", "사(뱀)", "오(말)", "미(양)", "신(원숭이)", "유(닭)", "술(개)", "해(돼지)" };
	int year, choice;
	printf("입력 년도 : ");
	scanf("%d", &year);
	choice = year % 12;
	switch (choice)
	{
	case 0:
		printf("%d년은 %s의 해입니다.\n", year, animal[8]);
		break;
	case 1:
		printf("%d년은 %s의 해입니다.\n", year, animal[9]);
		break;
	case 2:
		printf("%d년은 %s의 해입니다.\n", year, animal[10]);
		break;
	case 3:
		printf("%d년은 %s의 해입니다.\n", year, animal[11]);
		break;
	case 4:
		printf("%d년은 %s의 해입니다.\n", year, animal[0]);
		break;
	case 5:
		printf("%d년은 %s의 해입니다.\n", year, animal[1]);
		break;
	case 6:
		printf("%d년은 %s의 해입니다.\n", year, animal[2]);
		break;
	case 7:
		printf("%d년은 %s의 해입니다.\n", year, animal[3]);
		break;
	case 8:
		printf("%d년은 %s의 해입니다.\n", year, animal[4]);
		break;
	case 9:
		printf("%d년은 %s의 해입니다.\n", year, animal[5]);
		break;
	case 10:
		printf("%d년은 %s의 해입니다.\n", year, animal[6]);
		break;
	case 11:
		printf("%d년은 %s의 해입니다.\n", year, animal[7]);
		break;
	}

	return 0;
}