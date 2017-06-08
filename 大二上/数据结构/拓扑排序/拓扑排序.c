#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
# define MAX 20
typedef int VexType;
enum Status
{
	OK, ERROR, OVERFLOW
};
typedef  struct Vnode
{
	VexType data;
	struct Vnode *next;
}Vnode;                           /* Vnode是顶点的结点结构 */
typedef Vnode Lgraph[MAX];      /* Lgraph是一维数组类型标识符 */
int n, e, vis[MAX];
/* 函数原形声明 */
#define STACK_INIT_SIZE 100 
#define STACKINCREMENT 10 
typedef int SElemType;
typedef struct {
	SElemType *base; 
	SElemType *top; 
	int stacksize; 
}Sqstack;
enum BOOL {
	FALSE, TRUE
};
Status InitStack(Sqstack *s) {
	s->base = (SElemType *)malloc(STACK_INIT_SIZE * sizeof(SElemType));
	if (!s->base)exit(OVERFLOW);
	s->top = s->base;
	s->stacksize = STACK_INIT_SIZE;
	return OK;
}

Status DestoryStack(Sqstack *s) {
	if (s == NULL)return ERROR;
	free(s->base);
	s->base = NULL;
	s->top = NULL;
	s->stacksize = 0;
	return OK;
}

Status ClearStatus(Sqstack *s) {
	Status a = DestoryStack(s);
	if (a == ERROR)return ERROR;
	a = InitStack(s);
	return a;
}

int StackLength(Sqstack *s) {
	return (s->top - s->base);
}

Status GetTop(Sqstack *s, SElemType *e) {
	if (s->top == s->base)return ERROR;
	*e = *(s->top - 1);
	return OK;
}

Status Push(Sqstack *s, SElemType e) {
	if (s->top - s->base >= s->stacksize) {
		s->base = (SElemType *)realloc(s->base, (s->stacksize + STACKINCREMENT) * sizeof(SElemType));
		if (!s->base)exit(OVERFLOW);
		s->top = s->base + s->stacksize;
		s->stacksize += STACKINCREMENT;
	}
	*(s->top)++ = e;
	return OK;
}

Status Pop(Sqstack *s, SElemType *e) {
	if (s->top == s->base)return ERROR;
	*e = *--s->top;
	return OK;
}

BOOL StackEmpty(Sqstack *s) {
	if (s->top == s->base)return TRUE;
	else
	{
		return FALSE;
	}
}
/* 建立邻接链表  */
void creat_L(Lgraph G)
{
	Vnode *p, *q;  int i, j, k;
	printf("输入 n,e=?"); scanf("%d,%d", &n, &e);
	for (i = 1; i <= n; i++) { G[i].data = 0; G[i].next = NULL; }
	for (k = 1; k <= e; k++)
	{
		printf("输入 vi,vj=?"); scanf("%d,%d", &i, &j);

		q = (Vnode *)malloc(sizeof(Vnode));
		q->data = j;
		q->next = G[i].next; G[i].next = q;  /* q结点链接到第i条链  */
		G[j].data++;
	}
}/*  creat_L */
 /*  邻接链表的简单输出，为了检查输入是否正确  */
void out_L(Lgraph G)
{
	int i; Vnode *p; char ch;
	for (i = 1; i <= n; i++)
	{
		printf("\n i=%d 入度为%d", i,G[i].data);
		p = G[i].next;
		while (p != NULL) { printf("%5d", p->data); p = p->next; }
	}
	printf("\n\n   打回车键，继续。"); ch = getch();
} 
Sqstack s;

//拓扑排序
Status ToplogicalSort(Lgraph G) {
	InitStack(&s);
	for (int i = 0; i < n; i++) {
		if (G[i].data == 0)Push(&s, i);
	}
	int count= 0;
	SElemType temp;
	while (!StackEmpty(&s))
	{
		Pop(&s, &temp); printf(" %d", temp);
		++count;
		Vnode *p= G[temp].next;
		while (p!=NULL)
		{
			if (--G[p->data].data == 0)Push(&s, p->data);
			p = p->next;
		}
	}
	if (count < n)return ERROR;
	else return OK;
}

int main() {
	Lgraph Ga;	                  /*  Ga是邻接链表的表头数组名  */
	int v1, i;
	char ch;
	for (i = 0; i<MAX; i++) vis[i] = 0;     /*  顶点访问的标志数组   */
	creat_L(Ga);                     /*   建立图邻接链表Ga    */
	out_L(Ga);                             /*  输出邻接链表Ga */
	printf("\n拓扑排序输出为：");
	Status res = ToplogicalSort(Ga);
	printf("\n");
	if (res == OK)printf("拓扑排序成功,该图不带环");
	else
	{
		printf("拓扑排序失败,该图带环");
	}
	return 0;
}