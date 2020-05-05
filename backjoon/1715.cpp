//
//  1715.cpp
//  backjoon
//
//  Created by 조연희 on 09/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int n,temp;
int arr[100001];
int heap=0;
void insertHeap(int n){
    arr[++heap]=n;
    int child = heap;
    int parent = child/2;
    while(parent>=1 && arr[parent]>arr[child]){
        swap(arr[parent],arr[child]);
        child = parent;
        parent = child/2;
    }
}

int pop(){
    if(heap==0)return -1;
    int answer = arr[1];
    arr[1] = arr[heap--];
    int here = 1;
    int child = here*2;
    if(child+1 <=heap && arr[child]> arr[child+1]){
        child++;
    }
    while(child<=heap && arr[here]>arr[child]){
        swap(arr[here],arr[child]);
        here = child;
        child = here*2;
        if(child+1 <=heap && arr[child]> arr[child+1]){
            child++;
        }
    }
    return answer;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>temp;
        insertHeap(temp);
    }
    long long answer=0;
    while(heap!=0){
        int n1 = pop();
        int n2 = pop();
        if(n1==-1 || n2 ==-1) break;
        answer = answer + n1 +n2;
        insertHeap(n1+n2);
    }
    cout<<answer;
}
