//���ڿ� �����Ͽ� ����ϱ�
//������ ������
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
int main()
{
	int i;
	unsigned int len;
	int space;
	char str[101] = { 0 };
	char str_tmp[101] = { 0 };
	printf("���ڿ� �Է�(100�� ����) : ");
	scanf("%s", str);
	len = strlen(str);
	if (len % 2 == 0)
	{
		space = len / 2;
	}
	else
	{
		space = (len / 2) + 1;
	}

	for (i=0;i<len-space;i++)
	{
		str_tmp[i] = str[i];
	}
	printf("[%*s%s...]\n", space,"",str_tmp);

	return 0;
	
}