//1���� ��,��,��,�ʷ� ȯ���ϴ� ���α׷�
//������ ������
#include<stdio.h>
int main()
{
	double year = 365.2422;
    double daytohour = (year - (int)year) * 24;
	double hourtomin = (daytohour - (int)daytohour) * 60;
	double mintosec = (hourtomin - (int)hourtomin) * 60;
	printf("%.4lf���� %d��",year,(int)year);
	printf(" %d�ð�", (int)daytohour);
	printf(" %d��",(int)hourtomin);
	printf(" %.2lf���Դϴ�.\n",mintosec);



	

	

	return 0;
	
}