#include<stdio.h>
#pragma warning (disable:4996);
void sum_of_subsets(int i, int weight, int total, int W, int *include, int *w);
bool promising(int i, int weight, int total, int *w, int W);
void sort(int *w, int num);

int main()
{
	int *w;
	int i=0;
	int weight=0;
	int total=0;
	int W;
	int *include;
	int num1;
	printf("원소 개수 : ");
	scanf("%d", &num1);
	w = new int[num1+1];
	include = new int[num1 + 1];
	
	for (int j = 1;j <= num1;j++)
	{
		printf("%d번째 원소의 값 : ",j);
		scanf("%d", &w[j]);
		total += w[j];
	}
	sort(w, num1);
	
	printf("원하는 W 값 : ");
	scanf("%d", &W);
	
	sum_of_subsets(i, weight, total, W, include, w);

	return 0;
}
void sum_of_subsets(int i, int weight, int total, int W, int *include, int *w) 
{
	if (promising(i, weight, total, w, W))
	{
		if (weight == W)
		{
			printf("포함된 원소 : ");
			for (int k = 1;k <= i;k++)
			{
				if (include[k] == NULL)
				{
					continue;
				}
				printf("%d ", include[k]);
			}
			printf("\n");
		}

		else 
		{
			include[i + 1] = w[i+1];
			sum_of_subsets(i + 1, weight + w[i + 1], total - w[i + 1], W, include, w);
			include[i + 1] = NULL;
			sum_of_subsets(i + 1, weight, total - w[i + 1], W, include, w);
		}
	}
}

bool promising(int i, int weight, int total, int *w, int W)
{
	return (weight + total >= W)&&(weight == W || weight + w[i + 1] <= W);
}
void sort(int *w, int num)
{
	int tmp;
	for (int i = 1;i <= num;i++)
	{
		for (int j = i + 1;j <= num;j++)
		{
			if (w[i] > w[j])
			{
				tmp = w[i];
				w[i] = w[j];
				w[j] = tmp;
			}
		}
	}
}