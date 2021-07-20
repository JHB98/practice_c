// BMI 구하기
//수강생 정문수 HW15
#include<stdio.h>
#include<string.h>
#pragma warning(disable:4996)
float BMI(float weight, float height);
void check(float bmi);
int main()
{
	float bmi = 0;
	float height=0, weight=0;
	printf("BMI를 측정해드립니다.\n");
	printf("몸무게를 입력하세요:");
	scanf("%f", &weight);
	printf("키를 입력하세요(m단위):");
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
		strcpy(what, "저체중");
	else if (bmi < 25.0)
		strcpy(what,"정상체중");
	else if (bmi < 30.0)
		strcpy(what,"과체중");
	else if (bmi < 40.0)
		strcpy(what,"비만");
	else
		strcpy(what,"고도비만");

	printf("당신의 BMI는 %f로 %s입니다.\n", bmi,what);
	return;
}