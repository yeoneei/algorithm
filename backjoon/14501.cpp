//
//  14501.cpp
//  backjoon
//
//  Created by 조연희 on 27/08/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
using namespace std;

struct Node{
    int t;
    int p;
    
};
Node nodeList[16];
int n,t,p;
int mx;

void dfs(int cnt, int sum){
    mx =max(sum,mx);
    for(int i=cnt; i<n;i++){
        if(i+ nodeList[i].t>n) continue;
        sum+=nodeList[i].p;
        dfs(i+nodeList[i].t,sum);
        mx = max(sum, mx);
        sum-= nodeList[i].p;
    }
}
int main(){
    cin>>n;
    for(int i=0; i<n;i++){
        cin>>nodeList[i].t>>nodeList[i].p;
    }
    for(int i=0; i<n;i++){
        if(i+nodeList[i].t<=n){
            dfs(i+nodeList[i].t, nodeList[i].p);
        }
    }
    cout<<mx<<endl;
    
}
