#include <stdio.h>
#include <stdlib.h>
#define SElemType int
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10
//书上p46 
//http://blog.csdn.net/sszgg2006/article/details/7555974 

/************************栈的顺序存储表示**************************/

/********************** 结构体定义部分 **********************/
typedef struct
{
    SElemType *base;
    SElemType *top;
    int stacksize;
}SqStack;
/************************ 函数块部分 ************************/

/**********************构造一个空的栈 **********************/
int InitStack(SqStack *S)
{
    S->base=(SElemType *)malloc(STACK_INIT_SIZE*sizeof(SElemType));
    if (!S->base)
       exit(0);
    S->top=S->base;
    S->stacksize=STACK_INIT_SIZE;
    return 1;
}
/**********************销毁栈************************/
void DestroyStack(SqStack *S)
{
    free(S->base);
    S->base=NULL;
    S->top=NULL;
    S->stacksize=0;
}
/**********************清除栈************************/
int ClearStack(SqStack *S)
{
	S->top=S->base;
	S->stacksize=0;
	return 1;	
} 
/**********************栈是否为空************************/
int StackEmpty(SqStack S)
{
	if (S.top==S.base) 
	return 1;	          //空
	else return 0;       
} 
/**************用e返回栈顶元素**************/
int GetTop(SqStack S,SElemType *e)
{
    if (S.top==NULL)
      return 0;
    *e=*(S.top-1);
    return 1;
}
/**************得到栈的长度**************/
int StackLength(SqStack S)
{
    if (S.top==S.base)
      return 0;
   else
    return (S.top-S.base);
}
/************输入元素e为新的栈顶元素************/
int Push(SqStack *S,SElemType e)
{
    if(S->top-S->base >=S->stacksize)   //栈满，追加存储空间 
  {
    S->base=(SElemType *)realloc(S->base,(S->stacksize + STACKINCREMENT) * sizeof(SElemType));
    if(!S->base)
      exit(0);    //存储分配失败 
     
    S->top = S->base + S->stacksize;
    S->stacksize +=STACKINCREMENT;
  }
  *(S->top)++=e;
  return 1;
}
/********************** 若S不空，删除栈顶元素，用e返回其值 **********************/
int Pop(SqStack *S,SElemType *e)
{
    if(S->top == S->base)
    return 0;
  *e = *--S->top;
  return 1;
}
/********************** 显示栈内的元素  **********************/
void DisplayStack(SqStack S)
{
     if(StackEmpty(S)==1)
     exit(-1);
     while(S.top!=S.base)
     printf("%d ",*(--S.top));
}
/********** 从栈底到栈顶依次对*****************************
 ***********栈中每个元素调用函数visit（）*****************/
int StackTraverse(SqStack S,int(*visit)(SElemType))
{
   SElemType *p;
   p=S.base;
   int i,result;
   for(i=1;i<=S.top-S.base;i++)
   {
   	 result=visit(*p++);   //visit的1是有共性，0没共性  
		if (result==0)
	     return 0; 
   }
   return 1;    //l里的所有元素经过visit有共性 
}
/*************************主函数*********************/ 
int main()
{
	SqStack q1;
	InitStack(&q1);
	int a,b,c;
	while(~scanf("%d",&a))
	{
		Push(&q1,a);
	}
	printf("\n");
	printf("my stack is:");
	while(!StackEmpty(q1))
	{
		GetTop(q1,&b);
		printf("%d ",b);
		Pop(&q1,&c);	
	}
	DestroyStack(&q1);
}








