#include <stdio.h>
#include <stdlib.h>

#define OK 1
#define ERROR 0
#define TRUE 1
#define FALSE 0

#define MAXSIZE 40 /* 存储空间初始分配量 */

typedef int Status;		/* Status是函数的类型,其值是函数结果状态代码，如OK等 */
typedef int ElemType;	/* ElemType类型根据实际情况而定，这里假设为int */

typedef char String[MAXSIZE + 1];

int Index(String S, String T, int pos)
{
    int i = pos;

    int j = 1;
    while (i <= S[0] && j <= T[0])
    {
        if (S[i] == T[j])
        {
            ++i;
            ++j;
        }
        else
        {
            i = i - j + 2;
            j = 1;
        }
    }

    if (j > T[0])
    {
        return i - T[0];
    }
    else 
    {
        return 0;
    }
}