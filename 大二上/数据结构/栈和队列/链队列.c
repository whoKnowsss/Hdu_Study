#include<stdio.h>
#include<stdlib.h>
#include<malloc.h>
typedef int QElemenType;

typedef struct QNode
{
	QElemenType data;
	struct QNode *next;
 } QNode;
 
 typedef struct 
 {
 	QNode *front;  //队头指针 
 	QNode *rear;   //队尾指针 
 }LinkQueue;
 
 int InitQueue(LinkQueue q)
 {  //构造一个空的队列Q 
 	q.front=(QNode*)malloc(sizeof(QNode));
 	if(!q.front) 
 	{
 		printf("overflow");
 		return 0;
	  } 
	 q.rear=q.front;
	 q.front->next=NULL;
	 return 1; 
 }
 
 int DestroyQueue (LinkQueue *q)
 {   //销毁队列Q 
 	while(q->front)
 	{
 		q->rear=q->front->next;
 		free(q->front);
 		q->front=q->rear;
	 }
	 return 1;
 }
 
 int EnQueue(LinkQueue *q,QElemenType e)
 {    //插入元素e为Q的新的队尾元素 
 	QNode *p;
 	p=(QNode*)malloc(sizeof(QNode));   //存储分配失败 
 	if(!p) return 0;
 	p->data=e;
 	p->next=NULL;
 	q->rear->next=p;
 	q->rear=p;
 	return 1;
 }
 
 int DeQueue(LinkQueue *q,QElemenType *e)
 {      //若队列不空，则删除Q的对头元素，用e返回其值，并返回1 
 	QNode *p;
 	if(q->front==q->rear) return 0;
 	p=q->front->next;
 	*e=p->data;
 	q->front->next=p->next;
 	if(q->rear==p) q->rear=q->front;
 	free(p);
 	return 1;
 }

