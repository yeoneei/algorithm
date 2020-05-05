//
//  13549.cpp
//  backjoon
//
//  Created by 조연희 on 28/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int n,m;
int dist[200002];
int main(){
    cin>>n>>m;
    queue<int> qu;
    qu.push(n);
    memset(dist, -1,sizeof(dist));
    dist[n]=0;
    while(!qu.empty()){
        int x= qu.front();
        qu.pop();
        if(m==x){
            cout<<dist[x];
            return 0;
        }
        if(2*x <=100000 && 2*x >=0 && dist[2*x]==-1){
            qu.push(2*x);
            dist[2*x]=dist[x];
        }
        if(x+1<=100000 && x+1 >=0 && dist[x+1]==-1){
            qu.push(x+1);
            dist[x+1]=dist[x]+1;
        }
        if(x-1 <=100000 && x-1 >=0 && dist[x-1]==-1){
            qu.push(x-1);
            dist[x-1]=dist[x]+1;
        }
        
        
    }
}
