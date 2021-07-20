//나에 대한 정보를 출력하는 프로그램
//수강생 정문수 HW1
#include<stdio.h>
void printAge(int age1);
void printHeight(double height1);
int main()
{
	char name[20] = "홍길동";
	int age = 500;
	double height = 170.8;

	printf("성명 : %s\n", name);
	printAge(age);
	printHeight(height);

	return 0;

}
void printAge(int age1)
{
	printf("나이 : %d \n", age1);
	return;
}

void printHeight(double height1)
{
	printf("키 : %lf\n", height1);
	return;
}
