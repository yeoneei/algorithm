//
//  2250.cpp
//  backjoon
//
//  Created by 조연희 on 25/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>
#define MAX 100001
#define INF 987654321
using namespace std;

typedef pair<int,int> pii;
pii tree[MAX];
int node[MAX];
int pre[MAX];

int low[100];
int ri[100];

int n;
int parent,ch1,ch2;
int nodeIdx=1;

void dfs(int root,int h){
    if(tree[root].first>0){
        dfs(tree[root].first, h+1);
    }
    pre[root]=nodeIdx++;
    low[h] = (low[h]>pre[root]?pre[root]:low[h]);
    ri[h] = (ri[h]<pre[root]?pre[root]:ri[h]);
    if(tree[root].second>0){
        dfs(tree[root].second, h+1);
    }
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    
    cin>>n;
    for(int i=0;i<n;i++){
        low[i+1]=INF;
        cin>>parent>>ch1>>ch2;
        node[parent]++;
        if(ch1!=-1){
            node[ch1]++;
        }
        if(ch2!=-1){
            node[ch2]++;
        }
        tree[parent].first=ch1;
        tree[parent].second=ch2;
    }
    int root=0;
    for(int i=1; i<=n;i++){
        if(node[i]==1){
            root=i;
            break;
        }
    }
    dfs(root,1);
    int maxV=0;
    int maxI;
    for(int i=1; i<=n;i++){
        if(ri[i]==0 && low[i]==INF) break;
        if(maxV < ri[i]-low[i]+1){
            maxV = ri[i]-low[i]+1;
            maxI = i;
        }
    }
    cout<<maxI<<" "<<maxV;
}
