//
//  topology.cpp
//  backjoon
//
//  Created by 조연희 on 07/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//
#include <iostream>
#include <stack>
#include <vector>
#define MAX 3200
using namespace std;

vector<vector<int>> vt;
stack<int> st;
bool visited[MAX+1];
int n,m,x,y;

void dfs(int v){
    visited[v]=true;
    for(auto i : vt[v]){
        if(visited[i]) continue;
        dfs(i);
    }
    st.push(v);
}


int main(){
    cin>>n>>m;
    vt.resize(n+1);
    
    for(int i=0; i<m;i++){
        cin>>x>>y;
        vt[x].push_back(y);
    }
    
    for(int i=1; i<=n;i++){
        if(!visited[i]) dfs(i);
    }
    
    while(!st.empty()){
        cout<<st.top()<<" ";
        st.pop();
    }
}
