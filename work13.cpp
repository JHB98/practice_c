#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int num[3][3] = { 4,9,1,7,2,8,3,5,6 };
	
	printf("처음 배열에 저장된 값 : \n");

	for (int j = 0;j < 3;j++)
	{
		for (int i = 0;i < 3;i++)
		{
			printf("%d ", num[j][i]);
		}
		printf("\n");
	}

	int tmp;
	for (int i = 0;i < 2;i++)
	{
		for (int k = 0;k < 3 - i;k++)
		{
			tmp = num[i][k];
			num[i][k] = num[2 - i][2 - k];
			num[2 - i][2 - k] = tmp;
		}
	}

	printf("바뀐 배열에 저장된 값 : \n");

	for (int j = 0;j < 3;j++)
	{
		for (int i = 0;i < 3;i++)
		{
			printf("%d ", num[j][i]);
		}
		printf("\n");
	}

	printf("\n");
	return 0;
}