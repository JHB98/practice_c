//서로 다른 수의 개수 출력하기
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
void input(int *ary, int num);
int check(int *ary, int num);
void output(int count);

int main()
{
	int ary[1000] = { 0 };
	int num = 0;
	while (1)
	{
		printf("* 입력할 숫자의 개수 : ");
		scanf("%d", &num);
		if (getchar() != '\n')
		{
			break;
		}
		input(ary, num);
	}
	return 0;
}

void input(int *ary, int num)
{
	int i, count;
		
	printf("* 숫자 입력 : ");
	
	for (i = 0;i < num;i++)
	{
		scanf("%d", &ary[i]);
	}

	count = check(ary, num);

	output(count);
	
	return;
}

int check(int *ary, int num)
{
	int i, j, k;
	int check_ary[1000] = { 0 };
	int count = 0;
	for (i = 0;i < num;i++)
	{
		check_ary[i] = ary[i];
		for (j = 0;j < i;j++)
		{
			if (check_ary[j] == ary[i])
			{
				check_ary[i] = 0;
			}
		}
	}

	for (k = 0;k < num;k++)
	{
		if (check_ary[k] != 0)
		{
			count++;
		}
	}
	
	return count;
}

void output(int count)
{
	printf("  서로 다른 것의 개수 : %d\n\n", count);

	return;
}
