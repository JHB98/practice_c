#include<stdio.h>
#pragma warning (disable:4996);
struct edge
{
	int vertex[2] = { 0 };
	int weight = 0;
};
void dijkstra(int n, int **W, edge* F);
int main()
{
	int edgeNum = 0;
	int vertexNum = 0;
	int** W;
	edge* Edge;
	printf("edge의 개수 :");
	scanf("%d", &edgeNum);
	printf("vertex의 개수 :");
	scanf("%d", &vertexNum);
	Edge = new edge[edgeNum + 1];
	W = new int *[vertexNum + 1];
	for (int i = 1;i <= vertexNum;i++)
	{
		W[i] = new int[vertexNum + 1];
	}
	
	printf("그래프를 입력하세요(무한대는 1234, 제자리는 0) : \n");
	for (int n = 1;n <=vertexNum;n++)
	{
		for (int m = 1;m <= vertexNum;m++)
		{
			scanf("%d", &W[n][m]);
		}
	}

	dijkstra(vertexNum, W, Edge);

	return 0;

}
void dijkstra(int n, int **W, edge* F) {
	int i, vnear, count=1;
	edge e;
	int* touch = new int[n+1];
	int* length = new int[n+1];
	int min;
	for (i = 2; i <= n; i++) 
	{ 
		touch[i] = 1;
		length[i] = W[1][i]; 
	} 

	while(count!=n) 
	{
		min =100000;
		for (i = 2; i <= n; i++)
		{
			if ((0 <= length[i])&&(length[i] <= min)) 
			{
				min = length[i];
				vnear = i;
			}
		}
		e.vertex[0] = touch[vnear];
		e.vertex[1] = vnear;
		e.weight = W[touch[vnear]][vnear];
			
		F[count] = e;

		for (i = 2; i <= n; i++)
		{
			if (length[vnear] + W[vnear][i] < length[i])
			{
				length[i] = length[vnear] + W[vnear][i];
				touch[i] = vnear; 
			}
		}
		length[vnear] = -1;
		count++;
	}

	printf("선택된 edge\n");
	for (int i = 1;i <count; i++)
	{
		printf("%d %d %d\n", F[i].vertex[0], F[i].vertex[1], F[i].weight);
	}
}