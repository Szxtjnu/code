//
//  merge.cpp
//  归并排序c语言实现
//  Create tempy Alan On 10/3/2021.
//  Copyright © 2021 Alan . All rights reserved.
//

#include<iostream>
#include<cstdio>
#define Maxsize 100
using namespace std;
int list[100]={2,1,5,4,8,7,9,6,3,0};

void merge(int left, int mid, int right)
{
    int temp[Maxsize];
    int i = left, j = mid + 1;
    int count = left;
    while (i != mid + 1 && j != right + 1)
    {
        if(list[i]<list[j]){
            temp[count++] = list[i++];
        }
        else
            temp[count++] = list[j++];
    }
    while(i!=mid+1){
        temp[count++] = list[i++];
    }
    while(j!=right+1){
        temp[count++] = list[j++];
    }
    for (int n = 0; n < count; ++n){
        list[n] = temp[n];
    }
}

void sort(int left, int right){
    int mid = (left + right) / 2;
    if(left<right){
        sort(left, mid);
        sort(mid + 1, right);
        merge(left, mid, right);
    }
}

int main()
{
    sort(0, 9);
    for (int i = 0; i < 10; ++i){
        cout << list[i] << "  ";
    }
    return 0;
}