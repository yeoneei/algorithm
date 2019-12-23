//
//  1260-2.cpp
//  backjoon
//
//  Created by 조연희 on 01/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

bool mCheck[1001][1001];
bool check[1001];
int n,m,k;
queue<int> qu;
void dfs(int v){
    cout<<v<<" ";
    for(int i=1; i<=n;i++){
        if(check[i]==1) continue;
        if(mCheck[v][i]==1){
            check[i]=1;
            dfs(i);
        }
    }
}

void bfs(){
    while(1){
        if(qu.empty()==1){
            break;
        }
        int v = qu.front();
        cout<<v<<" ";
        qu.pop();
        for(int i=1; i<=n;i++){
            if(check[i]==1) continue;
            if(mCheck[v][i]==1){
                    check[i]=1;
                    qu.push(i);
                }
            }
        }
}

int main(){
    cin>>n>>m>>k;
    for(int i=0; i<m;i++){
        int f,s;
        cin>>f>>s;
        mCheck[f][s]=1;
        mCheck[s][f]=1;
        
    }
    check[k]=1;
    qu.push(k);
    dfs(k);
    for(int i=1; i<=n;i++){
        check[i]=0;
    }
    check[k]=1;
    cout<<endl;
    bfs();
}
