//���� ���ϴ� ���α׷�
//������ ������
#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
int input(int *year, int *month, int *day);
void errorcheck(int *year, int *month, int *day);
int yearCheck(int *year);
int sumday(int *year, int *month, int *day);
void output(int *year, int *month, int *day, int sum);
int main()
{
	int year, month, day, check, sum;
	check = input(&year, &month, &day);
	if (check == -1)
	{
		return 0;
	}
	errorcheck(&year, &month, &day);
	sum = sumday(&year, &month, &day);
	output(&year, &month, &day, sum);

	return 0;

}
int input(int *year, int *month, int *day)
{
	printf("* �� �� ���� �Է��Ͻÿ� : ");
	scanf("%d %d %d", year, month, day);
	if (getchar() != '\n')
	{
		return -1;
	}

	return 1;
}

void errorcheck(int *year, int *month, int *day)
{
	int check;
	while (1)
	{
		if ((*month < 1) || (*month > 12))
		{
			input(year, month, day);
		}
		else
		{
			break;
		}
	}

	check = yearCheck(year);
	while (1)
	{
		if (check == 1)//����
		{
			if (*month == 2)
			{
				if ((*day > 0) && (*day < 30))
				{
					break;
				}

				else
				{
					input(year, month, day);
				}
			}
			else
			{
				if ((*day > 0) && (*day < 32))
				{
					break;
				}

				else
				{
					input(year, month, day);
				}
			}
		}

		else//���
		{
			if (*month == 2)
			{
				if ((*day > 0) && (*day < 29))
				{
					break;
				}

				else
				{
					input(year, month, day);
				}
			}
			else
			{
				if ((*day > 0) && (*day < 32))
				{
					break;
				}

				else
				{
					input(year, month, day);
				}
			}
		}
	}
}

int yearCheck(int *year)
{
	int check = 0;
	if (*year % 4 == 0)
	{
		if (*year % 100 == 0)
		{
			if (*year % 400 == 0)
			{
				check = 1;
			}

			else
			{
				check = 0;
			}
		}

		else
		{
			check = 1;
		}
	}
	else
	{
		check = 0;
	}

	return check;
}

int sumday(int *year, int *month, int *day)
{
	int i, sum = 0, j, k;
	int mon_th[12] = { 31,29,31,30,31,30,31,31,30,31,30,31 };
	for (i = 1900;i < *year;i++)
	{
		if (yearCheck(&i))//����
		{
			sum += 366;
		}

		else
		{
			sum += 365;
		}
	}

	if (yearCheck(year))//����
	{	
		for (j = 1;j < *month;j++)		
		{
			sum += mon_th[j-1];
		}
	}

	else
	{
		for (j = 1;j < *month;j++)
		{
			mon_th[1] = 28;
			sum += mon_th[j-1];
		}
	}

	sum += *day;

	return sum;
}

void output(int *year, int *month, int *day, int sum)
{	
	char week[20];
	switch (sum % 7)
	{
	case 0: strcpy(week, "�Ͽ���"); break;
	case 1: strcpy(week, "������"); break;
	case 2: strcpy(week, "ȭ����"); break;
	case 3: strcpy(week, "������"); break;
	case 4: strcpy(week, "�����"); break;
	case 5: strcpy(week, "�ݿ���"); break;
	case 6: strcpy(week, "�����"); break;
	}

	printf("%d�� %d�� %d���� %s�Դϴ�.\n", *year, *month, *day, week);

	return;
}