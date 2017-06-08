# include <stdio.h>
# include <stdlib.h>
#include <conio.h>
typedef int Etype;
#define NULL 0
typedef struct BiTNode  /* 树结点结构 */
{
	Etype data;
	struct BiTNode *lch, *rch;
	struct BiTNode *parent;
	int level;
}BiTNode;
typedef BiTNode* QElemType;
//节点
typedef struct Queue {
	QElemType data;
	struct Queue *next;
}QNode, *QueuePtr;
//队列(头尾指针)
typedef struct {
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;
enum Status
{
	OK, ERROR, OVERFLOW
};
enum BOOL {
	FALSE, TRUE
};
//构造空队列 OK
Status InitQueue(LinkQueue *Q) {
	Q->front = Q->rear = (QueuePtr)malloc(sizeof(QNode));
	if (!Q->front)exit(OVERFLOW);//内存已满
	Q->front->next = NULL;
	return OK;
}
//销毁队列Q OK
Status DestoryQueue(LinkQueue *Q) {
	while (Q->front)//最后的next指针指向为NULL
	{
		Q->rear = Q->front->next;
		free(Q->front);
		Q->front = Q->rear;
	}
	return OK;
}
//入队 OK
Status EnQueue(LinkQueue *Q, QElemType e) {
	QueuePtr p = (QueuePtr)malloc(sizeof(QNode));
	if (!p)exit(OVERFLOW);
	p->data = e;
	p->next = NULL;
	Q->rear->next = p;//在队尾添加节点
	Q->rear = p;
}
//出队 OK
Status DeQueue(LinkQueue *Q, QElemType *e) {
	if (Q->front == Q->rear)return ERROR;//若为空，不删除
	QueuePtr p = Q->front->next;
	*e = p->data;
	Q->front->next = p->next;
	if (Q->rear == p)Q->rear = Q->front;
	free(p);
	return OK;
}
//清空为空队列 OK
Status ClearQueue(LinkQueue *Q) {
	if (DestoryQueue(Q) == ERROR)return ERROR;
	if (InitQueue(Q) == ERROR)return ERROR;
	return OK;
}
//判断队列是否为空 OK
BOOL QueueEmpty(LinkQueue *Q) {
	if (Q->front == Q->rear&&Q->front != NULL)return TRUE;
	else return FALSE;
}
//获取队列头元素 OK
Status GetHead(LinkQueue *Q, QElemType *e) {
	if (QueueEmpty(Q) == FALSE) {
		*e = Q->front->next->data;
		return OK;
	}
	else
	{
		return ERROR;
	}
}
//队列长度 OK
int QueueLength(LinkQueue *Q) {
	QueuePtr p = Q->front;
	int result = 0;
	while (p != NULL&&p->next != NULL)
	{
		result++;
		p = p->next;
	}
	return result;
}

/* 函数原形声明 */
BiTNode *creat_bt1();
BiTNode *creat_bt2(BiTNode *parent);
void inorder(BiTNode *p);
void preorder(BiTNode *p);
void postorder(BiTNode *p);
void numb(BiTNode *p);
void levelorder(BiTNode *p);
BiTNode *t; int n, n0, n1, n2;
int Maxlevel = 0;
/*  主函数 */
int main()
{
	char ch; int k;
	do {
		printf("\n\n\n");
		printf("\n\n     1. 建立二叉树方法1 ");
		printf("\n\n     2. 建立二叉树方法2");
		printf("\n\n     3. 中序递归遍历二叉树");
		printf("\n\n     4. 先序递归遍历二叉树");
		printf("\n\n     5. 后序递归遍历二叉树");
		printf("\n\n     6. 层级递归遍历二叉树");
		printf("\n\n     7. 计算树中结点个数");
		printf("\n\n     8. 结束程序运行");
		printf("\n======================================");
		printf("\n     请输入您的选择 (1,2,3,4,5,6)");  scanf("%d", &k);
		switch (k)
		{
		case 1:t = creat_bt1(); break; /*  调用性质5建立二叉树算法 */
		case 2:t = creat_bt2(NULL); 
			break; /*  调用递归建立二叉树算法   */
		case 3: { inorder(t);                /*  调用中序遍历     */
			printf("\n\n    打回车键，继续。"); 
			ch=getch();
		} break;
		case 4: { preorder(t);                /*  调用先序遍历     */
			printf("\n\n    打回车键，继续。");
			ch = getch();
		} break;
		case 5: { postorder(t);                /*  调用后序遍历     */
			printf("\n\n    打回车键，继续。");
			ch = getch();
		} break; 
		case 6: { 
			
			levelorder(t);                /*  调用后序遍历     */
		printf("\n\n    打回车键，继续。");
		ch = getch();
		} break;
		case 7: { n = 0; n0 = 0; n1 = 0; n2 = 0;  /* 全局变量置0 */
			numb(t);
			printf("\n     二叉树结点总数 n = %d", n);
			printf("\n     二叉树叶子结点数 n0 = %d", n0);
			printf("\n     度为1的结点数 n1 = %d", n1);
			printf("\n     度为2的结点数 n2 = %d", n2);
			printf("\n\n   打回车键，继续。"); 
			ch=getch();
		} break;
		case 8: exit(0);
		} /*  switch  */
		printf("\n ----------------");
	} while (k >= 1 && k<8);
	printf("\n               再见！");
	printf("\n      打回车键，返回。"); ch = getch();
	return 0;
} /* main */
  /* 利用二叉树性质5 ，借助一维数组V 建立二叉树 */
BiTNode *creat_bt1()
{
	int i = 0;
	BiTNode *t, *p, *v[20]; int I, j; Etype e;
	/* 输入结点的序号i 、结点的数据e  */
	printf("\n i,data=?"); scanf("%d,%d", &i, &e);
	while (i != 0 && e != 0)              /* 当 i ,e都为0时，结束循环  */
	{
		p = (BiTNode *)malloc(sizeof(BiTNode));
		p->data = e; p->lch = NULL; p->rch = NULL; p->parent = NULL;
		v[i] = p;
		if (i == 1) {
			p->level = 1;
			t = p;
		}                      /* 序号为1的结点是根 */
		else {
			j = i / 2;
			if (i % 2 == 0) {
				v[j]->lch = p; /* 序号为偶数，做左孩子*/	
			}
			else {
				v[j]->rch = p;  /* 序号为奇数，做右孩子*/
			}
			p->level = j + 1;
			p->parent = v[j];
		}
		printf("\n i,data=?"); scanf("%d,%d", &i, &e);
	}
	return(t);
} /* creat_bt1 */
  /* 模仿先序递归遍历方法，建立二叉树 */
BiTNode * creat_bt2(BiTNode *parent)
{
	int e=0;
	BiTNode *t;
	printf("\n data="); scanf("%d", &e);
	if (e == 0) t = NULL;                  /* 对于0值，不分配新结点 */
	else {
		t = (BiTNode *)malloc(sizeof(BiTNode));
		t->data = e;
		if (parent == NULL)t->level = 1;
		else {
			t->level = parent->level + 1;
		}
		t->parent = parent;
		t->lch = creat_bt2(t);  /* 左孩子获得新指针值  */
		t->rch = creat_bt2(t);  /* 右孩子获得新指针值  */
	}
	return(t);
} 
void inorder(BiTNode *p)
{
	if (p) {
		inorder(p->lch);
		printf("%d ", p->data);
		inorder(p->rch);
	}
	return;
} /* inorder  */
  
  /* 先序递归遍历二叉树方法 */
void preorder(BiTNode *p)
{
	if (p) {
		printf("%d ", p->data);
		preorder(p->lch);
		preorder(p->rch);
	}
	return;
}
//后序
void postorder(BiTNode *p)
{
	if (p) {
		postorder(p->lch);
		postorder(p->rch);
		printf("%d ", p->data);
	}
	return;
}
//计数
/* 利用中序递归遍历二叉树的方法，计算树中结点个数 */
void numb(BiTNode *p)
{
	if (p) {
		numb(p->lch);
		{ printf("%d ", p->data);
		n++;
		if (p->lch == NULL && p->rch == NULL) n0++;
		if ((p->lch == NULL && p->rch != NULL) ||(p->lch != NULL && p->rch == NULL)) n1++;
		if (p->lch != NULL && p->rch != NULL) n2++;
		} /*  把访问的功能扩大了 使用n0：统计没有子树，n1：仅有左子树or仅有右子树，n2：有左右子数的情况。*/
		numb(p->rch);
	}
} /* numb  */
void Traverse(BiTNode *p, int level) {
	if (p) {
		if(p->level==level)printf("%d ", p->data);
		else
		{
			Traverse(p->lch,level);
			Traverse(p->rch,level);
		}
	}
	return;
}
void levelAll(BiTNode *p) {
	if (p) {
		if (p->level > Maxlevel)Maxlevel = p->level;
		levelAll(p->lch);
		levelAll(p->rch);
	}
	return;
}
//层级
void levelorder(BiTNode *p) {
	LinkQueue Q1;
	BiTNode *temp=NULL;
	InitQueue(&Q1);
	EnQueue(&Q1, p);
	while (QueueEmpty(&Q1) == FALSE)
	{
		DeQueue(&Q1, &temp);
		printf("%d ",temp->data);
		if (temp->lch != NULL)
		{
			EnQueue(&Q1, temp->lch);
		}
		if (temp->rch != NULL)
		{
			EnQueue(&Q1, temp->rch);
		}
	}
	printf("\n");
}
