//
//  17485.cpp
//  backjoon
//
//  Created by 조연희 on 28/12/2019.
//  Copyright © 2019 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <queue>
#define MAX 1000
#define INF 98765432;
using namespace std;
int n,m;
int map[MAX+1][MAX+1];
int check[MAX+1][MAX+1][3];
int result = INF;
int dx[3]={-1,0,1};
struct Node{
    int y;
    int x;
    int r;
    int d;
    Node(int y, int x,int d, int r):y(y),x(x),d(d),r(r){}
};
queue<Node> qu;
int main(){
    ios_base :: sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    
    cin>>n>>m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>map[i][j];
            check[i][j][0]=INF;
            check[i][j][1]=INF;
            check[i][j][2]=INF;
        }
    }
    for(int s=0; s<m;s++){
        qu.push(Node(0,s,-1,map[0][s]));
        while(!qu.empty()){
            if(qu.front().r > result){
                qu.pop();
                continue;
            }
            int y = qu.front().y;
            int x = qu.front().x;
            int r = qu.front().r;
            int d = qu.front().d;
            qu.pop();
            for(int i=0; i<3;i++){
                int nx = x + dx[i];
                int ny = y+1;
                if(d==i || nx<0 ||nx>=m || check[ny][nx][i]<r+map[ny][nx]) continue;
                if(ny==n-1) result = min(result, r+map[ny][nx]);
                else{
                    check[ny][nx][i]=r+map[ny][nx];
                    qu.push(Node(ny,nx,i,r+map[ny][nx]));
                }
            }
        }
    }
    cout<<result;
}
