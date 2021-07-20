//누승함수
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int inputUInt(const char *message);
int ipow(int down, int up);
double inputDouble(const char *message);
double fpow(double _down, int up);
int main()
{
	int down, up, num1;
	double _down, num2;
	down = inputUInt("* 양의 정수 밑을 입력하시오 : ");
	up = inputUInt("* 양의 승을 입력하시오 : ");
	num1 = ipow(down, up);
	printf("%d의 %d승은 %d입니다.\n", down, up, num1);

	printf("\n\n\n");

	_down = inputDouble("* 양의 실수 밑을 입력하시오 : ");
	up = inputUInt("* 양의 승을 입력하시오 : ");
	num2 = fpow(_down, up);
	printf("%.2lf의 %d승은 %.3lf 입니다.\n", _down, up, num2);

	return 0;

}

int inputUInt(const char *message)
{
	int num = 0;
	while (1)
	{
		printf("%s", message);
		scanf("%d", &num);
		if (num < 0)
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
int ipow(int down, int up)
{
	if (up == 0)
	{
		down = 1;
	}
	else
	{
		int num = 0, i;
		num = down;
		for (i = 2;i <= up;i++)
		{
			down = down * num;
		}
	}
	return down;
}
double inputDouble(const char *message)
{
	double num = 0;
	while (1)
	{
		printf("%s", message);
		scanf("%lf", &num);
		if (num < 0)
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
double fpow(double _down, int up)
{
	if (up == 0)
	{
		_down = 1;
	}
	else
	{
		double num = 0, i;
		num = _down;
		for (i = 2;i <= up;i++)
		{
			_down = _down * num;
		}
	}
		return _down;
}