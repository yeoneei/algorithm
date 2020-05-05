//
//  5719.cpp
//  backjoon
//
//  Created by 조연희 on 07/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#include <string.h>
#define MAX 500
#define MAXD 98765432
using namespace std;
int n,m;
int s,d,u,v,p;
int value[MAX];
vector<int> pp[MAX];
priority_queue<int,vector<int>,greater<int>> ans;
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

//fisrt : 웨이트 , second : vertax
vector<vector<pair<int,int>>> vc;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    while(cin>>n>>m){
        while(!ans.empty()){
            ans.pop();
        }
        vc.clear();
        vc.resize(n);
        for(int i=0; i<n;i++){
            value[i]= MAXD;
        }
        if(n==0&&m==0){
            break;
        }
        cin>>s>>d;
        for(int i=0; i<m;i++){
            cin>>u>>v>>p;
            vc[u].push_back(make_pair(v,p));
        }
        value[s]=0;
        priority_queue<pair<int,int>,vector<pair<int, int>>,Cmp> qu;
        
        qu.push(make_pair(s, 0));
        while(!qu.empty()){
            int f = qu.top().first;
            qu.pop();
            for(int i=0; i<vc[f].size();i++){
                if(vc[f][i].first==d){
                    ans.push(value[f]+vc[f][i].second);
                }
                
                if(value[vc[f][i].first]> value[f]+vc[f][i].second){
                    value[vc[f][i].first]=value[f]+vc[f][i].second;
                    pp[vc[f][i].first].push_back(f);
                    qu.push(make_pair(vc[f][i].first, value[vc[f][i].first]));
                }
            }
        }
        
        if(!ans.empty()){
            int t = ans.top();
            while(t==ans.top()){
                
                ans.pop();
            }
        }
        if(ans.empty()){
            cout<<-1<<'\n';
        }else{
            cout<<ans.top()<<'\n';
        }
    }
}
