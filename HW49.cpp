//배열 내의 데이터를 역순으로 저장
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
void swap(int *num, int size);
int main()
{
	int num[] = { 1,2,3,4,5};
	int size, j, k;
	size = sizeof(num) / sizeof(num[0]);
	
	printf("처음 배열에 저장된 값 : ");

	for (j = 0;j < size;j++)
	{
		printf("%2d", num[j]);
	}
	printf("\n");
	swap(num, size);

	printf("바뀐 배열에 저장된 값 : ");

	for (k = 0;k < size;k++)
	{
		printf("%2d", num[k]);
	}

	printf("\n");
	return 0;
}

void swap(int *num, int size)
{	
	int tmp,i;
	for (i = 0;i < (size/2);i++)
	{
		tmp = num[i];
		num[i] = num[(size-1) - i];
		num[(size-1) - i] = tmp;
	}

	return;
}