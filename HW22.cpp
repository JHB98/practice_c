// 한줄에 * 5개씩 출력
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int main()
{
	int number,i=1;
	number = input();
	while (i <= number)
	{
		printf("*");
		if (i % 5 == 0)
		{
			printf("\n");
		}
		i++;
	}
	printf("\n");
	return 0;

}

int input()
{
	int number;
	printf("#정수값을 입력하세요 : ");
	scanf("%d", &number);

	return number;
}