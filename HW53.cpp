//ȸ�� �˻� ���α׷�
//������ ������
#include<stdio.h>
#include<ctype.h>
#include<string.h>
#pragma warning (disable:4996);
void inputstring(char *ch);
int circular(char *ch);
void output(char *ch, int check);
int main()
{
	char ch[100] = { 0 };
	int check;
	inputstring(ch);
	check = circular(ch);
	output(ch, check);

	return 0;

}
void inputstring(char *ch)
{
	printf("# ���ڿ��� �Է��Ͻʽÿ�: ");
	scanf("%s", ch);

	return;
}

int circular(char *ch)
{
	int tmp, i, j, size;
	size = strlen(ch);
	for (j = 0;j < size;j++)
	{
		ch[j] = (char)tolower(ch[j]);
	}
	
	for (i = 0;i < (size / 2);i++)
	{
		if (ch[i] != ch[(size-1)- i])
		{
			return 0;
		}
	
	}

	return 1;
}

void output(char *ch, int check)
{
	if(check==1)
	{
		printf("\"%s\" : ȸ���Դϴ�! \n", ch);
	}

	else
	{
		printf("\"%s\" : ȸ���� �ƴմϴ�! \n", ch);
	}

	return;
}