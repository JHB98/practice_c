//가위 바위 보 게임
//수강생 정문수
#include<stdlib.h>
#include<time.h>
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int output(int num, int answer, int *win, int *draw);
int main()
{
	int answer, num, win = 0, draw = 0;

	srand((unsigned int)time(NULL));

	while (1)
	{
		num = input();
		answer = rand() % 4;
		if (output(num, answer, &win, &draw))
		{
			break;
		}
	}
	printf("\n\n");
	printf("게임 결과 : %d 승 %d 무\n", win,draw);

	return 0;
}

int input()
{
	int num;
	while (1)
	{
		printf("# 바위는 1, 가위는 2, 보는 3 중에서 선택하세요 : ");
		scanf("%d", &num);
		if (getchar() == '\n')
		{
			if ((num > 0) && (num < 4))
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

	return num;
}

int output(int num, int answer, int *win, int *draw)
{	
	if (answer==1)
	{
		if (num == 1)
		{
			printf("당신은 바위 선택, 컴퓨터는 바위 선택 : 비겼습니다.\n\n");
			(*draw)++;
		}

		else if (num == 2)
		{
			printf("당신은 가위 선택, 컴퓨터는 바위 선택 : 당신이 졌습니다.\n\n");
			return 1;
		}

		else
		{
			printf("당신은 보 선택, 컴퓨터는 바위 선택 : 이겼습니다.\n\n");
			(*win)++;
		}
	}

	if (answer == 2)
	{
		if (num == 2)
		{
			printf("당신은 가위 선택, 컴퓨터는 가위 선택 : 비겼습니다.\n\n");
			(*draw)++;
		}

		else if (num == 3)
		{
			printf("당신은 보 선택, 컴퓨터는 가위 선택 : 졌습니다.\n\n");
			return 1;
		}

		else
		{
			printf("당신은 바위 선택, 컴퓨터는 가위 선택 : 이겼습니다.\n\n");
			(*win)++;
		}
	}

	if (answer == 3)
	{
		if (num == 3)
		{
			printf("당신은 보 선택, 컴퓨터는 보 선택 : 비겼습니다.\n\n");
			(*draw)++;
		}

		else if (num == 1)
		{
			printf("당신은 바위 선택, 컴퓨터는 보 선택 : 당신이 졌습니다.\n\n");
			return 1;
		}

		else
		{
			printf("당신은 가위 선택, 컴퓨터는 보 선택 : 이겼습니다.\n\n");
			(*win)++;
		}
	}

	return 0;
}