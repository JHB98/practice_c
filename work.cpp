#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
int main()
{
	char color[5][10] = { "red","green","yellow","blue","black" };

	char str[10] = { 0 }, answer = 0;
	char* strlink=NULL;
	int i;
	while (1)
	{
		printf("\n�����Է�? ");
		scanf("%s", str);
		strlink=strlwr(str);
		for (i = 0;i < 5;i++)
		{
			if (strcmp(color[i], strlink) == 0)
			{
				printf("color[%d] �࿡�� �˻� : %s \n", i, color[i]);

				break;
			}
		}

		if (i == 5)
		{
			printf("%s ������ color �迭�� ���ԵǾ� ���� �ʽ��ϴ�. \n", str);
		}

		printf("\n ����ұ��?(y/n)");
		getchar();
		answer = getchar();

		if (answer == 'n' || answer == 'N')
		{
			break;
		}

		if (answer == 'y' || answer == 'Y')
		{
			continue;
		}
	}

	return 0;
}