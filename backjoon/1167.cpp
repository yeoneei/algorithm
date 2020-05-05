//
//  1167.cpp
//  backjoon
//
//  Created by 조연희 on 24/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000
using namespace std;

int n,x,y,z;
bool check[MAX+1];
int dist[MAX+1];
vector<pair<int,int>> vc[MAX+1];

struct Node{
    int v;
    int c;
    Node(int v, int c):v(v),c(c){}
};
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>x;
        while(cin>>y){
            if(y==-1)break;
            cin>>z;
            vc[x].push_back(make_pair(y,z));
        }
    }
    queue<int> qu;
    qu.push(1);
    check[1]=1;
    while(!qu.empty()){
        int x = qu.front();
        qu.pop();
        for(auto t : vc[x]){
            if(check[t.first])continue;
            check[t.first]=1;
            dist[t.first] = dist[x]+t.second;
            qu.push(t.first);
        }
    }
    int idx=1;
    for(int i=1; i<=n;i++){
        if(dist[idx]<dist[i]){
            idx = i;
        }
    }
    
    memset(check,0, sizeof(check));
    memset(dist, 0, sizeof(dist));
    qu.push(idx);
    check[idx]=1;
    while(!qu.empty()){
        int x = qu.front();
        qu.pop();
        for(auto t : vc[x]){
            if(check[t.first])continue;
            check[t.first]=1;
            dist[t.first] = dist[x]+t.second;
            qu.push(t.first);
        }
    }
    idx=1;
    for(int i=1;i<=n;i++){
        if(dist[idx]<dist[i]){
            idx=i;
        }
    }
    cout<<dist[idx];

}
