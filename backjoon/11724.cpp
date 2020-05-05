//
//  11724.cpp
//  backjoon
//
//  Created by 조연희 on 24/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

bool check[1001];
int n,m,t1,t2;
vector<vector<int>> vc;

void dfs(int v){
    for(auto i : vc[v]){
        if(check[i])continue;
        check[i]=true;
        dfs(i);
    }
}
int main(){
    cin>>n>>m;
    vc.resize(n+1);
    for(int i=0; i<m;i++){
        cin>>t1>>t2;
        vc[t1].push_back(t2);
        vc[t2].push_back(t1);
    }
    int cnt=0;
    for(int i=1;i<=n;i++){
        if(check[i])continue;
        cnt++;
        dfs(i);
    }
    cout<<cnt;
}
