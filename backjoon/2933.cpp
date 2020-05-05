//
//  2933.cpp
//  backjoon
//
//  Created by 조연희 on 11/04/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <string.h>
#include <queue>
using namespace std;

int r,c,m,temp;
char map[100][100];
bool ch[100][100];

void left(int temp){
    temp  = r - temp;
    int idx=0;
    bool in = false;
    while(idx<c){
        if(map[temp][idx]=='x'){
            in = true;
            break;
        }
        idx++;
    }
    
    if(in){
        map[temp][idx]='.';
    }
    
}
void right(int temp){
    temp  = r - temp;
    int idx=c-1;
    bool in = false;
    while(idx>=0){
        if(map[temp][idx]=='x'){
            in = true;
            break;
        }
        idx--;
    }
    
    if(in){
        map[temp][idx]='.';
    }
    
}

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

struct Node{
    int y;
    int x;
    Node(int y, int x):y(y),x(x){}
};
void checkCluster(){
    queue<Node> qu;
    memset(ch,0,sizeof(ch));
    for(int i=0; i<c;i++){
        if(map[r-1][i]=='x'){
            qu.push(Node(r-1,i));
            ch[r-1][i]=1;
        }
    }
    
    while(!qu.empty()){
        int y = qu.front().y;
        int x = qu.front().x;
        qu.pop();
        for(int i=0; i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=r || nx<0 || nx>=c || ch[ny][nx] || map[ny][nx]=='.') continue;
            ch[ny][nx]=1;
            qu.push(Node(ny,nx));
        }
    }
    
}

void moveMineral(){
    
    queue<Node> qu;
    queue<Node> temp;
    for(int i=r-1; i>=0;i--){
        for(int j=0; j<c;j++){
            if(map[i][j]=='x' && ch[i][j]==false){
                qu.push(Node(i,j));
                temp.push(Node(i,j));
            }
        }
    }
    
    int minLen=r;
    while(!qu.empty()){
        int y = qu.front().y;
        int x = qu.front().x;
        qu.pop();
        int idx= y+1;
        while(idx<r){
            if(map[idx][x]=='x' && ch[idx][x]==1){
                break;
            }
            idx++;
        }
        idx--;
        minLen = min(minLen, abs(idx-y));
    }
    while(!temp.empty()){
        int y = temp.front().y;
        int x = temp.front().x;
        temp.pop();
        map[y][x]='.';
        map[y+minLen][x]='x';
    }
}
void printMap(){
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            cout<<map[i][j];
        }
        cout<<endl;
    }
    cout<<endl;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin>>r>>c;
    for(int i=0; i<r;i++){
        for(int j=0; j<c;j++){
            cin>>map[i][j];
        }
    }
    cin>>m;
    bool check=true;
    while(m--){
        cin>>temp;
        if(check){
            left(temp);
            check = !check;
        }else{
            right(temp);
            check = !check;
        }
        checkCluster();
        moveMineral();
    }
    printMap();
}
