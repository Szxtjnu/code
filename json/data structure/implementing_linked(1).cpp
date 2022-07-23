//
// implementing_linked.cpp
// 静态链表的c语言实现
//
// Created by Alan on 10/1/2021
// Copyright © 2021 Alan . All rights reserved.
//

#include<stdio.h>
#include<iostream>
#define maxsize 100
using namespace std;

typedef int ElemType;
typedef struct
{
    ElemType data;
    int next;
} spacestr;
spacestr SPACE[maxsize];
typedef int position, Cursor;
Cursor L, M, avail;

//初始化静态链表
void Initalize()
{
    int j;
    for (j = 0; j < maxsize - 1; ++j)
        SPACE[j].next = -1;
    avail = 0;
}

//可用空间的分配操作
Cursor GetNode()
{
    Cursor p;
    if(SPACE[avail].next = -1)
        p = -1;
    else{
        p = SPACE[avail].next;
        SPACE[avail].next = SPACE[p].next;
    }
    return p;
}

//可用空间的回收操作
void FreeNode(Cursor q)
{
    SPACE[q].next = SPACE[avail].next;
    SPACE[avail].next = q;
}

//插入操作
void Insert(ElemType x, position p, spacestr *SPACE)
{
    position q;
    q = GetNode();
    SPACE[q].next = SPACE[p].next;
    SPACE[q].data = x;
    SPACE[p].next = q;
}

int main() 
{
    Initalize();
    Insert(1, 2, L);
    for (int i = 0; i < 10; ++ i)
        cout << SPACE[i].data << endl;
    return 0;
}