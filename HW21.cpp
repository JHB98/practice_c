//�ټ����� �л��� Ű�� �Է� �޾� �� ��� ���
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int student = 1;
	double height = 0;
	double sum = 0;
	while (student != 6)
	{
		printf("%d �� �л��� Ű��? ", student);
		scanf("%lf", &height);
		sum += height;
		student++;
	}
	printf("�ټ� ���� ��� Ű�� %.1lf cm�Դϴ�.\n", sum / (double)5);

	return 0;
}