//�� ���� ���� �Է¹޾� ����,��� ����ϱ�
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int history;
	int literature;
	int art;
	int total;
	double average;
	printf("���� ���� ���� �������� ������ �Է��Ͻø� ������ ����� �˷��帳�ϴ�.\n");
	printf("����, ����, ���� ������ �Է��ϼ��� :");
	scanf("%d %d %d", &history, &literature, &art);
	total = history + literature + art;
	average = (double)total / 3;
	printf("������ %d �̰� ����� %.2lf �Դϴ�.\n", total, average);

	return 0;

}