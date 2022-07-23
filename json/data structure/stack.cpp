//
//  stack.cpp
//  链栈的c语言实现
//  Create By Alan On 10/2/2021
//  Copyright © 2021 Alan . All rights reserved.
//


#include<iostream>
#include<stdio.h>
#include<stdlib.h>
using namespace std;

typedef int ElemType;
typedef struct LinkStack
{
    ElemType data;
    struct LinkStack *next;
}LinkStack;
typedef LinkStack *Node;

Node InitStack()
{
    Node S;
    S = (LinkStack*)malloc(sizeof(LinkStack));
    S->next = NULL;
    return S;
}

void Push(LinkStack *stack, ElemType x)
{
    Node S;
    S = (LinkStack *)malloc(sizeof(LinkStack));
    S->data = x;
    S->next = stack->next;
    stack->next = S;
}

void Pop(LinkStack *stack)
{
    Node S;
    if(stack->next){
        S = stack->next;
        stack->next = S->next;
        free(S);
    }
}

ElemType Top(LinkStack *stack)
{
    if(stack->next)
    {
        return (stack->next->data);
    }
    else
        return -1;
}

int main()
{
    LinkStack *stack;
    stack = InitStack();
    for (int i = 0; i < 8; i++)
    {
        Push(stack, i);
    }
    cout << Top(stack) << endl;
    return 0;
}