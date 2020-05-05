//
//  1261.cpp
//  backjoon
//
//  Created by 조연희 on 28/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int n,m;
char map[100][100];
bool check[10003][100][100];
struct Node{
    int y;
    int x;
    int c;
    Node(int y, int x, int c):y(y),x(x),c(c){};
};
int dy[4]={1,-1,0,0};
int dx[4]={0,0,1,-1};
int main(){
    cin>>m>>n;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>map[i][j];
        }
    }
    check[0][0][0]=1;
    queue<Node> qu;
    qu.push(Node(0,0,0));
    int minV=n*m+1;
    
    while(!qu.empty()){
        if(qu.front().c >minV){
            qu.pop();
            continue;
        }
        int y = qu.front().y;
        int x = qu.front().x;
        int c = qu.front().c;
        qu.pop();
        if(y== n-1 && x == m-1){
            minV= min(minV, c);
            continue;
        }
        for(int i=0; i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=m || check[map[ny][nx]=='1'?c+1:c][ny][nx])continue;
            check[map[ny][nx]=='1'?c+1:c][ny][nx]=1;
            qu.push(Node(ny,nx,map[ny][nx]=='1'?c+1:c));
        }
    }
    cout<<minV;
}
