//���ڿ� ���� ������ �� ���ϱ�
//������ ������
#include<stdio.h>
#include<string.h>
#include<math.h>
#pragma warning (disable:4996);
void input(char *ary);
int calnum(char *ary);
void output(char *ary, int sum);
int main()
{
	int sum;
	char ary[100] = { 0 };
	input(ary);
	sum = calnum(ary);
	output(ary, sum);
	return 0;

}

void input(char *ary)
{
	printf("# ������ �Է��Ͻÿ�(99����) : ");
	scanf("%s", ary);

	return;
}

int calnum(char *ary)//char�迭 �濡 ���ڸ� ���� �Է¹޾� �̾�ٿ� ������ ���ڷ� �ٲ��ִ� �Լ�
{
	int size, i, j = 0, size2, k, l;
	double sum = 0;
	char num[10] = { 0 };
	size = strlen(ary);
	for (i = 0;i < size;i++)
	{
		if ((ary[i] >= '0') && (ary[i] <= '9'))
		{
			num[j] = ary[i];
			j++;

			if ((ary[i + 1] < '0') || (ary[i + 1] > '9'))
			{
				size2 = strlen(num);

				for (k = 1;k <= size2;k++)
				{
					sum += (double)(num[k-1] - '0') * pow((double)10, (double)(size2 - k));
				}
				for (l = 0;l < size2;l++)
				{
					num[l] = 0;
				}
				j = 0;
			}
		}
	}

	return sum;
}

void output(char *ary, int sum)
{
	printf("\"%s\" ���� �� ���ڴ� [%d] �Դϴ�.\n", ary, sum);

	return;
}