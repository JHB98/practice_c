//���� �˻� ���α׷�(���� �˻�)
//������ ������
#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
char inputnum(char *ch, char check);
int strcheck(char *ch, char check);
int main()
{
	char ch[99] = { 0 };
	char check = 0;
	int index;

	check = inputnum(ch, check);
	index = strcheck(ch, check);
	if (index == -1)
	{
		printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� �������� �ʽ��ϴ�.\n", ch, check);
	}

	else
	{
		printf("\"%s\" ���ڿ� �ȿ� '%c' ���ڴ� %d�� ��ġ�� �����մϴ�\n", ch, check, index);
	}

	return 0;
}

char inputnum(char *ch, char check)
{
	printf("# ���ڿ��� �Է��Ͻʽÿ�(1~99����) : ");
	scanf("%s", ch);
	
	printf("# ���ڸ� �Է��Ͻÿ� : ");
	scanf(" %c", &check);

	return check;
}

int strcheck(char *ch, char check)
{
	int size, i;
	size = strlen(ch);
	
	for (i = 0;i < size;i++)
	{
		if (ch[i] == check)
		{
			return i;
		}
	}

	return -1;
}