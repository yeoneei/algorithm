//
//  22.cpp
//  backjoon
//
//  Created by 조연희 on 26/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000000
using namespace std;
int parent[100000001];
int c[MAX+1];
int n,m;
int find(int x){
    if(x == parent[x]){
        return x;
    }
    return parent[x] = find(parent[x]);
}


bool uion_find(int x, int y){
    x = find(x);
    y = find(y);
    if(x==y) return false;
    if(x<y)parent[y]=x;
    else parent[x]=y;
    return true;
}
int t, com;
vector<pair<int,int>> input;
priority_queue<pair<int,pair<int,int>>> g;
int fi,se;
int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        parent[i]=i;
    }
    for(int i=0; i<n;i++){
        cin>>fi>>se;
        input.push_back(make_pair(fi,se));
    }
    for(int i=0; i<m;i++){
        cin>>fi>>se;
        uion_find(fi-1, se-1);
    }
    for(int i=0; i<input.size();i++){
        int x = find(i);
        g.push(make_pair(x,input[i]));
    }
    vector<pair<int,int>> vc;
    long long answer=0;
    
    int newG= g.top().first;
    while(!g.empty()){
        int Id = g.top().first;
        if(newG == Id){
            vc.push_back(g.top().second);
        }else{
            //길이 재기
            int xMIN =MAX;
            int xMAX = 0;
            int yMIN =MAX;
            int yMAX = 0;
            for(int i=0; i<vc.size();i++){
                xMIN = min(vc[i].first,xMIN);
                xMAX = max(vc[i].first,xMAX);
                yMIN = min(vc[i].second,yMIN);
                yMAX = max(vc[i].second,yMAX);
            }
            long long temp = (xMAX-xMIN)*2 + (yMAX - yMIN)*2;
            answer = max(answer,temp);
            
            vc.clear();
            newG = Id;
            vc.push_back(g.top().second);
        }
        g.pop();
    }
    int xMIN =MAX;
    int xMAX = 0;
    int yMIN =MAX;
    int yMAX = 0;
    for(int i=0; i<vc.size();i++){
        xMIN = min(vc[i].first,xMIN);
        xMAX = max(vc[i].first,xMAX);
        yMIN = min(vc[i].second,yMIN);
        yMAX = max(vc[i].second,yMAX);
    }
    long long temp = (xMAX-xMIN)*2 + (yMAX - yMIN)*2;
    answer = max(answer,temp);
    
    
    cout<<answer;
}
