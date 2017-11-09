#include <stdio.h>
#include <stdlib.h>

/* 静态链表就是用数组来实现链表 */

#define MAXSIZE 1000

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

typedef int Status;

typedef char ElemType;
typedef struct 
{
    ElemType data;
    int cur;
} Component, StaticLinkList[MAXSIZE];

int ListLength(StaticLinkList L)
{
    int j = 0;
    int i = L[MAXSIZE - 1].cur;
    while (i)
    {
        j++;
        i = L[i].cur;
    }

    return j;
}

Status InitList(StaticLinkList space)
{
    int i;
    for (i = 0; i < MAXSIZE - 1; i++)
    {
        space[i].cur = i + 1;
    }
    space[MAXSIZE - 1].cur = 0;

    return OK;
}

/* 若备用链表非空，则返回分配的节点下标，否则返回0 */
int Malloc_SLL(StaticLinkList space)
{
    int i = space[0].cur;
    if (i)
    {
        space[0].cur = space[i].cur;
    }

    return i;
}

Status ListInsert(StaticLinkList L, int i, ElemType e)
{
    int j, k, l;
    k = MAXSIZE - 1;
    if (i < 1 || i > (ListLength(L) + 1))
    {
        return ERROR;
    }
    j = Malloc_SLL(L);
    if (j)
    {
        L[j].data = e;
        for (l = 1; l <= i - 1; ++l)
        {
            k = L[k].cur;
        }
        L[j].cur = L[k].cur;
        L[k].cur = j;

        return OK;
    }

    return ERROR;
}

void Free_SSL(StaticLinkList L, int j)
{
    L[j].cur = L[0].cur;
    L[0].cur = j;
}

Status ListDelete(StaticLinkList L, int i)
{
    int j, k;
    k = MAXSIZE - 1; // 注意为什么要赋为这个值
    if (i < 1 || i > ListLength(L))
    {
        return ERROR;
    }
    
    for (j = 1; j < i; ++j)
    {
        k = L[k].cur;
    }

    j = L[k].cur;

    L[k].cur = L[L[k].cur].cur;

    // 回收第i个节点所占空间
    Free_SSL(L, j);

    return OK;
}

Status visit(ElemType c)
{
    printf("%c ",c);
    return OK;
}

Status ListTraverse(StaticLinkList L)
{
    int j=0;
    int i=L[MAXSIZE-1].cur;
    while(i)
    {
            visit(L[i].data);
            i=L[i].cur;
            j++;
    }
    return j;
    printf("\n");
    return OK;
}


int main()
{
    StaticLinkList L;
    Status i;
    i=InitList(L);
    printf("初始化L后：L.length=%d\n",ListLength(L));

    i=ListInsert(L,1,'F');
    i=ListInsert(L,1,'E');
    i=ListInsert(L,1,'D');
    i=ListInsert(L,1,'B');
    i=ListInsert(L,1,'A');

    printf("\n在L的表头依次插入FEDBA后：\nL.data=");
    ListTraverse(L); 

    i=ListInsert(L,3,'C');
    printf("\n在L的“B”与“D”之间插入“C”后：\nL.data=");
    ListTraverse(L); 

    i=ListDelete(L,1);
    printf("\n在L的删除“A”后：\nL.data=");
    ListTraverse(L); 

    printf("\n");

    return 0;
}
