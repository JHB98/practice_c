//�ּҰ�, �ִ밪 ã��
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
void input(double *num);
double maximum(double *num);
double minimum(double *num);
void output(double max_num, double mini_num);
int main()
{
	double num[5] = { 0 };
	double max_num, mini_num;
	input(num);
	max_num = maximum(num);
	mini_num = minimum(num);
	output(max_num, mini_num);

	return 0;
}

void input(double *num)
{
	int i = 0;
	double tmp;
	while (i != 5)
	{
		while (1)
		{
			printf("%d �� �� �� : ", i);
			scanf("%lf", &tmp);

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

		num[i] = tmp;
		i++;
	}

	return;
}

double maximum(double *num)
{
	int j;
	double maximum = num[0];
	for (j = 1;j < 5;j++)
	{
		if (maximum < num[j])
		{
			maximum = num[j];
		}
	}
	return maximum;
}

double minimum(double *num)
{
	int k;
	double minimum = num[0];
	for (k = 1;k < 5;k++)
	{
		if (minimum > num[k])
		{
			minimum = num[k];
		}
	}
	return minimum;
}

void output(double max_num, double mini_num)
{
	printf("\n\n");
	printf("���� ū ��: %.2lf\n", max_num);
	printf("���� ���� �� : %.2lf\n", mini_num);

	return;
}