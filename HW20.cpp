//pay ����ϱ�
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int input();
int calmoney(int worktime);
int caltax(int pay);
void output(int pay, int tax);
int main()
{
	int worktime,pay,tax;
	worktime = input();
	pay = calmoney(worktime);
	tax = caltax(pay);
	output(pay, tax);

	return 0;


}

int input()
{
	int worktime;
	printf("1���ϰ��� �ٹ��ð��� �Է��Ͻÿ� : ");
	scanf("%d", &worktime);

	return worktime;
}

int calmoney(int worktime)
{
	int pay;
	if (worktime <= 40)
	{
		pay = worktime * 3000;
	}
	else
	{
		pay = (3000 * 40) + ((worktime - 40) * 3000 * 1.5);
	}

	return pay;
}

int caltax(int pay)
{
	int tax;
	if (pay <= 100000)
	{
		tax = pay * 0.15;
	}
	else
	{
		tax = (100000 * 0.15) + ((pay - 100000)*0.25);
	}

	return tax;
}

void output(int pay, int tax)
{
	printf("�Ѽ��� : %d\n", pay);
	printf("���� : %d\n", tax);
	printf("�Ǽ��� : %d\n", pay - tax);

}