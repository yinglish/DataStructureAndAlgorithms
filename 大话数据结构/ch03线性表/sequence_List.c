#include <stdio.h>
#include <stdlib.h>

#define MAXSIZE 20
typedef int ElemType;
typedef struct 
{
    ElemType data[MAXSIZE];
    int length;
} SqList;

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
typedef int Status;


Status visit(ElemType c)
{
    printf("%d ",c);
    return OK;
}

/* 初始化顺序线性表 */
Status InitList(SqList *L) 
{ 
    L->length=0;
    return OK;
}

/* 初始条件：顺序线性表L已存在。操作结果：若L为空表，则返回TRUE，否则返回FALSE */
Status ListEmpty(SqList L)
{ 
	if(L.length==0)
		return TRUE;
	else
		return FALSE;
}

/* 初始条件：顺序线性表L已存在。操作结果：将L重置为空表 */
Status ClearList(SqList *L)
{ 
    L->length=0;
    return OK;
}

int ListLength(SqList L)
{
    return L.length;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：返回L中第1个与e满足关系的数据元素的位序。 */
/* 若这样的数据元素不存在，则返回值为0 */
int LocateElem(SqList L,ElemType e)
{
    int k;
    for (k = 0; k < L.length; ++k)
    {
        if (L.data[k] == e)
            return k + 1;
    }

    return 0;
}

Status GetElem(SqList L, int i, ElemType *e)
{
    if (L.length == 0 || i < 1 || i > L.length)
    {
        return ERROR;
    }
    *e = L.data[i - 1];
    return OK;
}

Status ListInsert(SqList *L, int i, ElemType e)
{
    int k;
    if (L->length == MAXSIZE)
        return ERROR;
    if (i < 1 || i > L->length + 1)
        return ERROR;
    if (i <= L->length) // 不在表尾插入
    {
        for (k = L->length - 1; k >= i - 1; --k)
            L->data[k + 1] = L->data[k];
    }

    L->data[i - 1] = e;
    L->length++;

    return OK;
}

// 删除元素的值返回
Status ListDelete(SqList *L, int i, ElemType *e)
{
    int k;
    if (L->length == 0) // 为什么要有这一步？如果线性表为空，无返回元素，应该返回错误
        return ERROR;
    if (i < 1 || i > L->length)
        return  ERROR;
    *e = L->data[i - 1];
    for (k = i; k < L->length; ++k)
        L->data[k - 1] = L->data[k];
    L->length--;
    return OK;
}

/* 初始条件：顺序线性表L已存在 */
/* 操作结果：依次对L的每个数据元素输出 */
Status ListTraverse(SqList L)
{
    int i;
    if (L.length == 0)
    {
        printf("表为空\n");
        return ERROR;
    }
    for (i = 0; i < L.length; ++i)
    {
        printf("%d, ", L.data[i]);
    }
    printf("\n");
    return OK;
}

void unionL(SqList *La,SqList Lb)
{
    ElemType e;
    int i, j;
    int la_len, lb_len;
    la_len = ListLength(*La);
    lb_len = ListLength(Lb);
    for (i = 1, j = la_len; i <= lb_len; ++i)
    {
        GetElem(Lb, i, &e);
        if (!LocateElem(*La, e))
        {
            ListInsert(La, ++j, e);
        }
    }
}

int main()
{
        
    SqList L;
	SqList Lb;
    
    ElemType e;
    Status i;
    int j,k;
    i=InitList(&L);
    printf("初始化L后：L.length=%d\n",L.length);
    for(j=1;j<=5;j++)
            i=ListInsert(&L,1,j);
    printf("在L的表头依次插入1～5后：L.data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    i=ClearList(&L);
    printf("清空L后：L.length=%d\n",L.length);
    i=ListEmpty(L);
    printf("L是否空：i=%d(1:是 0:否)\n",i);

    for(j=1;j<=10;j++)
            ListInsert(&L,j,j);
    printf("在L的表尾依次插入1～10后：L.data=");
    ListTraverse(L); 

    printf("L.length=%d \n",L.length);

    ListInsert(&L,1,0);
    printf("在L的表头插入0后：L.data=");
    ListTraverse(L); 
    printf("L.length=%d \n",L.length);

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
            i=ListDelete(&L,j,&e); /* 删除第j个数据 */
            if(i==ERROR)
                    printf("删除第%d个数据失败\n",j);
            else
                    printf("删除第%d个的元素值为：%d\n",j,e);
    }
    printf("依次输出L的元素：");
    ListTraverse(L); 

    j=5;
    ListDelete(&L,j,&e); /* 删除第5个数据 */
    printf("删除第%d个的元素值为：%d\n",j,e);

    printf("依次输出L的元素：");
    ListTraverse(L); 

	//构造一个有10个数的Lb
	i=InitList(&Lb);
    for(j=6;j<=15;j++)
            i=ListInsert(&Lb,1,j);

	unionL(&L,Lb);

	printf("依次输出合并了Lb的L的元素：");
    ListTraverse(L); 

    return 0;
}
