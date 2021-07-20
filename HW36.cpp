//피보나치 수열
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
void fibonacci(int num);
int main()
{
	int num;
	printf("피보나치 수열의 항수를 입력하시오 : ");
	scanf("%d", &num);
	fibonacci(num);

	return 0;
}

void fibonacci(int num)
{
	int i, n1 = 0, n2 = 1, n3 = 0, sum = 0;
	printf("1");
	for (i = 1;i < num;i++)
	{	
		n3 = n1 + n2;
		n1 = n2;
		n2 = n3;
		sum += n3;
		printf("+%d", n3);
	}
	printf("=%d\n", sum + 1);

	return;
}