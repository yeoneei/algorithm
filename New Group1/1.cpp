//
//  1.cpp
//  backjoon
//
//  Created by 조연희 on 14/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
using namespace std;

int n,m,T;
bool map[50][50];
bool check[50][50];
bool real[50][50];
bool answer=0;

int dx[2]={1,0};
int dy[2]={0,1};


bool answerCheck(){
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(map[i][j]!=real[i][j]) return false;
        }
    }
    return true;
}

void dfs(int y, int x){
    if(answer==true)return;
    if(answerCheck()){
        answer = true;
        return;
    }
    //check
    for(int i=0;i<2;i++){
        int ny = y+dy[i];
        int nx = x+dx[i];
        bool ch=false;
        //범위 확인
        if(0>ny || ny+1>=n || 0>nx || nx+1>=m)continue;
        if(check[ny][nx])continue;
        if(map[ny][nx]){
            ch = true;
            real[ny][nx]=1;
            real[ny+1][nx]=1;
            real[ny][nx+1]=1;
            real[ny+1][nx+1]=1;
        }
        dfs(ny,nx);
        if(ch){
            real[ny][nx]=0;
            real[ny+1][nx]=0;
            real[ny][nx+1]=0;
            real[ny+1][nx+1]=0;
        }
    }
}


int main(){
    cin>>T;
    for(int t=0; t<T;t++){
        cin>>n>>m;
        answer=false;
        memset(map,0,sizeof(map));
        memset(check,0,sizeof(check));
        memset(real,0,sizeof(real));
        for(int i=0; i<n;i++){
            for(int j=0; j<m;j++){
                cin>>map[i][j];
            }
        }
        if(map[0][0]){
            real[0][0]=1;
            real[1][0]=1;
            real[0][1]=1;
            real[1][1]=1;
            check[0][0]=1;
        }
        dfs(0,0);
        if(answer){
            cout<<"YES"<<'\n';
        }else{
            cout<<"NO"<<'\n';
        }
        
        
    }
}
