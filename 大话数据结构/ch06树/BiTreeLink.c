#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */

/* 用于构造二叉树********************************** */
int index1=1;
typedef char String[24]; /*  0号单元存放串的长度 */
String str;

Status StrAssign(String T,char *chars)
{ 
	int i;
	if(strlen(chars)>MAXSIZE)
		return ERROR;
	else
	{
		T[0]=strlen(chars);
		for(i=1;i<=T[0];i++)
			T[i]=*(chars+i-1);
		return OK;
	}
}
/* ************************************************ */

typedef char TElemType;
TElemType Nil=' '; /* 字符型以空格符为空 */

typedef struct BiTNode
{
    TElemType data;
    struct BiTNode *lchild, *rchild;
} BiTNode, *BiTree;

/* 构造空二叉树T */
Status InitBiTree(BiTree *T)
{ 
	*T=NULL;
	return OK;
}

/* 初始条件: 二叉树T存在。操作结果: 销毁二叉树T */
void DestroyBiTree(BiTree *T)
{ 
	if(*T) 
	{
		if((*T)->lchild) /* 有左孩子 */
			DestroyBiTree(&(*T)->lchild); /* 销毁左孩子子树 */
		if((*T)->rchild) /* 有右孩子 */
			DestroyBiTree(&(*T)->rchild); /* 销毁右孩子子树 */
		free(*T); /* 释放根结点 */
		*T=NULL; /* 空指针赋0 */
	}
}

/* 初始条件: 二叉树T存在 */
/* 操作结果: 若T为空二叉树,则返回TRUE,否则FALSE */
Status BiTreeEmpty(BiTree T)
{ 
	if(T)
		return FALSE;
	else
		return TRUE;
}

#define ClearBiTree DestroyBiTree

/* 初始条件: 二叉树T存在。操作结果: 返回T的深度 */
int BiTreeDepth(BiTree T)
{
	int i,j;
	if(!T)
		return 0;
	if(T->lchild)
		i=BiTreeDepth(T->lchild);
	else
		i=0;
	if(T->rchild)
		j=BiTreeDepth(T->rchild);
	else
		j=0;
	return i>j?i+1:j+1;
}

/* 初始条件: 二叉树T存在。操作结果: 返回T的根 */
TElemType Root(BiTree T)
{ 
	if(BiTreeEmpty(T))
		return Nil;
	else
		return T->data;
}

/* 初始条件: 二叉树T存在，p指向T中某个结点 */
/* 操作结果: 返回p所指结点的值 */
TElemType Value(BiTree p)
{
	return p->data;
}

/* 给p所指结点赋值为value */
void Assign(BiTree p,TElemType value)
{
	p->data=value;
}

void PreOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    printf("%c", T->data);
    PreOrderTraverse(T->lchild);
    PreOrderTraverse(T->rchild);
}

void InOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    InOrderTraverse(T->lchild);
    printf("%c", T->data);
    InOrderTraverse(T->rchild);
}

void PostOrderTraverse(BiTree T)
{
    if (T == NULL)
    {
        return;
    }
    PostOrderTraverse(T->lchild);
    PostOrderTraverse(T->rchild);
    printf("%c", T->data);
}

// 只能一次将需要创建的树以先序遍历的方式输入，如：ab#d##c##
void CreateBiTree(BiTree *T)
{
    TElemType ch;
    scanf("%c", &ch);
    if (ch == '#')
    {
        printf("1\n");
        *T = NULL;
    }
    else
    {
        *T = (BiTree)malloc(sizeof(BiTNode));
        if (!*T)
        {
            return;
        }
        (*T)->data = ch;     
        printf("2\n");
        CreateBiTree(&(*T)->lchild);
        CreateBiTree(&(*T)->rchild);
    }
}

int main()
{
	int i;
	BiTree T;
	TElemType e1;
	InitBiTree(&T);

	
	StrAssign(str,"ABDH#K###E##CFI###G#J##");

	CreateBiTree(&T);

	printf("构造空二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	e1=Root(T);
	printf("二叉树的根为: %c\n",e1);

	printf("\n前序遍历二叉树:");
	PreOrderTraverse(T);
	printf("\n中序遍历二叉树:");
	InOrderTraverse(T);
	printf("\n后序遍历二叉树:");
	PostOrderTraverse(T);
	ClearBiTree(&T);
	printf("\n清除二叉树后,树空否？%d(1:是 0:否) 树的深度=%d\n",BiTreeEmpty(T),BiTreeDepth(T));
	i=Root(T);
	if(!i)
		printf("树空，无根\n");
	
	return 0;
}

