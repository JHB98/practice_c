#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int num[3];
	int ref;
	scanf("%d %d %d", &num[0], &num[1], &num[2]);

	for (int i = 0;i < 3;i++)
	{
		for (int j = i + 1;j < 3;j++)
		{
			if (num[i] > num[j])
			{
				ref = num[i];
				num[i] = num[j];
				num[j] = ref;
			}
		}
	}
	printf("%d", num[1]);
	return 0;
	
}