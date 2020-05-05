//
//  13913.cpp
//  backjoon
//
//  Created by 조연희 on 24/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <queue>
#define MAX 100000
using namespace std;

int n,m;
int parent[MAX+1];
bool check[MAX+1];
queue<int> qu;
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    qu.push(n);
    int t=0;
    vector<int> result;
    bool complete=false;
    check[n]=1;
    while(!qu.empty()){
        if(complete)break;
        t++;
        int s = qu.size();
        while(s--){
            int x = qu.front();
            if(x==m){
                cout<<t-1<<'\n';
                int temp=m;
                while(temp!=n){
                    result.push_back(temp);
                    temp = parent[temp];
                    
                }
                result.push_back(n);
                complete=true;
                break;
                
            }
            qu.pop();
            for(int nx:{x-1,x+1,2*x}){
                if(nx<0 || nx>MAX || check[nx])continue;
                check[nx]=1;
                parent[nx]=x;
                qu.push(nx);
            }
        }
    }
    for(int i=result.size()-1; i>=0;i--){
        cout<<result[i]<<" ";
    }
    
    
}
