//
//  2294.cpp
//  backjoon
//
//  Created by 조연희 on 04/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <queue>
#define MAX 101
using namespace std;

int map[MAX][MAX];
int check[MAX][MAX][2];
int n,m,k;
struct Node{
    int y;
    int x;
    bool c;
    int t;
    Node(int y, int x, bool c,int t):y(y),x(x),c(c),t(t){}
};
int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};
queue<Node> qu;
int minK=1234567;
bool suc=false;
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>n>>m>>k;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>map[i][j];
            check[i][j][0]=10000;
            check[i][j][1]=10000;
        }
    }
    
    
    qu.push(Node(0,0,0,0));
    while(!qu.empty()){
        if(qu.front().t>k){
            qu.pop();
            continue;
        }
        if(qu.front().y == n-1 && qu.front().x == m-1 && qu.front().t<=k){
            suc= true;
            minK = min(minK, qu.front().t);
            qu.pop();
            continue;
        }
        int x = qu.front().x;
        int y = qu.front().y;
        bool c = qu.front().c;
        int t = qu.front().t;
        qu.pop();
        for(int i=0; i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(t+1>k || nx<0||nx>=m || ny<0 || ny>=n|| check[ny][nx][c]<=t+1 || (!c && map[ny][nx]==1)){
                continue;
            }
            check[ny][nx][c]=t+1;
            if(!c){
                qu.push(Node(ny,nx,map[ny][nx]==2,t+1));
            }else{
                qu.push(Node(ny,nx,1,t+1));
            }
        }
    }
    
    if(suc){
        cout<<minK<<endl;
    }else{
        cout<<"Fail"<<endl;
    }
    
}
