//ȯǳ�� ���� ���α׷�
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int menu();
char openFan(char fan);
char offFan(char fan);
char reverseFan(char fan);
void  displayFan(char fan);
int main()
{
	char fan = 0x00;
	int check;
	while (1)
	{
		check = menu();
		switch (check)
		{
		case 1: fan = openFan(fan);
				displayFan(fan);
				break;
		case 2: fan = offFan(fan);
				displayFan(fan);
				break;
		case 3: fan = reverseFan(fan);
				displayFan(fan);
				break;
		case 4: return 0;

		}
	}
	
}

int menu()
{
	int check;
	while (1)
	{
		printf("\n\n1. ȯǳ�� ���� / 2. ȯǳ�� �ݱ� / 3. ȯǳ�� ��ü ��ȯ / 4. ���� : ");
		scanf("%d", &check);
		if (getchar() == '\n')
		{
			if ((check > 0) && (check < 5))
			{
				break;
			}
			else
			{
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

char openFan(char fan)
{
	int num, i;
	unsigned char fan_check = 0x80;
	printf("--------------------------------------------------------\n");
	printf("\t\tFan ���� �۾� ���� ȭ��\n");
	printf("--------------------------------------------------------\n");
	
	while (1)
	{
		printf("* OPEN �� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
		scanf("%d", &num);
		if (getchar() == '\n')
		{
			if ((num > 0) && (num < 9))
			{
				break;
			}
			else
			{
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

	for (i = 0;i < (8 - num);i++)
	{
		fan_check = fan_check >> 1;
	}

	fan = fan | fan_check;

	return fan;
}

char offFan(char fan)
{
	int num, i;
	unsigned char fan_check = 0x80;
	printf("--------------------------------------------------------\n");
	printf("\t\tFan �ݱ� �۾� ���� ȭ��\n");
	printf("--------------------------------------------------------\n");

	while (1)
	{
		printf("* CLOSE �� FAN ��ȣ�� �Է��Ͻÿ�(1-8) : ");
		scanf("%d", &num);
		if (getchar() == '\n')
		{
			if ((num > 0) && (num < 9))
			{
				break;
			}
			else
			{
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

	for (i = 0;i < (8 - num);i++)
	{
		fan_check = fan_check >> 1;
	}

	fan = fan ^ fan_check;

	return fan;
}

char reverseFan(char fan)
{
	int num, i;
	printf("--------------------------------------------------------\n");
	printf("\t\tFan ��ü ��ȯ �۾� ���� ȭ��\n");
	printf("--------------------------------------------------------\n");
	printf("��ü FAN�� ���°� ��ȯ �Ǿ����ϴ�.(ON,OFF ���� �ڹٲ�)\n");
		
	
	fan = ~fan;
	
	return fan;
}

void  displayFan(char fan)
{
	unsigned char fan_check=0x80;
	int i, j;
	printf("--------------------------------------------------------\n");
	for (j = 8;j > 0;j--)
	{
		printf("%d�� FAN\t",j);
	}

	printf("\n");
	for (i = 0;i < 8;i++)
	{
		if (fan & fan_check)
		{
			printf("  ON\t");
		}

		else
		{
			printf("  OFF\t");
		}

		fan_check = fan_check >> 1;
	}
	printf("\n\n");
	printf("--------------------------------------------------------\n");

	return;
}