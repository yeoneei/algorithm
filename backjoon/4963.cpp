//
//  4963.cpp
//  backjoon
//
//  Created by 조연희 on 24/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int dx[8]={0,0,1,-1,1,1,-1,-1};
int dy[8]={1,-1,0,0,1,-1,1,-1};
int n,m;
bool map[50][50];
bool check[50][50];
struct Node{
    int y;
    int x;
    Node(int y, int x):y(y),x(x){};
};

void bfs(int y, int x){
    queue<Node> qu;
    qu.push(Node(y,x));
    while(!qu.empty()){
        int y = qu.front().y;
        int x = qu.front().x;
        qu.pop();
        for(int i=0; i<8;i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<0 || nx>=m || ny <0 || ny>=n)continue;
            if(map[ny][nx]==0 || check[ny][nx]==1)continue;
            check[ny][nx]=1;
            qu.push(Node(ny,nx));
        }
    }
}


int main(){
    while(cin>>m>>n){
        if(m==0 && n==0){
            break;
        }
        
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                cin>>map[i][j];
            }
        }
        memset(check,0,sizeof(check));
        int cnt=0;
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                if(map[i][j]==0 || check[i][j]==1) continue;
                check[i][j]=1;
                bfs(i,j);
                cnt++;
            }
        }
        cout<<cnt<<'\n';
        
        
    }
}
