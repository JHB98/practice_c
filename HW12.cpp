//�̸��� �������� �Է¹޾� ���
//������ ������
#include<stdio.h>
#pragma warning(disable:4996)
int main()
{
	char name[21] = { 0 };
	printf("�̸��� �Է��Ͻÿ�(���� �̸����̸� _�� �̾ �Է�) : ");
	scanf("%s", name);

	printf("\"%s\"\n", name);
	printf("\"%20s\"\n", name);
	printf("\"%-20s\"\n", name);

	return 0;
}