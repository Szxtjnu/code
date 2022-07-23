//
//  Btree_sequence.cpp
//
//  Created by Song Zixuan 
//  
 
#include<iostream>
#include<cstdio>
#include<stdlib.h>
using namespace std;

typedef int ElemType;


typedef struct BTnode{
    ElemType data;
    struct BTnode *lc, *rc;
}BTnode,*bitree;
typedef struct QNode{
    bitree data;
    struct QNode *next;
} QNode, *QueuePtr;
typedef struct{
    QueuePtr front;
    QueuePtr rear;
} LinkQueue;
void create_tree(bitree &T)
{
    ElemType x;
    cin >> x;
    if(x == -1)
        T = NULL;
    else{
        T = (BTnode*)malloc(sizeof(BTnode));
        T->data = x;
        create_tree(T->lc);
        create_tree(T->rc);
    }
}

void InitQueue(LinkQueue *pQ){
    pQ->front = (QueuePtr)malloc(sizeof(QNode));
    if(!(pQ->front)){
        printf("ERROR");
        exit(0);
    }
    pQ->rear = pQ->front;
    pQ->front->next = NULL;
}

void EnQueue(LinkQueue *pQ, bitree t){
    QueuePtr p;
    p = (QueuePtr)malloc(sizeof(QNode));
    if(!p){cout << "1";return;
	}
        
    p->data = t;
    p->next = NULL;
    pQ->rear->next = p;
    pQ->rear = p;
}

void DeQueue(LinkQueue *pQ,bitree *x){
    QueuePtr p;
    if(pQ->front==pQ->rear)
        return;
    p = pQ->front->next;
    pQ->front->next = p->next;
    if(pQ->rear == p)
        pQ->rear = pQ->front;
    *x=p->data;
    free(p);
}

bool IsEmpty(LinkQueue Q){
    if(Q.front == Q.rear)
        return true;
    else
        return false;
}

void LevelOrder(bitree T){
    LinkQueue Q;
    InitQueue(&Q);
    EnQueue(&Q, T);
    while(!IsEmpty(Q)){
        DeQueue(&Q,&T);
        cout << T->data;
        if(T->lc!=NULL){
            EnQueue(&Q,T->lc);}
        if(T->rc!=NULL){
            EnQueue(&Q,T->rc);}
    }
}

int main()
{
    bitree T;
    create_tree(T);
    LevelOrder(T);
    return 0;
}
