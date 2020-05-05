//
//  16562.cpp
//  backjoon
//
//  Created by 조연희 on 02/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
using namespace std;

int n,m,k,fi,se;
vector<int> parent;
vector<int> value;
vector<bool> check;

int find(int x){
    if(x==parent[x])return x;
    return parent[x] =find(parent[x]);
}

void uion(int x, int y){
    x = find(x);
    y = find(y);
    if(value[x]>= value[y]){
        parent[x]=y;
        value[x]=-1;
    }else{
        parent[y]=x;
        value[y]=-1;
    }
}

int main(){
    cin>>n>>m>>k;
    parent.resize(n);
    value.resize(n);
    check.resize(n);
    for(int i=0; i<n;i++){
        cin>>value[i];
        parent[i]=i;
    }
    for(int i=0; i<m;i++){
        cin>>fi>>se;
        uion(fi-1,se-1);
    }
    int sum=0;
    for(int i=0; i<n;i++){
        int pa = find(i);
        if(check[pa])continue;
        check[pa]=1;
        sum+=value[pa];
    }
    if(sum<=k){
        cout<<sum;
    }else{
        cout<<"Oh no";
    }
}
