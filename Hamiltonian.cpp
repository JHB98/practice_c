#include<stdio.h>
#pragma warning (disable:4996);
void hamiltonian(int i, int* vindex, int **W, int n);
bool promising(int i, int *vindex, int **W, int n);

int main()
{
	int vertexNum;
	int *vindex;
	int **W;
	int i = 0;
	printf("정점의 개수 : ");
	scanf("%d", &vertexNum);
	vindex = new int[vertexNum + 1];
	vindex[0] = 1;
	W = new int *[vertexNum + 1];
	for (int i = 1;i <= vertexNum;i++)
	{
		W[i] = new int[vertexNum + 1];
	}
	
	printf("그래프를 입력하세요\n");
	for (int j = 1;j <= vertexNum;j++)
	{
		for (int i = 1;i <= vertexNum;i++)
		{
			scanf("%d", &W[j][i]);
		}
	}

	hamiltonian(i, vindex, W, vertexNum);

	return 0;
}
void hamiltonian(int i,int* vindex,int **W,int n) 
{
	int j;
	if (promising(i, vindex, W, n))
		if (i == n - 1) 
		{
			printf("지나는 정점\n");
			for (int k = 1;k <= i;k++)
			{
				printf("%d ", vindex[k]);
			}
			printf("\n");
		}
		else
		{
			for (j = 2; j <= n; j++) 
			{ 
				vindex[i + 1] = j;
				hamiltonian(i + 1, vindex, W, n);
			}
		}
}
bool promising(int i,int *vindex,int **W,int n) {
	int j; 
	bool check;
	if (i == n - 1 && !W[vindex[n - 1]][vindex[0]])
		check = false;
	else if (i>0 && !W[vindex[i - 1]][vindex[i]])
		check = false;
	else {
		check = true;
		j = 1;
		while (j<i && check) {
			if (vindex[i] == vindex[j]) check = false;
			j++;
		}
	}
	return check;
}

