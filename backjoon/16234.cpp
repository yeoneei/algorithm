//
//  16234.cpp
//  backjoon
//
//  Created by 조연희 on 05/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//

#include <iostream>
#include <queue>
#include <string.h>
using namespace std;

int map[51][51];
bool ch[51][51];

int dx[4]={0,0,1,-1};
int dy[4]={1,-1,0,0};

struct Node{
    int y;
    int x;
    Node(int y,int x):y(y),x(x){};
};
int n,l,r;

void printMap(){
    for(int i=0;i<n;i++){
        for(int j=0; j<n;j++){
            cout<<map[i][j]<<" ";
        }
        cout<<'\n';
    }
    cout<<'\n';
}
int bfs(int y,int x){
    queue<Node> qu;
    queue<Node> list;
    qu.push(Node(y,x));
    ch[y][x]=1;
    list.push(Node(y,x));
    int sum= map[y][x];
    while(!qu.empty()){
        int y = qu.front().y;
        int x = qu.front().x;
        qu.pop();
        for(int i=0; i<4;i++){
            int ny = y+dy[i];
            int nx = x+dx[i];
            if(ny<0 || ny>=n || nx<0 || nx>=n ||ch[ny][nx] || abs(map[ny][nx]-map[y][x])>r || abs(map[ny][nx]-map[y][x])<l) continue;
            sum+=map[ny][nx];
            ch[ny][nx]=1;
            qu.push(Node(ny,nx));
            list.push(Node(ny,nx));
        }
    }
    if(list.size()==1) return 0;
    
    int size = (int)list.size();
    int v = sum/size;
    
    while(!list.empty()){
        map[list.front().y][list.front().x]=v;
        list.pop();
    }
    return size;
}

int main(){
    cin>>n>>l>>r;
    for(int i=0; i<n;i++){
        for(int j=0; j<n;j++){
            cin>>map[i][j];
        }
    }
    int t=0;
    while(1){
        int cnt =0;
        memset(ch,0,sizeof(ch));
        for(int i=0; i<n;i++){
            for(int j=0; j<n;j++){
                if(ch[i][j])continue;
                cnt+=bfs(i,j);
            }
        }
        if(cnt==0){
            cout<<t;
            return 0;
        }
        t++;
        
        
    }
}
