//정수 값 소트 프로그램
//수강생 정문수
#include<stdio.h>
#pragma warning (disable:4996);
FILE * fileOpen(const char *filename, const char *mode);
int fileRead(FILE *fp, int *dataArray);
void inputdata(FILE *fp, int dataCnt, int *dataArray);
void sort(int dataCnt, int *dataArray);
void output(int dataCnt, int *dataArray);

int main()
{
	int dataCnt = 0;
	int dataArray[20] = { 0 };
	FILE *fp;
	fp = fileOpen("c:\\data\\hw52_sortData.txt", "rt");
	if (fp == NULL)
	{
		return 1;
	}

	inputdata(fp, dataCnt, dataArray);

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

int fileRead(FILE *fp, int *dataArray)
{
	int dataCnt = 0, n;
	while (1)
	{
		fscanf(fp, "%d", &dataArray[dataCnt]);
		if (dataArray[dataCnt] == 0)
		{
			break;
		}
		dataCnt++;
	}
	printf("# 소트 전 데이터 : ");
	for (n = 0;n < dataCnt;n++)
	{
		printf("%3d", dataArray[n]);
	}
	printf("\n");

	return dataCnt;
}

void inputdata(FILE *fp, int dataCnt, int *dataArray)
{
	int i, count;
	fscanf(fp, "%d", &count);
	for (i = 0;i < count;i++)
	{
		dataCnt = fileRead(fp, dataArray);
		sort(dataCnt,dataArray);
	}

	return;

}

void sort(int dataCnt,int *dataArray)
{
	int k, l, tmp;
	for (k = 0;k < dataCnt-1;k++)
	{
		for (l=k+1;l<dataCnt;l++)
		{
			if (dataArray[k] > dataArray[l])
			{
				tmp = dataArray[k];
				dataArray[k] = dataArray[l];
				dataArray[l] = tmp;
			}
		}
	}
	output(dataCnt, dataArray);

	return;
}

void output(int dataCnt, int *dataArray)
{
	int n;

	printf("# 소트 후 데이터 : ");

	for (n = 0;n < dataCnt;n++)
	{
		printf("%3d", dataArray[n]);
	}

	printf("\n\n\n");

	return;
}