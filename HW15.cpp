// BMI ���ϱ�
//������ ������ HW15
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
float BMI(float weight, float height);
void check(float bmi);
int main()
{
	float bmi = 0;
	float height=0, weight=0;
	printf("BMI�� �����ص帳�ϴ�.\n");
	printf("�����Ը� �Է��ϼ���:");
	scanf("%f", &weight);
	printf("Ű�� �Է��ϼ���(m����):");
	scanf("%f", &height);
	bmi = BMI(weight, height);
	check(bmi);

		return 0;


}

float BMI(float weight, float height)
{
	float bmi;
	bmi = (weight / (height*height));
	return bmi;
}

void check(float bmi)
{
	char what[20];
	if (bmi < 18.5)
		strcpy(what, "��ü��");
	else if (bmi < 25.0)
		strcpy(what,"����ü��");
	else if (bmi < 30.0)
		strcpy(what,"��ü��");
	else if (bmi < 40.0)
		strcpy(what,"��");
	else
		strcpy(what,"����");

	printf("����� BMI�� %f�� %s�Դϴ�.\n", bmi,what);
	return;
}