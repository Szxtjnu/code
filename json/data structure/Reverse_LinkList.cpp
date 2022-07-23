//
//  Btree_sequence.cpp
//
//  Created by Song Zixuan 
//  


#include<iostream>
using namespace std;

typedef int ElemType;
typedef struct LNode{
    ElemType data;
    LNode *next;
}LNode, *LinkList;

LinkList List_TailInsert(LinkList &L){
    int x;
    L = (LinkList)malloc(sizeof(LNode));
    LNode *s, *r = L;
    scanf("%d", &x);
    while(x!=9999){
        s = (LNode *)malloc(sizeof(LNode));
        s->data = x;
        r->next = s;
        r = s;
        scanf("%d", &x);
    }
    r->next = NULL;
    return L;
}

LinkList Reverse_LinkList(LinkList &L){
    LinkList pre, p, r;
    pre = L;
    p = L->next;
    r = p->next;
    p->next = NULL;
    while(r!=NULL){
        pre = p;
        p = r;
        r = r->next;
        p->next = pre;
    }
    L->next = p;
    return L;
}

void visit_LinkList(LinkList L){
    LinkList p;
    p = L->next;
    while(p!=NULL){
        printf("%d", p->data);
        p = p->next;
    }
}

int main()
{
    LinkList L;
    L = List_TailInsert(L);
    visit_LinkList(L);
    cout << endl;
    Reverse_LinkList(L);
    visit_LinkList(L);
    return 0;
}