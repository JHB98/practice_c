//���� ������ ī��Ʈ ���α׷�
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	char ch;
	int alphabet = 0, num = 0, space = 0, etc = 0;
	printf("# ���� ������ �Է��Ͻÿ� : ");
	while (1)
	{
		ch = getchar();
		
		if (((ch >= 'A') && (ch <= 'Z')) || ((ch >= 'a') && (ch <= 'z')))
		{
			alphabet++;
		}

		else if ((ch >= '0') && (ch <= '9'))
		{
			num++;
		}

		else if ((ch == 9) || (ch == '\n') || (ch == 32))
		{
			space++;
		}
		else if (ch == EOF)
		{
			break;
		}

		else
		{
			etc++;
		}
		
	}

	printf("* ������ ��ҹ��� ���� : %d��\n", alphabet);
	printf("* ���ڹ��� ���� : %d��\n", num);
	printf("* ���鹮��(space,tab,enter) ���� : %d��\n", space);
	printf("* �� �� ��Ÿ���� ���� : %d��\n", etc);

	return 0;
}