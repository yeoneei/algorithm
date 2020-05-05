//
//  16947.cpp
//  backjoon
//
//  Created by 조연희 on 19/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int n,s,d;
int check[3001];
int dist[3001];
vector<vector<int>> map;

int go(int x, int p){
    //-2 : 사이클 찾은 후 포함 x , -1: 포함 x, 0~n : 사이클
    if(check[x]==1) return x;
    check[x]=1;
    for(int i : map[x]){
        if(i==p) continue;
        int res = go(i,x);
        if(res==-2){
            return res;
        }
        if(res>=0){
            check[x]=2;
            if(res==x) return -2;
            else return res;
        }
    }
    return -1;
}

int main(){
    cin>>n;
    map.resize(n+1);
    for(int i=0; i<n;i++){
        cin>>s>>d;
        map[s].push_back(d);
        map[d].push_back(s);
    }
    go(1,-1);
    queue<int> qu;
    for(int i=1; i<=n;i++){
        if(check[i]==2){
            qu.push(i);
            dist[i]=0;
        }else{
            dist[i]=-1;
        }
    }
    
    while(!qu.empty()){
        int x = qu.front();
        qu.pop();
        for(int y :map[x]){
            if(dist[y]==-1){
                dist[y]=dist[x]+1;
                qu.push(y);
            }
        }
    }
    for(int i=1; i<=n;i++){
        cout<<dist[i]<<" ";
    }
}
