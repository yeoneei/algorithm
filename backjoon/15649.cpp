//
//  15649.cpp
//  backjoon
//
//  Created by 조연희 on 22/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//
#include <iostream>
using namespace std;


void quick_sort(int data[], int start, int end){
    if(start >= end){
        return;
    }
    
    int pivot = start;
    int i = pivot + 1;
    int j = end;
    int temp;
    
    while(i <= j){
        while(i <= end && data[i] <= data[pivot]){
            i++;
        }
        while(j > start && data[j] >= data[pivot]){
            j--;
        }
        
        if(i > j){
            temp = data[j];
            data[j] = data[pivot];
            data[pivot] = temp;
        }else{
            temp = data[i];
            data[i] = data[j];
            data[j] = temp;
        }
    }
    
    quick_sort(data, start, j - 1);
    quick_sort(data, j + 1, end);
}

int N,M;
int input[8];
bool visited[8];
int arr[8];
int idx=0;
void printAll(){
    for(int i=0; i<M;i++){
        printf("%d ",arr[i]);
    }
    printf("\n");
}
void dfs(int id, int cnt){
    if(cnt==M){
        printAll();
        return;
    }
    
    for(int i=id; i<N;i++){
        arr[idx++]=input[i];
        dfs(i,cnt+1);
        arr[idx--]=0;
    }
}

int main(){
    cin>>N>>M;
    for(int i=0; i<N;i++){
        cin>>input[i];
    }
    quick_sort(input, 0, N-1);
    dfs(0,0);
    
}
