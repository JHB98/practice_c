//������ �칰 Ż�� ���α׷�
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int escape(int depth);
void output(int depth, int day);
int main()
{
	int depth = 0, day = 0;
	depth = input();
	day = escape(depth);
	output(depth, day);

	return 0;

}

int input()
{
	int depth = 0;
	printf("* �칰�� ���̸� �Է��Ͻÿ�(cm����) : ");
	scanf("%d", &depth);
	return depth;
}

int escape(int depth)
{
	int climb = 0;
	int day = 1;
	while (1)
	{
		if (depth == 0)
		{
			day = 0;
		}
		climb += 50;
		if (climb >= depth)
		{
			break;
		}

		else
		{
			climb -= 20;
			day++;
		}
	}
	return day;

}

void output(int depth, int day)
{
	printf("%.2lf���� ������ �칰�� Ż���ϱ� ���ؼ��� %d���� �ɸ��ϴ�.\n", depth / (double)100, day);
	return;
}