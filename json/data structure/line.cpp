//
//  line.cpp
//  双向链表c语言实现
//  Created by Alan on 10/7/2021
//  Copyright © 2021 Alan . All rights reserved.
//

#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef int Elemtype;
typedef struct line{
    struct line *prior;
    int data;
    struct line *next;
} Line;
typedef line *position;
line *head;
//创建双向链表
void CreateLine(line *head)
{
    head = (line *)malloc(sizeof(line));
    head->prior = NULL;
    head->next = NULL;
}

//初始化双向链表
void InitLine(line *head, Elemtype n)
{
    position h;
    h = (line *)malloc(sizeof(line));
    h->prior = head;
    h->data = n;
    h->next = NULL;
}

//插入新节点
void InsertLine(line *head, Elemtype n,int add)
{
    line *temp = (line *)malloc(sizeof(line));
    temp->data = n;
    temp->prior = NULL;
    temp->next = NULL;
    if(add == 1){
        temp->next = head;
        head->prior = temp;
        head = temp;
    }
    else{
        position p = head;
        for (int i = 1; i < add - 1; ++i){
            p = p->next;
        }
        
       
            temp->next = p->next;
            temp->next->prior = temp;
            p->next = temp;
            temp->prior = p;
        
    }
}

//删除节点
void DelLine(line *head, Elemtype n)
{
    position p = head;
    while(p)
    {
        if(p->data == n){
            p->prior->next = p->next;
            p->next->prior = p->prior;
            free(p);
        }
        p = p->next;
    }
}

//输出链表
void DisplayLine(line *head)
{
        cout << head->data << "  ";
        head = head->next;

    cout << endl;
}


int main()
{

    CreateLine(head);
    InitLine(head, 1);
    InitLine(head, 2);
    InitLine(head, 4);

    DisplayLine(head);
    DelLine(head, 3);
    DisplayLine(head);
    return 0;
}
