//����, Ű,������ �Է� �޾� ���
//������ ������
#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
int main()
{
	char name[21] = { 0 };
	double height = 0;
	char gender = 0;
	

	printf("# ���� �Է� : ");
	fgets(name, sizeof(name), stdin);
	name[strlen(name) - 1] = '\0';

	printf("# Ű �Է�(cm����) : ");
	scanf("%lf", &height);

	getchar();

	printf("# �����Է�(M/F) : ");
	scanf("%c", &gender);

	if (gender == 'M' || gender == 'm')
	{
		printf("%s���� Ű�� %.2lfcm �̰� �����Դϴ�.\n", name, height);
	}

	if (gender == 'F' || gender == 'f')
	{
		printf("%s���� Ű�� %.2lfcm�̰� �����Դϴ�.\n", name, height);
	}

	return 0;
}