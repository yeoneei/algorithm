//
//  2814.cpp
//  backjoon
//
//  Created by 조연희 on 30/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string.h>
using namespace std;

int n,v,u,c;
vector<vector<int>> map;
bool check[12];
int value;
void dfs(int v, int len){
    for(auto i:map[v]){
        if(check[i])continue;
        check[i]=true;
        value = max(value, len+1);
        dfs(i,len+1);
    }
}
int T,m;
int main(){
    cin>>T;
    for(int tc=1; tc<=T;tc++){
        cin>>n>>m;
        map.resize(n+1);
        for(int i=0; i<m;i++){
            cin>>v>>u;
            map[v].push_back(u);
            map[u].push_back(v);
        }
        value=0;
        for(int i=1;i<=n;i++){
            memset(check, 0, sizeof(check));
            check[i]=true;
            dfs(i,0);
        }
        cout<<"#"<<tc<<" "<<value+1<<'\n';
    }
}
