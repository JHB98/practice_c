//���� ���� ����� ���� ���α׷�
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int menu();
int inputInt(const char *message);
int deposit(int balance);
int withdraw(int balance);
int main()
{
	int check, balance = 0;
	while (1)
	{
		printf("* ���� �ܾ��� %d�� �Դϴ�.\n\n", balance);
		check = menu();
		switch (check)
		{
		case 105: balance = deposit(balance);
			break;

		case 111: balance = withdraw(balance);
			break;

		case 113: return 0;
		}
	}
}

int menu()
{
	char check;
	while (1)
	{
		printf("# �޴��� �Է��Ͻÿ�(i-�Ա�, o- ���, q-����) : ");
		scanf("%c", &check);

		if (getchar() == '\n')
		{
			if ((check == 'i') || (check == 'o') || (check == 'q'))
			{
				break;
			}

			else
			{
				printf("* �߸� �Է��ϼ̽��ϴ�.\n\n");
				continue;
			}
		}

		while (1)
		{
			if (getchar() == '\n')
			{
				break;
			}
		}
	}
	return check;

}

int inputInt(const char *message)
{
	int num = 0;
	while (1)
	{
		printf("%s", message);
		scanf("%d", &num);

		if (getchar() == '\n')
		{
			break;
		}

		printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ� : \n");
		while (1)
		{
			if (getchar() == '\n')
			{
				break;
			}
		}
	}

	return num;
}

int deposit(int balance)
{
	int money;
	while (1)
	{
		money = inputInt("# �Աݾ��� �Է��ϼ��� : ");
		
		if (money < 0)
		{
			printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ�\n");
		}

		else
		{
			break;
		}
	}

	balance = balance + money;

	return balance;
}
int withdraw(int balance)
{
	int money;
	while (1)
	{
		money = inputInt("# ��ݾ��� �Է��ϼ��� : ");

		if (money < 0)
		{
			printf("* �߸� �Է��ϼ̽��ϴ�. �ٽ� �Է��Ͻʽÿ�\n");
		}

		else
		{
			break;
		}
	}
	if (balance < money)
	{
		printf("�ܾ��� �����մϴ�.\n");
		return balance;
	}

	else
	{
		balance = balance - money;
	}
	return balance;
}