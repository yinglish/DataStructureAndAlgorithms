#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 100 /* 存储空间初始分配量 */

typedef int Status;	/* Status是函数的类型,其值是函数结果状态代码,如OK等 */
typedef char TElemType;

typedef enum {Link, Thread} PointerTag;

typedef struct BiThrNode
{
    TElemType data;
    struct BiThrNode *lchild, *rchild;
    PointerTag LTag;
    PointerTag RTag;
} BiThrNode, *BiThrTree;

BiThrTree pre; // 全局变量，始终指向刚刚访问过的节点

void InThreading(BiThrTree p)
{
    if (p)
    {
        InThreading(p->lchild);
        if (!p->lchild)
        {
            p->LTag = Thread;
            p->lchild = pre;
        }
        if (!pre->rchild)
        {
            pre->RTag = Thread;
            pre->rchild = p;
        }
        pre = p;
        InThreading(p->rchild);
    }
}

