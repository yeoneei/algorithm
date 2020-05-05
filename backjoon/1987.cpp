//
//  1987.cpp
//  backjoon
//
//  Created by 조연희 on 03/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
using namespace std;
int n,m;
char map[21][21];
bool checkMap[21][21];
int answer=0;
bool alph[26];
int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

void dfs(int y,int x,int cnt){
    if(cnt>answer){
        answer = cnt;
    }
    for(int i=0; i<4;i++){
        int ny = y + dy[i];
        int nx = x + dx[i];
        if(nx<0 || nx>=m || ny<0 || ny>=n||checkMap[ny][nx])continue;
        if(alph[map[ny][nx]-'A']==1){
            continue;
        }
        alph[map[ny][nx]-'A']=1;
        checkMap[ny][nx]=1;
        dfs(ny,nx,cnt+1);
        alph[map[ny][nx]-'A']=0;
        checkMap[ny][nx]=0;
    }
}

int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>map[i][j];
        }
    }
    
    checkMap[0][0]=1;
    alph[map[0][0]-'A']=1;
    dfs(0,0,1);
    cout<<answer;
}
