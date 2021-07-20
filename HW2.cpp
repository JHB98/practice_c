//용돈 화폐단위 환산 프로그램
//수강생 정문수 HW2
#include<stdio.h>
void calnum(int c, int a[]);
int main()
{
	int money = 278970;
	int won[20] = { 50000,10000,5000,1000,500,100,50,10 };
	calnum(money, won);
	
}

void calnum(int money1, int won1[])
{
	int i;
	for (i = 0;i < 8;i++)
	{
		printf("%d원 => %d개\n", won1[i], money1 / won1[i]);
		money1 = money1 - (won1[i] * (money1 / won1[i]));
	}
	return ;
}