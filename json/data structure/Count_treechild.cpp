//
//  Btree_sequence.cpp
//
//  Created by Song Zixuan 
//  

#include<stdio.h>
#include<stdlib.h>

int ans; //tree child count

typedef char ElemType;
typedef struct BTnode{
    ElemType data;
    struct BTnode *lc, *rc;
}BTnode,*bitree;

void create_tree(bitree &T)
{
    ElemType ch;
    scanf("%c", &ch);
    if(ch == '#')
        T = NULL;
    else{
        T = (BTnode*)malloc(sizeof(BTnode));
        T->data = ch;
        create_tree(T->lc);
        create_tree(T->rc);
    }
}

void Find(bitree T)
{
    if(T==NULL)
        return;
    if(T->lc==NULL&&T->rc==NULL)
        ans++;
    else{
        Find(T->lc);
        Find(T->rc);
    }
}

int main()
{
    ans = 0;
    bitree T;
    create_tree(T);
    Find(T);
    printf("%d", ans);
    return 0;
}