//�� ���� ��,��,�� ������ ȯ���ϴ� ���α׷�
//������ ������ HW3
#include<stdio.h>
void caltime(int sec1, int time1[],char name1[][30]);
int main()
{
	int sec = 54321;
	int time[20] = {3600,60,1};
	char name[3][30] = { "�ð�","��","��" };

	caltime(sec, time,name);

}

void caltime(int sec1, int time1[],char name1[][30])
{
	int i;
	printf("%d�ʴ�", sec1);
	for (i = 0;i < 3;i++)
	{
		printf("%d %s",sec1 / time1[i],name1[i]);
		sec1 = sec1 - time1[i] * (sec1 / time1[i]);
	}
	printf("�Դϴ�.");
	return;
}

