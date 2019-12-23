//
//  1260.cpp
//  backjoon
//
//  Created by 조연희 on 28/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;
bool map[1001][1001];
int n, m,v;
int check[1001];
queue<int> qu;
void bfs(){
    
    if(qu.empty()) return;
    
    while(!qu.empty())
    {
        int temp = qu.front();
        qu.pop();
        cout<<temp<<" ";
        for(int i=1; i<=n;i++){
            if(check[i]==0 && map[temp][i]==1){
                check[i]=1;
                qu.push(i);
            }
        }
    }
}
void init(){
    for(int i=1; i<=n;i++){
        check[i]=0;
    }
}
void dfs(int v){
    cout<<v<<" ";
    for(int i=1; i<=n;i++){
        if(check[i]==true) continue;
        if(map[v][i]==1){
            check[i]= true;
            dfs(i);
        }
    }
}
int main(){
    cin>>n>>m>>v;
    int x,y;
    for(int i=0;i<m;i++){
        cin>>x>>y;
        map[x][y]=map[y][x]=1;
    }
    check[v]=1;
    dfs(v);
    init();
    cout<<endl;
    qu.push(v);
    check[v]=1;
    bfs();
}
