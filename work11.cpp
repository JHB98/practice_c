#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#pragma warning (disable:4996);
typedef struct
{
	int x = 0;
	int y = 0;
}dot;
int main()
{
	int shopNum = 0;
	int peopleNum = 0;
	dot nearShop;
	double path = 1000;
	printf("������ ���� �Է��ϼ��� : ");
	scanf("%d", &shopNum);
	printf("����� ���� �Է��ϼ��� : ");
	scanf("%d", &peopleNum);

	dot *shop = (dot*)malloc(sizeof(dot)*(shopNum+1));
	dot *people = (dot*)malloc(sizeof(dot)*(peopleNum+1));

	for (int i = 1;i <= shopNum;i++)
	{
		printf("%d ��° ������ ��ǥ�� �Է��ϼ��� : ", i);
		scanf("%d %d", &shop[i].x, &shop[i].y);
	}

	for (int j = 1; j <= peopleNum;j++)
	{
		printf("%d ��° ����� ��ǥ�� �Է��ϼ��� : ", j);
		scanf("%d %d", &people[j].x, &people[j].y);
	}
	
	for (int i = 1;i <= peopleNum;i++)
	{
		for (int k = 1;k <= shopNum;k++)
		{
			if (sqrt(((shop[k].x - people[i].x)*(shop[k].x - people[i].x)) + ((shop[k].y - people[i].y)*(shop[k].y - people[i].y))) < path)
			{
				nearShop = shop[k];
				path = sqrt(((shop[k].x - people[i].x)*(shop[k].x - people[i].x)) + ((shop[k].y - people[i].y)*(shop[k].y - people[i].y)));
			}
		}
		printf("%d ��° ����� �����ִܰŸ� : %d %d�� �ִ� ����, �Ÿ� : %.4lf\n", i, nearShop.x, nearShop.y, path);
		path = 1000;
	}

	return 0;
}