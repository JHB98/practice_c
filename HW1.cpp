//���� ���� ������ ����ϴ� ���α׷�
//������ ������ HW1
#include<stdio.h>
void printAge(int age1);
void printHeight(double height1);
int main()
{
	char name[20] = "ȫ�浿";
	int age = 500;
	double height = 170.8;

	printf("���� : %s\n", name);
	printAge(age);
	printHeight(height);

	return 0;

}
void printAge(int age1)
{
	printf("���� : %d \n", age1);
	return;
}

void printHeight(double height1)
{
	printf("Ű : %lf\n", height1);
	return;
}
