#include <stdio.h>
#include <stdlib.h>
typedef struct Node{
    int element;
    struct Node *next;
}Node;

/*新建一个单链表*/
Node * creatList(Node *pHead)
{
    Node *p1,*p2;
    p1=p2=(Node *)malloc(sizeof(Node));                 //申请新节点
    if(p1 == NULL || p2 ==NULL)
    {
        printf("内存分配失败\n");
        exit(0);
    }
    printf("请输入一个或一组大于0的整数:");
    scanf("%d",&p1->element);                           //输入新节点
    pHead = NULL;                                    //头节点的指针置为空
    while(p1->element !=0)                              //输入的值b不等于?则继续，直到输入的值为?
    {
        if(pHead == NULL)                              //空表，接入表头
        {
            pHead = p1;
        }
        else
        {
            p2->next = p1;                             //非空表，接入表尾
        }
        p2 = p1;
        p1=(Node *)malloc(sizeof(Node));    //再重申请一个节点
        if(p1 == NULL || p2 ==NULL)
        {
        printf("内存分配失败\n");
        exit(0);
        }
        scanf("%d",&p1->element);
        p2->next = NULL;
    }
    printf("creatList函数执行，链表创建成功\n");
    return pHead;                          //返回链表的头指针
}

/*输出链表中的数据*/
void printList(Node *pHead)
{
    if(pHead == NULL)   //链表为空
    {
        printf("PrintList函数执行，链表为空\n请输入大于0的链表数据：\n");
    }
    else
    {
        printf("链表数据如下：");
        while(pHead != NULL)
        {
            printf("%d ",pHead->element);
            pHead = pHead->next;
        }
        printf("\n");
    }
}

/*删除链表数据*/
void clearList(Node *pHead)
{
    Node *pNext;            //定义一个与pHead相邻节点

    if(pHead == NULL)
    {
        printf("clearList函数执行，链表为空\n");
        return;
    }
    while(pHead->next != NULL)
    {
        pNext = pHead->next;//保存下一结点的指针
        free(pHead);
        pHead = pNext;      //表头下移
    }
    printf("clearList函数执行，链表已经清除\n");
}

/*返回单链表中的元素个数 */
int sizeList(Node *pHead)
{
    int size = 0;
    while(pHead != NULL)
    {
        size++;                     //遍历链表size大小比链表的实际长度小1
        pHead = pHead->next;
    }
    printf("sizeList函数执行,链表长度为 %d \n",size);
    return size;    //链表的实际长度
}

/*返回单链表中第pos个结点中的元素，若pos超出范围，则停止程序运行*/
int getElement(Node *pHead, int pos)
{
    int i=0;
    if(pos < 1)
    {
        printf("getElement函数执行,pos值非法\n");
        return 0;
    }
    if(pHead == NULL)
    {
        printf("getElement函数执行,链表为空\n");
        return 0;
    }
    while(pHead !=NULL)
    {
        ++i;
        if(i == pos)
        {
            break;
        }
        pHead = pHead->next; //移到下一结点
    }
    if(i < pos)                  //链表长度不足则退出
    {
        printf("getElement函数执行，pos值超出链表长度\n");
        return 0;
    }
    return pHead->element;
}

/*把单链表中第pos个结点的值修改为x的值,若修改成功返回１,否则返回０*/
int modifyElem(Node *pNode,int pos,int x)
{
    Node *pHead;
    pHead = pNode;
    int i = 0;

    if(NULL == pHead)
    {
        printf("modifyElem函数执行，链表为空\n");
    }
    if(pos < 1)
    {
        printf("modifyElem函数执行，pos值非法\n");
        return 0;
    }
    while(pHead !=NULL)
    {
        ++i;
        if(i == pos)
        {
            break;
        }
        pHead = pHead->next; //移到下一结点
    }
    if(i < pos)                  //链表长度不足则退出
    {
        printf("modifyElem函数执行，pos值超出链表长度\n");
        return 0;
    }
    pNode = pHead;
    pNode->element = x;
    printf("modifyElem函数执行\n");

    return 1;
}
/*删除链表中的某个结点*/
Node *deleteElem(Node *pNode,int pos)
{
    Node *pHead;
  //  pHead = pNode;
    int i = 0;
    if(NULL == pNode)
    {
        printf("deleteElem函数执行，链表为空\n");
    }
    if(pos < 1)
    {
        printf("delete函数执行，pos值非法\n");
        return 0;
    }
    while(pNode !=NULL)
    {
        ++i;
        if(i == pos)
        {
            break;
        }
        pNode = pNode->next; //移到下一结点
    }
    if(i < pos)                  //链表长度不足则退出
    {
        printf("deleteElem函数执行，pos值超出链表长度\n");
        return 0;
    }
    pHead = pNode->next;
    free(pNode);
    printf("deleteElem函数执行\n");

    return pHead;
}
/*归并两个链表*/
void MergeList(Node *a,Node *b, Node *c){
    //已知单链表a和b的元素按值非递减排列
    //归并单链表a和b得到新的单链表c,c的元素也按非递减排列
    Node *pa=a->next,*pb=b->next;
    Node *pc=a;
    c=pc=a;  //用a的头节点作为c的头结点
    while(pa&&pb){
        if(pa->element<=pb->element){
            pc->next=pa;
            pc=pa;
            pa=pa->next;
        }
        else{
            pc->next=pb;
            pc=pb;
            pb=pb->next;
        }
    }
    pc->next=pa?pa:pb;    //插入剩余段
    free(b);       //释放b的头结点
}
int main()
{
    Node *pt=NULL,*pb=NULL,*pc=NULL;
    pt=creatList(pt);
    pb=creatList(pb);
    MergeList(pt,pb,pc);
    printList(pc);
    sizeList(pt);
    printf("需要返回第几个结点的数字：");
    int n,i;
    scanf("%d",&n);
    i=getElement(pt,n);
    printf("%d\n",i);
    printf("你需要将第几个结点改为什么:");
    int p,q;
    scanf("%d%d",&p,&q);
    modifyElem(pt,p,q);
    printList(pt);
    printf("你需要将第几个结点删除:");
    int m;
    scanf("%d",&m);
    pt=deleteElem(pt,m);
    printList(pt);
    clearList(pt);
    return 0;
}
