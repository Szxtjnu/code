//
//  Btree_sequence.cpp
//
//  Created by Song Zixuan 
//  

#include<iostream>
#include<cstdlib>
#include<cstdio>
using namespace std;
#define STACK_INIT_SIZE 100
#define STACKINCREMENT 10

typedef int Status;
typedef int ElemType;
typedef struct {
    ElemType *base;
    ElemType *top;
    int stacksize;
} SqStack;

Status InitSatck_Sq(SqStack *pS) {
    pS->base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType));
    if(pS->base == NULL)
        return 0;
    pS->top = pS->base;
    pS->stacksize = STACK_INIT_SIZE;
    return 1;
}

Status Push_Sq(SqStack *pS, ElemType e){
    if(pS->top - pS->base >= STACK_INIT_SIZE){
        pS->base=(ElemType*)realloc(pS->base,(pS->stacksize+STACKINCREMENT)*sizeof(ElemType));
        if(pS->base==NULL) return(-1);
        pS->top = pS->base + pS->stacksize;
        pS->stacksize += STACKINCREMENT;
    }
    *pS->top = e;
    pS->top++;
    return 1;
}

Status Pop_Sq(SqStack *pS, ElemType *pe){
    if(pS->top==pS->base)
        exit(0) ;
    pS->top--;
    *pe = *pS->top;
    return 1;
}

int main()
{
    int n,tmp,idx=0;
    
    SqStack S;
    InitSatck_Sq(&S);
    cout << "Please input n" << endl;
    cin >> n;
    cout << "number" << endl;
    cin >> tmp;
    int x;
	while(tmp){
	
        x = tmp % n;
        tmp /= n;
        Push_Sq(&S, x);
        idx++;
}	
	
    int e;

	for(int i=0;i<idx;i++){
    Pop_Sq(&S, &e);
    cout << e;
}
	
    cout << endl;

    return 0;
}
