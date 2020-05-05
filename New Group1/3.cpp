//
//  3.cpp
//  backjoon
//
//  Created by 조연희 on 14/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n,k;
vector<int> input;
bool check[3001];
int arr[3001];
int realAnawer=3000*3000;

void dfs(int cnt,int v){
    if(cnt==k-1){
        
        arr[cnt]=input[n-1];
        int idx=0;
        int answer=0;
        int minV = input[0];
        int maxV = input[0];
        for(int i=0; i<n;i++){
            minV = min(minV,input[i]);
            maxV = max(maxV,input[i]);
            if(arr[idx]==input[i]){
                answer+=(maxV-minV);
                idx++;
                if(i==n-1) break;
                minV=input[i+1];
                maxV=input[i+1];
            }
        }
        realAnawer = min(realAnawer,answer);
        return;
        
    }
    for(int i=v; i<n;i++){
        if(check[i])continue;
        check[i]=1;
        arr[cnt]=input[i];
        dfs(cnt+1,i);
        check[i]=0;
    }
}

int main(){
    cin>>n>>k;
    input.resize(n);
    for(int i=0; i<n;i++){
        cin>>input[i];
    }
    dfs(0,0);
    cout<<realAnawer;
}
