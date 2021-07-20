#include<stdio.h>
#include<stdlib.h>
#pragma warning (disable:4996);
struct nodetype
{
	int parent;
	int depth;
};

struct edge
{
	int vertex[2] = { 0 };
	int weight = 0;
};
typedef int set_pointer;
void kruskal(int n, int m, edge* Edge, edge* Edge_ref, nodetype* U);
void initial(int n, nodetype* U);
bool equal(set_pointer p, set_pointer q);
void merge(set_pointer p, set_pointer q, nodetype* U);
set_pointer find(int i, nodetype* U);
void edgeSort(edge* Edge, int num);
void makeset(int i, nodetype* U);

int main()
{
	int num1 = 0;
	int num2 = 0;
	int v = 0;
	int weight = 0;
	edge* Edge;
	edge* Edge_ref;
	nodetype* U;
	printf("edge 의 개수 : ");
	scanf("%d", &num1);
	printf("vertex의 개수 :");
	scanf("%d", &num2);
	Edge = new edge[num1+1];
	Edge_ref = new edge[num1+1];
	U = new nodetype[num2+1];
	for (int i = 1;i <= num1;i++)
	{
		printf("%d번째 edge의 양쪽 vertex와 weight를 입력하세요 : ", i);
		scanf("%d %d %d", &Edge[i].vertex[0], &Edge[i].vertex[1], &Edge[i].weight);
	}
	kruskal(num2, num1, Edge, Edge_ref, U);

	return 0;
	
};

void makeset(int i, nodetype* U)
{
	U[i].parent = i;
	U[i].depth = 0;
};

void edgeSort(edge* Edge,int num)
{
	edge tmp;
	for (int i = 1;i <= num;i++)
	{
		for (int j = i + 1;j <= num;j++)
		{
			if (Edge[i].weight > Edge[j].weight)
			{
				tmp = Edge[i];
				Edge[i] = Edge[j];
				Edge[j] = tmp;
			}
		}
	}
}

set_pointer find(int i, nodetype* U)
{
	int j; 
	j = i;
	while (U[j].parent != j)
	{
		j = U[j].parent;
	}
	return j;
}

void merge(set_pointer p, set_pointer q, nodetype* U)
{
	if (U[p].depth == U[q].depth) 
	{
		U[p].depth += 1;
		U[q].parent = p;
	}
	else if (U[p].depth < U[q].depth)
	{
		U[p].parent = q;
	}

	else U[q].parent = p;
}
bool equal(set_pointer p, set_pointer q)
{
	if (p == q)
	{
		return true;
	}

	else
	{
		return false;
	}
}

void initial(int n, nodetype* U)
{
	int i;
	for (i = 1; i <= n; i++)
	{
		makeset(i, U);
	}
}

void kruskal(int n, int m, edge* Edge, edge* Edge_ref, nodetype* U)
{
	int i, j;
	int num1 = 1;
	int num2 = 1;
	int sum = 0;
	set_pointer p, q;
	edge e;
	edgeSort(Edge, m);
	initial(n, U);
	while (num2 < n)
	{
		e = Edge[num1];
		i = e.vertex[0];
		j = e.vertex[1];
		p = find(i, U);
		q = find(j, U);
		if (!equal(p, q))
		{
			merge(p, q, U);
			Edge_ref[num2] = e;
			num2++;
			sum += e.weight;
		}

		num1++;
	}

	printf("선택된 edge\n");
	for (int i = 1;i < num2; i++)
	{
		printf("%d %d %d\n", Edge_ref[i].vertex[0], Edge_ref[i].vertex[1], Edge_ref[i].weight);
	}
	printf("최저 가중치 : %d\n", sum);
}