#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;
#define LIST_INIT_SIZE  100
#define LIST_INCREMENT  10
typedef int ElemType;
typedef struct
{
    ElemType *elem;
    int length;
    int listsize;
}SqList;
typedef int Status;
typedef int position;
//构建顺序表
void InitList_Sq(SqList *L)
{
    L->elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
    if (!L->elem)
        exit(-1);
    L->length = 0;
    L->listsize = LIST_INIT_SIZE;
}

//向顺序表中插入元素
Status ListInsert_Sq(ElemType x,position i, SqList *L)
{
    position j;
    if(i<0 || i>L->length+1)
        return 0;
    else{
        for (j = L->length; j >= i; --j)
        {
            L->elem[j + 1] = L->elem[j];
        }
        L->elem[i] = x;
        (*L).length++;
    }
    return 0;
}

// 删除位置为p的元素
void ListDelete_Sq(position p,SqList *L)
{
    position q;
    if(p<0 || p>L->length)
        exit(-1);
    else{
        L->length--;
        for (q = p; q <= L->length;q++)
            L->elem[q] = L->elem[q + 1];
    }
}

//get the elem that  is in position = q
Status GetElem_Sq(SqList *L, position p)
{
    if(p<1 || p>L->length)
        return 0;
    else
        return (L->elem[p - 1]);
}

//print all linerlist
void PrintAll(SqList L)
{
    position p;
    for (p = 0; p < L.length; p++){
        printf("%d ", L.elem[p]);
    }
    printf("\n");
}

int main()
{
    SqList L;
    InitList_Sq(&L);
    ElemType e;
    cin >> e;
    ListInsert_Sq(e, 0, &L);
    PrintAll(L);
    return 0;
}
