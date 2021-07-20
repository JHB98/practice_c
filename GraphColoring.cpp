#include<stdio.h>
#pragma warning (disable:4996);
void m_coloring(int i, int n, int m, int *vcolor, int **W);
bool promising(int i, int **W, int *vcolor);

int main()
{
	int i = 0;
	int vertexNum;
	int colorNum;
	int **W;
	int *vcolor;

	printf("정점의 개수 : ");
	scanf("%d", &vertexNum);
	
	W = new int *[vertexNum + 1];
	for (int i = 1;i <= vertexNum;i++)
	{
		W[i] = new int[vertexNum+1];
	}
	printf("그래프를 입력하세요\n");
	for (int j = 1;j <= vertexNum;j++)
	{
		for (int i = 1;i <= vertexNum;i++)
		{
			scanf("%d", &W[j][i]);
		}
	}
	
	printf("색의 개수 : ");
	scanf("%d", &colorNum);

	vcolor = new int[colorNum + 1];
	
	m_coloring(i, vertexNum, colorNum, vcolor,W);

	return 0;
}
void m_coloring(int i,int n,int m,int *vcolor,int **W) 
{
	int color;
	if (promising(i, W, vcolor))
	{
		if (i == n)
		{
			printf("정점별 색\n");
			for (int k = 1;k <= i;k++)
			{
				printf("%d번째 정점 : %d번째 색\n",k,vcolor[k]);
			}
			printf("\n");
		}

		else 
		{
			for (color = 1; color <= m; color++) 
			{
				vcolor[i + 1] = color;
				m_coloring(i + 1, n, m, vcolor, W);
			}
		}
	}
}
bool promising(int i, int **W, int *vcolor)
{
	int j; 
	bool check;
	check = true;
	j = 1;
	while (j<i && check) 
	{
		if (W[i][j] && vcolor[i] == vcolor[j])
		{
			check = false;
		}
		j++;
	}

	return check;
}