//�ﰢ ���ĺ� ���
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int i, j;
	char english;

	printf("*������ �빮�� �Է�('A'~'Z') : ");
	scanf("%c", &english);
	
	if ((english >= 'A') && (english <= 'Z'))
	{
		for (i = english;i >= 'A';i--)
		{
			for (j = english;j >= i;j--)
			{
				printf("%c", j);
			}
			printf("\n");
		}
	}

	return 0;
}