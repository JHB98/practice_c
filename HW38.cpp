//������ �ݾ����� ���� ����
//������ ������
#include<stdio.h>
#pragma warning (disable:4996);
int main()
{
	int price, c_p, s_p, co_p;

	printf("���� ����� ���� �ݾ� �Է� : ");
	scanf("%d", &price);

	if (getchar() != '\n')
	{
		return 0;
	}

	for (c_p = 500;c_p < price;c_p += 500)
	{
		for (s_p = 700;s_p < price;s_p += 700)
		{
			for (co_p = 400;co_p <= price;co_p += 400)
			{
				if (c_p + s_p + co_p == price)
				{
					printf("ũ����(%d ��), �����(%d ����), �ݶ�(%d ��)\n", c_p / 500, s_p / 700, co_p / 400);
				}
				else
				{
					continue;
				}
			}
		}
		
	}

	return 0;
	
}