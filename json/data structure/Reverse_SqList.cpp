//
//  Btree_sequence.cpp
//
//  Created by Song Zixuan 
//  

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
using namespace std;

#define LIST_INI_SIZE 100
#define LISTINCREMENT 10
typedef int ElemType;
typedef struct SqList{
    ElemType *elem;
    int length;
    int listsize;
} SqList;

void InitList_Sq(SqList *pL){
    pL->elem = (ElemType *)malloc(LIST_INI_SIZE * sizeof(ElemType));
    if(!pL->elem){
        printf("ERROR");
        exit(0);
    }
    pL->length = 0;
    pL->listsize = LIST_INI_SIZE;
}

void ListInsert_Sq(SqList *pL, int i, ElemType e){
    int j;
    if(i<1 || i>pL->length)
        return;
    for (j = pL->length; j >= i; j--)
        pL->elem[j] = pL->elem[j - 1];
    pL->elem[i + 1] = e;
    pL->length++;
}

void Creat_Sq(SqList *pL,int n){
    if (n < 0 || n > LIST_INI_SIZE)
        return;
    else{
        int i;
        for (i = 0; i < n; i++){
            cin >> pL->elem[i];
            pL->length++;
        }
    }
}

void Reverse_Sq(SqList *pL){
    ElemType temp;
    int i;
    int x = pL->length;
    for (i = 0; i < x / 2;i++){
        temp = pL->elem[i];
        pL->elem[i] = pL->elem[x - i-1];
        pL->elem[x - i - 1] = temp;
    }
}

void PrintAll(SqList L){
    int j;
    for (j = 0; j < L.length; j++)
        cout << L.elem[j];
}

int main()
{
    SqList L;
    int n;
    cin >> n;
    InitList_Sq(&L);
    Creat_Sq(&L,n);
    Reverse_Sq(&L);
    PrintAll(L);
}