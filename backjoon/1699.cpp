//
//  1699.cpp
//  backjoon
//
//  Created by 조연희 on 01/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int n,m;
char map[50][50];
bool check[50][50];
int dist[50][50];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
bool go(int y, int x,int cnt,char color){
    if(check[y][x]) return cnt-dist[y][x]>=4;
    check[y][x]=1;
    dist[y][x]=cnt;
    for(int i=0; i<4;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        if(ny<0 ||ny>=n || nx<0 || nx>=m || color != map[ny][nx]) continue;
        if(go(ny,nx,cnt+1,map[ny][nx])) return true;
    }
    return false;
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>map[i][j];
        }
    }
    
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            bool ch = go(i,j,0,map[i][j]);
            if(ch){
                cout<<"Yes"<<endl;
                return 0;
            }
        }
    }
    cout<<"No"<<endl;
    
}
