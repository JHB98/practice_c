//주민등록번호 유효성 검사 프로그램
//수강생 정문수
#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
int check(int *resident_number_i, int len);
int yearCheck(int *resident_number_i, int year);
int check_month_day(int *resident_number_i, int check);
int check_len_char(int *resident_number_i, int len);
int check_gender(int *resident_number_i);
int check_identi(int *resident_number_i);

int main()
{
	int i, j, count, len;
	char resident_number[][20] = { "0402291000008", "870401102321", "00031541949179",
		"0003154194917", "801203#201122", "7804155328845", "7804150328840",
		"9612241068382", "9902292194322", "0230174326176", "8811391042219",
		"8100122042213", "8112002042213", "9210101069415", "0802294012345",
		"8806311069417","8807311069418" };

	int resident_number_i[20] = { 0 };

	count = sizeof(resident_number) / sizeof(resident_number[0]);

	for (i = 0;i < count;i++)
	{
		len = strlen(resident_number[i]);
		for (j = 0;j < len;j++)
		{
			resident_number_i[j] = resident_number[i][j] - '0';
		}

		if (check(resident_number_i, len))
		{
			printf("(+) 주민번호 %s는 유효한 번호입니다.\n\n", resident_number[i]);
		}

		else
		{
			printf("(-) 주민번호 %s는 유효하지 않은 번호입니다,\n\n", resident_number[i]);
		}
	}

	return 0;
} 

int check(int *resident_number_i, int len)
{
	int year_1_2, year_3, year_4, year, check;

	if (check_len_char(resident_number_i, len) == 0)
	{
		return 0;
	}
	
	if (check_gender(resident_number_i) == 0)
	{
		return 0;
	}
	year_1_2 = check_gender(resident_number_i);

	year_3 = resident_number_i[0] * 10;
	year_4 = resident_number_i[1];
	year = year_1_2 + year_3 + year_4;
	check = yearCheck(resident_number_i, year);
	
	if (check_month_day(resident_number_i, check) == 0)
	{
		return 0;
	}

	if (check_identi(resident_number_i) == 0)
	{
		return 0;
	}

	return 1;
}

int yearCheck(int *resident_number_i,int year)
{
	int check;

	if (year % 4 == 0)
	{
		if (year % 100 == 0)
		{
			if (year % 400 == 0)
			{
				check = 1;//윤년
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

int check_month_day(int *resident_number_i, int check)
{
	int month, day;

	if (resident_number_i[2] == 0)
	{
		month = resident_number_i[3];
	}

	else
	{
		month = (resident_number_i[2] * 10) + resident_number_i[3];
	}

	if (resident_number_i[4] == 0)
	{
		day = resident_number_i[5];
	}

	else
	{
		day = (resident_number_i[4] * 10) + resident_number_i[5];
	}

	if ((month < 1) || (month > 12))
	{
		return 0;
	}
	
	while (1)
	{
		if (check == 1)//윤년
		{
			if (month == 2)
			{
				if ((day > 0) && (day < 30))
				{
					return 1;
				}

				else
				{
					return 0;
				}
			}

			else if ((month == 4) || (month == 6) || (month == 9) || (month == 11))
			{
				if ((day > 0) && (day < 31))
				{
					return 1;
				}

				else
				{
					return 0;
				}
			}

			else
			{
				if ((day > 0) && (day < 32))
				{
					return 1;
				}

				else
				{
					return 0;
				}
			}
		}

		else//평년
		{
			if (month == 2)
			{
				if ((day > 0) && (day < 29))
				{
					return 1;
				}

				else
				{
					return 0;
				}
			}
			else
			{
				if ((day > 0) && (day < 32))
				{
					return 1;
				}

				else
				{
					return 0;
				}
			}
		}
	}
}

int check_len_char(int *resident_number_i, int len)
{
	int i;
	if (len > 13)
	{
		return 0;
	}

	for (i = 0;i < len;i++)
	{
		if ((resident_number_i[i] > 9) || (resident_number_i[i] < 0))
		{
			return 0;
		}
	}

	return 1;
}

int check_gender(int *resident_number_i)
{
	int year_1_2;
	if ((resident_number_i[6] > 0) && (resident_number_i[6] < 5))
	{
		if ((resident_number_i[6] == 1) || (resident_number_i[6] == 2))
		{
			year_1_2 = 1900;
		}

		else
		{
			year_1_2 = 2000;
		}

		return year_1_2;
	}

	else
	{
		return 0;
	}
}

int check_identi(int *resident_number_i)
{
	int i, sum = 0;
	for (i = 0;i < 12;i++)
	{
		sum += resident_number_i[i];
	}

	if ((sum % 10) == resident_number_i[12])
	{
		return 1;
	}

	return 0;
}

