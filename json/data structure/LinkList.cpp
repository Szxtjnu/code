//
//  LinkList.cpp
//  单链表c语言实现
// 
//  Created by Alan on 10/1/2021
//  Copyright © 2021 Alan . All rights reserved.
//

#include<stdio.h>
#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct Link
{
    ElemType data;
    struct Link *next;
}link;
typedef link Lnode;
typedef link *position;

//创建一个单链表
link *Initlink()
{
    link *p = (link *)malloc(sizeof(link));
    link *temp = p;
    for (int i = 1; i < 5; ++i)
    {
        link *a = (link *)malloc(sizeof(link));
        a->data = i;
        a->next = NULL;
        temp->next = a;
        temp = temp->next;
    }
    return p;
}


/*
//单链表的初始化
link *Initlink()
{
    link *p = (link *)malloc(sizeof(Lnode));
    p->next = NULL;
    return p;
}

//单链表的尾插法
void CreateList_tail(link *L, int num)
{
    link *p, *q;
    int i = 0;
    L = (link *)malloc(sizeof(Lnode));
    p = L;
    
    while(i<num){
        q = (link *)malloc(sizeof(Lnode));
        q->data = i;
        p->next = q;
        p = q;
        free(q);
        ++i;
    }
    p->next = NULL;
}
*/

//单链表的插入
void InsertLink(ElemType x, position p, link &L)
{
    position q;
    q = (link *)malloc(sizeof(Lnode));
    if(p->next == NULL)
        exit(-1);
    else{
        q->data = x;
        q->next = p->next;
        p->next = q;
    }
}

//单链表的删除
void DeleteLink(position p, Link &L)
{
    position q;
    if(p->next!=nullptr){
        q = p->next;
        p->next = q->next;
        free(q);
    }
}

//单链表数据的获取
void GetNumLink(int n, Link &L)
{
    position p;
    p = &L;
    int i=0;
    while(i<n-1){
        p = p->next;
        i++;
    }
    printf("%d ", p->next->data);
}

int main()
{
    link *L;
    L = Initlink();
    GetNumLink(1, *L);
    return 0;
}