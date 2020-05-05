//
//  3190.cpp
//  backjoon
//
//  Created by 조연희 on 26/02/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
using namespace std;

int dx[4]={1,0,-1,0};
int dy[4]={0,1,0,-1};

int map[100][100];
bool chMap[100][100];
struct Node{
    int y;
    int x;
    int d;
    int t;
    Node(int y, int x):y(y),x(x){}
    Node(int y,int x, int d,int t):x(x),y(y),d(d),t(t){}
};

int n,k,l,y,x,tt;
void printMap(){
    for(int i=0; i<n;i++){
        for(int j=0;j<n;j++){
            cout<<chMap[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}
char ch;
queue<Node> snake;
queue<Node>temp;
queue<pair<int, char>> tim;
int main(){
    cin>>n;
    cin>>k;
    for(int i=0; i<k;i++){
        cin>>y>>x;
        map[y-1][x-1]=1;
    }
    cin>>l;
    for(int i=0; i<l;i++){
        cin>>tt>>ch;
        tim.push(make_pair(tt, ch));
    }

    snake.push(Node(0,0));
    temp.push(Node(0,0,0,0));
    chMap[0][0]=1;
    while(!temp.empty()){
        int y = temp.front().y;
        int x = temp.front().x;
        int d = temp.front().d;
        int timeSnake = temp.front().t;
        timeSnake++;
        temp.pop();
        int ny = y+dy[d];
        int nx = x+dx[d];
        //종료조건
        if(chMap[ny][nx]==1 || ny<0 || ny>=n || nx<0 || nx>=n){
            // 끝남
            cout<<timeSnake;
            return 0;
        }
        // 틀어야할 시간 -> 사과 먹음 / 안먹음
        // 안틀어도 됨 -> 사과먹음 / 안먹음
        int now = tim.front().first;
        chMap[ny][nx]=1;
        if(now==timeSnake) {
            snake.push(Node(ny,nx));
            if(map[ny][nx]==0){
                chMap[snake.front().y][snake.front().x]=0;
                snake.pop();
            }else{
                map[ny][nx]=0;
            }
            if(tim.front().second=='D'){
                d++;
                d = (d>3?d%4:d);
            }else{
                d--;
                d = (d<0?d+4:d);
            }
            tim.pop();
            temp.push(Node(ny,nx,d,timeSnake));
        }else{
            snake.push(Node(ny,nx));
            if(map[ny][nx]==0){
                chMap[snake.front().y][snake.front().x]=0;
                snake.pop();
            }else{
                map[ny][nx]=0;
            }
            temp.push(Node(ny,nx,d,timeSnake));
        }
    }
}
