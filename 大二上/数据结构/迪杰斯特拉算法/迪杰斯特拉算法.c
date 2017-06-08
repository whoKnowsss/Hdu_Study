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
BOOL *FINAL;
void ShortestPath_DIJ(Mgraph G, int v0,BOOL (*P)[MAX], VexType *D) {
	int v = 0;
	for (; v < n; ++v) {
		FINAL[v] = FALSE;
		D[v] = G[v0][v];
		for (int w = 0; w < n; ++w)
			P[v][w] = FALSE;
		if (D[v] < INFINITY) {
			P[v][v0] = TRUE;
			P[v][v] = TRUE;
		}
	}


	D[v0] = 0; FINAL[v0] = TRUE;
	for (int i = 1; i < n; i++) {
		int min = INFINITY;
		for (int w = 0; w < n; w++) {
			if (FINAL[w] != TRUE) {
				if (D[w] < min) {
					v = w; min = D[w];
				}
			}
		}
		FINAL[v] = TRUE;
		for (int w = 0; w < n; ++w) {
			if (FINAL[w] != TRUE && (min + G[v][w] < D[w])) {
				D[w] = min + G[v][w];
				for (int j = 0; j < n; j++) {
					P[w][j] = P[v][j];
				}
				P[v][v] = TRUE;
				P[w][v] = TRUE;
			}
		}
	}
}
/*  主函数 */
int main()
{
	creat_mg(G1);
	BOOL P[MAX][MAX];
	VexType *D = (VexType *)malloc(n*sizeof(VexType));
	out_mg(G1);
	FINAL = (BOOL *)malloc(n * sizeof(BOOL));
	ShortestPath_DIJ(G1,0,P,D);
	printf("\nS中有（有最短路径的点）为：");
	for (int i = 0; i < n; i++) {
		if(P[i][0]!=FALSE)
			printf("%d ", i);	
	}
	printf("\n");
	printf("\n各自距离为：\n");
	for (int i = 0; i < n; i++) {
		if (D[i] == INFINITY && D[i]==0)printf("");
		else printf("%d ", D[i]);
	}
	return 0;
}
/*  建立邻接矩阵  */
void creat_mg(Mgraph G)
{
	int i, j, k, w;
	printf("\n  n,e = ? ");
	scanf("%d,%d", &n, &e);  /* 输入顶点数n，边数e */
	for (i = 0; i < n; i++)
		for (j = 0; j < n; j++) G[i][j] = INFINITY;
	/* 如果是网，G[i][j]=0该为G[i][j]=32767（无穷）*/
	for (k = 0; k < e; k++)                                /* 组织边数的循环  */
	{
		printf("\n  vi,vj,W= ? ");
		scanf("%d,%d,%d", &i, &j, &w);          /* 输入一条边的两个顶点编号i,j */
		G[i-1][j-1] = w; //G[j][i] = w;            /* 有向图的邻接矩阵是非对称矩阵 */
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
			if ( G[i][j] == INFINITY) {
				printf("∞ ");
			}
			else printf("%d ", G[i][j]);
		}
	}
	/*  输出所存在的边 */
	for (i = 0; i <n; i++)
		for (j = 0; j < n; j++)
			if (G[i][j] <65535&&G[i][j]>0)printf("\n 存在边< %d, %d >", i+1, j+1);
	printf("\n\n   打回车键，继续。"); ch = getch();
}
