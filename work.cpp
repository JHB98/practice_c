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
		printf("\n색상입력? ");
		scanf("%s", str);
		strlink=strlwr(str);
		for (i = 0;i < 5;i++)
		{
			if (strcmp(color[i], strlink) == 0)
			{
				printf("color[%d] 행에서 검색 : %s \n", i, color[i]);

				break;
			}
		}

		if (i == 5)
		{
			printf("%s 색상은 color 배열에 포함되어 있지 않습니다. \n", str);
		}

		printf("\n 계속할까요?(y/n)");
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