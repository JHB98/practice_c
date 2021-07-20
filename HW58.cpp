//히스토그램 출력
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
FILE * fileOpen(const char *filename, const char *mode);
void input(FILE *fp, int *num);
void print_histogram(int *num, int data_count);
int main()
{
	int num[30] = { 0 }, count, n;
	FILE *fp;
	fp = fileOpen("c:\\HW58_histogram.txt", "rt");
	if (fp == NULL)
	{
		return 1;
	}
	
	fscanf(fp, "%d", &count);
	
	for (n = 0;n < count;n++)
	{
		input(fp, num);
		printf("\n\n------------------------------------------------------\n\n");
	}

	fclose(fp);

	return 0;
}

FILE * fileOpen(const char *filename, const char *mode)
{
	FILE *fp;
	if ((fp = fopen(filename, mode)) == NULL)
	{
		printf("파일 오픈 error\n");
	}

	return fp;
}

void input(FILE *fp, int *num)
{
	int data_count = 0;
	while (1)
	{
		fscanf(fp, "%d", &num[data_count]);
		if (num[data_count] == 0)
		{
			break;
		}
		data_count++;
	}
	print_histogram(num, data_count);

	return;
}

void print_histogram(int *num, int data_count)
{
	char histogram[9][30] = { 0 };
	int i, j, k, l, m;

	for (i = 0;i < data_count;i++)
	{
		for (j = (9 - num[i]);j < 9;j++)
		{
			histogram[j][i] = '*';
		}
	}

	for (k = 0;k < 9;k++)
	{
		for (l = 0;l < data_count;l++)
		{
			printf("%3c", histogram[k][l]);
		}
		printf("\n");
	}

	printf("\n");

	for (m = 0;m < data_count;m++)
	{
		printf("%3d", num[m]);
	}

	
	return;
}
