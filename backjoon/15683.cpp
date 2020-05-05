//
//  15683.cpp
//  backjoon
//
//  Created by 조연희 on 02/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;
int n,m;
int map[8][8];
int check[8][8];
struct Node{
    int y;
    int x;
    Node(int y,int x):y(y),x(x){}
};
queue<Node> qu;
int dx[4]={0,1,0,-1};
int dy[4]={-1,0,1,0};
int answer=64;
void printCheck(){
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cout<<check[i][j]<<" ";
        }
        cout<<endl;
    }
    cout<<endl;
}

int answerReturn(int check[][8]){
    int cnt=0;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            if(check[i][j]==0 && map[i][j]==0)cnt++;
        }
    }
    return cnt;
}
void MapCopty(int s[][8],int d[][8]){
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            d[i][j]=s[i][j];
        }
    }
}


void spread(int dir, int x, int y){
    while(1){
        y+=dy[dir];
        x+=dx[dir];
        if(x<0 || x>=m || y<0 ||y>=n ||map[y][x]==6)break;
        check[y][x]=1;
    }
}

void dfs(queue<Node> qu){
    if(qu.empty()){
        answer = min(answer,answerReturn(check));
        return;
    }
    int y = qu.front().y;
    int x = qu.front().x;
    int v  = map[y][x];
    qu.pop();
    int tempCheck[8][8];
    MapCopty(check, tempCheck);
    if(v==1){
        for(int i=0; i<4;i++){
            MapCopty(tempCheck, check);
            spread(i, x, y);
            dfs(qu);
        }
    }
    if(v==2){
        for(int i=0; i<2;i++){
            MapCopty(tempCheck, check);
            spread(i, x, y);
            spread(i+2, x, y);
            dfs(qu);
        }
    }
    if(v==3){
        for(int i=0; i<4;i++){
            MapCopty(tempCheck, check);
            spread(i, x, y);
            spread((i+1)%4, x, y);
            dfs(qu);
        }
    }
    if(v==4){
        for(int i=0; i<4;i++){
            MapCopty(tempCheck, check);
            spread(i, x, y);
            spread((i+1)%4, x, y);
            spread((i+2)%4, x, y);
            dfs(qu);
        }
    }
    if(v==5){
        spread(0, x, y);
        spread(1, x, y);
        spread(2, x, y);
        spread(3, x, y);
        dfs(qu);
    }
}



int main(){
    cin>>n>>m;
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            cin>>map[i][j];
            if(map[i][j]==6){
                check[i][j]=map[i][j];
            }
            if(map[i][j]>=1 && map[i][j]<6){
                check[i][j]=map[i][j];
                qu.push(Node(i,j));
            }
        }
    }
    answer=n*m;
    dfs(qu);
    cout<<answer;
}
