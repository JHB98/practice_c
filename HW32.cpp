//�����Լ�
//������ ������
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
	down = inputUInt("* ���� ���� ���� �Է��Ͻÿ� : ");
	up = inputUInt("* ���� ���� �Է��Ͻÿ� : ");
	num1 = ipow(down, up);
	printf("%d�� %d���� %d�Դϴ�.\n", down, up, num1);

	printf("\n\n\n");

	_down = inputDouble("* ���� �Ǽ� ���� �Է��Ͻÿ� : ");
	up = inputUInt("* ���� ���� �Է��Ͻÿ� : ");
	num2 = fpow(_down, up);
	printf("%.2lf�� %d���� %.3lf �Դϴ�.\n", _down, up, num2);

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