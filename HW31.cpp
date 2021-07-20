//은행 계좌 입출금 관리 프로그램
//수강생 정문수
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
		printf("* 현재 잔액은 %d원 입니다.\n\n", balance);
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
		printf("# 메뉴를 입력하시오(i-입금, o- 출금, q-종료) : ");
		scanf("%c", &check);

		if (getchar() == '\n')
		{
			if ((check == 'i') || (check == 'o') || (check == 'q'))
			{
				break;
			}

			else
			{
				printf("* 잘못 입력하셨습니다.\n\n");
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

		printf("* 잘못 입력하셨습니다. 다시 입력하십시오 : \n");
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
		money = inputInt("# 입금액을 입력하세요 : ");
		
		if (money < 0)
		{
			printf("* 잘못 입력하셨습니다. 다시 입력하십시오\n");
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
		money = inputInt("# 출금액을 입력하세요 : ");

		if (money < 0)
		{
			printf("* 잘못 입력하셨습니다. 다시 입력하십시오\n");
		}

		else
		{
			break;
		}
	}
	if (balance < money)
	{
		printf("잔액이 부족합니다.\n");
		return balance;
	}

	else
	{
		balance = balance - money;
	}
	return balance;
}