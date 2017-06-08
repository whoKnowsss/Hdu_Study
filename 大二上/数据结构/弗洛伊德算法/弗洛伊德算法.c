#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
# define MAX 20
# define INFINITY 65535
typedef int VexType;
typedef  VexType Mgraph[MAX][MAX]; /* Mgraph是二维数组类型标识符 */
enum BOOL {
	FALSE, TRUE
};
/* 函数原形声明 */
void creat_mg(Mgraph G);
void out_mg(Mgraph G);
Mgraph G1;                         /*  G1是邻接矩阵的二维数组名  */
int n, e, v0;

void ShortestPath_FLOYD(Mgraph G, BOOL P[][MAX][MAX], VexType D[][MAX]) {
	for(int v=0;v<n;v++)
		for (int w = 0; w < n; w++) {
			D[v][w] = G[v][w];
			for (int u = 0; u < n; u++)P[v][w][u] = FALSE;
			if (D[v][w] < INFINITY) {
				P[v][w][v] = TRUE; P[v][w][w] = TRUE;
			}
		}
	for(int u=0;u<n;u++)
		for(int v=0;v<n;v++)
			for (int w = 0; w < n; w++)
			{
				if (D[v][u] + D[u][w] < D[v][w]) {
					D[v][w] = D[v][u] + D[u][w];
					for (int i = 0; i < n; i++) {
						if (P[v][u][i] == TRUE || P[u][w][i] == TRUE)P[v][w][i] = TRUE;
						else P[v][w][i] = FALSE;
					}
				}
			}
}
/*  主函数 */
int main()
{
	creat_mg(G1);
	BOOL P[MAX][MAX][MAX];
	VexType D[MAX][MAX];
	out_mg(G1);
	ShortestPath_FLOYD(G1, P,D);
	printf("\n");
	printf("顶点间最短路径所过点为（编号）：\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < n; k++)
			{
				if (i == j)printf(" ");
				else if(P[i][j][k]!=0)printf("%d", k+1);
			}
			printf("  ");
		}printf("\n");
	}
	printf("顶点间最短路径长度为：\n");
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
		{
			printf("%d ", D[i][j]);
		}printf("\n");
	}
	printf("\n\n   打回车键，继续。");char ch = getch();
	return 0;
}
/*  建立邻接矩阵  */
void creat_mg(Mgraph G)
{
	int i, j, k, w;
	printf("\n  n,e = ? ");
	scanf("%d,%d", &n, &e);  /* 输入顶点数n，边数e */
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) {
			G[i][j] = INFINITY;
			if (i == j)G[i][j] = 0;
		}
	/* 如果是网，G[i][j]=0该为G[i][j]=32767（无穷）*/
	for (k = 0; k < e; k++)                                /* 组织边数的循环  */
	{
		printf("\n  vi,vj,W= ? ");
		scanf("%d,%d,%d", &i, &j, &w);          /* 输入一条边的两个顶点编号i,j */
		G[i - 1][j - 1] = w; //G[j][i] = w;            /* 有向图的邻接矩阵是非对称矩阵 */
							 /* 如果是网，还要输入边的权值w，再让G[i][j]=w */
	}
} /* creat_mg */
  /* 邻接矩阵简单输出，为了检查输入是否正确 */
void out_mg(Mgraph G)
{
	int i, j, k;  char ch;
	for (i = 0; i < n; i++)        /*  矩阵原样输出 */
	{
		printf("\n ");
		for (j = 0; j < n; j++) {
			if (G[i][j] == INFINITY) {
				printf("∞ ");
			}
			else printf("%d ", G[i][j]);
		}
	}
	/*  输出所存在的边 */
	for (i = 0; i <n; i++)
		for (j = 0; j < n; j++)
			if (G[i][j] <65535 && G[i][j]>0)printf("\n 存在边< %d, %d >", i + 1, j + 1);
	printf("\n\n   打回车键，继续。"); ch = getch();
}
