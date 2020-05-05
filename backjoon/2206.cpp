//
//  2206.cpp
//  backjoon
//
//  Created by 조연희 on 15/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int n,m;
int check[2][1000][1000];
int map[1000][1000];

struct Node{
    int y;
    int x;
    int c;
    Node(int y, int x,int c):y(y),x(x),c(c){}
};

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
char t;
int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>t;
            map[i][j]=(int)(t-'0');
        }
    }
    
    queue<Node> qu;
    qu.push(Node(0,0,0));
    check[0][0][0]=1;
    
    while(!qu.empty()){
        int y = qu.front().y;
        int x= qu.front().x;
        int c = qu.front().c;
        qu.pop();
        if(y==n-1 && x==m-1){
            cout<<check[c][y][x];
            return 0;
        }
        for(int i=0; i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=m || check[c][ny][nx])continue;
            if(map[ny][nx]==1 && c==0){
                check[c+1][ny][nx]=check[0][y][x]+1;
                qu.push(Node(ny,nx,1));
            }
            
            if(map[ny][nx]==0){
                check[c][ny][nx]=check[c][y][x]+1;
                qu.push(Node(ny,nx,c));
            }
        }
    }
    cout<<-1;
}
