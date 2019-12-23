//
//  1766.cpp
//  backjoon
//
//  Created by 조연희 on 07/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#define MAX 3200
using namespace std;

int check[MAX+1];
vector<vector<int>> vt;
priority_queue<int> pq;

int n,m,x,y;

int main(){
    scanf("%d%d", &n, &m);
    vt.resize(n+1);
    
    for(int i=0; i<m;i++){
        scanf("%d%d", &x, &y);
        vt[x].push_back(y);
        check[y]++;
    }
    
    for(int i=1; i<=n;i++){
        if(!check[i])pq.push(-i);
    }
    
    while(!pq.empty()){
        int v = -pq.top();
        pq.pop();
        cout<<v<<" ";
        for( auto i : vt[v]){
            check[i]--;
            if(check[i]==0) pq.push(-i);
        }
        
    }
    return 0;
}


