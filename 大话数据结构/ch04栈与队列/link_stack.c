#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0
#define MAXSIZE 20 /* 存储空间初始分配量 */

typedef int Status; 
typedef int SElemType; /* SElemType类型根据实际情况而定，这里假设为int */


typedef struct StackNode
{
    SElemType data;
    struct Node *next;
} StackNode, *LinkStackPtr;

typedef struct LinkStack
{
    LinkStackPtr top;
    int count;
} LinkStack;

Status visit(SElemType c)
{
        printf("%d ",c);
        return OK;
}

/*  构造一个空栈S */
Status InitStack(LinkStack *S)
{ 
        S->top = (LinkStackPtr)malloc(sizeof(StackNode));
        if(!S->top)
                return ERROR;
        S->top=NULL;
        S->count=0;
        return OK;
}

/* 把S置为空栈 */
Status ClearStack(LinkStack *S)
{ 
        LinkStackPtr p,q;
        p=S->top;
        while(p)
        {  
                q=p;
                p=p->next;
                free(q);
        } 
        S->count=0;
        return OK;
}

/* 若栈S为空栈，则返回TRUE，否则返回FALSE */
Status StackEmpty(LinkStack S)
{ 
        if (S.count==0)
                return TRUE;
        else
                return FALSE;
}

/* 返回S的元素个数，即栈的长度 */
int StackLength(LinkStack S)
{ 
        return S.count;
}

/* 若栈不空，则用e返回S的栈顶元素，并返回OK；否则返回ERROR */
Status GetTop(LinkStack S,SElemType *e)
{
        if (S.top==NULL)
                return ERROR;
        else
                *e=S.top->data;
        return OK;
}

Status StackTraverse(LinkStack S)
{
        LinkStackPtr p;
        p=S.top;
        while(p)
        {
                 visit(p->data);
                 p=p->next;
        }
        printf("\n");
        return OK;
}

int main()
{
        int j;
        LinkStack s;
        int e;
        if(InitStack(&s)==OK)
                for(j=1;j<=10;j++)
                        Push(&s,j);
        printf("栈中元素依次为：");
        StackTraverse(s);
        Pop(&s,&e);
        printf("弹出的栈顶元素 e=%d\n",e);
        printf("栈空否：%d(1:空 0:否)\n",StackEmpty(s));
        GetTop(s,&e);
        printf("栈顶元素 e=%d 栈的长度为%d\n",e,StackLength(s));
        ClearStack(&s);
        printf("清空栈后，栈空否：%d(1:空 0:否)\n",StackEmpty(s));
        return 0;
}

Status Push(LinkStack *S, SElemType e)
{
    LinkStackPtr p = (LinkStackPtr)malloc(sizeof(StackNode));
    p->data = e;
    p->next = S->top;
    S->top = p;
    S->count++;

    return OK;
}

Status Pop(LinkStack *S, SElemType *e)
{
    LinkStackPtr p;
    if (S->count == 0)
    {
        return ERROR;
    }

    p = S->top;
    S->top = p->next;
    *e = p->data;
    free(p);
    S->count--;
    return OK;
}