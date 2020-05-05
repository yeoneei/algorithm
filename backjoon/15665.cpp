//
//  15665.cpp
//  backjoon
//
//  Created by 조연희 on 28/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int n,m,temp;
int c[10001];
int arr[10];
int arrIdx=0;
vector<int> in;

void dfs(int cnt, int v){
    if(cnt==m){
        for(int i=0; i<m;i++){
            cout<<arr[i]<<" ";
        }
        cout<<'\n';
        return;
    }
    for(int i=v; i<in.size();i++){
        if(c[in[i]]==0) continue;
        c[in[i]]--;
        arr[arrIdx++]=in[i];
        dfs(cnt+1,i);
        arrIdx--;
        c[in[i]]++;
    }
}

int main(){
    cin>>n>>m;
    int temp;
    for(int i=0;i<n;i++){
        cin>>temp;
        in.push_back(temp);
    }
    sort(in.begin(),in.end());
    in.erase(unique(in.begin(),in.end()),in.end());
    for(int i=0; i<in.size();i++){
        c[in[i]]=m;
    }
    
    dfs(0,0);
}
