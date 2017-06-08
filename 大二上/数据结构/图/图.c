# include <stdio.h>
# include <stdlib.h>
#include <conio.h>
# define MAX 20
#define NULL 0
typedef int QElemType;
//节点
typedef struct Queue
{
	QElemType data;
	struct Queue *next;
}QNode, *QueuePtr;
//队列(头尾指针)
typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
enum Status
{
	OK, ERROR, OVERFLOW
};
enum BOOL		
{
	FALSE, TRUE
};
//构造空队列 OK
Status InitQueue(LinkQueue *Q)
{
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)exit(OVERFLOW);//内存已满
	Q->front->next = NULL;
	return OK;
}
//销毁队列Q OK
Status DestoryQueue(LinkQueue *Q)
{
	while (Q->front)//最后的next指针指向为NULL
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}
//入队 OK
Status EnQueue(LinkQueue *Q, QElemType e)
{
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;//在队尾添加节点
	Q->rear = p;
}
//出队 OK
Status DeQueue(LinkQueue *Q, QElemType *e)
{
	if (Q->front == Q->rear)return ERROR;//若为空，不删除
	QueuePtr p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)Q->rear = Q->front;
	free(p);
	return OK;
}
//清空为空队列 OK
Status ClearQueue(LinkQueue *Q)
{
	if (DestoryQueue(Q) == ERROR)return ERROR;
	if (InitQueue(Q) == ERROR)return ERROR;
	return OK;
}
//判断队列是否为空 OK
BOOL QueueEmpty(LinkQueue *Q)
{
	if (Q->front == Q->rear&&Q->front != NULL)return TRUE;
	else return FALSE;
}
//获取队列头元素 OK
Status GetHead(LinkQueue *Q, QElemType *e)
{
	if (QueueEmpty(Q) == FALSE)
	{
		*e = Q->front->next->data;
		return OK;
	}
	else
	{
		return ERROR;
	}
}
//队列长度 OK
int QueueLength(LinkQueue *Q)
{
	QueuePtr p = Q->front;
	int result = 0;
	while (p != NULL&&p->next != NULL)
	{
		result++;
		p = p->next;
	}
	return result;
}
typedef int VexType;
typedef  struct Vnode
{
	VexType data;
	struct Vnode *next;
}Vnode;                           /* Vnode是顶点的结点结构 */
typedef Vnode Lgraph[MAX];      /* Lgraph是一维数组类型标识符 */
								/* 函数原形声明 */
void creat_L(Lgraph G);
void out_L(Lgraph G);
void dfsL(Lgraph G, int v);
void bfsL(Lgraph g, int v);
Lgraph Ga;                      /*  Ga是邻接链表的表头数组名  */
int n, e, vis[MAX];
/*  主函数 */
int main()
{
	int v1, i;
	char ch;
	for (i = 0; i<MAX; i++) vis[i] = 0;     /*  顶点访问的标志数组   */
	creat_L(Ga);                     /*   建立图邻接链表Ga    */
	out_L(Ga);                             /*  输出邻接链表Ga */
	printf("\n "); scanf("%d", &v1);
	dfsL(Ga, v1);     /* 从顶点v1开始，对图Ga进行深度优先遍历 */
	for (i = 0; i<MAX; i++) vis[i] = 0;     /*  顶点访问的标志数组   */
	printf("\n广度优先遍历。");
	bfsL(Ga, v1);
	printf("\n\n   打回车键，继续。"); ch=getch();

	return 0;
}/* main */
 /* 建立邻接链表  */
void creat_L(Lgraph G)
{
	Vnode *p, *q;  int i, j, k;
	printf("输入 n,e=?"); scanf("%d,%d", &n, &e);
	for (i = 1; i <= n; i++) { G[i].data = i; G[i].next = NULL; }
	for (k = 1; k <= e; k++)
	{
		printf("输入 vi,vj=?"); scanf("%d,%d", &i, &j);
		p = (Vnode *)malloc(sizeof(Vnode));
		p->data = i;
		p->next = G[j].next; G[j].next = p;   /* p结点链接到第j条链 */
		q = (Vnode *)malloc(sizeof(Vnode));
		q->data = j;
		q->next = G[i].next; G[i].next = q;  /* q结点链接到第i条链  */
	}
}/*  creat_L */
 /*  邻接链表的简单输出，为了检查输入是否正确  */
void out_L(Lgraph G)
{
	int i; Vnode *p; char ch;
	for (i = 1; i <= n; i++)
	{
		printf("\n i=%d", i);
		p = G[i].next;
		while (p != NULL) { printf("%5d", p->data); p = p->next; }
	}
	printf("\n\n   打回车键，继续。"); ch=getch();
} /* out_L */
  /* 深度优先遍历图 */
void dfsL(Lgraph G, int v)
{
	Vnode *p;
	printf("%3d", G[v].data);  vis[v] = 1; /*  顶点v被访问，标志置1 */
	p = G[v].next;
	while (p)
	{
		v = p->data;
		if (vis[v] == 0)dfsL(G, v);  /* 顶点v未被访问时继续遍历 */
		p = p->next;
	}
}/* dfs  */
 /* 广度优先遍历图  */
void bfsL(Lgraph g, int v)
{
	char ch;
	LinkQueue Q;
	InitQueue(&Q);
	printf("\n %d", g[v].data); vis[v] = 1;  EnQueue(&Q, v);
	while (!QueueEmpty(&Q))
	{
		QElemType X;
		DeQueue(&Q,&X);
		Vnode *p = g[X].next;
		while (p!=NULL)
		{
			v = p->data;
			if (vis[v] == 0)
			{
				printf("\n %d", g[v].data);
				vis[v] = 1;  EnQueue(&Q, v);
			}
			p = p->next;
		}
	}
	printf("\n\n   打回车键，继续。"); ch=getch();
} /* bfsL  */