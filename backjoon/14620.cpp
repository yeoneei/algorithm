//
//  14620.cpp
//  backjoon
//
//  Created by 조연희 on 05/01/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
#define MAX 10
using namespace std;

int map[MAX][MAX];
int n;
bool check[MAX*MAX+1];
int minV=200000;
int nodes[3];
bool value[MAX][MAX];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};
int getValue(int nodes[3]){
    memset(value, 0, sizeof(value));
    int sum=0;
    for(int i=0; i<3;i++){
        int y = nodes[i]/n;
        int x = nodes[i]%n;
        value[y][x]=1;
        sum+=map[y][x];
        for(int s=0; s<4;s++){
            int ny = y+dy[s];
            int nx = x+dx[s];
            if(ny<0 || nx<0 || ny>=n || nx>=n || value[ny][nx]==1){
                return -1;
            }
            sum+=map[ny][nx];
            value[ny][nx]=1;
        }
    }
    return sum;
}
void dfs(int cnt,int v){
    if(cnt==3){
        int s = getValue(nodes);
        if(s>=0){
            minV = min(getValue(nodes),minV);
        }
        return;
    }
    
    for(int i=v; i<n*n;i++){
        if(check[i]) continue;
        check[i]=1;
        nodes[cnt]=i;
        dfs(cnt+1,i+1);
        nodes[cnt]=0;
        check[i]=0;
    }
}

int main(){
    cin>>n;
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            cin>>map[i][j];
        }
    }
    
    dfs(0,0);
    cout<<minV<<endl;
}
