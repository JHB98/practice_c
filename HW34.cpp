//������� ��� ���α׷�
//������ ������
#include<stdio.h>
#include<string.h>
#pragma warning (disable:4996);
int input();
double input2();
double calfee(int fee,double ton);
void output(int code, double ton, double sumfee);

int main()
{
	int code, fee;
	double sumfee = 0, ton;
	code = input();
	getchar();
	ton = input2();
	switch(code)
	{
	case 1: fee = 50;
			sumfee = calfee(fee, ton);
			break;
	case 2: fee = 45;
			sumfee = calfee(fee,ton);
			break;
	case 3: fee = 30; 
			sumfee = calfee(fee,ton);
			break;

	default: printf("�߸� �Է��ϼ̽��ϴ�.");
	}
	output(code, ton, sumfee);

	return 0;
}

int input()
{
	int code=0;
	printf("* ����� �ڵ带 �Է��Ͻÿ�(1:������ / 2 : ����� / 3 : ������) : ");
	scanf("%d", &code);

	return code;
}

double input2()
{
	double ton;
	printf("* ��뷮�� �Է��Ͻÿ�(ton����) : ");
	scanf("%lf", &ton);
	return ton;
}
double calfee(int fee,double ton)
{
	double sumfee = 0;//�� �������
	double sum = 0;//���������
	
	sum = ton * fee;
	sumfee = sum + (sum*0.05);
	return sumfee;
}

void output(int code, double ton, double sumfee)
{
	char codename[20] = { 0 };
	if (code == 1)
	{
		strcpy(codename, "������");
	}
	if (code == 2)
	{
		strcpy(codename, "�����");
	}
	if (code == 3)
	{
		strcpy(codename, "������");
	}

	printf("#����� �ڵ� : %d(%s)\n", code, codename);
	printf("#��뷮 : %lfton\n", ton);
	printf("#�Ѽ������ : %.2lf��\n", sumfee);
	
	return;
}