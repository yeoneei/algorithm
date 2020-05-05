//
//  1753.cpp
//  backjoon
//
//  Created by 조연희 on 30/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 987654321
using namespace std;

int v,e,a,b,w,k;
struct Cmp{
bool operator()(pair<int,int> p1, pair<int,int> p2){
    if(p1.second > p2.second) return true;
    else if(p1.second < p2.second)return false;
    else {
        if(p1.first > p2.first)return true;
        else if(p1.first < p2.first)return false;
    }
    return true;
}
};

priority_queue<pair<int,int>,vector<pair<int, int>>,Cmp> qu;
vector<vector<pair<int, int>>> vc;
int value[20001];
bool visit[20001];
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>v>>e>>k;
    for(int i=1;i<=v;i++){
        value[i]=MAX;
    }
    vc.resize(v+1);
    for(int i=0;i<e;i++){
        cin>>a>>b>>w;
        vc[a].push_back(make_pair(b, w));
    }
    value[k]=0;
    qu.push(make_pair(k, 0));
    while(!qu.empty()){
        int f = qu.top().first;
        qu.pop();
        for(int i=0; i<vc[f].size();i++){
            if(value[vc[f][i].first]> value[f]+vc[f][i].second){
                value[vc[f][i].first]=value[f]+vc[f][i].second;
                qu.push(make_pair(vc[f][i].first, value[vc[f][i].first]));
            }
        }
    }
    
    for(int i=1; i<=v;i++){
        if(value[i]==MAX)cout<<"INF"<<'\n';
        else cout<<value[i]<<"\n";
    }
    
}
