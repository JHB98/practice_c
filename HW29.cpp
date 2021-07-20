//고집수
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int transNumber(int i);
int inputUInt(const char *message);
void output(int p1, int p2, int N);
int main()
{
	int p1, p2, N, i, count = 0;
	p1 = inputUInt("시작 값(P1) : ");
	p2 = inputUInt("끝 값(P2) : ");
	N = inputUInt("고집수(N) : ");
	output(p1, p2, N);
	
	return 0;
	
}

int transNumber(int i)
{
	int num[5] = { 0, };
	int thousand, hundred, ten, one, count = 0;
	if ((i / 1000) < 1)
	{
		while (1)
		{
			hundred = i / 100;
			i -= hundred * 100;
			ten = i / 10;
			i -= ten * 10;
			one = i;

			num[0] = hundred;
			num[1] = ten;
			num[2] = one;
			if (num[0] != 0)
			{
				i = num[0] * num[1] * num[2];
				count++;
			}
			else
			{
				i = num[1] * num[2];
				count++;
			}
			if ((i >= 0) && (i <= 9))
			{
				break;
			}
		}
	}
	else
	{
		while (1)
		{
			thousand = i / 1000;
			i -= thousand * 1000;
			hundred = i / 100;
			i -= hundred * 100;
			ten = i / 10;
			i -= ten * 10;
			one = i;

			num[0] = thousand;
			num[1] = hundred;
			num[2] = ten;
			num[3] = one;
			if (num[0] != 0)
			{
				i = num[0] * num[1] * num[2] * num[3];
				count++;
			}
			else
			{
				if (num[1] != 0)
				{
					i = num[1] * num[2] * num[3];
					count++;
				}

				else
				{
					i = num[2] * num[3];
					count++;
				}
			}
			if ((i >= 0) && (i <= 9))
			{
				break;
			}
		}
	}

	return count;

}

int inputUInt(const char *message)
{
	int num = 1;
	while (1)
	{
		printf("%s",message);
		scanf("%d", &num);
		if(num <= 0)
		{
			continue;
		}

		if (getchar() == '\n')
		{
			break;
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

void output(int p1, int p2, int N)
{
	int i, count = 0;
	for (i = p1;i <= p2;i++)
	{
		if (transNumber(i) == N)
		{
			printf("%d\n", i);
			count++;
		}

	}
	printf("총 개수 : %d개\n", count);

	return;
}