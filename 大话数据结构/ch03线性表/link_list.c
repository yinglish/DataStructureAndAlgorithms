#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status;/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;/* ElemType类型根据实际情况而定，这里假设为int */

typedef struct Node 
{
    ElemType data;
    struct Node *next;
} Node;

typedef struct Node *LinkList;

Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/* 初始化顺序线性表 */
Status InitList(LinkList *L) 
{ 
    *L=(LinkList)malloc(sizeof(Node)); /* 产生头结点,并使L指向此头结点 */
    if(!(*L)) /* 存储分配失败 */
            return ERROR;
    (*L)->next=NULL; /* 指针域为空 */

    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(LinkList L)
{ 
    if(L->next)
            return FALSE;
    else
            return TRUE;
}

/* 初始条件：顺序线性表L已存在。操作结果：返回L中数据元素个数 */
int ListLength(LinkList L)
{
    int i=0;
    LinkList p=L->next; /* p指向第一个结点 */
    while(p)                        
    {
        i++;
        p=p->next;
    }
    return i;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(LinkList L,ElemType e)
{
    int i=0;
    LinkList p=L->next;
    while(p)
    {
        i++;
        if(p->data==e) /* 找到这样的数据元素 */
                return i;
        p=p->next;
    }

    return 0;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(LinkList L)
{
    LinkList p=L->next;
    while(p)
    {
        visit(p->data);
        p=p->next;
    }
    printf("\n");
    return OK;
}


Status GetElem(LinkList L, int i, ElemType *e)
{
    LinkList p;
    int j;
    if (i < 1)
        return ERROR;
    // p points to the first node
    // assume there is head node
    p = L->next;
    for (j = 1; j < i; ++j)
    {
        if (p == NULL)
            return ERROR;
        p = p->next;
    }

    *e = p->data;
    return OK;
}

Status ListInsert(LinkList *L, int i, ElemType e)
{
    if (i < 1)
        return ERROR;
    LinkList p, n;
    int j;
    p = *L; // p指向头节点
    j = 1;
    while (p && j < i)
    {
        p = p->next;
        j++;
    }
    if (!p)
        return ERROR;
    
    n = (Node *)malloc(sizeof(Node));
    n->data = e;
    n->next = p->next;
    p->next = n;

    return OK;
}


// 觉得不需要传指针（与书中不同），因为链表头指针指向头节点并不会变
Status ListDelete(LinkList L, int i, ElemType *e)
{
    int j;
    LinkList p, q;
    p = L;
    j = 1;
    while (p->next && j < i)
    {
        p = p->next;
        j++;
    }

    if (!p->next) // 第i个元素不存在
    {
        return ERROR;
    }

    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);

    return OK;
}

void CreateListHead(LinkList *L, int n) // L必须为指针，要创建头节点
{
    LinkList p;
    int i;
    srand(time(NULL));

    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;

    for (i = 0; i < n; ++i)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        p->next = (*L)->next;
        (*L)->next = p;
    }
}

void CreateListTail(LinkList *L, int n)
{
    LinkList p, cur;
    int i;
    // head node
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL;
    cur = *L;

    for (i = 0; i < n; ++i)
    {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;
        cur->next = p;
        p->next = NULL;
        cur = cur->next;
    }

}

Status ClearList(LinkList *L)
{
    LinkList p, q;
    p = (*L)->next;
    while (p)
    {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL; // 头节点指针置空

    return OK;
}

int main()
{        
    LinkList L;
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：ListLength(L)=%d\n",ListLength(L));
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：ListLength(L)=%d\n",ListLength(L));
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L); 

    printf("ListLength(L)=%d \n",ListLength(L));

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L); 
    printf("ListLength(L)=%d \n",ListLength(L));

    GetElem(L,5,&e);
    printf("第5个元素的值为：%d\n",e);
    for(j=3;j<=4;j++)
    {
            k=LocateElem(L,j);
            if(k)
                    printf("第%d个元素的值为%d\n",k,j);
            else
                    printf("没有值为%d的元素\n",j);
    }
    

    k=ListLength(L); /* k为表长 */
    for(j=k+1;j>=k;j--)
    {
            i=ListDelete(L,j,&e); /* 删除第j个数据 */
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L); 

    j=5;
    ListDelete(L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L); 

    i=ClearList(&L);
    printf("\n清空L后：ListLength(L)=%d\n",ListLength(L));
    CreateListHead(&L,20);
    printf("整体创建L的元素(头插法)：");
    ListTraverse(L); 
    
    i=ClearList(&L);
    printf("\n删除L后：ListLength(L)=%d\n",ListLength(L));
    CreateListTail(&L,20);
    printf("整体创建L的元素(尾插法)：");
    ListTraverse(L); 


    return 0;
}








