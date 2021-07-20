//move box 프로그램
//수강생 정문수
#include<stdio.h>
#include<windows.h>
#include<conio.h>
#pragma warning (disable:4996)
void gotoxy(int x, int y);
void input(int *sx, int *sy, int *ex, int *ey);
void drawbox(int *sx, int *sy, int *ex, int *ey);
int movebox(int *sx, int *sy, int *ex, int *ey);
int main()
{
	int sx, sy, ex, ey;
	int end;
	input(&sx, &sy, &ex, &ey);
	drawbox(&sx, &sy, &ex, &ey);
	while (1)
	{
		end = movebox(&sx, &sy, &ex, &ey);
		if (end)
		{
			break;
		}
	}

	return 0;
}

void gotoxy(int x, int y)
{
	COORD Pos = { x,y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), Pos);
}

void input(int *sx, int *sy, int *ex, int *ey)
{
	while (1)
	{
		printf("sx의 좌표를 입력하세요 : ");
		scanf("%d", sx);

		if (getchar() == '\n')
		{
			if ((*sx >= 1) && (*sx <= 70))
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

	while (1)
	{
		printf("ex의 좌표를 입력하세요 : ");
		scanf("%d", ex);

		if (getchar() == '\n')
		{
			if ((*sx < *ex) && (*ex <= 80))
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

	while (1)
	{
		printf("sy의 좌표를 입력하세요 : ");
		scanf("%d", sy);

		if (getchar() == '\n')
		{
			if ((*sy >= 1) && (*sy <= 20))
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

	while (1)
	{
		printf("ey의 좌표를 입력하세요 : ");
		scanf("%d", ey);

		if (getchar() == '\n')
		{
			if ((*sy < *ey) && (*ey <= 24))
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
	return;
}

void drawbox(int *sx, int *sy, int *ex, int *ey)
{
	int i, j;
	system("cls");

	if ((*sx) < 1)
	{
		*sx = 80;
	}

	if ((*ex) < 1)
	{
		*ex = 80;
	}

	if ((*ex) > 80)
	{
		*ex = 1;
	}

	if ((*sx) > 80)
	{
		*sx = 1;
	}
	
	if ((*sx > *ex) && (*sy < *ey))
	{
		gotoxy(*sx, *sy);

		for (i = *sx;i <= 80;i++)
		{
			printf("*");
		}

		gotoxy(1, *sy);

		for (i = 1;i <= *ex;i++)
		{
			printf("*");
		}

		for (j = (*sy + 1);j < *ey;j++)
		{
			gotoxy(*sx, j);
			printf("*");
			gotoxy(*ex, j);
			printf("*");
		}
		gotoxy(*sx, *ey);

		for (i = *sx;i <= 80;i++)
		{
			printf("*");
		}

		gotoxy(1, *ey);

		for (i = 1;i <= *ex;i++)
		{
			printf("*");
		}
		printf("\n");
	}

	if ((*sy) < 1)
	{
		*sy = 24;
	}

	if ((*ey) < 1)
	{
		*ey = 24;
	}

	if ((*sy) > 24)
	{
		*sy = 1;
	}

	if ((*ey) > 24)
	{
		*ey = 1;
	}

	if ((*sx < *ex) && (*sy > *ey))
	{
		gotoxy(*sx, *sy);
		for (i = *sx;i <= *ex;i++)
		{
			printf("*");
		}

		for (j = (*sy + 1);j < 25;j++)
		{
			gotoxy(*sx, j);
			printf("*");
			gotoxy(*ex, j);
			printf("*");
		}

		for (j = 1;j < *ey;j++)
		{
			gotoxy(*sx, j);
			printf("*");
			gotoxy(*ex, j);
			printf("*");
		}

		gotoxy(*sx, *ey);

		for (i = *sx;i <= *ex;i++)
		{
			printf("*");
		}

		printf("\n");
	}

	if ((*sx < *ex) && (*sy < *ey))
	{
		gotoxy(*sx, *sy);
		for (i = *sx;i <= *ex;i++)
		{
			printf("*");
		}

		for (j = (*sy + 1);j < *ey;j++)
		{
			gotoxy(*sx, j);
			printf("*");
			gotoxy(*ex, j);
			printf("*");
		}
		gotoxy(*sx, *ey);

		for (i = *sx;i <= *ex;i++)
		{
			printf("*");
		}

		printf("\n");
	}
	return;
}

int movebox(int *sx, int *sy, int *ex, int *ey)
{
	char ch;
	int end = 0;
	ch = getch();
	switch (ch)
	{
	case 'w': (*sy)--; 
		(*ey)--;
		drawbox(sx, sy, ex, ey);
		break;
	case 'a': (*sx)--;
		(*ex)--;
		drawbox(sx, sy, ex, ey);
		break;
	case 'd': (*sx)++;
		(*ex)++;
		drawbox(sx, sy, ex, ey);
		break;
	case 's': (*sy)++;
		(*ey)++;
		drawbox(sx, sy, ex, ey);
		break;
	case 27: end = 1;
		break;
	}

	return end;
}
