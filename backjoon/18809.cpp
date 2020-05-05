//
//  18809.cpp
//  backjoon
//
//  Created by 조연희 on 25/03/2020.
//  Copyright © 2020 조연희. All rights reserved.
//
#include <iostream>
#include <queue>
#include <vector>
#include <string.h>
using namespace std;
int map[50][50];
int n,m,gg,rr;

struct Node{
    int y;
    int x;
    Node(int y, int x):y(y),x(x){}
};
vector<Node> one;
bool check[2500];
int dy[4]={1,-1,0,0};
int dx[4]={0,0,-1,1};
int answer=0;
int green[50][50];
int red[50][50];
int quSize=0;
int gSelect[5];
int rSelect[5];

void init(){
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            green[i][j]=0;
        }
    }
    for(int i=0; i<n;i++){
        for(int j=0; j<m;j++){
            red[i][j]=0;
        }
    }
}
void getAnswer(){
    queue<Node> g;
    queue<Node> r;
    init();
    for(int i=0; i<gg;i++){
        green[one[gSelect[i]].y][one[gSelect[i]].x]=1;
        g.push(Node(one[gSelect[i]].y,one[gSelect[i]].x));
    }
    for(int i=0; i<rr;i++){
        red[one[rSelect[i]].y][one[rSelect[i]].x]=1;
        r.push(Node(one[rSelect[i]].y,one[rSelect[i]].x));
    }
    int ss=0;
    while(!(g.empty()&& r.empty())){
        int gSize = g.size();
        while(gSize--){
            int y = g.front().y;
            int x = g.front().x;
            g.pop();
            if(green[y][x]==-1)continue;
            for(int i=0; i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny<0 || ny>=n || nx<0 ||nx>=m || green[ny][nx]!=0 ||map[ny][nx]==0)continue;
                green[ny][nx]=green[y][x]+1;
                g.push(Node(ny,nx));
            }
        }
        
        int rSize = r.size();
        while(rSize--){
            int y = r.front().y;
            int x = r.front().x;
            r.pop();
            for(int i=0; i<4;i++){
                int ny = y+dy[i];
                int nx = x+dx[i];
                if(ny<0 || ny>=n || nx<0 ||nx>=m || red[ny][nx]!=0 ||map[ny][nx]==0)continue;
                red[ny][nx]=red[y][x]+1;
                if(red[ny][nx]==green[ny][nx]){
                    red[ny][nx]=-1;
                    green[ny][nx]=-1;
                    ss++;
                    continue;
                }
                r.push(Node(ny,nx));
            }
        }
    }
    answer = max(ss, answer);
}

void getR(int cnt,int v){
    if(cnt==rr){
        getAnswer();
        return;
    }
    for(int  i=v;i<quSize;i++){
        if(check[i])continue;
        check[i]=1;
        rSelect[cnt]=i;
        getR(cnt+1,i+1);
        check[i]=0;
    }
}


void getG(int cnt,int v){
    if(cnt==gg){
        getR(0, 0);
        return;
    }
    for(int i=v;i<quSize;i++){
        if(check[i])continue;
        check[i]=1;
        gSelect[cnt]=i;
        getG(cnt+1,i+1);
        check[i]=0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m>>gg>>rr;
    for(int i=0; i<n;i++){
        for(int j=0;j<m;j++){
            cin>>map[i][j];
            if(map[i][j]==2){
                one.push_back(Node(i,j));
            }
        }
    }
    quSize = one.size();
    getG(0,0);
    cout<<answer;
    
}
