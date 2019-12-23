//
//  2179.cpp
//  backjoon
//
//  Created by 조연희 on 01/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int n,m;
bool map[101][101];
int check[101][101];
int minV;

struct Node{
    int x;
    int y;
    Node(int y, int x):x(x),y(y){}
};
queue<Node> qu;

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void bfs(){
    while(1){
        if(qu.empty()){
            return;
        }
        int x = qu.front().x;
        int y = qu.front().y;
        qu.pop();
        for(int i=0; i<4;i++){
            int nx = x+dx[i];
            int ny = y+dy[i];
            if(nx<=0 || nx>m || ny<=0 || ny>n)continue;
            if(map[ny][nx]==1 && check[ny][nx]==0){
                qu.push(Node(ny,nx));
                check[ny][nx]= check[y][x]+1;
            }
        }
        
    }
}

int main(){
    cin>>n>>m;
    for(int i = 1; i<=n; i++){
        for(int j = 1; j<=m; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    qu.push(Node(1,1));
    bfs();
    cout<<check[n][m]+1;
    
}
