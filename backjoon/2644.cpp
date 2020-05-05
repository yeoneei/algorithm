//
//  2644.cpp
//  backjoon
//
//  Created by 조연희 on 29/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#define MAX 101
using namespace std;
int n;
int t;
bool map[MAX][MAX];
bool visit[MAX];
int a,b;
int v1,v2;
int c=-1;
bool check=0;

void dfs(int v,int cnt){
    if(cnt>n)return;
    if(v==b){
        check=true;
        c= cnt;
        return;
    }
    for(int i=0; i<=n;i++){
        if(visit[i] || !map[v][i]) continue;
        visit[i]=true;
        dfs(i,cnt+1);
    }
    return;
}
int main(){
    cin>>n;
    cin>>a>>b;
    cin>>t;
    for(int i=0; i<t;i++){
        cin>>v1>>v2;
        map[v1][v2]=1;
        map[v2][v1]=1;
    }
    dfs(a,0);
    if(check){
        cout<<c;
    }else{
        cout<<-1;
    }
}
