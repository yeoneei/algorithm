//
//  4195.cpp
//  backjoon
//
//  Created by 조연희 on 04/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string>
#include <map>
#include <vector>
using namespace std;

int T,n;
string fi, se;
vector<int> parent;
vector<int> value;
map<string,int> m;
int find(int x){
    if(parent[x]==x)return x;
    return parent[x] = find(parent[x]);
}

int uion(int y, int x){
    y = find(y);
    x = find(x);
    if (y>x){
        parent[y]=x;
        value[x]+=value[y];
        return value[x];
    }else if(y<x){
        parent[x]=y;
        value[y]+=value[x];
        return value[y];
    }
    return value[y];
}

void init(){
    parent.clear();
    m.clear();
    value.clear();
    value.push_back(0);
}
int main(){
    ios_base :: sync_with_stdio(false); cin.tie(NULL); cout.tie(NULL);
    cin>>T;
    while(T--){
        cin>>n;
        init();
        parent.resize(2*n);
        int idx=1;
        for(int i=0; i<n;i++){
            cin>>fi>>se;
            if(!m[fi]){
                m[fi]=idx;
                parent[m[fi]]=idx++;
                value.push_back(1);
            }
            if(!m[se]){
                m[se]=idx;
                parent[m[se]]=idx++;
                value.push_back(1);
            }
            cout<<uion(m[fi],m[se])<<'\n';
        }
    }
    
}
