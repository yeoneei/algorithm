//
//  12817.cpp
//  backjoon
//
//  Created by 조연희 on 28/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#define MAX 1000000
using namespace std;

int n,y,x;
vector<vector<int>> vc;

long long ans[MAX+1];
long long dfs(int h, int p){
    long long s=1;
    for(auto i : vc[h]){
        if(p==i)continue;
        long long children = dfs(i,h);
        ans[h]+= children*s;
        s+=children;
    }
    ans[h]+=s*(n-s);
    return s;
}

int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>n;
    vc.resize(n+1);
    for(int i=0; i<n-1;i++){
        cin>>y>>x;
        vc[y].push_back(x);
        vc[x].push_back(y);
    }
    dfs(1,0);
    for(int i=1; i<=n;i++){
        cout<<ans[i]*2<<" ";
    }
}
