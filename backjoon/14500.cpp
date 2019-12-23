//
//  14500.cpp
//  backjoon
//
//  Created by 조연희 on 16/07/2019.
//  Copyright © 2019 조연희. All rights reserved.
//
#include <iostream>
using namespace std;

int map[500][500];
bool check[500][500];
int n,m;
int maxN=0;
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dfs(int cnt, int sum, int x, int y){
    if(cnt ==4){
        if(maxN<sum){
            maxN=sum;
        }
        return;
    }
    if(cnt>=4){
        return;
    }
    for(int i=0; i<4;i++){
        int nx = x+ dx[i];
        int ny = y + dy[i];
        if(nx<0 || nx>=m || ny<0 || ny>=n) continue;
        if(check[ny][nx]==1)continue;
        check[ny][nx]=1;
        sum+=map[ny][nx];
        dfs(cnt+1,sum,nx,ny);
        sum-=map[ny][nx];
        check[ny][nx]=0;
    }
}
void dfs2(int x, int y){
    int sum=0;
    if(x>=0 && x+2<m && y-1>=0 && y<n){
        sum=0;
        for(int i= x; i<x+3;i++){
            sum+=map[y][i];
        }
        sum+=map[y-1][x+1];
        if(maxN<sum){
            maxN = sum;
        }
    }
    
    if(x>=0 && x+2<m && y+1<n && y>=0){
        sum=0;
        for(int i= x; i<x+3;i++){
            sum+=map[y][i];
        }
        sum+=map[y+1][x+1];
        
        if(maxN<sum){
            
            maxN = sum;
        }
    }
    
    if(y+2<n && y>=0 && x>=0 && x+1<m){
        sum=0;
        for(int i= y; i<y+3;i++){
            sum+=map[i][x];
        }
        sum+=map[y+1][x+1];
        
        if(maxN<sum){
            
            maxN= sum;
        }
        
    }
    
    if(y+2<n && y>=0 && x<m && x-1>=0){
        sum=0;
        for(int i= y; i<y+3;i++){
            sum+=map[i][x];
        }
        sum+=map[y+1][x-1];
        
        if(maxN<sum){
            
            maxN= sum;
        }
    }
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
            
            dfs2(j,i);
            dfs(0,0,j,i);
        }
    }
    cout<<maxN<<endl;
    
}
